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
#include <map>

#include <cuda.h>
#include <cuda_runtime_api.h>

#include "pos/include/common.h"
#include "pos/include/log.h"
#include "pos/include/log.h"
#include "pos/cuda_impl/handle.h"
#include "pos/cuda_impl/handle/memory.h"
#include "pos/cuda_impl/proto/memory.pb.h"


std::map<int, CUdeviceptr>  POSHandleManager_CUDA_Memory::alloc_ptrs;
std::map<int, uint64_t>     POSHandleManager_CUDA_Memory::alloc_granularities;
bool                        POSHandleManager_CUDA_Memory::has_finshed_reserved;
const uint64_t              POSHandleManager_CUDA_Memory::reserved_vm_base = 0x7facd0000000;


POSHandle_CUDA_Memory::POSHandle_CUDA_Memory(size_t size_, void* hm, pos_u64id_t id_, size_t state_size_)
    : POSHandle_CUDA(size_, hm, id_, state_size_)
{
    this->resource_type_id = kPOS_ResourceTypeId_CUDA_Memory;

#if POS_CONF_EVAL_CkptOptLevel > 0 || POS_CONF_EVAL_MigrOptLevel > 0
    // initialize checkpoint bag
    if(unlikely(POS_SUCCESS != this->__init_ckpt_bag())){
        POS_ERROR_C_DETAIL("failed to inilialize checkpoint bag");
    }
#endif
}


POSHandle_CUDA_Memory::POSHandle_CUDA_Memory(void* hm) : POSHandle_CUDA(hm)
{
    this->resource_type_id = kPOS_ResourceTypeId_CUDA_Memory;
}


POSHandle_CUDA_Memory::POSHandle_CUDA_Memory(void *client_addr_, size_t size_, void* hm, pos_u64id_t id_, size_t state_size_)
    : POSHandle_CUDA(client_addr_, size_, hm, id_, state_size_)
{
    POS_ERROR_C_DETAIL("shouldn't be called");
}


pos_retval_t POSHandle_CUDA_Memory::tear_down(){
    pos_retval_t retval = POS_SUCCESS;
    CUresult dv_retval;
    bool ctx_switched = false; // moved before any goto
    CUcontext old_ctx = nullptr; // moved before any goto
    POSHandle* ctx_handle = nullptr; // moved before any goto
    
    if(unlikely(this->status != kPOS_HandleStatus_Active)){ goto exit; }

    // 显式上下文切换到父 Context（守护进程 Primary Context）
    if (this->parent_handles.size() > 0) {
        ctx_handle = this->parent_handles[0];
        CUresult ctx_err = cuCtxPushCurrent((CUcontext)ctx_handle->server_addr);
        if (ctx_err == CUDA_SUCCESS) {
            ctx_switched = true;
        } else {
            POS_WARN_DETAIL("tear_down: failed to push context, id(%lu), err(%d)", this->id, ctx_err);
            // 尝试继续释放（在当前上下文），以避免资源泄露
        }
    } else {
        POS_WARN_DETAIL("tear_down: no parent context handle found for id(%lu)", this->id);
        // 尝试继续释放（在当前上下文），以避免资源泄露
    }

    // UVM 释放
    dv_retval = cuMemFree((CUdeviceptr)(uintptr_t)this->server_addr);
    if(unlikely(CUDA_SUCCESS != dv_retval)){
        POS_WARN_DETAIL(
            "tear_down: cuMemFree failed: id(%lu), ptr(%p), retval(%d)",
            this->id, this->server_addr, dv_retval
        );
        retval = POS_FAILED;
    }

    // 恢复上下文
    if (ctx_switched) {
        cuCtxPopCurrent(&old_ctx);
    }

exit:
    return retval;
}


pos_retval_t POSHandle_CUDA_Memory::__init_ckpt_bag(){ 
    this->ckpt_bag = new POSCheckpointBag(
        this->state_size,
        this->__checkpoint_allocator,
        this->__checkpoint_deallocator,
        this->__checkpoint_dev_allocator,
        this->__checkpoint_dev_deallocator
    );
    POS_CHECK_POINTER(this->ckpt_bag);
    return POS_SUCCESS;
}


pos_retval_t POSHandle_CUDA_Memory::__add(uint64_t version_id, uint64_t stream_id){
    pos_retval_t retval = POS_SUCCESS;
    cudaError_t cuda_rt_retval;
    POSCheckpointSlot* ckpt_slot;

    // apply new on-device checkpoint slot
    if(unlikely(POS_SUCCESS != (
        this->ckpt_bag->template apply_checkpoint_slot<kPOS_CkptSlotPosition_Device, kPOS_CkptStateType_Device>(
            /* version */ version_id,
            /* ptr */ &ckpt_slot,
            /* dynamic_state_size */ 0,
            /* force_overwrite */ true
        )
    ))){
        POS_WARN_C("failed to apply checkpoint slot");
        retval = POS_FAILED;
        goto exit;
    }

    cuda_rt_retval = cudaMemcpyAsync(
        /* dst */ ckpt_slot->expose_pointer(), 
        /* src */ this->server_addr,
        /* size */ this->state_size,
        /* kind */ cudaMemcpyDeviceToDevice,
        /* stream */ (cudaStream_t)(stream_id)
    );
    if(unlikely(cuda_rt_retval != cudaSuccess)){
        POS_WARN_C(
            "failed to checkpoint memory handle on device: server_addr(%p), retval(%d)",
            this->server_addr, cuda_rt_retval
        );
        retval = POS_FAILED;
        goto exit;
    }

    cuda_rt_retval = cudaStreamSynchronize((cudaStream_t)(stream_id));
    if(unlikely(cuda_rt_retval != cudaSuccess)){
        POS_WARN_C(
            "failed to synchronize after checkpointing memory handle on device: server_addr(%p), retval(%d)",
            this->server_addr, cuda_rt_retval
        );
        retval = POS_FAILED;
        goto exit;
    }

exit:
    return retval;
}


pos_retval_t POSHandle_CUDA_Memory::__commit(uint64_t version_id, uint64_t stream_id, bool from_cache, bool is_sync){ 
    pos_retval_t retval = POS_SUCCESS;
    cudaError_t cuda_rt_retval;
    POSCheckpointSlot *ckpt_slot, *cow_ckpt_slot;
    
    // TODO: [zhuobin] why we have this call??
    cudaSetDevice(0);

    // apply new host-side checkpoint slot for device-side state
    if(unlikely(POS_SUCCESS != (
        this->ckpt_bag->template apply_checkpoint_slot<kPOS_CkptSlotPosition_Host, kPOS_CkptStateType_Device>(
            /* version */ version_id,
            /* ptr */ &ckpt_slot,
            /* dynamic_state_size */ 0,
            /* force_overwrite */ true
        )
    ))){
        POS_WARN_C("failed to apply host-side checkpoint slot");
        retval = POS_FAILED;
        goto exit;
    }

    POS_CHECK_POINTER(ckpt_slot);

    if(from_cache == false){
        // commit from origin buffer
        cuda_rt_retval = cudaMemcpyAsync(
            /* dst */ ckpt_slot->expose_pointer(), 
            /* src */ this->server_addr,
            /* size */ this->state_size,
            /* kind */ cudaMemcpyDeviceToHost,
            /* stream */ (cudaStream_t)(stream_id)
        );
        if(unlikely(cuda_rt_retval != cudaSuccess)){
            POS_WARN_C(
                "failed to checkpoint memory handle from origin buffer: server_addr(%p), retval(%d)",
                this->server_addr, cuda_rt_retval
            );
            retval = POS_FAILED;
            goto exit;
        }
    } else {
        // commit from cache buffer
        if(unlikely(POS_SUCCESS != (
            this->ckpt_bag->template get_checkpoint_slot<kPOS_CkptSlotPosition_Device, kPOS_CkptStateType_Device>(
                /* ptr */ &cow_ckpt_slot,
                /* version */ version_id
            )
        ))){
            POS_ERROR_C_DETAIL(
                "no cache buffer with the version founded, this is a bug: version_id(%lu), server_addr(%p)",
                version_id, this->server_addr
            );
        }
        cuda_rt_retval = cudaMemcpyAsync(
            /* dst */ ckpt_slot->expose_pointer(), 
            /* src */ cow_ckpt_slot->expose_pointer(),
            /* size */ this->state_size,
            /* kind */ cudaMemcpyDeviceToHost,
            /* stream */ (cudaStream_t)(stream_id)
        );
        if(unlikely(cuda_rt_retval != cudaSuccess)){
            POS_WARN_C(
                "failed to checkpoint memory handle from COW buffer: server_addr(%p), retval(%d)",
                this->server_addr, cuda_rt_retval
            );
            retval = POS_FAILED;
            goto exit;
        }
    }

    if(is_sync){
        cuda_rt_retval = cudaStreamSynchronize((cudaStream_t)(stream_id));
        if(unlikely(cuda_rt_retval != cudaSuccess)){
            POS_WARN_C(
                "failed to synchronize after commiting memory handle: server_addr(%p), retval(%d)",
                this->server_addr, cuda_rt_retval
            );
            retval = POS_FAILED;
            goto exit;
        }
    }

exit:
    return retval;
}


pos_retval_t POSHandle_CUDA_Memory::__get_checkpoint_slot_for_persist(POSCheckpointSlot** ckpt_slot, uint64_t version_id){
    pos_retval_t retval = POS_SUCCESS;

    POS_CHECK_POINTER(ckpt_slot);

    if(unlikely(POS_SUCCESS != (
        retval = this->ckpt_bag->template get_checkpoint_slot<kPOS_CkptSlotPosition_Host, kPOS_CkptStateType_Device>(
            /* ckpt_slot */ ckpt_slot,
            /* version */ version_id
        )
    ))){
        POS_WARN_C("failed to obtain checkpoint slot for persist: version_id(%lu), retval(%d)", version_id, retval);
        goto exit;
    }

exit:
    return retval;
}



pos_retval_t POSHandle_CUDA_Memory::__generate_protobuf_binary(google::protobuf::Message** binary, google::protobuf::Message** base_binary){
    pos_retval_t retval = POS_SUCCESS;
    pos_protobuf::Bin_POSHandle_CUDA_Memory *cuda_memory_binary;

    POS_CHECK_POINTER(binary);
    POS_CHECK_POINTER(base_binary);

    cuda_memory_binary = new pos_protobuf::Bin_POSHandle_CUDA_Memory();
    POS_CHECK_POINTER(cuda_memory_binary);

    *binary = reinterpret_cast<google::protobuf::Message*>(cuda_memory_binary);
    POS_CHECK_POINTER(*binary);
    *base_binary = cuda_memory_binary->mutable_base();
    POS_CHECK_POINTER(*base_binary);

    // serialize handle specific fields
    /* currently nothing */

    return retval;
}


pos_retval_t POSHandle_CUDA_Memory::__restore(){
    pos_retval_t retval = POS_SUCCESS;
    CUresult dv_retval;
    CUcontext phos_daemon_ctx = nullptr;
    CUcontext old_ctx = nullptr;
    POSHandle* ctx_handle = nullptr;
    CUdeviceptr d_ptr = 0;
    CUdevice cu_device = 0;

    // [1] 获取父 Context
    if (this->parent_handles.size() > 0) {
        ctx_handle = this->parent_handles[0];
        phos_daemon_ctx = (CUcontext)ctx_handle->server_addr;
    } else {
        POS_WARN_DETAIL("Memory restore failed: missing parent context");
        retval = POS_FAILED_INVALID_INPUT;
        goto exit;
    }

    // [2] 切换上下文
    if (unlikely(CUDA_SUCCESS != cuCtxPushCurrent(phos_daemon_ctx))) {
        POS_WARN_DETAIL("Memory restore failed: push context error");
        retval = POS_FAILED_DRIVER;
        goto exit;
    }

    // [3] 强制 UVM 分配 (无视旧 server_addr)
    dv_retval = cuMemAllocManaged(&d_ptr, this->state_size, CU_MEM_ATTACH_GLOBAL);
    if (unlikely(CUDA_SUCCESS != dv_retval)) {
        POS_WARN_DETAIL("Memory restore failed: cuMemAllocManaged error %d", dv_retval);
        cuCtxPopCurrent(&old_ctx);
        retval = POS_FAILED_DRIVER;
        goto exit;
    }

    // [3.1] 立即预取到 GPU，避免后续 Kernel 首次访问触发 UVM 缺页
    dv_retval = cuCtxGetDevice(&cu_device);
    if (unlikely(CUDA_SUCCESS != dv_retval)) {
        POS_WARN_DETAIL("Memory restore warning: cuCtxGetDevice failed %d, skip prefetch", dv_retval);
    } else {
        dv_retval = cuMemPrefetchAsync(d_ptr, this->state_size, cu_device, /*stream*/0);
        if (unlikely(CUDA_SUCCESS != dv_retval)) {
            POS_WARN_DETAIL("Memory restore warning: cuMemPrefetchAsync failed %d", dv_retval);
        }
    }

    // [4] 更新映射 (保留 client_addr, 更新 server_addr)
    this->server_addr = (void*)(uintptr_t)d_ptr;
    {
        // 影子页表记录：Key=旧 client_addr, Value=更新过 server_addr 的当前对象
        auto* hm_cast = (POSHandleManager<POSHandle_CUDA_Memory>*)(this->_hm);
        POS_CHECK_POINTER(hm_cast);
        (void)hm_cast->record_handle_address(this->client_addr, this);
    }

    // [5] 恢复上下文
    cuCtxPopCurrent(&old_ctx);

    // [6] 句柄状态设为 Active（数据填充在 __reload_state 中执行，目标地址为新的 server_addr）
    this->mark_status(kPOS_HandleStatus_Active);

exit:
    return retval;
}



pos_retval_t POSHandle_CUDA_Memory::__reload_state(void* mapped, uint64_t ckpt_file_size, uint64_t stream_id){
    pos_retval_t retval = POS_SUCCESS;
    pos_protobuf::Bin_POSHandle_CUDA_Memory memory_binary;
    cudaError_t cuda_rt_retval;

    POS_CHECK_POINTER(mapped);

    if(!memory_binary.ParseFromArray(mapped, ckpt_file_size)){
        POS_WARN_C("failed to restore handle state, failed to deserialize from mmap area");
        retval = POS_FAILED;
        goto exit;
    }
    POS_CHECK_POINTER(memory_binary.mutable_base());

    #if POS_CONF_RUNTIME_EnableTrace
        ((POSHandleManager_CUDA_Memory*)(this->_hm))->metric_tickers.start(POSHandleManager_CUDA_Memory::RESTORE_reload_state);
    #endif

    cuda_rt_retval = cudaMemcpyAsync(
        /* dst */ this->server_addr,
        /* src */ reinterpret_cast<const void*>(memory_binary.mutable_base()->state().c_str()),
        /* count */ this->state_size,
        /* kind */ cudaMemcpyHostToDevice,
        /* stream */ (cudaStream_t)(stream_id)
    );
    if(unlikely(cuda_rt_retval != cudaSuccess)){
        POS_WARN_DETAIL("failed to reload state of CUDA memory: server_addr(%p), retval(%d)", this->server_addr, cuda_rt_retval);
        retval = POS_FAILED;
        goto exit;
    }

    cuda_rt_retval = cudaStreamSynchronize((cudaStream_t)(stream_id));
    if(unlikely(cuda_rt_retval != cudaSuccess)){
        POS_WARN_DETAIL("failed to synchronize after reloading state of CUDA memory: server_addr(%p), retval(%d)", this->server_addr, cuda_rt_retval);
        retval = POS_FAILED;
        goto exit;
    }

    #if POS_CONF_RUNTIME_EnableTrace
        ((POSHandleManager_CUDA_Memory*)(this->_hm))->metric_tickers.end(POSHandleManager_CUDA_Memory::RESTORE_reload_state);
    #endif

exit:
    // this should be the end of using this mmap area, so we release it here
    munmap(mapped, ckpt_file_size);
    return retval;
}


POSHandleManager_CUDA_Memory::POSHandleManager_CUDA_Memory() : POSHandleManager(/* passthrough */ true) {}


pos_retval_t POSHandleManager_CUDA_Memory::init(std::map<uint64_t, std::vector<POSHandle*>> related_handles, bool is_restoring){
    pos_retval_t retval = POS_SUCCESS;
    
    // 设置资源类型 ID
    this->_rid = kPOS_ResourceTypeId_CUDA_Memory;

    // =================================================================================
    // 1. 保留基本的输入检查
    // 即使不预分配，我们也需要确保 Context Handle 存在，保证系统依赖关系正确
    // =================================================================================
    if(unlikely(related_handles.count(kPOS_ResourceTypeId_CUDA_Context) == 0)){
        retval = POS_FAILED_INVALID_INPUT;
        POS_WARN_C("failed to init handle manager for CUDA memory, no context provided");
        goto exit;
    }

    if(unlikely(related_handles[kPOS_ResourceTypeId_CUDA_Context].size() == 0)){
        retval = POS_FAILED_INVALID_INPUT;
        POS_WARN_C("failed to init handle manager for CUDA memory, no context provided");
        goto exit;
    }

    // =================================================================================
    // [删除] 核心改动点
    // =================================================================================
    // 1. 删除了 __reserve_device_vm_space Lambda 函数
    // 2. 删除了 cuCtxPushCurrent / cuCtxPopCurrent (因为不需要再操作设备了)
    // 3. 删除了 cuMemAddressReserve (不再预占虚拟地址)
    // 4. 删除了 alloc_ptrs 和 alloc_granularities 的赋值
    // 5. 删除了遍历 Context 的 for 循环
    // =================================================================================

    // 2. 直接标记初始化完成
    // 此时，PhOS 不持有任何虚拟地址空间，完全依赖后续 Parser 阶段的 UVM 分配
    this->has_finshed_reserved = true;

exit:
    return retval;
}


pos_retval_t POSHandleManager_CUDA_Memory::allocate_mocked_resource(
    POSHandle_CUDA_Memory** handle,
    std::map<uint64_t, std::vector<POSHandle*>> related_handles,
    size_t size,
    bool use_expected_addr,
    uint64_t expected_addr,
    uint64_t state_size,
    void* pre_alloc_ptr
){
    pos_retval_t retval = POS_SUCCESS;
    CUdeviceptr alloc_ptr;
    POSHandle *context_handle;

    POS_CHECK_POINTER(handle);

    // 获取父 Context 句柄（用于记录父子关系）
    POS_ASSERT(related_handles.count(kPOS_ResourceTypeId_CUDA_Context) == 1);
    POS_ASSERT(related_handles[kPOS_ResourceTypeId_CUDA_Context].size() == 1);
    POS_CHECK_POINTER(context_handle = related_handles[kPOS_ResourceTypeId_CUDA_Context][0]);
    
    // UVM 模式：直接使用传入的指针
    if (likely(pre_alloc_ptr != nullptr)) {
        alloc_ptr = (CUdeviceptr)(uintptr_t)pre_alloc_ptr;
    } else {
        POS_WARN_C("UVM Error: allocate_mocked_resource called without pre_alloc_ptr");
        retval = POS_FAILED_INVALID_INPUT;
        goto exit;
    }

    // 分配 Handle（调用通用模板，state_size 直接透传）
    retval = this->__allocate_mocked_resource(handle, size, use_expected_addr, expected_addr, state_size);
    if(unlikely(retval != POS_SUCCESS)){
        POS_WARN_C("failed to allocate mocked CUDA memory in the manager");
        goto exit;
    }

    POS_CHECK_POINTER(*handle);
    (*handle)->record_parent_handle(context_handle);

    // 设置透传地址（client_addr/server_addr 同步为真实 UVM 指针数值）
    (*handle)->set_passthrough_addr((void*)(uintptr_t)alloc_ptr, (*handle));

exit:
    return retval;
}


pos_retval_t POSHandleManager_CUDA_Memory::preserve_pooled_handles(uint64_t amount){
    return POS_SUCCESS;
}


pos_retval_t POSHandleManager_CUDA_Memory::try_restore_from_pool(POSHandle_CUDA_Memory* handle){
    return POS_FAILED;
}


pos_retval_t POSHandleManager_CUDA_Memory::__reallocate_single_handle(void* mapped, uint64_t ckpt_file_size, POSHandle_CUDA_Memory** handle){
    pos_retval_t retval = POS_SUCCESS;
    pos_protobuf::Bin_POSHandle_CUDA_Memory cuda_memory_binary;
    int i, nb_parent_handles, nb_parent_handles_;
    std::vector<std::pair<pos_resource_typeid_t, pos_u64id_t>> parent_handles_waitlist;
    pos_resource_typeid_t parent_handle_rid;
    pos_u64id_t parent_handle_hid;

    POS_CHECK_POINTER(mapped);
    POS_CHECK_POINTER(handle);

    if(!cuda_memory_binary.ParseFromArray(mapped, ckpt_file_size)){
        POS_WARN_C("failed to restore handle, failed to deserialize from mmap area");
        retval = POS_FAILED;
        goto exit;
    }
    POS_CHECK_POINTER(cuda_memory_binary.mutable_base());

    // form parent handles waitlist
    nb_parent_handles = cuda_memory_binary.mutable_base()->parent_handle_resource_type_idx_size();
    nb_parent_handles_ = cuda_memory_binary.mutable_base()->parent_handle_idx_size();
    POS_ASSERT(nb_parent_handles == nb_parent_handles_);
    for (i=0; i<nb_parent_handles; i++) {
        parent_handle_rid = cuda_memory_binary.mutable_base()->parent_handle_resource_type_idx(i);
        parent_handle_hid = cuda_memory_binary.mutable_base()->parent_handle_idx(i);
        parent_handles_waitlist.push_back({ parent_handle_rid, parent_handle_hid });
    }

    // create resource shell in this handle manager
    retval = this->__restore_mocked_resource(
        /* handle */ handle,
        /* id */ cuda_memory_binary.mutable_base()->id(),
        /* client_addr */ cuda_memory_binary.mutable_base()->client_addr(),
        /* server_addr */ cuda_memory_binary.mutable_base()->server_addr(),
        /* size */ cuda_memory_binary.mutable_base()->size(),
        /* parent_handles_waitlist */ parent_handles_waitlist,
        /* state_size */ cuda_memory_binary.mutable_base()->state_size()
    );
    if(unlikely(retval != POS_SUCCESS)){
        POS_WARN_C(
            "failed to restore mocked resource in handle manager: client_addr(%p)",
            cuda_memory_binary.mutable_base()->client_addr()
        );
        goto exit;
    }
    POS_CHECK_POINTER(*handle);

exit:
    return retval;
}


#if POS_CONF_RUNTIME_EnableTrace

void POSHandleManager_CUDA_Memory::print_metrics() {
    static std::unordered_map<metrics_ticker_type_t, std::string> ticker_names = {
        { RESTORE_reload_state, "Restore State" }
    };
    POS_ASSERT(pos_resource_map.count(this->_rid) > 0);
    POS_LOG(
        "[HandleManager Metrics] %s:\n%s",
        pos_resource_map[this->_rid].c_str(),
        this->metric_tickers.str(ticker_names).c_str()
    );
}

#endif
