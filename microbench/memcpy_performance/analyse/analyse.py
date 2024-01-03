import matplotlib.pyplot as plt
import seaborn as sns
import pandas as pd

device_name = "V100 (Gen3, x16)"

file_path = "/root/memcpy_performance/profile.txt"
file = open(file_path, 'r')
lines = file.readlines()

# parsing exp result
us_durations:list = list()
byte_sizes:list = list()
gbps_host_bws:list = list()
for line in lines:
    duration, size = [x.strip() for x in line.split(',', 1)]
    us_durations.append(float(duration))
    byte_sizes.append(int(size))
    gbps_host_bws.append(int(size)*8/float(duration)/1000)

# generate pcie result
from pcie_model import pcie, mem_bw
gbps_pcie_theory_bw = list()
pciecfg = pcie.Cfg(version='gen3', lanes='x16', addr=64, ecrc=0, mps=256, mrrs=512, rcb=64)
tlp_bw = pciecfg.TLP_bw
bw_spec = pcie.BW_Spec(tlp_bw, tlp_bw, pcie.BW_Spec.BW_RAW)
for size in byte_sizes:
    rd_bw = mem_bw.read(pciecfg, bw_spec, size)
    gbps_pcie_theory_bw.append(rd_bw.rx_eff)


# draw
plt.figure(figsize=(9, 8), dpi=200)
plt.title(f"CUDA Device to Host Memcpy Performance\n{device_name}")
plt.xlabel("Copy Size / Bytes", fontsize=10)
plt.xticks(size=6)
plt.xticks(rotation=30)
plt.grid(True, linestyle='dashed', alpha=0.5)

fig_dataframe:pd.DataFrame = pd.DataFrame(
    data = {
        'durations': us_durations,
        'sizes': byte_sizes,
        'host_bws': gbps_host_bws,
        'pcie_bws': gbps_pcie_theory_bw
    }
)

byte_sizes_labels = []
for size in byte_sizes:
    if size >= 1000 and size < 1000000:
        byte_sizes_labels.append(f"{size/1000:.2f}K")
    elif size >= 1000000:
        byte_sizes_labels.append(f"{size / 1000000:.2f}M")
    else:
        byte_sizes_labels.append(f"{size}")

# plot 1: bandwidth
ax1 = sns.lineplot(data=fig_dataframe, x='sizes', y='host_bws', marker='o', color = 'r', label='CUDA Bandwidth')
ax1.set_ylabel("Copy Throughput / Gbps")
ax1.set(xscale='log')
ax1.set(xticks=byte_sizes)
ax1.set(xticklabels=byte_sizes_labels)
ax1.legend().set_visible(False)

# plot 2: latency
ax2 = ax1.twinx()
sns.barplot(data=fig_dataframe, x='sizes', y='durations', ax=ax2, native_scale=True)
ax2.set_ylabel("Latency / us")
for i, duration in enumerate(us_durations):
    ax2.text(byte_sizes[i], duration+10, f"{duration:.1f}", ha='center', size=6, rotation=0, color="blue")

# put ax2 under ax1
ax2.set_zorder(ax1.get_zorder() - 1)
ax1.patch.set_visible(False)

# plot 3: pcie
ax3 = ax1.twiny()
sns.lineplot(data=fig_dataframe, x='sizes', y='pcie_bws', marker='o', color = 'g', ax=ax3, label='PCIe Bandwidth Bound')
ax3.set(xscale='log')


lines = ax1.get_lines() + ax3.get_lines()
labels = [line.get_label() for line in lines]
ax3.legend(lines, labels, loc='upper left')

plt.savefig("/root/memcpy_performance/profile.png")
