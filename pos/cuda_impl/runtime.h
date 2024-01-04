#pragma once

#include <cuda_runtime_api.h>

#include "pos/include/common.h"
#include "pos/include/workspace.h"
#include "pos/include/client.h"
#include "pos/include/transport.h"
#include "pos/include/runtime.h"
#include "pos/cuda_impl/client.h"

#include "pos/cuda_impl/api_index.h"

namespace rt_functions {
    /* CUDA runtime functions */
    POS_RT_DECLARE_FUNCTIONS(cuda_malloc);
    POS_RT_DECLARE_FUNCTIONS(cuda_free);
    POS_RT_DECLARE_FUNCTIONS(cuda_launch_kernel);
    POS_RT_DECLARE_FUNCTIONS(cuda_memcpy_h2d);
    POS_RT_DECLARE_FUNCTIONS(cuda_memcpy_d2h);
    POS_RT_DECLARE_FUNCTIONS(cuda_memcpy_d2d);
    POS_RT_DECLARE_FUNCTIONS(cuda_memcpy_h2d_async);
    POS_RT_DECLARE_FUNCTIONS(cuda_memcpy_d2h_async);
    POS_RT_DECLARE_FUNCTIONS(cuda_memcpy_d2d_async);
    POS_RT_DECLARE_FUNCTIONS(cuda_set_device);
    POS_RT_DECLARE_FUNCTIONS(cuda_get_last_error);
    POS_RT_DECLARE_FUNCTIONS(cuda_get_error_string);
    POS_RT_DECLARE_FUNCTIONS(cuda_get_device_count);
    POS_RT_DECLARE_FUNCTIONS(cuda_get_device_properties);
    POS_RT_DECLARE_FUNCTIONS(cuda_get_device);
    POS_RT_DECLARE_FUNCTIONS(cuda_stream_synchronize);
    POS_RT_DECLARE_FUNCTIONS(cuda_stream_is_capturing);
    POS_RT_DECLARE_FUNCTIONS(cuda_event_create_with_flags);
    POS_RT_DECLARE_FUNCTIONS(cuda_event_destory);
    POS_RT_DECLARE_FUNCTIONS(cuda_event_record);
    
    /* CUDA driver functions */
    POS_RT_DECLARE_FUNCTIONS(cu_module_load_data);
    POS_RT_DECLARE_FUNCTIONS(cu_module_get_function);
    POS_RT_DECLARE_FUNCTIONS(cu_module_get_global);
    POS_RT_DECLARE_FUNCTIONS(cu_device_primary_ctx_get_state);    

    /* cuBLAS functions */
    POS_RT_DECLARE_FUNCTIONS(cublas_create);
    POS_RT_DECLARE_FUNCTIONS(cublas_set_stream);
    POS_RT_DECLARE_FUNCTIONS(cublas_set_math_mode);
    POS_RT_DECLARE_FUNCTIONS(cublas_sgemm);
} // namespace rt_functions

/*!
 *  \brief  POS Runtime (CUDA Implementation)
 *  \note   1. Parser:      parsing each API call, translate virtual handles to physicall handles;
 *          2. DAG:         maintainance of launch flow for checkpoint/restore and scheduling;
 *          3. Scheduler:   launch unfinished / previously-failed call to worker
 */
template<class T_POSTransport>
class POSRuntime_CUDA : public POSRuntime<T_POSTransport, POSClient_CUDA> {
 public:
    POSRuntime_CUDA(POSWorkspace<T_POSTransport, POSClient_CUDA>* ws)
        : POSRuntime<T_POSTransport, POSClient_CUDA>(ws){}
    ~POSRuntime_CUDA() = default;

 private:
    /*!
     *  \brief      initialization of the runtime daemon thread
     *  \example    for CUDA, one need to call API e.g. cudaSetDevice first to setup the context for a thread
     */
    pos_retval_t daemon_init() override {
        // /*!
        //  *  \note   make sure the worker thread is bound to a CUDA context
        //  *          if we don't do this and use the driver API, it might be unintialized
        //  */
        // if(cudaSetDevice(0) != cudaSuccess){
        //     POS_WARN_C_DETAIL("runtime thread failed to invoke cudaSetDevice");
        //     return POS_FAILED; 
        // }
        // cudaDeviceSynchronize();
        return POS_SUCCESS; 
    }

    /*!
     *  \brief  insertion of parse and dag functions
     *  \return POS_SUCCESS for succefully insertion
     */
    pos_retval_t init_rt_functions() override {
        this->_parser_functions.insert({
            /* CUDA runtime functions */
            {   CUDA_MALLOC,                    rt_functions::cuda_malloc::parse                        },
            {   CUDA_FREE,                      rt_functions::cuda_free::parse                          },
            {   CUDA_LAUNCH_KERNEL,             rt_functions::cuda_launch_kernel::parse                 },
            {   CUDA_MEMCPY_HTOD,               rt_functions::cuda_memcpy_h2d::parse                    },
            {   CUDA_MEMCPY_DTOH,               rt_functions::cuda_memcpy_d2h::parse                    },
            {   CUDA_MEMCPY_DTOD,               rt_functions::cuda_memcpy_d2d::parse                    },
            {   CUDA_MEMCPY_HTOD_ASYNC,         rt_functions::cuda_memcpy_h2d_async::parse              },
            {   CUDA_MEMCPY_DTOH_ASYNC,         rt_functions::cuda_memcpy_d2h_async::parse              },
            {   CUDA_MEMCPY_DTOD_ASYNC,         rt_functions::cuda_memcpy_d2d_async::parse              },
            {   CUDA_SET_DEVICE,                rt_functions::cuda_set_device::parse                    },
            {   CUDA_GET_LAST_ERROR,            rt_functions::cuda_get_last_error::parse                },
            {   CUDA_GET_ERROR_STRING,          rt_functions::cuda_get_error_string::parse              },
            {   CUDA_GET_DEVICE_COUNT,          rt_functions::cuda_get_device_count::parse              },
            {   CUDA_GET_DEVICE_PROPERTIES,     rt_functions::cuda_get_device_properties::parse         },
            {   CUDA_GET_DEVICE,                rt_functions::cuda_get_device::parse                    },
            {   CUDA_STREAM_SYNCHRONIZE,        rt_functions::cuda_stream_synchronize::parse            },
            {   CUDA_STREAM_IS_CAPTURING,       rt_functions::cuda_stream_is_capturing::parse           },
            {   CUDA_EVENT_CREATE_WITH_FLAGS,   rt_functions::cuda_event_create_with_flags::parse       },
            {   CUDA_EVENT_DESTROY,             rt_functions::cuda_event_destory::parse                 },
            {   CUDA_EVENT_RECORD,              rt_functions::cuda_event_record::parse                  },
            /* CUDA driver functions */
            {   rpc_cuModuleLoad,               rt_functions::cu_module_load_data::parse                },
            {   rpc_cuModuleGetFunction,        rt_functions::cu_module_get_function::parse             },
            {   rpc_register_var,               rt_functions::cu_module_get_global::parse               },
            {   rpc_cuDevicePrimaryCtxGetState, rt_functions::cu_device_primary_ctx_get_state::parse    },
            /* cuBLAS functions */
            {   rpc_cublasCreate,               rt_functions::cublas_create::parse                      },
            {   rpc_cublasSetStream,            rt_functions::cublas_set_stream::parse                  },
            {   rpc_cublasSetMathMode,          rt_functions::cublas_set_math_mode::parse               },
            {   rpc_cublasSgemm,                rt_functions::cublas_sgemm::parse                       }
        });
        POS_DEBUG_C("insert %lu runtime parse functions", this->_parser_functions.size());

        return POS_SUCCESS;
    }

    /*!
     *  \brief  naive implementation of checkpoint insertion procedure
     *  \note   this implementation naively insert a checkpoint op to the dag, 
     *          without any optimization hint
     *  \param  wqe the exact WQ element before inserting checkpoint op
     *  \return POS_SUCCESS for successfully checkpoint insertion
     */
    pos_retval_t __checkpoint_insertion_naive(POSAPIContext_QE_ptr wqe) { 
        pos_retval_t retval = POS_SUCCESS;
        POSHandle_ptr handle;
        POSAPIContext_QE_ptr ckpt_wqe;

        ckpt_wqe = std::make_shared<POSAPIContext_QE>(
            /* api_id*/ this->_ws->checkpoint_api_id,
            /* client */ wqe->client,
            /* dag_vertex_id_ */ wqe->dag_vertex_id
        );
        POS_CHECK_POINTER(ckpt_wqe);
        retval = ((POSClient*)wqe->client)->dag.launch_op(ckpt_wqe);

    exit:
        return retval;
    }

    /*!
     *  \brief  level-1 optimization of checkpoint insertion procedure
     *  \note   this implementation give hints of those memory handles that
     *          been modified (INOUT/OUT) since last checkpoint
     *  \param  wqe the exact WQ element before inserting checkpoint op
     *  \return POS_SUCCESS for successfully checkpoint insertion
     */
    pos_retval_t __checkpoint_insertion_o1(POSAPIContext_QE_ptr wqe) {
        pos_retval_t retval = POS_SUCCESS;
        POSClient_CUDA *client;
        POSHandleManager<POSHandle>* hm;
        POSAPIContext_QE_ptr ckpt_wqe;
        uint64_t i;

        POS_CHECK_POINTER(wqe);

        client = (POSClient_CUDA*)(wqe->client);
        
        ckpt_wqe = std::make_shared<POSAPIContext_QE>(
            /* api_id*/ this->_ws->checkpoint_api_id,
            /* client */ wqe->client,
            /* dag_vertex_id_ */ wqe->dag_vertex_id
        );
        POS_CHECK_POINTER(ckpt_wqe);

        // we only checkpoint those resources that has been modified since last checkpoint
        for(auto &stateful_handle_id : this->_ws->stateful_handle_type_idx){
            hm = client->handle_managers[stateful_handle_id];
            POS_CHECK_POINTER(hm);
            std::vector<POSHandle_ptr>& modified_handles = hm->get_modified_handles(); 
            for(i=0; i<modified_handles.size(); i++){
                ckpt_wqe->record_handle(
                    stateful_handle_id, 
                    POSHandleView_t(modified_handles[i], kPOS_Edge_Direction_Out, 0)
                );
            }
            hm->clear_modified_handle();
            retval = ((POSClient*)wqe->client)->dag.launch_op(ckpt_wqe);
        }
        
    exit:
        return retval;
    }   

    /*!
     *  \brief  insert checkpoint op to the DAG based on certain conditions
     *  \param  wqe the exact WQ element before inserting checkpoint op
     *  \return POS_SUCCESS for successfully checkpoint insertion
     */
    pos_retval_t checkpoint_insertion(POSAPIContext_QE_ptr wqe) override {
        #if POS_CKPT_OPT_LEVAL == 1
            // return __checkpoint_insertion_naive(wqe);
            return __checkpoint_insertion_o1(wqe);
        #else // POS_CKPT_OPT_LEVAL == 0
            return POS_SUCCESS;
        #endif
    }
};

#include "pos/cuda_impl/runtime/base.h"
