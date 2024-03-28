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

    /* CUDA driver functions */
    POS_WK_DECLARE_FUNCTIONS(cu_module_load);
    POS_WK_DECLARE_FUNCTIONS(cu_module_load_data);
    POS_WK_DECLARE_FUNCTIONS(cu_module_get_function);
    POS_WK_DECLARE_FUNCTIONS(cu_module_get_global);
    POS_WK_DECLARE_FUNCTIONS(cu_ctx_get_current);
    POS_WK_DECLARE_FUNCTIONS(cu_device_primary_ctx_get_state);

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
    POSWorker_CUDA(POSWorkspace* ws) : POSWorker(ws), _ckpt_stream(nullptr), _ckpt_commit_stream(nullptr) {}
    ~POSWorker_CUDA(){};

 protected:
    /*!
     *  \brief  naive implementation of the checkpoint procedure
     *  \note   this procedure checkpoints all memory handles, stores all checkpointing
     *          history of all buffers, cause (1) long checkpoint latency and (2) large
     *          checkpointing memory consumption
     * \note    this is the implementation of singularity
     * \param   wqe WQ element of the checkpoint op
     */
    pos_retval_t __checkpoint_sync_naive(POSAPIContext_QE* wqe) {
        pos_retval_t retval = POS_SUCCESS;
        cudaError_t cuda_rt_retval;
        uint64_t nb_handles;
        POSClient_CUDA *client;
        POSHandle *handle;
        POSHandleManager<POSHandle>* hm;
        POSCheckpointSlot *ckpt_slot;
        uint64_t i;

        POS_CHECK_POINTER(wqe);

        client = (POSClient_CUDA*)(wqe->client);
        POS_CHECK_POINTER(client);

        wqe->nb_ckpt_handles = 0;
        wqe->ckpt_size = 0;
        wqe->ckpt_memory_consumption = 0;
        
        for(auto &stateful_handle_id : this->_ws->stateful_handle_type_idx){
            hm = pos_get_client_typed_hm(client, stateful_handle_id, POSHandleManager<POSHandle>);
            POS_CHECK_POINTER(hm);
            nb_handles = hm->get_nb_handles();
            for(i=0; i<nb_handles; i++){
                handle = hm->get_handle_by_id(i);
                POS_CHECK_POINTER(handle);

                if(unlikely(   handle->status == kPOS_HandleStatus_Deleted 
                            || handle->status == kPOS_HandleStatus_Create_Pending
                            || handle->status == kPOS_HandleStatus_Broken
                )){
                    continue;
                }

                retval = handle->checkpoint_sync(
                    /* version_id */ handle->latest_version,
                    /* stream_id */ 0
                );
                if(unlikely(POS_SUCCESS != retval)){
                    POS_WARN_C("failed to checkpoint handle");
                    // retval = POS_FAILED;
                    // goto exit;
                    continue;
                }

                wqe->nb_ckpt_handles += 1;
                wqe->ckpt_size += handle->state_size;
            }
        }

        // make sure the checkpoint is finished
        // TODO: make this to be more generic?
        cuda_rt_retval = cudaStreamSynchronize(0);
        if(unlikely(cuda_rt_retval != cudaSuccess)){
            POS_WARN_C("failed to synchronize after checkpointing");
            retval = POS_FAILED;
            goto exit;
        }

    exit:
        // collect statistics
        for(auto &stateful_handle_id : this->_ws->stateful_handle_type_idx){
            hm = pos_get_client_typed_hm(client, stateful_handle_id, POSHandleManager<POSHandle>);
            POS_CHECK_POINTER(hm);
            nb_handles = hm->get_nb_handles();
            for(i=0; i<nb_handles; i++){
                handle = hm->get_handle_by_id(i);
                POS_CHECK_POINTER(handle);

                if(unlikely(handle->status == kPOS_HandleStatus_Deleted)){
                    continue;
                }

                wqe->ckpt_memory_consumption += handle->ckpt_bag->get_memory_consumption();
            }
        }

        POS_LOG(
            "checkpoint finished: #finished_handles(%lu), size(%lu Bytes), #abandoned_handles(%lu), size(%lu Bytes)",
            wqe->nb_ckpt_handles, wqe->ckpt_size, wqe->nb_abandon_handles, wqe->abandon_ckpt_size
        );

        return retval;
    }

    /*!
     *  \brief  level-1 optimizing implementation of the checkpoint procedure
     *  \note   this procedure checkpoints only those memory handles that been modified
     *          since last checkpointing
     * \param   wqe WQ element of the checkpoint op
     */
    pos_retval_t __checkpoint_sync_incremental(POSAPIContext_QE* wqe) {
        uint64_t i;
        std::vector<POSHandleView_t>* handle_views;
        uint64_t nb_handles;
        POSClient_CUDA *client;
        POSHandleManager<POSHandle>* hm;
        cudaError_t cuda_rt_retval;
        POSCheckpointSlot *ckpt_slot;
        pos_retval_t retval = POS_SUCCESS;

        typename std::map<pos_resource_typeid_t, std::set<POSHandle*>>::iterator map_iter;
        typename std::set<POSHandle*>::iterator set_iter;

        POS_CHECK_POINTER(wqe);

        wqe->nb_ckpt_handles = 0;
        wqe->ckpt_size = 0;
        wqe->ckpt_memory_consumption = 0;

        for(set_iter=wqe->checkpoint_handles.begin(); set_iter!=wqe->checkpoint_handles.end(); set_iter++){
            const POSHandle *handle = *set_iter;
            POS_CHECK_POINTER(handle);

            if(unlikely(   handle->status == kPOS_HandleStatus_Deleted 
                        || handle->status == kPOS_HandleStatus_Create_Pending
                        || handle->status == kPOS_HandleStatus_Broken
            )){
                continue;
            }

            retval = handle->checkpoint_sync(
                /* version_id */ handle->latest_version,
                /* stream_id */ 0
            );
            if(unlikely(POS_SUCCESS != retval)){
                POS_WARN_C("failed to checkpoint handle");
                retval = POS_FAILED;
                goto exit;
            }

            wqe->nb_ckpt_handles += 1;
            wqe->ckpt_size += handle->state_size;
        }
        
        // make sure the checkpoint is finished
        cuda_rt_retval = cudaStreamSynchronize(0);
        if(unlikely(cuda_rt_retval != cudaSuccess)){
            POS_WARN_C("failed to synchronize after checkpointing");
            retval = POS_FAILED;
            goto exit;
        }

    exit:
        return retval;
    }

    /*!
     *  \brief  checkpoint procedure, should be implemented by each platform
     *  \param  wqe     the checkpoint op
     *  \return POS_SUCCESS for successfully checkpointing
     */
    pos_retval_t checkpoint_sync(POSAPIContext_QE* wqe) override {
        #if POS_CKPT_ENABLE_PREEMPT == 1
            return __checkpoint_sync_naive(wqe);
        #else
            #if POS_CKPT_ENABLE_INCREMENTAL == 1
                return __checkpoint_sync_incremental(wqe);
            #else
                return __checkpoint_sync_naive(wqe);
            #endif
        #endif
    }

    /*!
     *  \brief  overlapped checkpoint procedure, should be implemented by each platform
     *  \note   this thread will be raised by level-2 ckpt
     *  \note   aware of the macro POS_CKPT_ENABLE_PIPELINE
     *  \note   aware of the macro POS_CKPT_ENABLE_ORCHESTRATION
     *  \param  cxt     the context of this checkpointing
     */
    void checkpoint_async_thread(checkpoint_async_cxt_t* cxt) override {
        uint64_t i;
        pos_vertex_id_t checkpoint_version;
        cudaError_t cuda_rt_retval;
        pos_retval_t retval = POS_SUCCESS;
        POSAPIContext_QE *wqe;
        POSHandle *handle;
        uint64_t s_tick = 0, e_tick = 0;

    #if POS_CKPT_ENABLE_PIPELINE == 1
        std::vector<std::shared_future<pos_retval_t>> _commit_threads;
        std::shared_future<pos_retval_t> _new_commit_thread;
    #endif

        typename std::map<pos_resource_typeid_t, std::set<POSHandle*>>::iterator map_iter;
        typename std::set<POSHandle*>::iterator set_iter;

        POS_CHECK_POINTER(cxt);

        if(unlikely(_ckpt_stream == nullptr)){
            POS_ASSERT(cudaSuccess == cudaStreamCreate(&_ckpt_stream));
        }

    #if POS_CKPT_ENABLE_PIPELINE == 1
        if(unlikely(_ckpt_commit_stream == nullptr)){
            POS_ASSERT(cudaSuccess == cudaStreamCreate(&_ckpt_commit_stream));
        }
    #endif

        POS_CHECK_POINTER(wqe = cxt->wqe);

        wqe->nb_ckpt_handles = 0;
        wqe->ckpt_size = 0;
        wqe->nb_abandon_handles = 0;
        wqe->abandon_ckpt_size = 0;
        wqe->ckpt_memory_consumption = 0;
        
        for(set_iter=wqe->checkpoint_handles.begin(); set_iter!=wqe->checkpoint_handles.end(); set_iter++){
            POSHandle *handle = *set_iter;
            POS_CHECK_POINTER(handle);

            if(unlikely(cxt->checkpoint_version_map.count(handle) == 0)){
                POS_WARN_C("failed to checkpoint handle, no checkpoint version provided: client_addr(%p)", handle->client_addr);
                continue;
            }

            checkpoint_version = cxt->checkpoint_version_map[handle];

        #if POS_CKPT_ENABLE_PIPELINE == 1
            retval = handle->checkpoint_pipeline_add_async(
                /* version_id */ checkpoint_version,
                /* stream_id */ (uint64_t)(_ckpt_stream)
            );
            POS_ASSERT(retval == POS_SUCCESS);
            /*!
             *  \note   we wait until the checkpoint of this handle to be completed here, so then we can judge whether
             *          we should invalidate this checkpoint
             */
            cuda_rt_retval = cudaStreamSynchronize(_ckpt_stream);
            if(unlikely(cuda_rt_retval != cudaSuccess)){
                POS_WARN_C("failed to synchronize after start checkpointing handle: client_addr(%p)", handle->client_addr);
                retval = POS_FAILED;
                goto exit;
            }
        #else
            retval = handle->checkpoint_async(
                /* version_id */ checkpoint_version,
                /* stream_id */ (uint64_t)(_ckpt_stream)
            );
            POS_ASSERT(retval == POS_SUCCESS);
            /*!
             *  \note   we wait until the checkpoint of this handle to be completed here, so then we can judge whether
             *          we should invalidate this checkpoint
             */
            cuda_rt_retval = cudaStreamSynchronize(_ckpt_stream);
            if(unlikely(cuda_rt_retval != cudaSuccess)){
                POS_WARN_C("failed to synchronize after start checkpointing handle: client_addr(%p)", handle->client_addr);
                retval = POS_FAILED;
                goto exit;
            }
        #endif
        
            if(unlikely(std::end(cxt->invalidated_handles) != std::find(cxt->invalidated_handles.begin(), cxt->invalidated_handles.end(), handle))){
                #if POS_CKPT_ENABLE_PIPELINE == 1
                    retval = handle->ckpt_bag->invalidate_by_version</* on_deivce */ true>(/* version */ checkpoint_version);
                #else
                    retval = handle->ckpt_bag->invalidate_by_version</* on_deivce */ false>(/* version */ checkpoint_version);
                #endif
                POS_ASSERT(retval == POS_SUCCESS);
                wqe->nb_abandon_handles += 1;
                wqe->abandon_ckpt_size += handle->state_size;
            } else {
                #if POS_CKPT_ENABLE_PIPELINE == 1
                    /*!
                     *  \note   if no invalidation happened, we can commit this checkpoint from device to host
                     */
                    _new_commit_thread = handle->spawn_checkpoint_pipeline_commit_thread(
                            /* version_id */ checkpoint_version,
                           /* stream_id */ (uint64_t)(_ckpt_commit_stream)
                    );
                    _commit_threads.push_back(_new_commit_thread);

                    // retval = handle->checkpoint_pipeline_commit_async(
                    //     /* version_id */ checkpoint_version,
                    //     /* stream_id */ (uint64_t)(_ckpt_commit_stream)
                    // );
                #endif
                wqe->nb_ckpt_handles += 1;
                wqe->ckpt_size += handle->state_size;
            }
        }

        #if POS_CKPT_ENABLE_PIPELINE == 1
            for(auto &commit_thread : _commit_threads){
                if(unlikely(POS_SUCCESS != commit_thread.get())){
                    POS_WARN_C("failure occured within the commit thread");
                }
            }

            /*!
             *  \note   we need to wait all commits to be finished
             */
            cuda_rt_retval = cudaStreamSynchronize(_ckpt_commit_stream);
            if(unlikely(cuda_rt_retval != cudaSuccess)){
                POS_WARN_C("failed to synchronize the commit stream: nb_ckpt_handles(%lu), nb_abandon_handles(%lu)", wqe->nb_ckpt_handles, wqe->nb_abandon_handles);
                retval = POS_FAILED;
                goto exit;
            }
        #endif

        POS_LOG(
            "checkpoint finished: #finished_handles(%lu), size(%lu Bytes), #abandoned_handles(%lu), size(%lu Bytes)",
            wqe->nb_ckpt_handles, wqe->ckpt_size, wqe->nb_abandon_handles, wqe->abandon_ckpt_size
        );

    exit:
        cxt->is_active = false;
    }

 private:
    /*!
     *  \brief  stream for overlapped memcpy while computing happens
     */
    cudaStream_t _ckpt_stream;  

    /*!
     *  \brief  stream for commiting checkpoint from device
     */
    cudaStream_t _ckpt_commit_stream;
    
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
            /* CUDA driver functions */
            {   rpc_cuModuleLoad,               wk_functions::cu_module_load::launch                    },
            {   rpc_cuModuleLoadData,           wk_functions::cu_module_load_data::launch               },
            {   rpc_cuModuleGetFunction,        wk_functions::cu_module_get_function::launch            },
            {   rpc_register_var,               wk_functions::cu_module_get_global::launch              },
            {   rpc_cuDevicePrimaryCtxGetState, wk_functions::cu_device_primary_ctx_get_state::launch   },
            {   rpc_cuLaunchKernel,             wk_functions::cuda_launch_kernel::launch                },
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
