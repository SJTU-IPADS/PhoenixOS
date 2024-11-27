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

#ifndef _BUFFER_MANAGER_H_
#define _BUFFER_MANAGER_H_

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <cassert>
#include <thread>
#include <chrono>
#include <mutex>
#include <cstdint>

#include <stdio.h>
#include <dirent.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <cuda.h>
#include <cuda_runtime.h>

#include "segfault_catch/segvcatch.h"

#include "cudam.h"
#include "utils.h"
#include "log.h"

enum {
  CUDA_MEMORY_API_cudaArrayGetInfo = 0,
  CUDA_MEMORY_API_cudaArrayGetMemoryRequirements,
  CUDA_MEMORY_API_cudaArrayGetPlane,
  CUDA_MEMORY_API_cudaArrayGetSparseProperties,
  CUDA_MEMORY_API_cudaFree,
  CUDA_MEMORY_API_cudaFreeArray,
  CUDA_MEMORY_API_cudaFreeHost,
  CUDA_MEMORY_API_cudaFreeMipmappedArray,
  CUDA_MEMORY_API_cudaGetMipmappedArrayLevel,
  CUDA_MEMORY_API_cudaGetSymbolAddress,
  CUDA_MEMORY_API_cudaGetSymbolSize,
  CUDA_MEMORY_API_cudaHostAlloc,
  CUDA_MEMORY_API_cudaHostGetDevicePointer,
  CUDA_MEMORY_API_cudaHostGetFlags,
  CUDA_MEMORY_API_cudaHostRegister,
  CUDA_MEMORY_API_cudaHostUnregister,
  CUDA_MEMORY_API_cudaMalloc,
  CUDA_MEMORY_API_cudaMalloc3D,
  CUDA_MEMORY_API_cudaMalloc3DArray,
  CUDA_MEMORY_API_cudaMallocArray,
  CUDA_MEMORY_API_cudaMallocHost,
  CUDA_MEMORY_API_cudaMallocManaged,
  CUDA_MEMORY_API_cudaMallocMipmappedArray,
  CUDA_MEMORY_API_cudaMallocPitch,
  CUDA_MEMORY_API_cudaMemAdvise,
  CUDA_MEMORY_API_cudaMemGetInfo,
  CUDA_MEMORY_API_cudaMemPrefetchAsync,
  CUDA_MEMORY_API_cudaMemRangeGetAttribute,
  CUDA_MEMORY_API_cudaMemRangeGetAttributes,
  CUDA_MEMORY_API_cudaMemcpy,
  CUDA_MEMORY_API_cudaMemcpy2D,
  CUDA_MEMORY_API_cudaMemcpy2DArrayToArray,
  CUDA_MEMORY_API_cudaMemcpy2DAsync,
  CUDA_MEMORY_API_cudaMemcpy2DFromArray,
  CUDA_MEMORY_API_cudaMemcpy2DFromArrayAsync,
  CUDA_MEMORY_API_cudaMemcpy2DToArray,
  CUDA_MEMORY_API_cudaMemcpy2DToArrayAsync,
  CUDA_MEMORY_API_cudaMemcpy3D,
  CUDA_MEMORY_API_cudaMemcpy3DAsync,
  CUDA_MEMORY_API_cudaMemcpy3DPeer,
  CUDA_MEMORY_API_cudaMemcpy3DPeerAsync ,
  CUDA_MEMORY_API_cudaMemcpyAsync,
  CUDA_MEMORY_API_cudaMemcpyFromSymbol,
  CUDA_MEMORY_API_cudaMemcpyFromSymbolAsync,
  CUDA_MEMORY_API_cudaMemcpyPeer ,
  CUDA_MEMORY_API_cudaMemcpyPeerAsync,
  CUDA_MEMORY_API_cudaMemcpyToSymbol,
  CUDA_MEMORY_API_cudaMemcpyToSymbolAsync,
  CUDA_MEMORY_API_cudaMemset,
  CUDA_MEMORY_API_cudaMemset2D,
  CUDA_MEMORY_API_cudaMemset2DAsync,
  CUDA_MEMORY_API_cudaMemset3D,
  CUDA_MEMORY_API_cudaMemset3DAsync,
  CUDA_MEMORY_API_cudaMemsetAsync,
  CUDA_MEMORY_API_cudaMipmappedArrayGetMemoryRequirements,
  CUDA_MEMORY_API_cudaMipmappedArrayGetSparseProperties,
  CUDA_MEMORY_API_make_cudaExtent,
  CUDA_MEMORY_API_make_cudaPitchedPtr,
  CUDA_MEMORY_API_make_cudaPos,
  CUDA_MEMORY_API_TOTAL_NUM,
};

enum {
  BUFFER_DEVICE_ID_CPU = -1,
  BUFFER_DEVICE_ID_UNIFIED = -2,
  BUFFER_DEVICE_ID_UNKOWN = -3,
  /* BUFFER_DEVICE_ID_GPU starts from 0 */
};

#define CUDAM_BM_CHECKPOINT_PATH "./cudam_buffer_checkpoint"

class Buffer;

/* buffer relationship */
class BufferRelation {
  public:
    BufferRelation(){};
    BufferRelation(Buffer *peer_buffer, const void *peer_base_addr, const void *local_base_addr, uint64_t size)
      :_peer_buffer(peer_buffer), _peer_base_addr(peer_base_addr), 
      _local_base_addr(local_base_addr), _size(size){}

    /* getters */
    inline Buffer* getPeerBuffer(){ return _peer_buffer; }
    inline const void* getPeerBaseAddr(){ return _peer_base_addr; }
    inline const void* getLocalBaseAddr(){ return _local_base_addr; }
    inline uint64_t getPeerSize(){ return _size; }

    /* setters */
    inline void setPeerBuffer(Buffer* peer_buffer){ _peer_buffer=peer_buffer; }
    inline void setPeerBaseAddr(const void* peer_base_addr){ 
      _peer_base_addr=peer_base_addr;
    }
    inline void setLocalBaseAddr(Buffer* local_base_addr){ 
      _local_base_addr=local_base_addr;
    }
    inline void setPeerSize(uint64_t size){ _size=size; }

  private:
    /* the peer buffer */
    Buffer *_peer_buffer;

    /* base address on the peer buffer of this relationship */
    const void *_peer_base_addr;

    /* base address on the local buffer of this relationship */
    const void *_local_base_addr;

    /* number of the mapping bytes of this relationship */
    uint64_t _size;
};

/* buffer base class */
class Buffer {
  public:
    Buffer(){};

    Buffer(void **ptr, const void *addr, uint64_t size, int16_t device_id, bool is_page_locked, bool is_unified):
        _ptr(ptr), _addr(addr), _size(size), 
        _device_id(device_id), _has_freed(false),
        _is_page_locked(is_page_locked), _is_unified(is_unified)
    {
      /* we cast the pointer value to unsigned long here, for further de/serilization */
      _ptr_int = reinterpret_cast<std::uintptr_t>(_ptr);
      _addr_int = reinterpret_cast<std::uintptr_t>(_addr);
    }

    Buffer(std::uintptr_t ptr_int, std::uintptr_t addr_int, uint64_t size, int16_t device_id, bool is_page_locked, bool has_free, bool is_unified):
        _ptr_int(ptr_int), _addr_int(addr_int), _size(size),
        _device_id(device_id), _has_freed(has_free),
        _is_page_locked(is_page_locked), _is_unified(is_unified){}

    /* getters */
    inline void** getPtr() { return _ptr; }
    inline const void* getAddr() { return _addr; }
    inline uint64_t getSize() { return _size; }
    inline int16_t getDeviceId() { return _device_id; }
    inline bool isPageLocked() { return _is_page_locked; }
    inline bool isUnified() { return _is_unified; }
    inline bool hasFreed() { return _has_freed; }
    inline std::vector<BufferRelation*> getAllRelations(bool isIn){
      return isIn ? _in_relations : _out_relations;
    }

    /* setters */
    inline void setFreed(){ _has_freed = true; }

    /* judge whether two buffers are equal */
    bool operator==(const Buffer& b){
      return _ptr == b._ptr && _addr == b._addr && _size == b._size;
    }

    /* judge whether the given address is within this buffer */
    inline bool isInRange(const void *addr, bool isExclusive){
      return isExclusive 
            ? (addr > _addr && addr < ((uint8_t*)_addr+_size))
            : (addr >= _addr && addr <= ((uint8_t*)_addr+_size));
    }

    inline bool isInRange(const void *addr, uint64_t size, bool isExclusive){
      return isExclusive
            ? ( addr > _addr && ((uint8_t*)addr+size < (uint8_t*)_addr+_size) )
            : ( addr >= _addr && ((uint8_t*)addr+size <= (uint8_t*)_addr+_size) );
    }

    /* obtain the checksum of the buffer */
    uint8_t getChecksum(const void *base, uint64_t size, uint32_t *checksum);

    /* add buffer relation */
    uint8_t addRelation(Buffer *peer_buffer, const void *peer_base_addr, const void *local_base_addr, uint64_t size, bool isIn);
    uint8_t addRelation(BufferRelation *relation, bool isIn);

    /* get buffer relation by peer base address */
    BufferRelation* getRelation(const void *peer_base_addr, const void *local_base_addr, uint64_t peer_size, bool isIn);

  private:
    /* pointer to the buffer */
    void **_ptr;
    std::uintptr_t _ptr_int;

    /* base address of the buffer */
    const void *_addr;
    std::uintptr_t _addr_int;

    /* size of the buffer */
    uint64_t _size;

    /* 
     * position of the buffer (CPU/GPU)
     * could be BUFFER_DEVICE_ID_CPU (-1), BUFFER_DEVICE_ID_UNIFIED(-2) or device id starts from 0
     */
    int16_t _device_id;

    /* indicator of whether this buffer is page-locked host buffer */
    bool _is_page_locked;

    /* indicator of whether this buffer is unified memory-managed buffer */
    bool _is_unified;

    /* indicator of whether this buffer has been freed */
    bool _has_freed;

    /* two-way buffer edge */
    std::vector<BufferRelation*> _in_relations;
    std::vector<BufferRelation*> _out_relations;
};

static void handle_SIGSEGV(){
    throw std::runtime_error("My SEGV");
}

/* buffer manager */
class BufferManager {
  public:
    BufferManager(){}

    BufferManager(uint8_t do_hijack):_selected_gpu_device_id(0){
      // initialize api invoking times
      uint64_t i=0, current_time;
      char checkpoint_file_path[512] = {0};

      for(i=0; i<CUDA_MEMORY_API_TOTAL_NUM; i++){
        _api_invoking_times_map[i] = 0;
      }

      segvcatch::init_segv(&handle_SIGSEGV);

      if(do_hijack){
        // create folder to store checkpoint data (if not exist)
        if(NULL == opendir(CUDAM_BM_CHECKPOINT_PATH)){
          if (-1 == mkdir(CUDAM_BM_CHECKPOINT_PATH, 0777)) {
            CUDAM_ERROR(
              "failed to create checkpoint folder for buffer manager at %s",
              CUDAM_BM_CHECKPOINT_PATH
            )
            abort();
          }
        }

        // delete all previous checkpoint files
        utils_delete_all_files_under_folder(CUDAM_BM_CHECKPOINT_PATH);

        // create and open checkpoint file
        current_time = utils_timestamp_ns();
        sprintf(checkpoint_file_path, "%s/%lu", CUDAM_BM_CHECKPOINT_PATH, current_time);
        _checkpoint_file_fd = fopen(checkpoint_file_path, "w+");
        assert(_checkpoint_file_fd != NULL);

        // set the termination flag of profiling thread as false
        _terminated = false;

        // create profiling thread
        _profiling_thread = new std::thread(&BufferManager::profiling_thread_func, this);
      }
    }

    ~BufferManager(){
      // setup the termination flag
      _terminated = true;

      // wait the profiling thread to terminate
      _profiling_thread->join();
      
      // close the checkpoint file stream
      fclose(_checkpoint_file_fd);
      // _checkpoint_file_ofs->close();
    }

    /* record api invoking times */
    inline void recordApiInvoke(uint64_t api_index){
      assert(api_index < CUDA_MEMORY_API_TOTAL_NUM);
      _api_invoking_times_map[api_index] += 1;
    }

    /* record new buffer in the manager */
    uint8_t recordBuffer(void **ptr, const void *addr, uint64_t size, int16_t device_id, bool is_page_locked, bool is_unified);

    /* mark the buffer as freed */
    uint8_t markBufferFreed(void *addr);

    /* obtain the one-and-only buffer that include the given address */
    Buffer* getBufferByAddr(const void *addr, int16_t device_id);

    /* obtain buffers that partially locate within the given range */
    std::vector<Buffer*> getPartialBuffersByRange(const void *base_addr, uint64_t size, bool isExclusive, int16_t device_id);

    /* obtain buffers that totally locate within the given range */
    std::vector<Buffer*> getFullBuffersByRange(const void *base_addr, uint64_t size, bool isExclusive, int16_t device_id);

    /* printf all buffer for debug */
    void printAllBuffers();

    /* getters */
    inline uint16_t getSelectedGpuDeviceId(){ return _selected_gpu_device_id; }
    inline std::mutex& getProfilingMtx(){ return _profiling_mtx; }

    /* setters */
    inline void setSelectedGpuDeviceId(uint16_t id){ _selected_gpu_device_id = id; }
    inline void lockProfilingMtx(){ _profiling_mtx.lock(); }
    inline void unlockProfilingMtx(){ _profiling_mtx.unlock(); }

  private:
    /* signal handler of cudam buffer manager */
    bool _terminated;
    void _signal_handler(int signum) {
        _terminated = true;
    }

    /* currently selected device Id */
    uint16_t _selected_gpu_device_id;

    /* recorded buffers */
    std::vector<Buffer*> _buffers;

    /* api invoke times */
    std::map<uint64_t, uint64_t> _api_invoking_times_map;

    /* indicator of whether the profiling thread is working */
    std::mutex _profiling_mtx;

    /* last profiling timestap */
    void _profiling_routine();

    /* profiling thread handler */
    std::thread *_profiling_thread;

    /* profiling thread */
    void profiling_thread_func();

    /* checkpoint file stream */
    FILE *_checkpoint_file_fd;
};

/* convert buffer position to string for debugging printing */
static const char* convertBufferPosToString(int16_t device_id, bool is_paged_lock, bool is_unified){
  if(is_unified){ return "unified"; }
  
  switch (device_id)
  {
  case BUFFER_DEVICE_ID_CPU:
    if(is_paged_lock){ 
      return "page-locked cpu"; 
    } else {
      return "cpu";
    }

  case BUFFER_DEVICE_ID_UNIFIED:
    return "unified";

  default:
    return "gpu";
  }
}

static const char* convertBufferPosToString(Buffer &buffer){
  return convertBufferPosToString(buffer.getDeviceId(), buffer.isPageLocked(), buffer.isUnified());
}

extern BufferManager bufferManager;

#define START_MEMORY_PROFILING(api_name, api_index, is_intercepted)       \
{                                                                         \
    bufferManager.recordApiInvoke(api_index);                             \
    std::lock_guard<std::mutex> lk(bufferManager.getProfilingMtx());      \
    if(!is_intercepted){                                                  \
      CUDAM_WARNING_MESSAGE("called %s without intercepted", api_name);   \
    }                                                                     \
}

#endif