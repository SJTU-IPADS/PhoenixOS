

.. _ckpt_memory:
Checkpoint of Device Memory
===========================

**Authors**: `Zhuobin Huang <https://zobinhuang.github.io/>`_, `Xingda Wei <https://ipads.se.sjtu.edu.cn/pub/members/xingda_wei>`_

In this section, 
we introduce the mechanism of how *PhOS* concurrently and efficiently conducts checkpointing of device memories overlapped with kernel execution via **pipelining**.

Before we starts,
we first declare the symbols to be used:

+-------------------------------------------------------------+-----------------------------------------------------------------------------------+
| Notation                                                    | Description                                                                       |
+=============================================================+===================================================================================+
| :math:`K_{\text{x}}`                                        | The :math:`\text{x}^{\text{th}}` launched GPU kernel                              |
+-------------------------------------------------------------+-----------------------------------------------------------------------------------+
| :math:`P_{t_{\text{x}}}`                                    | Pre-copy stage started at time :math:`t_{\text{x}}`                               |
+-------------------------------------------------------------+-----------------------------------------------------------------------------------+
| :math:`\Delta_{t_{\text{x}}}`                               | Delta-copy stage started at time :math:`t_{\text{x}}`                             |
+-------------------------------------------------------------+-----------------------------------------------------------------------------------+
| :math:`\mathbb{M}_{t_{\text{x}}}`                           | State of device memory at time :math:`t_{\text{x}}`                               |
+-------------------------------------------------------------+-----------------------------------------------------------------------------------+
| :math:`\delta(\mathbb{M})|_{t_{\text{x}}}^{t_{\text{x+1}}}` | Dirty device memory produced during time :math:`t_{\text{x}} \sim t_{\text{x+1}}` |
+-------------------------------------------------------------+-----------------------------------------------------------------------------------+
| :math:`\mathbb{I}_{t_{\text{x}}}`                           | Memory checkpoint image saved at :math:`t_{\text{x}}`                             |
+-------------------------------------------------------------+-----------------------------------------------------------------------------------+
| :math:`\mathbb{G}|_{t_{\text{x}}}^{t_{\text{x+1}}}`         | Computation graph during time :math:`t_{\text{x}} \sim t_{\text{x+1}}`            |
+-------------------------------------------------------------+-----------------------------------------------------------------------------------+


.. _ckpt_stages:
Checkpoint Stages
-----------------

.. image:: /ckpt/pic/stages.png
   :width: 90%
   :align: center
   :alt: Checkpoint stages
\

Similar to the concepts in CPU-side checkpoint,
as illustrated in the figure above,
checkpointing GPU memory in *PhOS* could be divided into 2 stages:

- **Pre-copy**:
    Pre-copy stage is overlapped with kernel execution,
    which uses a different GPU stream to conduct device-to-host memory copy
    while executing normal kernel on default work stream.
    With the help of **Copy-on-Write** (CoW) mechanism,
    the pre-copy could correctly save the memory state in :math:`t_1`,
    which is the time to start pre-copy.
    Hence, we can express pre-copy stage started at :math:`t_1` as:

    .. math::
        P_{t_1}: \mathbb{M}_{t_1} \rightarrow \mathbb{I}_{t_1}

- **Delta-copy**:
    During pre-copy stage,
    a memory buffer could be updated after it has already been pre-copied 
    (aka become "dirty memories").
    For the correctness of checkpoint image,
    one should conduct another round of memory copy of these "dirty memories"
    while shutting down the execution of kernels.
    Hence, we can express delta-copy stage started at :math:`t_2` as:

    .. math::
        \Delta_{t_2}: \delta(\mathbb{M})|_{t_{\text{1}}}^{t_{\text{2}}} \rightarrow \mathbb{I}_{t_2}

    A comprehensive checkpoint image to restore memory state at :math:`t_1` should be: :math:`\mathbb{I}_{t_1}`

    On the other hand, an image to restore memory state at :math:`t_2` should be:

    .. math::
        \mathbb{I} = \mathbb{I}_{t_1} + \mathbb{I}_{t_2}

While delta-copy help to patch the pre-copy image :math:`\mathbb{I}_{t_1}` to be comprehensive,
it introduces certain overheads.
In different scenarioes,
*PhOS* adopts different choices to use delta-copy:

* **Fault-tolerance** (C)
    Fault-tolerance is essentially continuous checkpoint, 
    where doesn't require the program to stop after checkpointing. 
    Hence,
    *PhOS* only use pre-copy to checkpoint.

    To run pre-copy, one could simply run the following CLI command to pre-copy the device memory state of process with pid 1234

    .. code-block:: bash

        pos-cli pre-dump -p 1234 -f ./ckpt/v1 --non-stop

* **Migration** (C+R)
    Migration requires the program to be restored as the latest state before migrate,
    hence delta-copy is mandatory under migration.
    However,
    the introduce of delta-copy could cause the high downtime,
    due to high ratio of dirty memories under certain workloads.

    To resolve this problem,
    *PhOS* adopts **re-computation** during restore instead of delta-copy during checkpoint.
    A naive re-computation-based design would be replay all kernels issued during pre-copy stage,
    but still, we found this introduces high downtime due to many kernels need to be re-computed.
    
    Instead, as *PhOS* holds the information of "each kernel read and write on which memories",
    it's easy for *PhOS* to construct a computation graph :math:`\mathbb{G}|_{t_{\text{1}}}^{t_{\text{2}}}` in the form of DAG,
    which contains the dependency information between kernels and memories during pre-copy stage.
    During restore,
    by leveraging on-demand restore based on :math:`\mathbb{I}_{t_1}` and :math:`\mathbb{G}|_{t_{\text{1}}}^{t_{\text{2}}}`,
    with optimization such as pre-fetching,
    *PhOS* reduces the downtime of migration process.

    Note that if the ratio of dirty memories isn't high, *PhOS* still adopts delta-copy to generate the latest image.

* **Startup** (R)
    The startup of container is a pure restore process.
    To accelerate the startup process,
    the image should contains comprehensive memory state (i.e., :math:`\mathbb{M}_{t_1} + \delta(\mathbb{M})|_{t_{\text{1}}}^{t_{\text{2}}}`),
    which is generated after delta-copy statge.

    To generate such a image, one could simply run the following CLI command:

    .. code-block:: bash

        pos-cli dump -p 1234 -f ./ckpt/v2

    To restore a process based on this image, one could simply run the following CLI command:

    .. code-block:: bash

        pos-cli restore -f ./ckpt/v2


Checkpoint Pipeline
-------------------

.. image:: /ckpt/pic/pipeline.png
   :width: 80%
   :align: center
   :alt: Checkpoint Pipeline

.. image:: /ckpt/pic/example.png
   :width: 300px
   :align: center
   :alt: Example Kernel

.. image:: /ckpt/pic/cow_1.png
   :width: 80%
   :align: center
   :alt: Pipeline 1

.. image:: /ckpt/pic/cow_2.png
   :width: 80%
   :align: center
   :alt: Pipeline 2

.. _ckpt_deduplication:
Checkpoint Deduplication
------------------------
