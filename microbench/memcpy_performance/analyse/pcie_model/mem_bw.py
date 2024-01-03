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

"""Simple PCIe memory bandwidth models"""

# pylint: disable=invalid-name
# pylint: disable=too-many-locals
# pylint: disable=unused-variable

import math
from . import pcie

def write(pcicfg, bwspec, size):
    """
    Calculate the bandwidth a simple continuous PCIe memory write of
    size 'size' will consume given the maximum payload size of 'mps'.

    The write requests are broken into up to mps sized chunks and the TLP
    header is added.  There is no reverse direction traffic.

    @param pcicfg    PCIe configuration
    @param bwspec    Bandwidth specification
    @param size      Size of payload in bytes
    """
    data_bytes = size

    # compute the number of TLPs
    num_tlps = int(math.ceil(float(data_bytes) / float(pcicfg.mps)))
    raw_bytes = (num_tlps * pcicfg.TLP_MWr_Hdr_Sz) + data_bytes

    if bwspec.type == pcie.BW_Spec.BW_RAW:
        raw_bw = bwspec.tx_bw
        eff_bw = float(data_bytes) * raw_bw / float(raw_bytes)
    else:
        eff_bw = bwspec.tx_bw
        raw_bw = float(raw_bytes) * eff_bw / float(data_bytes)

    return pcie.BW_Res(0.0, 0.0, raw_bw, eff_bw)

def read(pcicfg, bwspec, size):
    """
    Calculate the bandwidth a simple continuous PCIe memory read of
    size 'size' will consume given the maximum payload size of 'mps'.

    PCIe memory reads require bandwidth in both directions: TX for sending
    requests and RX for receiving the data (PCIe Completions with Data).

    avail_??_bw is assumed to be of the same type for both RX and TX

    The read data is broken up into M PCIe completions with data
    transactions.  Typically the first completion will align to Read
    Completion Boundary (RCB) and remaining completions will be
    multiples of RCB till the last completion.

    For simplicity we assume that read requests are aligned to
    boundaries.  Depending on 'rcb_chunks' we break the completion in
    RCB sized chunks or MPS sized chunks.  RCB sized chunks have been
    observed on several older chipsets.

    @param pcicfg    PCIe configuration
    @param bwspec    Bandwidth specification
    @param size      Size of payload in bytes
    """
    dat_rx_B = size
    dat_tx_B = 0    # no data transmitted

    # Size of the read request. A request might have to be broken into
    # several requests according to MRRS.
    tx_num_tlps = int(math.ceil(float(dat_rx_B) / float(pcicfg.mrrs)))
    raw_tx_B = tx_num_tlps * pcicfg.TLP_MRd_Hdr_Sz

    # Size of the completion with data chopped up
    if pcicfg.rcb_chunks:
        rx_num_tlps = int(math.ceil(float(dat_rx_B) / float(pcicfg.rcb)))
    else:
        rx_num_tlps = int(math.ceil(float(dat_rx_B) / float(pcicfg.mps)))
    raw_rx_B = (rx_num_tlps * pcicfg.TLP_CplD_Hdr_Sz) + dat_rx_B

    if bwspec.type == pcie.BW_Spec.BW_RAW:
        # this calculation only makes sense if a raw bandwidth has been
        # specified. We work out if raw_tx_b fits in the available
        # bandwidth. If not, we need to adjust the number of rx blocks...
        raw_tx_b = raw_tx_B * 8
        raw_rx_b = raw_rx_B * 8
        avail_raw_tx_bw_b = bwspec.tx_bw * (10**9)
        avail_raw_rx_bw_b = bwspec.rx_bw * (10**9)
        # work out how many transactions the RX can cope with
        max_trans = avail_raw_rx_bw_b / float(raw_rx_b)
        # assume we can support the RX data rate with TX for requests
        req_raw_tx_bw_b = max_trans * raw_tx_b

        if req_raw_tx_bw_b > avail_raw_tx_bw_b:
            # can't send enough requests as we'd run out of TX bandwidth
            # Adjust the tx and rx work. Assume TX is maxed out
            req_raw_tx_bw_b = avail_raw_tx_bw_b
            # number of read requests we can support
            max_trans = req_raw_tx_bw_b / float(raw_tx_b)
            # work out new rx bandwidth
            req_raw_rx_bw_b = max_trans * raw_rx_b
        else:
            # we are maxed out on RX, so just use the tlp_bw
            req_raw_rx_bw_b = avail_raw_rx_bw_b

        req_raw_tx_bw = req_raw_tx_bw_b / float(10**9)
        req_raw_rx_bw = req_raw_rx_bw_b / float(10**9)

        eff_tx_bw = float(dat_tx_B) * req_raw_tx_bw / float(raw_tx_B) # = 0
        eff_rx_bw = float(dat_rx_B) * req_raw_rx_bw / float(raw_rx_B)

    else: # BW_EFF
        if not bwspec.tx_bw == 0:
            print("Effective TX BW for reads is always 0")
            bwspec.tx_bw = 0
        eff_tx_bw = bwspec.tx_bw
        eff_rx_bw = bwspec.rx_bw

    return pcie.BW_Res(req_raw_rx_bw, eff_rx_bw, req_raw_tx_bw, eff_tx_bw)

def read_write(pcicfg, bwspec, size):
    """
    PCIe read and writes at the same time. read should impact write
    Assume symmetric read and writes,

    @param pcicfg    PCIe configuration
    @param bwspec    Bandwidth specification
    @param size      Size of payload in bytes
    """
    data_bytes = size

    # Write bytes
    wr_rx_data_B = 0 # bytes for Writes received by the device
    wr_tx_data_B = 0 # bytes for Writes transmitted by the device
    wr_tx_num_tlps = int(math.ceil(float(data_bytes) / float(pcicfg.mps)))
    wr_rx_num_tlps = 0 # no TLPs our way for reads
    wr_tx_data_B = (wr_tx_num_tlps * pcicfg.TLP_MWr_Hdr_Sz) + data_bytes

    # Read bytes
    rd_rx_data_B = 0 # bytes for Reads received by the device
    rd_tx_data_B = 0 # bytes for Reads transmitted by the device
    # Size of the read request. A request might have to be broken into
    # several requests according to MRRS.
    rd_tx_num_tlps = int(math.ceil(float(data_bytes) / float(pcicfg.mrrs)))
    rd_tx_data_B = rd_tx_num_tlps * pcicfg.TLP_MRd_Hdr_Sz
    # Size of the completion with data chopped up
    if pcicfg.rcb_chunks:
        rd_rx_num_tlps = int(math.ceil(float(data_bytes) / float(pcicfg.rcb)))
    else:
        rd_rx_num_tlps = int(math.ceil(float(data_bytes) / float(pcicfg.mps)))
    rd_rx_data_B = (rd_rx_num_tlps * pcicfg.TLP_CplD_Hdr_Sz) + data_bytes

    # we now have number of RAW bytes transferred in each direction for
    # both read and write requests

    # Work out overall bytes in each direction per transaction
    raw_rx_B = 0
    raw_tx_B = 0

    raw_rx_B += wr_rx_data_B
    raw_rx_B += rd_rx_data_B

    raw_tx_B += wr_tx_data_B
    raw_tx_B += rd_tx_data_B

    eff_data = data_bytes

    if bwspec.type == pcie.BW_Spec.BW_RAW:
        # We have been given available raw BW in each direction.
        # Reads requires BW in both direction. Writes only require BW in one
        # direction.
        raw_tx_b = raw_tx_B * 8
        raw_rx_b = raw_rx_B * 8
        avail_raw_tx_bw_b = bwspec.tx_bw * (10**9)
        avail_raw_rx_bw_b = bwspec.rx_bw * (10**9)

        # work out how many Read transactions the RX avail BW can support
        max_rd_trans = avail_raw_rx_bw_b / float(raw_rx_b)
        # assume the TX BW can support Read requests and Write data
        req_raw_tx_bw_b = max_rd_trans * raw_tx_b

        if req_raw_tx_bw_b > avail_raw_tx_bw_b:
            # Ran out of TX BW
            # Adjust the tx and rx work. Assume TX is maxed out
            req_raw_tx_bw_b = avail_raw_tx_bw_b
            # number of read requests we can support
            max_rd_trans = req_raw_tx_bw_b / float(raw_tx_b)
            # work out new rx bandwidth
            req_raw_rx_bw_b = max_rd_trans * raw_rx_b
        else:
            # we are maxed out on RX, so just use all of the avail rx BW
            req_raw_rx_bw_b = avail_raw_rx_bw_b

        req_raw_tx_bw = req_raw_tx_bw_b / float(10**9)
        req_raw_rx_bw = req_raw_rx_bw_b / float(10**9)

        eff_tx_bw = eff_data * req_raw_tx_bw / float(raw_tx_B)
        eff_rx_bw = eff_data * req_raw_rx_bw / float(raw_rx_B)

    else: # BW_EFF
        eff_tx_bw = bwspec.tx_bw
        eff_rx_bw = bwspec.rx_bw
        req_raw_tx_bw = eff_tx_bw * raw_tx_B / float(eff_data)
        req_raw_rx_bw = eff_rx_bw * raw_rx_B / float(eff_data)

    return pcie.BW_Res(req_raw_rx_bw, eff_rx_bw, req_raw_tx_bw, eff_tx_bw)
