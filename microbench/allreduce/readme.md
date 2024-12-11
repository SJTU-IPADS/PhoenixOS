apt-get install libopenmpi-dev mpich

mpic++ -o nccl_allreduce main.cpp -L/usr/local/cuda/lib64 -I/usr/local/cuda/include -lnccl -lcudart -lmpi
mpirun -n 4 --allow-run-as-root ./nccl_allreduce
