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

"""Utility functions"""

from . import pcie

# pylint: disable=invalid-name
# pylint: disable=too-many-arguments
# pylint: disable=too-many-locals

def low_com_mul(x, y):
    """Find the lowest common multiplier of two numbers
    """
    def find_gcf(dividend, divisor):
        reminder = -1
        while reminder != 0:
            reminder = dividend % divisor
            if reminder != 0:
                dividend = divisor
                divisor = reminder
        return divisor

    def find_lcm(x, y, gcf):
        lcm = (x*y)/gcf
        return lcm

    gcf = 0
    lcm = 0
    if x > y:
        dividend = x
        divisor = y
    else:
        dividend = y
        divisor = x

    gcf = find_gcf(dividend, divisor)
    lcm = find_lcm(x, y, gcf)
    return lcm

def gen_res(bwspec, direction, data_sz,
            tx_rx_data_B, tx_tx_data_B, rx_rx_data_B, rx_tx_data_B):
    """Work out the result based on the available bandwidth (@bwspec),
    @direction of transfer and how many bytes were transferred
    (@data_sz).

    The caller also has to provide:
    @tx_rx_data_B: Bytes for TX received by the device
    @tx_tx_data_B: Bytes for TX transmitted by the device
    @rx_rx_data_B: Bytes for RX received by the device
    @rx_tx_data_B: Bytes for RX transmitted by the device
    """

    # Work out overall bytes in each direction per batch
    raw_rx_B = 0
    raw_tx_B = 0
    if direction & pcie.DIR_TX != 0:
        # DIR_TX is from the device, so we look at rx_??_data_B
        raw_rx_B += rx_rx_data_B
        raw_tx_B += rx_tx_data_B
    if direction & pcie.DIR_RX != 0:
        # DIR_RX is from the device, so we look at tx_??_data_B
        raw_rx_B += tx_rx_data_B
        raw_tx_B += tx_tx_data_B

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

        if direction & pcie.DIR_TX and direction & pcie.DIR_RX:
            eff_tx_bw = data_sz * req_raw_tx_bw / float(raw_tx_B)
            eff_rx_bw = data_sz * req_raw_rx_bw / float(raw_rx_B)
        elif direction & pcie.DIR_TX:
            eff_tx_bw = data_sz * req_raw_tx_bw / float(raw_tx_B)
            eff_rx_bw = 0.0
        elif direction & pcie.DIR_RX:
            eff_tx_bw = 0.0
            eff_rx_bw = data_sz * req_raw_rx_bw / float(raw_rx_B)

    else: # BW_EFF
        if direction & pcie.DIR_TX and direction & pcie.DIR_RX:
            eff_tx_bw = bwspec.tx_bw
            eff_rx_bw = bwspec.rx_bw
            req_raw_tx_bw = eff_tx_bw * raw_tx_B / float(data_sz)
            req_raw_rx_bw = eff_rx_bw * raw_rx_B / float(data_sz)
        elif direction & pcie.DIR_TX:
            eff_tx_bw = bwspec.tx_bw
            eff_rx_bw = 0.0
            req_raw_tx_bw = eff_tx_bw * raw_tx_B / float(data_sz)
            # how many batches per second?
            num_batches = eff_tx_bw / float(data_sz)
            # work out rx bandwidth based on batches
            req_raw_rx_bw = num_batches * raw_rx_B
        elif direction & pcie.DIR_RX:
            eff_tx_bw = 0.0
            eff_rx_bw = bwspec.rx_bw
            num_batches = eff_rx_bw / float(data_sz)
            req_raw_tx_bw = num_batches * raw_tx_B
            req_raw_rx_bw = eff_rx_bw * raw_rx_B / float(data_sz)

    return pcie.BW_Res(req_raw_rx_bw, eff_rx_bw, req_raw_tx_bw, eff_tx_bw)
