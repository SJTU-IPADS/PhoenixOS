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
        : POSWorker<T_POSTransport, POSClient_CUDA>(ws), _ckpt_stream(nullptr) {}
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
            hm = client->handle_managers[stateful_handle_id];
            POS_CHECK_POINTER(hm);
            nb_handles = hm->get_nb_handles();
            for(i=0; i<nb_handles; i++){
                handle = hm->get_handle_by_id(i);
                POS_CHECK_POINTER(handle);

                retval = handle->checkpoint(
                    /* version_id */ wqe->dag_vertex_id,
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
            hm = client->handle_managers[stateful_handle_id];
            POS_CHECK_POINTER(hm);
            nb_handles = hm->get_nb_handles();
            for(i=0; i<nb_handles; i++){
                handle = hm->get_handle_by_id(i);
                POS_CHECK_POINTER(handle);
                wqe->ckpt_memory_consumption += handle->ckpt_bag->get_memory_consumption();
            }
        }

        return retval;
    }

    /*!
     *  \brief  level-1 optimizing implementation of the checkpoint procedure
     *  \note   this procedure checkpoints only those memory handles that been modified
     *          since last checkpointing
     * \param   wqe WQ element of the checkpoint op
     */
    pos_retval_t __checkpoint_sync_selective(POSAPIContext_QE* wqe) {
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

        for(map_iter=wqe->checkpoint_handles.begin(); map_iter!=wqe->checkpoint_handles.end(); map_iter++){
            std::set<POSHandle*>& target_set = map_iter->second;

            for(set_iter=target_set.begin(); set_iter!=target_set.end(); set_iter++){
                const POSHandle *handle = *set_iter;
                POS_CHECK_POINTER(handle);

                retval = handle->checkpoint(
                    /* version_id */ wqe->dag_vertex_id,
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
        // return __checkpoint_sync_naive(wqe); // singularity
        return __checkpoint_sync_selective(wqe);
    }

    /*!
     *  \brief  overlapped checkpoint procedure, should be implemented by each platform
     *  \note   this thread will be raised by level-2 ckpt
     *  \param  cxt     the context of this checkpointing
     */
    void checkpoint_async_thread(checkpoint_async_cxt_t* cxt) override {
        uint64_t i;
        cudaError_t cuda_rt_retval;
        pos_retval_t retval = POS_SUCCESS;
        POSAPIContext_QE *wqe;
        POSHandle *handle;

        typename std::map<pos_resource_typeid_t, std::set<POSHandle*>>::iterator map_iter;
        typename std::set<POSHandle*>::iterator set_iter;

        if(unlikely(_ckpt_stream == nullptr)){
            POS_ASSERT(cudaSuccess == cudaStreamCreate(&_ckpt_stream));
        }

        wqe = cxt->wqe;
        POS_CHECK_POINTER(wqe);

        wqe->nb_ckpt_handles = 0;
        wqe->ckpt_size = 0;
        wqe->ckpt_memory_consumption = 0;

        for(map_iter=wqe->checkpoint_handles.begin(); map_iter!=wqe->checkpoint_handles.end(); map_iter++){
            std::set<POSHandle*>& target_set = map_iter->second;

            for(set_iter=target_set.begin(); set_iter!=target_set.end(); set_iter++){
                const POSHandle *handle = *set_iter;
                POS_CHECK_POINTER(handle);

                retval = handle->checkpoint(
                    /* version_id */ wqe->dag_vertex_id,
                    /* stream_id */ (uint64_t)(_ckpt_stream)
                );
                if(unlikely(POS_SUCCESS != retval)){
                    POS_WARN_C("failed to checkpoint handle");
                    retval = POS_FAILED;
                    goto exit;
                }

                wqe->nb_ckpt_handles += 1;
                wqe->ckpt_size += handle->state_size;
            }
        }
        
        // make sure the checkpoint is finished
        cuda_rt_retval = cudaStreamSynchronize(_ckpt_stream);
        if(unlikely(cuda_rt_retval != cudaSuccess)){
            POS_WARN_C("failed to synchronize after checkpointing");
            retval = POS_FAILED;
            goto exit;
        }

    exit:
        POS_LOG("checkpoint finished: #handles(%lu), size(%lu Bytes)", wqe->nb_ckpt_handles, wqe->ckpt_size);
        cxt->is_active = false;
    }

 private:
    cudaStream_t _ckpt_stream;

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

        return POS_SUCCESS;
    }
};

#include "pos/cuda_impl/worker/base.h"
