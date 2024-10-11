#include <iostream>

#include <stdint.h>
#include <assert.h>
#include <cuda.h>
#include <cuda_runtime_api.h>


// this kernel should be further optimized
__global__ void crc32_kernel(const uint8_t* buffer, size_t size, uint32_t* checksum, const uint32_t* lookup_table) {
    int tid = threadIdx.x + blockIdx.x * blockDim.x;
  
    if (tid < size) {
        uint32_t crc = 0xFFFFFFFF;
    
        for (size_t i = tid; i < size; i += blockDim.x * gridDim.x) {
            crc = (crc >> 8) ^ lookup_table[(crc ^ buffer[i]) & 0xFF];
        }

        atomicXor(checksum, crc ^ 0xFFFFFFFF);
    }
}

void initialize_crc32_lookup_table(uint32_t* lookup_table)
{
    const uint32_t polynomial = 0xEDB88320;
    
    for (int i = 0; i < 256; ++i) {
        uint32_t crc = i;
        
        for (int j = 0; j < 8; ++j) {
            crc = (crc >> 1) ^ ((crc & 1) ? polynomial : 0);
        }
        
        lookup_table[i] = crc;
    }
}

static inline void
checkRtError(cudaError_t res, const char *tok, const char *file, unsigned line)
{
    if (res != cudaSuccess) {
        std::cerr << file << ':' << line << ' ' << tok
                  << "failed (" << (unsigned)res << "): " << cudaGetErrorString(res) << std::endl;
        abort();
    }
}

#define CHECK_RT(x) checkRtError(x, #x, __FILE__, __LINE__);

#define KB(x)   (uint64_t(x)<<10)
#define MB(x)   (uint64_t(x)<<20)
#define GB(x)   (uint64_t(x)<<30)

#define NB_BUFS             65
#define OVERALL_BUF_SIZE    MB(1128)
#define PER_BUF_SIZE        (uint64_t)((double)(OVERALL_BUF_SIZE)/(double)(NB_BUFS))

int main(){
    printf("NB_BUFS: %lu, OVERALL_BUF_SIZE: %lu, PER_BUF_SIZE: %lu\n", NB_BUFS, OVERALL_BUF_SIZE, PER_BUF_SIZE);
    // Initialize the CRC32 lookup table
    uint32_t host_lookup_table[256];
    initialize_crc32_lookup_table(host_lookup_table);
    
    // Create stream for checksum calculation and result copying
    cudaStream_t cal_stream, copy_stream;
    CHECK_RT(cudaStreamCreate(&cal_stream));
    CHECK_RT(cudaStreamCreate(&copy_stream));

    // Allocate and initialize the input buffer
    uint8_t *host_buffers[NB_BUFS] = {0};
    for(int i=0; i<NB_BUFS; i++){
        host_buffers[i] = new uint8_t[PER_BUF_SIZE];
        assert(host_buffers[i] != nullptr);
    }
    
    // Allocate device memory for the buffer and the checksum
    uint8_t *device_buffers[NB_BUFS] = {0};
    for(int i=0; i<NB_BUFS; i++){
        CHECK_RT(cudaMalloc((void**)&(device_buffers[i]), PER_BUF_SIZE));
        CHECK_RT(cudaMemcpy(device_buffers[i], host_buffers[i], PER_BUF_SIZE, cudaMemcpyHostToDevice));
    }

    uint32_t *device_checksums[NB_BUFS] = {0};
    for(int i=0; i<NB_BUFS; i++){
        CHECK_RT(cudaMalloc((void**)&(device_checksums[i]), sizeof(uint32_t)));
        CHECK_RT(cudaMemset(device_checksums[i], 0, sizeof(uint32_t)));
    }

    // Allocate device memory for the lookup table and copy it
    uint32_t* device_lookup_table;
    CHECK_RT(cudaMalloc((void**)&device_lookup_table, sizeof(uint32_t) * 256));
    CHECK_RT(cudaMemcpy(device_lookup_table, host_lookup_table, sizeof(uint32_t) * 256, cudaMemcpyHostToDevice));
    
    // Launch the kernel and copy the checksum result back to the host
    uint32_t host_checksums[NB_BUFS];
    const int block_size = 256;
    const int grid_size = (PER_BUF_SIZE + block_size - 1) / block_size;
    for(int i=0; i<NB_BUFS; i++){
        crc32_kernel<<<grid_size, block_size, 0, cal_stream>>>(device_buffers[i], PER_BUF_SIZE, device_checksums[i], device_lookup_table);
        CHECK_RT(cudaStreamSynchronize(cal_stream));
        CHECK_RT(cudaMemcpyAsync(&(host_checksums[i]), device_checksums[i], sizeof(uint32_t), cudaMemcpyDeviceToHost, copy_stream));
    }
    CHECK_RT(cudaStreamSynchronize(copy_stream));

    // Clean up
    for(int i=0; i<NB_BUFS; i++){
        delete[] host_buffers[i];
        CHECK_RT(cudaFree(device_buffers[i]));
        CHECK_RT(cudaFree(device_checksums[i]));
    }
    CHECK_RT(cudaFree(device_lookup_table));
        
    return 0;
}

