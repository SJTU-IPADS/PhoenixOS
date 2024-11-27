# Copyright 2024 The PhoenixOS Authors. All rights reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

#"""A model for a Intel Niantic 10G NIC"""

# pylint: disable=invalid-name
# pylint: disable=bad-whitespace
# pylint: disable=too-many-arguments
# pylint: disable=too-many-locals
# pylint: disable=too-many-statements

import math
from . import pcie
from . import util

def bw(pcicfg, bwspec, direction, pkt_size, irq_mod=32, h_opt=None):
    """
    This code estimates the PCIe bandwidth requirements for a device
    which looks very much like a Intel Niantic NIC.

    @param pcicfg    PCIe configuration
    @param bwspec    Bandwidth specification
    @param pkt_size  Size of the Ethernet frame (subtract 4 to calculate
                     with FCS stripping)
    @param irq_mod   Controls interrupts. IRQ every n packets. 0 no IRQ
    @param h_opt     Host driver optimisations (see below)
    @returns A BW_Res object

    The details below are taken from the Intel 82599 10 GbE Controller
    Datasheet, specifically, the following sections:

    - 1.9.1 Transmit (Tx) Data Flow
    - 7.2.1.2 Transmit Path in the 82599
    - 7.2.3.4 Transmit Descriptor Fetching
    - 7.2.3.2.4 Advanced Transmit Data Descriptor

    - 1.9.2 Receive (Rx) Data Flow
    - 7.1.6 Advanced Receive Descriptors
    - 7.1.7 Receive Descriptor Fetching

    Throughout we assume the advanced descriptor format being used.
    We further assume that a single RX and TX ring is being used.

    TX from the host:
    1. Host updates the TX queue tail pointer            (PCIe write: rx)
    2. Device DMAs descriptor(s)                         (PCIe read:  rx/tx)
    3. Device DMAs packet content                        (PCIe read:  rx/tx)
    4. Device writes back TX descriptor                  (PCIe write: tx)
    5. Device generates interrupt                        (PCIe write: tx)
    6. Host reads TX queue head pointer                  (PCIe read:  rx/tx)
    Note: The device may fetch up to 40 TX descriptors at a time
    Note: The device may prefetch TX descriptors if its internal Q
          becomes close to empty.  We don't model that.
    Note: TX descriptor write back (step 4) is optional and can be
          batched if TXDCTL[n].WTHRESH is set to non-0.  Default on
          Linux seems to be 8.
    Note: There is an optional head pointer write back which disables
          TX descriptor right back.  This is enable via
          TDWBAL[n].Head_WB_En and is disabled by default on Linux.
    Note: All descriptors are 128bit
    Note: The linux driver updates the TX tail pointer on every packet

    RX to the host:
    1. Host updates RX Queue Tail Pointer -> free buf    (PCIe write: rx)
    2. Device DMAs descriptor from host                  (PCIe read:  rx/tx)
    3. Device DMAs packet to host                        (PCIe write: tx)
    4. Device writes back RX descriptor                  (PCIe write: tx)
    5. Device generates interrupt                        (PCIe write: tx)
    6. Host reads RX queue head pointer                  (PCIe read:  rx/tx)
    Note: By default the Ethernet FCS is stripped before transmitting
          to the host. HLREG0.RXCRCSTRP.  We leave it up to the caller to
          determine if the FCS should be stripped.
    Note: Niantic does not pre-fetch freelist descriptors.  They are
          fetched on demand, when needed.
    Note: Niantic does not seem to be doing any batching of RX
          descriptor write-back unless descriptors belong to the same
          packet (e.g. RSC).
    Note: All descriptors are 128bit

    The default configuration is based on the Linux kernel ixgbe
    driver and how it sets up and uses the NIC.  The DPDK poll mode
    driver uses interacts with the device slightly different.
    Specifically:
    - TX: Steps 5 and 6 are omitted.  No interrupts are generated on
      transmit and the TX Descriptor Done is checked to free
      transmitted buffers.  TX descriptors are enqueue in batches of 32
    - RX: Steps 5 and 6 are omitted.  No interrupts are generated on
      receive and the RX Descriptor Done is checked to new packets.
    To enable these optimisations set @h_opt="PMD"
    """
    tx_desc_sz    = 16
    tx_desc_wb_sz = 16
    rx_desc_sz    = 16
    rx_desc_wb_sz = 16

    ptr_sz        = 4

    # Niantic can prefetch up to 40 descriptors and write back batches of 8
    d_tx_batch    = 40
    d_tx_batch_wb = 8

    # Assumptions about what the host is doing: Update the TX pointer
    # every @h_tx_batch packets. En-queue @h_fl_batch free buffers at
    # a time and update the RX head pointer every @h_rx_batch
    h_tx_batch    = 1
    h_fl_batch    = 32
    h_rx_batch    = 8

    if h_opt == "PMD":
        h_tx_batch = 32
        irq_mod =  0

    # work out batch size and multiplier for different tasks
    batch_mul = util.low_com_mul(h_fl_batch, d_tx_batch)
    d_tx_batch_mul    = batch_mul / d_tx_batch
    d_tx_batch_wb_mul = batch_mul / d_tx_batch_wb
    h_tx_batch_mul    = batch_mul / h_tx_batch
    h_fl_batch_mul    = batch_mul / h_fl_batch
    h_rx_batch_mul    = batch_mul / h_rx_batch
    if irq_mod > 0:
        irq_mul       = batch_mul / irq_mod
    else:
        irq_mul       = 0

    # stash the packet size away
    data_B = pkt_size

    if not direction & pcie.DIR_BOTH:
        raise Exception("Unknown Direction %d" % direction)

    # XXX add a check that the batch reads/writes of descriptors do not
    # exceed MPS, MRRS, RCB. It is not handled in this code...

    # Packet TX
    tx_rx_data_B = 0 # bytes for TX received by the device
    tx_tx_data_B = 0 # bytes for TX transmitted by the device
    # H: tail pointer write (once per h_tx_batch)
    tx_rx_data_B += (ptr_sz + pcicfg.TLP_MWr_Hdr_Sz) * h_tx_batch_mul
    # D: read descriptor (once per d_tx_batch)
    _rd_sz = tx_desc_sz * d_tx_batch
    tlps = int(math.ceil(float(_rd_sz) / float(pcicfg.mrrs)))
    tx_tx_data_B += (tlps * pcicfg.TLP_MRd_Hdr_Sz) * d_tx_batch_mul
    if pcicfg.rcb_chunks:
        tlps = int(math.ceil(float(_rd_sz) / float(pcicfg.rcb)))
    else:
        tlps = int(math.ceil(float(_rd_sz) / float(pcicfg.mps)))
    tx_rx_data_B += ((tlps * pcicfg.TLP_CplD_Hdr_Sz) + _rd_sz) * d_tx_batch_mul
    # D: data DMA reads (For each packet)
    tlps = int(math.ceil(float(data_B) / float(pcicfg.mrrs)))
    tx_tx_data_B += (tlps * pcicfg.TLP_MRd_Hdr_Sz) * batch_mul
    if pcicfg.rcb_chunks:
        tlps = int(math.ceil(float(data_B) / float(pcicfg.rcb)))
    else:
        tlps = int(math.ceil(float(data_B) / float(pcicfg.mps)))
    tx_rx_data_B += ((tlps * pcicfg.TLP_CplD_Hdr_Sz) + data_B) * batch_mul
    # D: Write back descriptors (once per d_tx_batch_wb)
    _wr_sz = tx_desc_wb_sz * d_tx_batch_wb
    tlps = int(math.ceil(float(_wr_sz)/float(pcicfg.mps)))
    tx_tx_data_B += ((tlps * pcicfg.TLP_MWr_Hdr_Sz) + _wr_sz) *d_tx_batch_wb_mul
    if not h_opt == "PMD":
        # D: send IRQ (depending on setting)
        tx_tx_data_B += (pcie.MSI_SIZE + pcicfg.TLP_MWr_Hdr_Sz) * irq_mul
        # H: read head pointer (once per h_tx_batch)
        tx_rx_data_B += pcicfg.TLP_MRd_Hdr_Sz * h_tx_batch_mul
        tx_tx_data_B += (ptr_sz + pcicfg.TLP_CplD_Hdr_Sz) * h_tx_batch_mul
    # done

    # Packet RX
    rx_rx_data_B = 0 # bytes for RX received by the device
    rx_tx_data_B = 0 # bytes for RX transmitted by the device
    # H: tail pointer write (once per h_fl_batch)
    rx_rx_data_B += (ptr_sz + pcicfg.TLP_MWr_Hdr_Sz) * h_fl_batch_mul
    # D: read descriptors (For each packet)
    rx_tx_data_B += pcicfg.TLP_MRd_Hdr_Sz * batch_mul
    rx_rx_data_B += (rx_desc_sz + pcicfg.TLP_CplD_Hdr_Sz) * batch_mul
    # D: DMA write (For each packet)
    tlps = int(math.ceil(float(data_B) / float(pcicfg.mps)))
    rx_tx_data_B = ((tlps * pcicfg.TLP_MWr_Hdr_Sz) + data_B) * batch_mul
    # D: Write back descriptors (For each packet)
    rx_tx_data_B += (rx_desc_wb_sz + pcicfg.TLP_MWr_Hdr_Sz) * batch_mul
    if not h_opt == "PMD":
        # D: send IRQ (Depending on setting)
        rx_tx_data_B += (pcie.MSI_SIZE + pcicfg.TLP_MWr_Hdr_Sz) * irq_mul
        # H: read head pointer (once per packet)
        rx_rx_data_B += pcicfg.TLP_MRd_Hdr_Sz * h_rx_batch_mul
        rx_tx_data_B += (ptr_sz + pcicfg.TLP_CplD_Hdr_Sz) * h_rx_batch_mul
    # done

    # we now know how many bytes are transfered in each direction for
    # both RX and TX for a batch. Lets work out how much we can transfer etc.
    return util.gen_res(bwspec, direction, data_B * batch_mul,
                        tx_rx_data_B, tx_tx_data_B, rx_rx_data_B, rx_tx_data_B)
ul,
                        tx_rx_data_B, tx_tx_data_B, rx_rx_data_B, rx_tx_data_B)
