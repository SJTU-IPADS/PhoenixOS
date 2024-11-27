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

#"""General definitions for PCIe bandwidth calculations"""

# pylint: disable=invalid-name
# pylint: disable=too-many-instance-attributes
# pylint: disable=too-many-arguments
# pylint: disable=too-few-public-methods

##
## General PCIe variables from the Spec
##
Vers = ['gen1', 'gen2', 'gen3', 'gen4', 'gen5']
Laness = ['x1', 'x2', 'x4', 'x8', 'x16', 'x32']
Laness_mul = [1, 2, 4, 8, 16, 32]

# Transactions per second
GTs = {'gen1' : 2.5,
       'gen2' : 5.0,
       'gen3' : 8.0,
       'gen4' : 16.0,
       'gen5' : 32.0}

# Either 8b/10b or 128b/130b symbol encoding
Gbs = {}
for ver in GTs.keys():
    if GTs[ver] >= 8.0:
        Gbs[ver] = (128.0/130.0) * GTs[ver]
    else:
        Gbs[ver] = (8.0/10.0) * GTs[ver]


# Raw bandwidth Gbs * Lanes
Raw = {}
for ver in Vers:
    for lanes in Laness:
        if not ver in Raw:
            Raw[ver] = {}
        Raw[ver][lanes] = Gbs[ver] * \
                          Laness_mul[Laness.index(lanes)]

# Maximum Payload Size
MPSs = [128, 256, 512, 1024, 2048, 4096]
# Maximum Read Request Sizes
MRRSs = [128, 256, 512, 1024, 2048, 4096]
# Read Completion Boundaries
RCBs = [64, 128, 256, 512]

# FC Update Rate,
# see PCIe Base Spec rev 5.0 Table 2-46, 2-47, and 2-48
FC_Size = 8 # 2 B Phys + 4 B DLLP + 2B DLLP CRC
FC_Guide = {
    'gen1' : {
        'x1'  : {128: 237, 256: 416, 512: 559, 1024: 1071, 2048: 2095, 4096: 4143},
        'x2'  : {128: 128, 256: 217, 512: 289, 1024:  545, 2048: 1057, 4096: 2081},
        'x4'  : {128:  73, 256: 118, 512: 154, 1024:  282, 2048:  538, 4096: 1050},
        'x8'  : {128:  67, 256: 107, 512:  86, 1024:  150, 2048:  278, 4096:  534},
        'x16' : {128:  48, 256:  72, 512:  86, 1024:  150, 2048:  278, 4096:  534},
        'x32' : {128:  33, 256:  45, 512:  52, 1024:   84, 2048:  248, 4096:  276},
        },
    'gen2' : {
        'x1'  : {128: 288, 256: 467, 512: 610, 1024: 1122, 2048: 2146, 4096: 4194},
        'x2'  : {128: 179, 256: 268, 512: 340, 1024:  596, 2048: 1108, 4096: 2132},
        'x4'  : {128: 124, 256: 169, 512: 205, 1024:  333, 2048:  589, 4096: 1101},
        'x8'  : {128: 118, 256: 158, 512: 137, 1024:  201, 2048:  329, 4096:  585},
        'x16' : {128:  99, 256: 123, 512: 137, 1024:  201, 2048:  329, 4096:  585},
        'x32' : {128:  84, 256:  96, 512: 103, 1024:  135, 2048:  199, 4096:  327},
        },
    'gen3' : {
        'x1'  : {128: 333, 256: 512, 512: 655, 1024: 1167, 2048: 2191, 4096: 4239},
        'x2'  : {128: 224, 256: 313, 512: 385, 1024:  641, 2048: 1153, 4096: 2177},
        'x4'  : {128: 169, 256: 214, 512: 250, 1024:  378, 2048:  634, 4096: 1146},
        'x8'  : {128: 163, 256: 203, 512: 182, 1024:  246, 2048:  374, 4096:  630},
        'x16' : {128: 144, 256: 168, 512: 182, 1024:  246, 2048:  374, 4096:  630},
        'x32' : {128: 129, 256: 141, 512: 148, 1024:  180, 2048:  244, 4096:  372},
        },
    'gen4' : {
        'x1'  : {128: 333, 256: 512, 512: 655, 1024: 1167, 2048: 2191, 4096: 4239},
        'x2'  : {128: 224, 256: 313, 512: 385, 1024:  641, 2048: 1153, 4096: 2177},
        'x4'  : {128: 169, 256: 214, 512: 250, 1024:  378, 2048:  634, 4096: 1146},
        'x8'  : {128: 163, 256: 203, 512: 182, 1024:  246, 2048:  374, 4096:  630},
        'x16' : {128: 144, 256: 168, 512: 182, 1024:  246, 2048:  374, 4096:  630},
        'x32' : {128: 129, 256: 141, 512: 148, 1024:  180, 2048:  244, 4096:  372},
        },
    'gen5' : {
        'x1'  : {128: 333, 256: 512, 512: 655, 1024: 1167, 2048: 2191, 4096: 4239},
        'x2'  : {128: 224, 256: 313, 512: 385, 1024:  641, 2048: 1153, 4096: 2177},
        'x4'  : {128: 169, 256: 214, 512: 250, 1024:  378, 2048:  634, 4096: 1146},
        'x8'  : {128: 163, 256: 203, 512: 182, 1024:  246, 2048:  374, 4096:  630},
        'x16' : {128: 144, 256: 168, 512: 182, 1024:  246, 2048:  374, 4096:  630},
        'x32' : {128: 129, 256: 141, 512: 148, 1024:  180, 2048:  244, 4096:  372},
        },
    }

# Ack Limit,
# see PCIe Base Spec rev 5.0 Table 3-7, 3-8, and 3-9
Ack_Size = 8 # 2 B Phys + 4 B DLLP + 2B DLLP CRC
Ack_Limits = {
    'gen1' : {
        'x1'  : {128: 237, 256: 416, 512: 559, 1024: 1071, 2048: 2095, 4096: 4143},
        'x2'  : {128: 128, 256: 217, 512: 289, 1024:  545, 2048: 1057, 4096: 2081},
        'x4'  : {128:  73, 256: 118, 512: 154, 1024:  282, 2048:  538, 4096: 1050},
        'x8'  : {128:  67, 256: 107, 512:  86, 1024:  150, 2048:  278, 4096:  534},
        'x16' : {128:  48, 256:  72, 512:  86, 1024:  150, 2048:  278, 4096:  534},
        'x32' : {128:  33, 256:  45, 512:  52, 1024:   84, 2048:  148, 4096:  276},
        },
    'gen2' : {
        'x1'  : {128: 288, 256: 467, 512: 610, 1024: 1122, 2048: 2146, 4096: 4194},
        'x2'  : {128: 179, 256: 268, 512: 340, 1024:  596, 2048: 1108, 4096: 2132},
        'x4'  : {128: 124, 256: 169, 512: 205, 1024:  333, 2048:  589, 4096: 1101},
        'x8'  : {128: 118, 256: 158, 512: 137, 1024:  201, 2048:  329, 4096:  585},
        'x16' : {128:  99, 256: 123, 512: 137, 1024:  201, 2048:  329, 4096:  585},
        'x32' : {128:  84, 256:  96, 512: 103, 1024:  135, 2048:  199, 4096:  237},
        },
    'gen3' : {
        'x1'  : {128: 333, 256: 512, 512: 655, 1024: 1167, 2048: 2191, 4096: 4239},
        'x2'  : {128: 224, 256: 313, 512: 385, 1024:  641, 2048: 1153, 4096: 2177},
        'x4'  : {128: 169, 256: 214, 512: 250, 1024:  378, 2048:  634, 4096: 1146},
        'x8'  : {128: 163, 256: 203, 512: 182, 1024:  246, 2048:  374, 4096:  630},
        'x16' : {128: 144, 256: 168, 512: 182, 1024:  246, 2048:  374, 4096:  630},
        'x32' : {128: 129, 256: 141, 512: 148, 1024:  180, 2048:  244, 4096:  372},
        },
    'gen4' : {
        'x1'  : {128: 333, 256: 512, 512: 655, 1024: 1167, 2048: 2191, 4096: 4239},
        'x2'  : {128: 224, 256: 313, 512: 385, 1024:  641, 2048: 1153, 4096: 2177},
        'x4'  : {128: 169, 256: 214, 512: 250, 1024:  378, 2048:  634, 4096: 1146},
        'x8'  : {128: 163, 256: 203, 512: 182, 1024:  246, 2048:  374, 4096:  630},
        'x16' : {128: 144, 256: 168, 512: 182, 1024:  246, 2048:  374, 4096:  630},
        'x32' : {128: 129, 256: 141, 512: 148, 1024:  180, 2048:  244, 4096:  372},
        },
    'gen5' : {
        'x1'  : {128: 333, 256: 512, 512: 655, 1024: 1167, 2048: 2191, 4096: 4239},
        'x2'  : {128: 224, 256: 313, 512: 385, 1024:  641, 2048: 1153, 4096: 2177},
        'x4'  : {128: 169, 256: 214, 512: 250, 1024:  378, 2048:  634, 4096: 1146},
        'x8'  : {128: 163, 256: 203, 512: 182, 1024:  246, 2048:  374, 4096:  630},
        'x16' : {128: 144, 256: 168, 512: 182, 1024:  246, 2048:  374, 4096:  630},
        'x32' : {128: 129, 256: 141, 512: 148, 1024:  180, 2048:  244, 4096:  372},
        },
    }

# SKIP ordered sets for clock compensation (inserted on all lanes)
SKIP_Interval = 1538
SKIP_Length = 4
# DLLP header (6 bytes) plus start and end symbol at Phys layer
DLLP_Hdr = 8

# Maximum Bandwidth usable at TLP layer. This takes into account the
# recommended rates for ACKs and FC updates as per spec as well as the SKIP
# ordered sets for clock compensation. The Bandwidth can be further reduced
# due to bit errors or different chipset configurations
TLP_bw = {}
for ver in Vers:
    for lanes in Laness:
        for mps in MPSs:
            if not ver in TLP_bw:
                TLP_bw[ver] = {}
            if not lanes in TLP_bw[ver]:
                TLP_bw[ver][lanes] = {}

            ack_overhead = float(Ack_Size) / float(Ack_Limits[ver][lanes][mps])
            fc_overhead = float(FC_Size) / float(FC_Guide[ver][lanes][mps])
            skip_overhead = float(SKIP_Length) / float(SKIP_Interval)
            overheads = ack_overhead + fc_overhead + skip_overhead
            # deduct overheads for ACKs and FC updates
            TLP_bw[ver][lanes][mps] = Raw[ver][lanes] - Raw[ver][lanes] * overheads


# TLP Types
TLP_Hdr = 4         # 4 byte generic TLP header
TLP_MWr_32_Hdr = 8  # Mem Write 4 byte for address + 4 bytes
TLP_MWr_64_Hdr = 12 # Mem Write 8 byte for address + 4 bytes
TLP_MRd_32_Hdr = 8  # Mem Read 4 byte for address + 4 bytes
TLP_MRd_64_Hdr = 12 # Mem Read 8 byte for address + 4 bytes
TLP_Msg = 16        # Message Request Header
TLP_Cpl_Hdr = 8     # Completion no Data 4 bytes completer ID + extra
TLP_CplD_Hdr = 8    # Completion with Data 4 bytes completer ID + extra
TLP_Dig = 4         # Optional digest trailer, 4 bytes, e.g. for ECRC
# There are a few other TLP Types (MRdLk, IORd, IOWr CfgRd0, CfgRd1,
# CfgWr0, CfgWr1, CplLk, CplDLk) which we ignore for now

# Indexed by address size and optional ECRC
TLP_MWr_Hdr_Szs = {
    32: {0: DLLP_Hdr + TLP_Hdr + TLP_MWr_32_Hdr,
         1: DLLP_Hdr + TLP_Hdr + TLP_MWr_32_Hdr + TLP_Dig},
    64: {0: DLLP_Hdr + TLP_Hdr + TLP_MWr_64_Hdr,
         1: DLLP_Hdr + TLP_Hdr + TLP_MWr_64_Hdr + TLP_Dig}
}
TLP_MRd_Hdr_Szs = {
    32: {0: DLLP_Hdr + TLP_Hdr + TLP_MRd_32_Hdr,
         1: DLLP_Hdr + TLP_Hdr + TLP_MRd_32_Hdr + TLP_Dig},
    64: {0: DLLP_Hdr + TLP_Hdr + TLP_MRd_64_Hdr,
         1: DLLP_Hdr + TLP_Hdr + TLP_MRd_64_Hdr + TLP_Dig}
}

TLP_CplD_Hdr_Szs = {
    0: DLLP_Hdr + TLP_Hdr + TLP_CplD_Hdr,
    1: DLLP_Hdr + TLP_Hdr + TLP_CplD_Hdr + TLP_Dig
}

# SIze of a sending a MSI
MSI_SIZE = 4

class Cfg():
    """A glorified struct to represent a specific PCIe device configuration"""

    def __init__(self, version, lanes, addr, ecrc,
                 mps, mrrs, rcb, rcb_chunks=False):
        """Use this class as a struct for the PCI configuration
        @param version: String, 'gen1', 'gen2' 'gen3', 'gen4', 'gen5'
        @param lanes: String, 'x1', 'x2', 'x4, 'x8', 'x16', 'x32'
        @param addr: either 32 or 64. What type of addresses to use
        @param ecrc: either 0 or 1, indicating if ECRC was configured
        @param mps: Maximum Payload Size configured
        @param mrss: Maximum Read Request Size configured
        @param rcb: Read Completion Boundaries
        @param rcb_chunks: Boolean, are read requests chopped into RCB or MPS
        """
        if version not in Vers:
            raise Exception("Unknown PCIe version: %s" % version)
        self.version = version
        if lanes not in Laness:
            raise Exception("Unknown Lane configuration: %s" % lanes)
        self.lanes = lanes
        if addr not in [32, 64]:
            raise Exception("Unknown address lenght: %d" % addr)
        self.addr = addr
        if ecrc not in [0, 1]:
            raise Exception("Unknown ECRC value: %d" % ecrc)
        self.ecrc = ecrc
        if mps not in MPSs:
            raise Exception("Unknown MPS value: %d" % mps)
        self.mps = mps
        if mrrs not in MRRSs:
            raise Exception("Unknown MRRS value: %d" % mps)
        self.mrrs = mrrs
        if rcb not in RCBs:
            raise Exception("Unknown RCB value: %d" % mps)
        self.rcb = rcb
        self.rcb_chunks = rcb_chunks

        # derive Header Sizes for Memory Write, Read and Completion
        self.TLP_MWr_Hdr_Sz = TLP_MWr_Hdr_Szs[addr][ecrc]
        self.TLP_MRd_Hdr_Sz = TLP_MRd_Hdr_Szs[addr][ecrc]
        self.TLP_CplD_Hdr_Sz = TLP_CplD_Hdr_Szs[ecrc]

        self.TLP_bw = TLP_bw[version][lanes][mps]
        self.RAW_bw = Raw[version][lanes]

    def pp(self):
        """Print the configuration"""
        print("PCIe configuration: Version=%s, Lanes=%s" % (self.version, self.lanes))
        print("                    mps=%s, mrrs=%s, rcb=%s, rcb_chunks=%s" % \
              (self.mps, self.mrrs, self.rcb, self.rcb_chunks))
        print("                    addr=%d ecrc=%d" % (self.addr, self.ecrc))
        print("                    => TLP BW=%.2f Gb/s" % (self.TLP_bw))


## Functions to calculate PCIe bandwidth for different PCIe
## configurations and operations.

# Direction of Transfer from the device perspective
DIR_RX = 1
DIR_TX = 2
DIR_BOTH = DIR_RX | DIR_TX

class BW_Spec():
    """
    All functions take a object of this class as a argument. It
    specifies bandwidth for the configuration.  Bandwidth is either
    RAW TLP level bandwidth and the function will work out a effective
    bandwidth which can be achieved with it.  Effective bandwidth is
    the ratio of data bytes versus the bytes actually transmitted
    (data bytes + overhead).

    Or, the bandwidth specification dictates a effective bandwidth to be
    achieved and the model will work out the required raw bandwidth.

    Bandwidth is specified in both direction, RX and TX, from the device
    perspective.

    This is basically a glorified struct.
    """

    BW_RAW = 0
    BW_EFF = 1

    def __init__(self, rx_bw=0.0, tx_bw=0.0, bw_type=0):
        self.rx_bw = rx_bw
        self.tx_bw = tx_bw
        if bw_type not in [self.BW_RAW, self.BW_EFF]:
            raise Exception("Unknown BW type")
        self.type = bw_type
        return

class BW_Res():
    """
    A Bandwidth result object returned by all functions. Contains the
    required Raw TLP bandwidth and the effective bandwidth in each
    direction.  RX and TX are always seen from the PCIe peer
    initiating the transfer.

    Another glorified struct
    """
    def __init__(self, rx_raw, rx_eff, tx_raw, tx_eff):
        self.rx_raw = rx_raw
        self.rx_eff = rx_eff
        self.tx_raw = tx_raw
        self.tx_eff = tx_eff

if __name__ == '__main__':
    # Print out some useful data
    for mps in [128, 256]:
        for ver in Vers:
            print("PCIe Version:", ver)
            print("Lanes Phys BW (Gb/s) Data BW (Gb/s) MPS=%d" % mps)
            for lanes in Laness:
                print("%5s %6.2f %6.2f" % \
                      (lanes, Raw[ver][lanes],
                       TLP_bw[ver][lanes][mps]))
     (lanes, Raw[ver][lanes],
                       TLP_bw[ver][lanes][mps]))
