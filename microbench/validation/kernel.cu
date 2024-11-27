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
#include <vector>
#include <vector_addition.cuh>

/*!
 * \brief [CUDA Kernel] Conduct vector adding (a+b=c)
 * \param vector_a  source vector
 * \param vector_b  source vector
 * \param vector_c  destination vector
 * \param d         dimension of vectors
 */
__global__ void vectorAdd_1(
    const int *__restrict vector_a, 
    const int *__restrict vector_b, 
    int *__restrict vector_c, 
    int d){
  int tid = blockIdx.x * blockDim.x + threadIdx.x;
  if (tid < d){
    vector_c[tid] = vector_a[tid] + vector_b[tid];
  }
}

/*!
 * \brief [CUDA Kernel] Conduct vector adding (a+b=c)
 * \param vector_a  source vector
 * \param vector_b  source vector
 * \param vector_c  destination vector
 * \param d         dimension of vectors
 */
__global__ void vectorAdd_2(
    int *vector_a, 
    int *vector_b, 
    int *vector_c, 
    int d){
  int tid = blockIdx.x * blockDim.x + threadIdx.x;
  if (tid < d){
    vector_c[tid] = vector_a[tid] + vector_b[tid];
  }
}
