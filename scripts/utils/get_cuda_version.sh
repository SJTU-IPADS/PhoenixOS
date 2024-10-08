#!/bin/bash

nvcc --version | grep -oP 'Cuda compilation tools, release \K[0-9]+\.[0-9]+'
