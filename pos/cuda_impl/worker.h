#pragma once

#include <cuda_runtime_api.h>

#include "pos/include/common.h"
#include "pos/include/workspace.h"
#include "pos/include/client.h"
#include "pos/include/transport.h"
#include "pos/include/worker.h"
#include "pos/include/checkpoint.h"
#include "pos/cuda_impl/client.h"

#include "pos/cuda_impl/api_index.h"

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
    POS_WK_DECLARE_FUNCTIONS(cuda_set_device);
    POS_WK_DECLARE_FUNCTIONS(cuda_get_last_error);
    POS_WK_DECLARE_FUNCTIONS(cuda_get_error_string);
    POS_WK_DECLARE_FUNCTIONS(cuda_get_device_count);
    POS_WK_DECLARE_FUNCTIONS(cuda_get_device_properties);
    POS_WK_DECLARE_FUNCTIONS(cuda_get_device);
    POS_WK_DECLARE_FUNCTIONS(cuda_stream_synchronize);
    POS_WK_DECLARE_FUNCTIONS(cuda_stream_is_capturing);
    POS_WK_DECLARE_FUNCTIONS(cuda_event_create_with_flags);
    POS_WK_DECLARE_FUNCTIONS(cuda_event_destory);
    POS_WK_DECLARE_FUNCTIONS(cuda_event_record);

    /* CUDA driver functions */
    POS_WK_DECLARE_FUNCTIONS(cu_module_load_data);
    POS_WK_DECLARE_FUNCTIONS(cu_module_get_function);
    POS_WK_DECLARE_FUNCTIONS(cu_module_get_global);
    POS_WK_DECLARE_FUNCTIONS(cu_device_primary_ctx_get_state);

    /* cuBLAS functions */
    POS_WK_DECLARE_FUNCTIONS(cublas_create);
    POS_WK_DECLARE_FUNCTIONS(cublas_set_stream);
    POS_WK_DECLARE_FUNCTIONS(cublas_set_math_mode);
    POS_WK_DECLARE_FUNCTIONS(cublas_sgemm);
} // namespace rt_functions

/*!
 *  \brief  POS Worker (CUDA Implementation)
 */
template<class T_POSTransport>
class POSWorker_CUDA : public POSWorker<T_POSTransport, POSClient_CUDA> {
 public:
    POSWorker_CUDA(POSWorkspace<T_POSTransport, POSClient_CUDA>* ws) 
        : POSWorker<T_POSTransport, POSClient_CUDA>(ws), sample_ckpt(0) {}
    ~POSWorker_CUDA() = default;
 
 protected:
    uint64_t sample_ckpt;

    /*!
     *  \brief  naive implementation of the checkpoint procedure
     *  \note   this procedure checkpoints all memory handles, stores all checkpointing
     *          history of all buffers, cause (1) long checkpoint latency and (2) large
     *          checkpointing memory consumption
     * \param   wqe WQ element of the checkpoint op
     */
    pos_retval_t __checkpoint_naive(POSAPIContext_QE_ptr wqe) {
        pos_retval_t retval = POS_SUCCESS;
        cudaError_t cuda_rt_retval;
        uint64_t nb_memory_handles;
        POSClient_CUDA *client;
        POSHandle_CUDA_Memory_ptr memory_handle;
        POSHandleManager<POSHandle_CUDA_Memory>* hm_memory;
        POSCheckpointSlot_ptr ckpt_slot;
        uint64_t i;

        POS_CHECK_POINTER(wqe);

        client = (POSClient_CUDA*)(wqe->client);
        POS_CHECK_POINTER(client);

        wqe->nb_ckpt_handles = 0;
        wqe->ckpt_size = 0;
        wqe->ckpt_memory_consumption = 0;
        
        // TODO: maybe we can encapsulate the following code as an lambda, to checkpoint more stateful handles
        hm_memory = client->handle_managers[kPOS_ResourceTypeId_CUDA_Memory];
        POS_CHECK_POINTER(hm_memory);
        nb_memory_handles = hm_memory->get_nb_handles();
        for(i=0; i<nb_memory_handles; i++){
            memory_handle = hm_memory->get_handle_by_id(i);
            POS_CHECK_POINTER(memory_handle.get());

            // apply new checkpoint slot
            if(unlikely(
                POS_SUCCESS != memory_handle->ckpt_bag.apply_new_checkpoint(
                    /* version */ wqe->dag_vertex_id,
                    /* ptr */ &ckpt_slot
                )
            )){
                POS_WARN_C("failed to apply checkpoint slot");
                retval = POS_FAILED;
                goto exit;
            }

            // checkpoint
            cuda_rt_retval = cudaMemcpyAsync(
                /* dst */ ckpt_slot->expose_pointer(), 
                /* src */ memory_handle->server_addr,
                /* size */ memory_handle->state_size,
                /* kind */ cudaMemcpyDeviceToHost,
                /* stream */ 0
            );

            if(unlikely(cuda_rt_retval != cudaSuccess)){
                POS_WARN_C(
                    "failed to checkpoint memory handle: server_addr(%p), retval(%d)",
                    memory_handle->server_addr, cuda_rt_retval
                );
                retval = POS_FAILED;
                goto exit;
            }

            wqe->nb_ckpt_handles += 1;
            wqe->ckpt_size += memory_handle->state_size;
        }

        // make sure the checkpoint is finished
        cuda_rt_retval = cudaStreamSynchronize(0);
        if(unlikely(cuda_rt_retval != cudaSuccess)){
            POS_WARN_C("failed to synchronize after checkpointing");
            retval = POS_FAILED;
            goto exit;
        }

    exit:
        for(i=0; i<nb_memory_handles; i++){
            memory_handle = hm_memory->get_handle_by_id(i);
            POS_CHECK_POINTER(memory_handle.get());
            wqe->ckpt_memory_consumption += memory_handle->ckpt_bag.get_memory_consumption();
        }

        // POS_LOG_C("checkpointed %lu memory handles", nb_memory_handles);

        return retval;
    }

    /*!
     *  \brief  level-1 optimizing implementation of the checkpoint procedure
     *  \note   this procedure checkpoints only those memory handles that been modified
     *          since last checkpointing
     * \param   wqe WQ element of the checkpoint op
     */
    pos_retval_t __checkpoint_o1(POSAPIContext_QE_ptr wqe) {
        uint64_t i;
        std::vector<POSHandleView_t>* handle_views;
        uint64_t nb_memory_handles;
        POSClient_CUDA *client;
        POSHandle_CUDA_Memory_ptr memory_handle;
        POSHandleManager<POSHandle_CUDA_Memory>* hm_memory;
        cudaError_t cuda_rt_retval;
        POSCheckpointSlot_ptr ckpt_slot;
        pos_retval_t retval = POS_SUCCESS;

        POS_CHECK_POINTER(wqe);

        wqe->nb_ckpt_handles = 0;
        wqe->ckpt_size = 0;
        wqe->ckpt_memory_consumption = 0;

        client = (POSClient_CUDA*)(wqe->client);
        POS_CHECK_POINTER(client);
        hm_memory = client->handle_managers[kPOS_ResourceTypeId_CUDA_Memory];
        POS_CHECK_POINTER(hm_memory);
        nb_memory_handles = hm_memory->get_nb_handles();

        // we only checkpoint those memory handles that been modified since last checkpointing
        if(likely(wqe->handle_view_map.count(kPOS_ResourceTypeId_CUDA_Memory) == 0)){
            goto exit;
        }
        POS_CHECK_POINTER(handle_views = wqe->handle_view_map[kPOS_ResourceTypeId_CUDA_Memory]);
        for(i=0; i<handle_views->size(); i++){
            memory_handle = std::dynamic_pointer_cast<POSHandle_CUDA_Memory>((*handle_views)[i].handle);
            POS_CHECK_POINTER(memory_handle.get());

            // apply new checkpoint slot
            if(unlikely(
                POS_SUCCESS != memory_handle->ckpt_bag.apply_new_checkpoint(
                    /* version */ wqe->dag_vertex_id,
                    /* ptr */ &ckpt_slot
                )
            )){
                POS_WARN_C("failed to apply checkpoint slot");
                retval = POS_FAILED;
                goto exit;
            }

            // checkpoint
            cuda_rt_retval = cudaMemcpyAsync(
                /* dst */ ckpt_slot->expose_pointer(), 
                /* src */ memory_handle->server_addr,
                /* size */ memory_handle->state_size,
                /* kind */ cudaMemcpyDeviceToHost,
                /* stream */ 0
            );

            if(unlikely(cuda_rt_retval != cudaSuccess)){
                POS_WARN_C(
                    "failed to checkpoint memory handle: server_addr(%p), retval(%d)",
                    memory_handle->server_addr, cuda_rt_retval
                );
                retval = POS_FAILED;
                goto exit;
            }

            wqe->nb_ckpt_handles += 1;
            wqe->ckpt_size += memory_handle->state_size;
        }

        // make sure the checkpoint is finished
        cuda_rt_retval = cudaStreamSynchronize(0);
        if(unlikely(cuda_rt_retval != cudaSuccess)){
            POS_WARN_C("failed to synchronize after checkpointing");
            retval = POS_FAILED;
            goto exit;
        }

    exit:
        for(i=0; i<nb_memory_handles; i++){
            memory_handle = hm_memory->get_handle_by_id(i);
            POS_CHECK_POINTER(memory_handle.get());
            wqe->ckpt_memory_consumption += memory_handle->ckpt_bag.get_memory_consumption();
        }

        // POS_LOG_C(
        //     "checkpointed %lu memory handles, memory consumption: %lu",
        //     wqe->nb_ckpt_handles, wqe->ckpt_memory_consumption
        // );

        return retval;
    }

    /*!
     *  \brief  level-2 optimizing implementation of the checkpoint procedure
     *  \note   this procedure checkpoints only those memory handles that been modified
     *          since last checkpointing, and delete history checkpointing of memory buffers
     *  \param  wqe WQ element of the checkpoint op
     */
    pos_retval_t __checkpoint_o2(POSAPIContext_QE_ptr wqe) {
        uint64_t i;
        std::vector<POSHandleView_t>* handle_views;
        uint64_t nb_memory_handles;
        POSClient_CUDA *client;
        POSHandle_CUDA_Memory_ptr memory_handle;
        POSHandleManager<POSHandle_CUDA_Memory>* hm_memory;
        cudaError_t cuda_rt_retval;
        POSCheckpointSlot_ptr ckpt_slot;
        pos_retval_t retval = POS_SUCCESS;

        POS_CHECK_POINTER(wqe);

        wqe->nb_ckpt_handles = 0;
        wqe->ckpt_size = 0;
        wqe->ckpt_memory_consumption = 0;

        client = (POSClient_CUDA*)(wqe->client);
        POS_CHECK_POINTER(client);
        hm_memory = client->handle_managers[kPOS_ResourceTypeId_CUDA_Memory];
        POS_CHECK_POINTER(hm_memory);
        nb_memory_handles = hm_memory->get_nb_handles();

        // we only checkpoint those memory handles that been modified since last checkpointing
        if(likely(wqe->handle_view_map.count(kPOS_ResourceTypeId_CUDA_Memory) == 0)){
            goto exit;
        }
        POS_CHECK_POINTER(handle_views = wqe->handle_view_map[kPOS_ResourceTypeId_CUDA_Memory]);
        for(i=0; i<handle_views->size(); i++){
            memory_handle = std::dynamic_pointer_cast<POSHandle_CUDA_Memory>((*handle_views)[i].handle);
            POS_CHECK_POINTER(memory_handle.get());

            // apply new checkpoint slot
            if(unlikely(
                POS_SUCCESS != memory_handle->ckpt_bag.apply_new_checkpoint(
                    /* version */ wqe->dag_vertex_id,
                    /* ptr */ &ckpt_slot
                )
            )){
                POS_WARN_C("failed to apply checkpoint slot");
                retval = POS_FAILED;
                goto exit;
            }

            // checkpoint
            cuda_rt_retval = cudaMemcpyAsync(
                /* dst */ ckpt_slot->expose_pointer(), 
                /* src */ memory_handle->server_addr,
                /* size */ memory_handle->state_size,
                /* kind */ cudaMemcpyDeviceToHost,
                /* stream */ 0
            );

            if(unlikely(cuda_rt_retval != cudaSuccess)){
                POS_WARN_C(
                    "failed to checkpoint memory handle: server_addr(%p), retval(%d)",
                    memory_handle->server_addr, cuda_rt_retval
                );
                retval = POS_FAILED;
                goto exit;
            }

            // delete all old checkpoints
            memory_handle->ckpt_bag.clear_all_old_checkpoints(/* except_version */ wqe->dag_vertex_id);

            wqe->nb_ckpt_handles += 1;
            wqe->ckpt_size += memory_handle->state_size;
        }

        // make sure the checkpoint is finished
        cuda_rt_retval = cudaStreamSynchronize(0);
        if(unlikely(cuda_rt_retval != cudaSuccess)){
            POS_WARN_C("failed to synchronize after checkpointing");
            retval = POS_FAILED;
            goto exit;
        }

    exit:
        for(i=0; i<nb_memory_handles; i++){
            memory_handle = hm_memory->get_handle_by_id(i);
            POS_CHECK_POINTER(memory_handle.get());
            wqe->ckpt_memory_consumption += memory_handle->ckpt_bag.get_memory_consumption();
        }

        // POS_LOG_C(
        //     "checkpointed %lu memory handles, memory consumption: %lu",
        //     wqe->nb_ckpt_handles, wqe->ckpt_memory_consumption
        // );

        return retval;
    }

    /*!
     *  \brief  checkpoint procedure, should be implemented by each platform
     *  \param  wqe     the checkpoint op
     *  \return POS_SUCCESS for successfully checkpointing
     */
    pos_retval_t checkpoint(POSAPIContext_QE_ptr wqe) override {
        #ifdef POS_ENABLE_CHECKPOINT
            // return __checkpoint_naive(wqe);
            // return __checkpoint_o1(wqe);
            return __checkpoint_o2(wqe);
        #else
            return POS_SUCCESS;
        #endif
    }

 private:
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

        return POS_SUCCESS; 
    }
    
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
            {   CUDA_SET_DEVICE,                wk_functions::cuda_set_device::launch                   },
            {   CUDA_GET_LAST_ERROR,            wk_functions::cuda_get_last_error::launch               },
            {   CUDA_GET_ERROR_STRING,          wk_functions::cuda_get_error_string::launch             },
            {   CUDA_GET_DEVICE_COUNT,          wk_functions::cuda_get_device_count::launch             },
            {   CUDA_GET_DEVICE_PROPERTIES,     wk_functions::cuda_get_device_properties::launch        },
            {   CUDA_GET_DEVICE,                wk_functions::cuda_get_device::launch                   },
            {   CUDA_STREAM_SYNCHRONIZE,        wk_functions::cuda_stream_synchronize::launch           },
            {   CUDA_STREAM_IS_CAPTURING,       wk_functions::cuda_stream_is_capturing::launch          },
            {   CUDA_EVENT_CREATE_WITH_FLAGS,   wk_functions::cuda_event_create_with_flags::launch      },
            {   CUDA_EVENT_DESTROY,             wk_functions::cuda_event_destory::launch                },
            {   CUDA_EVENT_RECORD,              wk_functions::cuda_event_record::launch                 },
            /* CUDA driver functions */
            {   rpc_cuModuleLoad,               wk_functions::cu_module_load_data::launch               },
            {   rpc_cuModuleGetFunction,        wk_functions::cu_module_get_function::launch            },
            {   rpc_register_var,               wk_functions::cu_module_get_global::launch              },
            {   rpc_cuDevicePrimaryCtxGetState, wk_functions::cu_device_primary_ctx_get_state::launch   },
            /* cuBLAS functions */
            {   rpc_cublasCreate,               wk_functions::cublas_create::launch                     },
            {   rpc_cublasSetStream,            wk_functions::cublas_set_stream::launch                 },
            {   rpc_cublasSetMathMode,          wk_functions::cublas_set_math_mode::launch              },
            {   rpc_cublasSgemm,                wk_functions::cublas_sgemm::launch                      },
        });
        POS_DEBUG_C("insert %lu worker launch functions", this->_launch_functions.size());

        this->_landing_functions.insert({
            /* CUDA runtime functions */
            {   CUDA_MALLOC,                    wk_functions::cuda_malloc::landing                      },
            {   CUDA_FREE,                      wk_functions::cuda_free::landing                        },
            {   CUDA_LAUNCH_KERNEL,             wk_functions::cuda_launch_kernel::landing               },
            {   CUDA_MEMCPY_HTOD,               wk_functions::cuda_memcpy_h2d::landing                  },
            {   CUDA_MEMCPY_DTOH,               wk_functions::cuda_memcpy_d2h::landing                  },
            {   CUDA_MEMCPY_DTOD,               wk_functions::cuda_memcpy_d2d::landing                  },
            {   CUDA_MEMCPY_HTOD_ASYNC,         wk_functions::cuda_memcpy_h2d_async::landing            },
            {   CUDA_MEMCPY_DTOH_ASYNC,         wk_functions::cuda_memcpy_d2h_async::landing            },
            {   CUDA_MEMCPY_DTOD_ASYNC,         wk_functions::cuda_memcpy_d2d_async::landing            },
            {   CUDA_SET_DEVICE,                wk_functions::cuda_set_device::landing                  },
            {   CUDA_GET_LAST_ERROR,            wk_functions::cuda_get_last_error::landing              },
            {   CUDA_GET_ERROR_STRING,          wk_functions::cuda_get_error_string::landing            },
            {   CUDA_GET_DEVICE_COUNT,          wk_functions::cuda_get_device_count::landing            },
            {   CUDA_GET_DEVICE_PROPERTIES,     wk_functions::cuda_get_device_properties::landing       },
            {   CUDA_GET_DEVICE,                wk_functions::cuda_get_device::landing                  },
            {   CUDA_STREAM_SYNCHRONIZE,        wk_functions::cuda_stream_synchronize::landing          },
            {   CUDA_STREAM_IS_CAPTURING,       wk_functions::cuda_stream_is_capturing::landing         },
            {   CUDA_EVENT_CREATE_WITH_FLAGS,   wk_functions::cuda_event_create_with_flags::landing     },
            {   CUDA_EVENT_DESTROY,             wk_functions::cuda_event_destory::landing               },
            {   CUDA_EVENT_RECORD,              wk_functions::cuda_event_record::landing                },
            /* CUDA driver functions */
            {   rpc_cuModuleLoad,               wk_functions::cu_module_load_data::landing              },
            {   rpc_cuModuleGetFunction,        wk_functions::cu_module_get_function::landing           },
            {   rpc_register_var,               wk_functions::cu_module_get_global::landing             },
            {   rpc_cuDevicePrimaryCtxGetState, wk_functions::cu_device_primary_ctx_get_state::landing  },
            /* cuBLAS functions */
            {   rpc_cublasCreate,               wk_functions::cublas_create::landing                    },
            {   rpc_cublasSetStream,            wk_functions::cublas_set_stream::landing                },
            {   rpc_cublasSetMathMode,          wk_functions::cublas_set_math_mode::landing             },
            {   rpc_cublasSgemm,                wk_functions::cublas_sgemm::landing                     }
        });
        POS_DEBUG_C("insert %lu worker landing functions", this->_landing_functions.size());

        return POS_SUCCESS;
    }
};

#include "pos/cuda_impl/worker/base.h"