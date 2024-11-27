PhoenixOS Documentation
=========================

Introduction
------------

.. image:: /_static/images/home/pos_logo.png
   :width: 30%
   :align: center
   :alt: PhoenixOS Logo

PhoenixOS is an OS-level GPU C/R system: It can transparently checkpoint or restore processes that use the GPU.


Guidance
---------

For usage of POS, please check the following docs according to your used platform (currently support nVIDIA CUDA only):

.. toctree::
   :maxdepth: 1

   cuda_gsg/index
   rocm_gsg/index


For learning the mechanism of how POS works, please check:

.. toctree::
   :maxdepth: 1

   arch/index
   ckpt/index
   migrate/index
