CUDA_VISIBLE_DEVICES='0' LD_DEBUG=libs $@ 2>&1 | grep -Ei 'cuda.+calling|calling.+cuda'
