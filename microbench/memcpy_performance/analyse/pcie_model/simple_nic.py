## Copyright (C) 2015-2018 Rolf Neugebauer.  All rights reserved.
## Copyright (C) 2015 Netronome Systems, Inc.  All rights reserved.
##
## Licensed under the Apache License, Version 2.0 (the "License");
## you may not use this file except in compliance with the License.
## You may obtain a copy of the License at
##
##   http://www.apache.org/licenses/LICENSE-2.0
##
## Unless required by applicable law or agreed to in writing, software
## distributed under the License is distributed on an "AS IS" BASIS,
## WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
## See the License for the specific language governing permissions and
## limitations under the License.

"""A simple NIC model"""

import math
from . import pcie
from . import util

# pylint: disable=invalid-name
# pylint: disable=bad-whitespace

def bw(pcicfg, bwspec, direction, pkt_size):
    """
    This code estimates the PCIe bandwidth requirements for a very simple NIC.

    @param pcicfg    PCIe configuration
    @param bwspec    Bandwidth specification
    @param pkt_size  Size of the Ethernet frame (subtract 4 to calculate
                     with FCS stripping)
    @returns A BW_Res object

    We assume that descriptors are 128bit in size and a single RX and TX ring.

    TX from the host:
    1. Host updates the TX queue tail pointer            (PCIe write: rx)
    2. Device DMAs descriptor                            (PCIe read:  rx/tx)
    3. Device DMAs packet content                        (PCIe read:  rx/tx)
    4. Device generates interrupt                        (PCIe write: tx)
    5. Host reads TX queue head pointer                  (PCIe read:  rx/tx)

    RX to the host:
    1. Host updates RX Queue Tail Pointer -> free buf    (PCIe write: rx)
    2. Device DMAs descriptor from host                  (PCIe read:  rx/tx)
    3. Device DMAs packet to host                        (PCIe write: tx)
    4. Device writes back RX descriptor                  (PCIe write: tx)
    5. Device generates interrupt                        (PCIe write: tx)
    6. Host reads RX queue head pointer                  (PCIe read:  rx/tx)

    We assume these steps are performed for every packet.
    """
    tx_desc_sz    = 16
    rx_desc_sz    = 16
    rx_desc_wb_sz = 16

    ptr_sz        = 4

    if not direction & pcie.DIR_BOTH:
        raise Exception("Unknown Direction %d" % direction)

    data_B = pkt_size

    # Packet TX
    tx_rx_data_B = 0 # bytes for TX received by the device
    tx_tx_data_B = 0 # bytes for TX transmitted by the device
    # H: tail pointer write
    tx_rx_data_B += ptr_sz + pcicfg.TLP_MWr_Hdr_Sz
    # D: read descriptor
    _rd_sz = tx_desc_sz
    tlps = int(math.ceil(float(_rd_sz) / float(pcicfg.mrrs)))
    tx_tx_data_B += tlps * pcicfg.TLP_MRd_Hdr_Sz
    if pcicfg.rcb_chunks:
        tlps = int(math.ceil(float(_rd_sz) / float(pcicfg.rcb)))
    else:
        tlps = int(math.ceil(float(_rd_sz) / float(pcicfg.mps)))
    tx_rx_data_B += (tlps * pcicfg.TLP_CplD_Hdr_Sz) + _rd_sz
    # D: data DMA reads
    tlps = int(math.ceil(float(data_B) / float(pcicfg.mrrs)))
    tx_tx_data_B += tlps * pcicfg.TLP_MRd_Hdr_Sz
    if pcicfg.rcb_chunks:
        tlps = int(math.ceil(float(data_B) / float(pcicfg.rcb)))
    else:
        tlps = int(math.ceil(float(data_B) / float(pcicfg.mps)))
    tx_rx_data_B += (tlps * pcicfg.TLP_CplD_Hdr_Sz) + data_B
    # D: send IRQ
    tx_tx_data_B += pcie.MSI_SIZE + pcicfg.TLP_MWr_Hdr_Sz
    # H: read head pointer
    tx_rx_data_B += pcicfg.TLP_MRd_Hdr_Sz
    tx_tx_data_B += ptr_sz + pcicfg.TLP_CplD_Hdr_Sz
    # done

    # Packet RX
    rx_rx_data_B = 0 # bytes for RX received by the device
    rx_tx_data_B = 0 # bytes for RX transmitted by the device
    # H: tail pointer write
    rx_rx_data_B += ptr_sz + pcicfg.TLP_MWr_Hdr_Sz
    # D: read descriptors
    rx_tx_data_B += pcicfg.TLP_MRd_Hdr_Sz
    rx_rx_data_B += rx_desc_sz + pcicfg.TLP_CplD_Hdr_Sz
    # D: DMA write
    tlps = int(math.ceil(float(data_B) / float(pcicfg.mps)))
    rx_tx_data_B = (tlps * pcicfg.TLP_MWr_Hdr_Sz) + data_B
    # D: Write back descriptors
    rx_tx_data_B += rx_desc_wb_sz + pcicfg.TLP_MWr_Hdr_Sz
    # D: send IRQ (Depending on setting)
    rx_tx_data_B += pcie.MSI_SIZE + pcicfg.TLP_MWr_Hdr_Sz
    # H: read head pointer
    rx_rx_data_B += pcicfg.TLP_MRd_Hdr_Sz
    rx_tx_data_B += ptr_sz + pcicfg.TLP_CplD_Hdr_Sz
    # done

    # we now know how many bytes are transfered in each direction for
    # both RX and TX. Lets work out how much we can transfer etc.
    return util.gen_res(bwspec, direction, data_B,
                        tx_rx_data_B, tx_tx_data_B, rx_rx_data_B, rx_tx_data_B)
