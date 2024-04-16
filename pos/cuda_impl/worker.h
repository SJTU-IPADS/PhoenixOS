#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <thread>
#include <future>

#include <cuda_runtime_api.h>

#include "pos/include/common.h"
#include "pos/include/workspace.h"
#include "pos/include/client.h"
#include "pos/include/transport.h"
#include "pos/include/worker.h"
#include "pos/include/checkpoint.h"

#include "pos/cuda_impl/client.h"
#include "pos/cuda_impl/api_index.h"
#include "pos/cuda_impl/handle/memory.h"


namespace wk_functions {
    /* CUDA runtime functions */
    POS_WK_DECLARE_FUNCTIONS(cuda_malloc);
    POS_WK_DECLARE_FUNCTIONS(cuda_free);
    POS_WK_DECLARE_FUNCTIONS(cuda_launch_kernel);
    POS_WK_DECLARE_FUNCTIONS(cuda_memcpy_h2d);
    POS_WK_DECLARE_FUNCTIONS(cuda_memcpy_d2h);
    POS_WK_DECLARE_FUNCTIONS(cuda_memcpy_d2d);
    POS_WK_DECLARE_FUNCTIONS(cuda_memcpy_h2d_async);
    POS_WK_DECLARE_FUNCTIONS(cuda_memcpy_d2h_async);
    POS_WK_DECLARE_FUNCTIONS(cuda_memcpy_d2d_async);
    POS_WK_DECLARE_FUNCTIONS(cuda_memset_async);
    POS_WK_DECLARE_FUNCTIONS(cuda_set_device);
    POS_WK_DECLARE_FUNCTIONS(cuda_get_last_error);
    POS_WK_DECLARE_FUNCTIONS(cuda_get_error_string);
    POS_WK_DECLARE_FUNCTIONS(cuda_peek_at_last_error);
    POS_WK_DECLARE_FUNCTIONS(cuda_get_device_count);
    POS_WK_DECLARE_FUNCTIONS(cuda_get_device_properties);
    POS_WK_DECLARE_FUNCTIONS(cuda_device_get_attribute);
    POS_WK_DECLARE_FUNCTIONS(cuda_get_device);
    POS_WK_DECLARE_FUNCTIONS(cuda_func_get_attributes);
    POS_WK_DECLARE_FUNCTIONS(cuda_occupancy_max_active_bpm_with_flags);
    POS_WK_DECLARE_FUNCTIONS(cuda_stream_synchronize);
    POS_WK_DECLARE_FUNCTIONS(cuda_stream_is_capturing);
    POS_WK_DECLARE_FUNCTIONS(cuda_event_create_with_flags);
    POS_WK_DECLARE_FUNCTIONS(cuda_event_destory);
    POS_WK_DECLARE_FUNCTIONS(cuda_event_record);
    POS_WK_DECLARE_FUNCTIONS(cuda_event_query);

    /* CUDA driver functions */
    POS_WK_DECLARE_FUNCTIONS(__register_function);
    POS_WK_DECLARE_FUNCTIONS(cu_module_load);
    POS_WK_DECLARE_FUNCTIONS(cu_module_load_data);
    POS_WK_DECLARE_FUNCTIONS(cu_module_get_function);
    POS_WK_DECLARE_FUNCTIONS(cu_module_get_global);
    POS_WK_DECLARE_FUNCTIONS(cu_ctx_get_current);
    POS_WK_DECLARE_FUNCTIONS(cu_device_primary_ctx_get_state);
    POS_WK_DECLARE_FUNCTIONS(cu_get_error_string);

    /* cuBLAS functions */
    POS_WK_DECLARE_FUNCTIONS(cublas_create);
    POS_WK_DECLARE_FUNCTIONS(cublas_set_stream);
    POS_WK_DECLARE_FUNCTIONS(cublas_set_math_mode);
    POS_WK_DECLARE_FUNCTIONS(cublas_sgemm);
    POS_WK_DECLARE_FUNCTIONS(cublas_sgemm_strided_batched);
} // namespace ps_functions

/*!
 *  \brief  POS Worker (CUDA Implementation)
 */
class POSWorker_CUDA : public POSWorker {
 public:
    POSWorker_CUDA(POSWorkspace* ws) : POSWorker(ws) {}
    ~POSWorker_CUDA(){};

 protected:
    /*!
     *  \brief  make the worker thread synchronized
     *  \param  stream_id   index of the stream to be synced, default to be 0
     */
    pos_retval_t sync(uint64_t stream_id=0) override {
        pos_retval_t retval = POS_SUCCESS;
        cudaError_t cuda_rt_retval;

        cuda_rt_retval = cudaStreamSynchronize((cudaStream_t)(stream_id));
        if(unlikely(cuda_rt_retval != cudaSuccess)){
            POS_WARN_C_DETAIL(
                "failed to synchronize worker, is this a bug?: stream_id(%p), cuda_rt_retval(%d)",
                stream_id, cuda_rt_retval
            );
            retval = POS_FAILED;
        }

        return retval;
    }
    
    /*!
     *  \brief      initialization of the worker daemon thread
     *  \example    for CUDA, one need to call API e.g. cudaSetDevice first to setup the context for a thread
     */
    pos_retval_t daemon_init() override {
        /*!
         *  \note   make sure the worker thread is bound to a CUDA context
         *          if we don't do this and use the driver API, it might be unintialized
         */
        if(cudaSetDevice(0) != cudaSuccess){
            POS_WARN_C_DETAIL("worker thread failed to invoke cudaSetDevice");
            return POS_FAILED; 
        }
        cudaDeviceSynchronize();

        #if POS_CKPT_OPT_LEVEL == 2
            POS_ASSERT(
                cudaSuccess == cudaStreamCreate((cudaStream_t*)(&this->_ckpt_stream_id))
            );

            POS_ASSERT(
                cudaSuccess == cudaStreamCreate((cudaStream_t*)(&this->_cow_stream_id))
            );
        #endif

        #if POS_CKPT_OPT_LEVEL == 2 && POS_CKPT_ENABLE_PIPELINE == 1
            POS_ASSERT(
                cudaSuccess == cudaStreamCreate((cudaStream_t*)(&this->_ckpt_commit_stream_id))
            );
        #endif

        #if POS_MIGRATION_OPT_LEVEL == 2
            POS_ASSERT(
                cudaSuccess == cudaStreamCreate((cudaStream_t*)(&this->_migration_precopy_stream_id))
            );
        #endif

        return POS_SUCCESS; 
    }

    #if POS_MIGRATION_OPT_LEVEL == 2

        pos_retval_t migration_remote_malloc(POSClient* client) override {
            pos_retval_t retval = POS_SUCCESS;
            POSHandleManager_CUDA_Memory *hm_memory;
            POSHandle_CUDA_Memory *memory_handle;
            uint64_t i, nb_handles;

            hm_memory = pos_get_client_typed_hm(client, kPOS_ResourceTypeId_CUDA_Memory, POSHandleManager_CUDA_Memory);
            POS_CHECK_POINTER(hm_memory);

            // TODO: we should only traverse those non-host buffer
            nb_handles = hm_memory->get_nb_handles();
            for(i=0; i<nb_handles; i++){
                memory_handle = hm_memory->get_handle_by_id(i);
                POS_CHECK_POINTER(memory_handle);
                if(unlikely(POS_SUCCESS != memory_handle->remote_restore())){
                    POS_WARN("failed to remotely restore memory handle: server_addr(%p)", memory_handle->server_addr);
                }
            }

            // force switch to origin device
            cudaSetDevice(0);

        exit:
            return retval;
        }

        void migration_precopy_asyc_thread() override {
            POS_LOG("step 3: pre-copy");
            POSHandleManager_CUDA_Memory *hm_memory;
            POSHandle_CUDA_Memory *memory_handle;
            uint64_t i, nb_handles;
            cudaError_t cuda_rt_retval;
            typename std::set<POSHandle_CUDA_Memory*>::iterator memory_handle_set_iter;

            uint64_t nb_precopy_handle = 0, precopy_size = 0, nb_invalidate_handle = 0, invalidate_size = 0;

            hm_memory = pos_get_client_typed_hm(this->async_migration_cxt.client, kPOS_ResourceTypeId_CUDA_Memory, POSHandleManager_CUDA_Memory);
            POS_CHECK_POINTER(hm_memory);

            std::set<POSHandle_CUDA_Memory*>& modified_handles = hm_memory->get_modified_handles();
            if(likely(modified_handles.size() > 0)){
                for(memory_handle_set_iter = modified_handles.begin(); memory_handle_set_iter != modified_handles.end(); memory_handle_set_iter++){
                    memory_handle = *memory_handle_set_iter;
                    POS_CHECK_POINTER(memory_handle);
                    
                    // skip duplicated buffers
                    if(hm_memory->is_host_stateful_handle(memory_handle)){
                        continue;
                    }

                    cuda_rt_retval = cudaMemcpyPeerAsync(
                        /* dst */ memory_handle->remote_server_addr,
                        /* dstDevice */ 1,
                        /* src */ memory_handle->server_addr,
                        /* srcDevice */ 0,
                        /* count */ memory_handle->state_size,
                        /* stream */ (cudaStream_t)(this->_migration_precopy_stream_id)
                    );
                    if(unlikely(cuda_rt_retval != CUDA_SUCCESS)){
                        POS_WARN("failed to p2p copy memory: server_addr(%p), state_size(%lu)", memory_handle->server_addr, memory_handle->state_size);
                        continue;
                    }

                    cuda_rt_retval = cudaStreamSynchronize((cudaStream_t)(this->_migration_precopy_stream_id));
                    if(unlikely(cuda_rt_retval != CUDA_SUCCESS)){
                        POS_WARN("failed to synchronize p2p copy memory: server_addr(%p), state_size(%lu)", memory_handle->server_addr, memory_handle->state_size);
                        continue;
                    }

                    // invalidate handles
                    if(this->async_migration_cxt.invalidate_handles.count(memory_handle) > 0){
                        this->async_migration_cxt.delta_copy_set.insert(memory_handle);
                        nb_invalidate_handle += 1;
                        invalidate_size += memory_handle->state_size;
                    } else {
                        nb_precopy_handle += 1;
                        precopy_size += memory_handle->state_size;
                    }
                }
            }

            nb_handles = hm_memory->get_nb_handles();
            POS_LOG(
                "    pre-copy finished: nb_precopy_handle(%lu), precopy_size(%lu Bytes), nb_invalidate_handle(%lu), invalidate_size(%lu), duplicated rate(%lf)",
                nb_precopy_handle, precopy_size, nb_invalidate_handle, invalidate_size, (double)(nb_handles - modified_handles.size())/(double)(nb_handles)
            );

            hm_memory->clear_modified_handle();
            
        exit:
            this->async_migration_cxt.precopy_finished = true;
        }

    #endif // POS_MIGRATION_OPT_LEVEL == 2
    
    /*!
     *  \brief  insertion of worker functions
     *  \return POS_SUCCESS for succefully insertion
     */
    pos_retval_t init_wk_functions() override {
        this->_launch_functions.insert({
            /* CUDA runtime functions */
            {   CUDA_MALLOC,                    wk_functions::cuda_malloc::launch                       },
            {   CUDA_FREE,                      wk_functions::cuda_free::launch                         },
            {   CUDA_LAUNCH_KERNEL,             wk_functions::cuda_launch_kernel::launch                },
            {   CUDA_MEMCPY_HTOD,               wk_functions::cuda_memcpy_h2d::launch                   },
            {   CUDA_MEMCPY_DTOH,               wk_functions::cuda_memcpy_d2h::launch                   },
            {   CUDA_MEMCPY_DTOD,               wk_functions::cuda_memcpy_d2d::launch                   },
            {   CUDA_MEMCPY_HTOD_ASYNC,         wk_functions::cuda_memcpy_h2d_async::launch             },
            {   CUDA_MEMCPY_DTOH_ASYNC,         wk_functions::cuda_memcpy_d2h_async::launch             },
            {   CUDA_MEMCPY_DTOD_ASYNC,         wk_functions::cuda_memcpy_d2d_async::launch             },
            {   CUDA_MEMSET_ASYNC,              wk_functions::cuda_memset_async::launch                 },
            {   CUDA_SET_DEVICE,                wk_functions::cuda_set_device::launch                   },
            {   CUDA_GET_LAST_ERROR,            wk_functions::cuda_get_last_error::launch               },
            {   CUDA_GET_ERROR_STRING,          wk_functions::cuda_get_error_string::launch             },
            {   CUDA_PEEK_AT_LAST_ERROR,        wk_functions::cuda_peek_at_last_error::launch           },
            {   CUDA_GET_DEVICE_COUNT,          wk_functions::cuda_get_device_count::launch             },
            {   CUDA_GET_DEVICE_PROPERTIES,     wk_functions::cuda_get_device_properties::launch        },
            {   CUDA_DEVICE_GET_ATTRIBUTE,      wk_functions::cuda_device_get_attribute::launch         },
            {   CUDA_GET_DEVICE,                wk_functions::cuda_get_device::launch                   },
            {   CUDA_FUNC_GET_ATTRIBUTES,       wk_functions::cuda_func_get_attributes::launch          },
            {   CUDA_OCCUPANCY_MAX_ACTIVE_BPM_WITH_FLAGS,   
                                        wk_functions::cuda_occupancy_max_active_bpm_with_flags::launch  },
            {   CUDA_STREAM_SYNCHRONIZE,        wk_functions::cuda_stream_synchronize::launch           },
            {   CUDA_STREAM_IS_CAPTURING,       wk_functions::cuda_stream_is_capturing::launch          },
            {   CUDA_EVENT_CREATE_WITH_FLAGS,   wk_functions::cuda_event_create_with_flags::launch      },
            {   CUDA_EVENT_DESTROY,             wk_functions::cuda_event_destory::launch                },
            {   CUDA_EVENT_RECORD,              wk_functions::cuda_event_record::launch                 },
            {   CUDA_EVENT_QUERY,               wk_functions::cuda_event_query::launch                  },
            
            /* CUDA driver functions */
            {   rpc_cuModuleLoad,               wk_functions::cu_module_load::launch                    },
            {   rpc_cuModuleLoadData,           wk_functions::cu_module_load_data::launch               },
            {   rpc_register_function,          wk_functions::__register_function::launch               },
            {   rpc_cuModuleGetFunction,        wk_functions::cu_module_get_function::launch            },
            {   rpc_register_var,               wk_functions::cu_module_get_global::launch              },
            {   rpc_cuDevicePrimaryCtxGetState, wk_functions::cu_device_primary_ctx_get_state::launch   },
            {   rpc_cuLaunchKernel,             wk_functions::cuda_launch_kernel::launch                },
            {   rpc_cuGetErrorString,           wk_functions::cu_get_error_string::launch               },
            
            /* cuBLAS functions */
            {   rpc_cublasCreate,               wk_functions::cublas_create::launch                     },
            {   rpc_cublasSetStream,            wk_functions::cublas_set_stream::launch                 },
            {   rpc_cublasSetMathMode,          wk_functions::cublas_set_math_mode::launch              },
            {   rpc_cublasSgemm,                wk_functions::cublas_sgemm::launch                      },
            {   rpc_cublasSgemmStridedBatched,  wk_functions::cublas_sgemm_strided_batched::launch      },
        });
        POS_DEBUG_C("insert %lu worker launch functions", this->_launch_functions.size());

        return POS_SUCCESS;
    }
};
