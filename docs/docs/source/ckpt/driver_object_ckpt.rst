Checkpoint of Driver Abstraction
================================

Checkpoint of Driver Abstraction
--------------------------------

Note that for successfully restoring based on checkpoint image, 
one needs to save not only the state of device memory buffers during checkpoint (:ref:`ckpt_memory`),
but also state of all registered driver abstractions (e.g., `CUModule`, `CUStream`, `CUEvent`, etc. in CUDA).
