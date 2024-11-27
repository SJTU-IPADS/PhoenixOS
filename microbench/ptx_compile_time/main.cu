/*
 * Copyright 2024 The PhoenixOS Authors. All rights reserved.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <iostream>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define CUDA_SAFECALL(call)                                                 \
    {                                                                       \
        call;                                                               \
        cudaError err = cudaGetLastError();                                 \
        if (cudaSuccess != err) {                                           \
            fprintf(                                                        \
                stderr,                                                     \
                "Cuda error in function '%s' file '%s' in line %i : %s.\n", \
                #call, __FILE__, __LINE__, cudaGetErrorString(err));        \
            fflush(stderr);                                                 \
            exit(EXIT_FAILURE);                                             \
        }                                                                   \
    }


// CUDA kernel. Each thread takes care of one element of c
__global__ void vecSec(double *a, double *b, double *c, int n) {
    // Get our global thread ID
    int id = blockIdx.x * blockDim.x + threadIdx.x;

    // Make sure we do not go out of bounds
    if (id < n) c[id] = a[id] + b[id];
    if (id > n) c[id] = b[id] + a[id-1];
}

int main(int argc, char *argv[]) {
    // Size of vectors
    int n = 100000;
    if (argc > 1) n = atoi(argv[1]);

    // Host input vectors
    double *h_a;
    double *h_b;
    // Host output vector
    double *h_c;

    // Device input vectors
    double *d_a;
    double *d_b;
    // Device output vector
    double *d_c;

    // Size, in bytes, of each vector
    size_t bytes = n * sizeof(double);

    // Allocate memory for each vector on host
    h_a = (double *)malloc(bytes);
    h_b = (double *)malloc(bytes);
    h_c = (double *)malloc(bytes);

    // Allocate memory for each vector on GPU
    cudaMalloc(&d_a, bytes);
    cudaMalloc(&d_b, bytes);
    cudaMalloc(&d_c, bytes);

    int i;
    // Initialize vectors on host
    for (i = 0; i < n; i++) {
        h_a[i] = sin(i) * sin(i);
        h_b[i] = cos(i) * cos(i);
        h_c[i] = 0;
    }

    // Copy host vectors to device
    cudaMemcpy(d_a, h_a, bytes, cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, h_b, bytes, cudaMemcpyHostToDevice);
    cudaMemcpy(d_c, h_c, bytes, cudaMemcpyHostToDevice);

    int blockSize, gridSize;

    // Number of threads in each thread block
    blockSize = 1024;

    // Number of thread blocks in grid
    gridSize = (int)ceil((float)n / blockSize);

    // Execute the kernel
    CUDA_SAFECALL((vecSec<<<gridSize, blockSize>>>(d_a, d_b, d_c, n)));
    cudaMemcpy(h_c, d_c, bytes, cudaMemcpyDeviceToHost);

    // Execute the kernel
    CUDA_SAFECALL((vecSec<<<gridSize, blockSize>>>(d_a, d_b, d_c, n)));
    cudaMemcpy(h_c, d_c, bytes, cudaMemcpyDeviceToHost);

    // Execute the kernel
    CUDA_SAFECALL((vecSec<<<gridSize, blockSize>>>(d_a, d_b, d_c, n)));
    cudaMemcpy(h_c, d_c, bytes, cudaMemcpyDeviceToHost);

    // Execute the kernel
    CUDA_SAFECALL((vecSec<<<gridSize, blockSize>>>(d_a, d_b, d_c, n)));
    cudaMemcpy(h_c, d_c, bytes, cudaMemcpyDeviceToHost);

    // Execute the kernel
    CUDA_SAFECALL((vecSec<<<gridSize, blockSize>>>(d_a, d_b, d_c, n)));
    cudaMemcpy(h_c, d_c, bytes, cudaMemcpyDeviceToHost);

    // Sum up vector c and print result divided by n, this should equal 1 within
    // error
    double sum = 0;
    for (i = 0; i < n; i++) sum += h_c[i];
    printf("Final sum = %f; sum/n = %f (should be ~1)\n", sum, sum / n);

    // Release device memory
    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);

    // Release host memory
    free(h_a);
    free(h_b);
    free(h_c);

    return 0;
}
