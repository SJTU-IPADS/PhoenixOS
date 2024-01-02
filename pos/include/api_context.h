#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <string>

#include <string.h>
#include <stdint.h>
#include <assert.h>

#include "pos/include/common.h"
#include "pos/include/log.h"
#include "pos/include/utils/timestamp.h"
#include "pos/include/handle.h"
#include "pos/include/utils/bipartite_graph.h"

/*!
 *  \brief  type of api
 */
enum pos_api_type_t : uint8_t {
    /*!
     *  \brief      create XPU sofware/hardware resource
     *  \example    cudaMalloc, cudaCreateStream
     */
    kPOS_API_Type_Create_Resource = 0,

    /*!
     *  \brief      delete XPU sofware/hardware resource
     *  \example    cudaFree, cudaDestoryStream
     */
    kPOS_API_Type_Delete_Resource,

    /*!
     *  \brief      obtain the state of XPU resource
     *  \example    cudaMemcpy (D2H)
     */
    kPOS_API_Type_Get_Resource,

    /*!
     *  \brief      set the state of XPU resource
     *  \example    cudaMemcpy (H2D), cudaLaunchKernel
     */
    kPOS_API_Type_Set_Resource,

    /*!
     *  \brief      checkpoint XPU resource state
     */
    kPOS_API_Type_Checkpoint
};

/*!
 *  \brief  metadata of XPU API
 */
typedef struct POSAPIMeta {
    // whether this is a sync api
    bool is_sync;

    // type of the api
    pos_api_type_t api_type;

    // id of the destination located library (e.g., cuda rt, driver, cublas)
    uint8_t library_id;

    // name of the api
    std::string api_name;
} POSAPIMeta_t;

/*!
 *  \brief  manager of XPU APIs
 */
class POSApiManager {
 public:
    POSApiManager(){}
    ~POSApiManager() = default;

    /*!
     *  \brief  register metadata of all API on the platform to the manager
     */
    virtual void init();

    /*!
     *  \brief  translate POS retval to corresponding retval on the XPU platform
     *  \param  pos_retval  the POS retval to be translated
     *  \param  library_id  id of the destination library (e.g., cuda rt, driver, cublas)
     */
    virtual int cast_pos_retval(pos_retval_t pos_retval, uint8_t library_id);

    // map: api_id -> metadata of the api
    std::map<uint64_t, POSAPIMeta_t> api_metas;

 protected:
};

/*!
 *  \brief  execution state of an API instance
 */
enum pos_api_execute_status_t : uint8_t {
    kPOS_API_Execute_Status_Init = 0,
    kPOS_API_Execute_Status_Return_After_Parse,
    kPOS_API_Execute_Status_Parse_Failed,
    kPOS_API_Execute_Status_Launch_Failed
};

/*!
 *  \brief  descriptor of one parameter of an API call
 */
typedef struct POSAPIParam {
    // payload of the parameter
    void *param_value;

    // size of the parameter
    size_t param_size;

    /*!
     *  \brief  constructor
     *  \param  src_value   pointer to the actual value of the parameter
     *  \param  size        size of the parameter
     */
    POSAPIParam(void *src_value, size_t size) : param_size(size) {
        POS_CHECK_POINTER(param_value = malloc(size));
        memcpy(param_value, src_value, param_size);
    }

    /*!
     *  \brief  deconstructor
     */
    ~POSAPIParam(){
        POS_CHECK_POINTER(param_value); free(param_value);
    }
} POSAPIParam_t;

/*!
 *  \brief  macro to obtain parameter value of an API instance by given index,
 *          and cast to corresponding type
 */
#define pos_api_param_value(qe_ptr, index, type)                \
    (*((type*)(qe_ptr->api_cxt->params[index]->param_value)))

#define pos_api_param_addr(qe_ptr, index)           \
    (qe_ptr->api_cxt->params[index]->param_value)

#define pos_api_param_size(qe_ptr, index)           \
    (qe_ptr->api_cxt->params[index]->param_size)

/*!
 *  \brief  descriptor of one parameter of an API call
 */
typedef struct POSAPIParamDesp { void *value; size_t size; } POSAPIParamDesp_t;

/*!
 *  \brief  context of an API call
 */
typedef struct POSAPIContext {
    // index of the called API
    uint64_t api_id;

    // parameter list of the called API
    std::vector<POSAPIParam_t*> params;

    // pointer to the area to store the return result
    void *ret_data;

    // return code of the API
    int return_code;

    uint64_t retval_size;

    /*!
     *  \brief  constructor
     *  \param  id              index of the called API
     *  \param  param_desps     descriptors of all involved parameters
     *  \param  ret_data_       pointer to the memory area that store the returned value
     *  \param  retval_size_    size of the return value
     */
    POSAPIContext(uint64_t id, std::vector<POSAPIParamDesp_t> param_desps, void* ret_data_=nullptr, uint64_t retval_size_=0) 
        : api_id(id), ret_data(ret_data_), retval_size(retval_size_)
    {
        POSAPIParam_t *param;

        // insert parameters
        for(auto param_desp : param_desps){
            POS_CHECK_POINTER(param = new POSAPIParam_t(param_desp.value, param_desp.size));
            params.push_back(param);
        }
    }

    /*!
     *  \brief  constructor
     *  \note   this constructor is for checkpointing ops
     *  \param  id  specialized API index of the checkpointing op
     */
    POSAPIContext(uint64_t id) : api_id(id) {}

    ~POSAPIContext(){
        for(auto param : params){ POS_CHECK_POINTER(param); delete param; }
    }
} POSAPIContext_t;

using POSAPIContext_ptr = std::shared_ptr<POSAPIContext_t>;

/*!
 *  \brief  view of the api instance to use the handle
 */
typedef struct POSHandleView {
    // pointer to the used handle
    POSHandle_ptr handle;

    // direction to use this handle
    pos_edge_direction_t dir;

    /*!
     *  \brief  host-side new value of the resource behind this handle
     *  \note   for those APIs which bring new value to handle from the host-side,
     *          we need to cache the host-side value in case we would reply this
     *          API call later
     */
    POSMem_ptr host_value;
    uint64_t host_value_size;

    /*!
     *  \brief      index of the corresponding parameter of this handle view
     *  \example    for API such as launchKernel, we need to know which parameter this handle 
     *              is corresponding to, in order to translating the address in the worker 
     *              launching function
     */
    uint64_t param_index;

    /*!
     *  \brief      offset from the base address of the handle
     *  \example    for memory handle, the client might provide an non-base address, so we should
     *              record the offset here, so that we can obtain the correct server-side address
     *              within the worker launching function
     */
    uint64_t offset;

    /*!
     *  \brief  constructor
     *  \param  handle_             pointer to the handle which is view targeted on
     *  \param  dir_                direction of the view to use this handle
     *  \param  host_value_         new value of the resource behind this handle (optional)
     *  \param  host_value_size_    size of the host-side new value (optional)
     *  \param  param_index_        index of the corresponding parameter of this handle view
     *  \param  offset_             offset from the base address of the handle
     */
    POSHandleView(
        POSHandle_ptr handle_, pos_edge_direction_t dir_, 
        void* host_value_ = nullptr, uint64_t host_value_size_ = 0,
        uint64_t param_index_ = 0, uint64_t offset_ = 0
    ) : handle(handle_), dir(dir_), param_index(param_index_), offset(offset_)
    {
        if(unlikely(host_value_ != nullptr && host_value_size_ > 0)){
            /*!
             *  \note   seems it's ok to use std::make_unique to allocate a shared_ptr
             *          that point to an array
             *  \ref    https://stackoverflow.com/a/47202220
             */
            host_value = std::make_unique<uint8_t[]>(host_value_size_);
            POS_CHECK_POINTER(host_value);
            memcpy(host_value.get(), host_value_, host_value_size_);
        }
        host_value_size = host_value_size_;
    }

} POSHandleView_t;

/*!
 *  \brief  work queue element, as the element within work 
 *          queue between frontend and runtime
 */
typedef struct POSAPIContext_QE {
    // uuid of the remote client
    pos_client_uuid_t client_id;

    // pointer to the POSClient instance
    void *client;

    // pointer to the POSTransport instance
    void *transport;

    // uuid of this API call instance within the client
    uint64_t api_inst_id;

    // context of the called API
    POSAPIContext_ptr api_cxt;

    // timestamp of the api call
    uint64_t create_tick, return_tick;
    uint64_t runtime_s_tick, runtime_e_tick, worker_s_tick, worker_e_tick;

    // execution status of the API call
    pos_api_execute_status_t status;

    // id of the DAG vertex of this api instance (aka, op)
    pos_vertex_id_t dag_vertex_id;

    // all involved handle during the processing of this API instance
    std::map<pos_resource_typeid_t, std::vector<POSHandleView_t>*> handle_view_map;

    /* =========== checkpoint op specific fields =========== */
    uint64_t nb_ckpt_handles;
    uint64_t ckpt_size;
    uint64_t ckpt_memory_consumption;
    /* ======= end of checkpoint op specific fields ======== */

    /*!
     *  \brief  constructor
     *  \param  api_id          index of the called API
     *  \param  uuid            uuid of the remote client
     *  \param  param_desps     description of all parameters of the call
     *  \param  inst_id         uuid of this API call instance within the client
     *  \param  retval_data     pointer to the memory area that store the returned value
     *  \param  retval_size     size of the return value
     *  \param  pos_client      pointer to the POSClient instance
     *  \param  pos_transport   pointer to the POSTransport instance
     */
    POSAPIContext_QE(
        uint64_t api_id, pos_client_uuid_t uuid, std::vector<POSAPIParamDesp_t> param_desps,
        uint64_t inst_id, void* retval_data, uint64_t retval_size, void* pos_client, void* pos_transport
    ) : client_id(uuid), client(pos_client), transport(pos_transport),
        status(kPOS_API_Execute_Status_Init), dag_vertex_id(0), api_inst_id(inst_id)
    {
        POS_CHECK_POINTER(pos_client);
        api_cxt = std::make_shared<POSAPIContext_t>(api_id, param_desps, retval_data, retval_size);
        POS_CHECK_POINTER(api_cxt);
        create_tick = POSUtilTimestamp::get_tsc();
        runtime_s_tick = runtime_e_tick = worker_s_tick = worker_e_tick = 0;

        // initialization of checkpoint op specific fields
        nb_ckpt_handles = 0;
        ckpt_size = 0;
        ckpt_memory_consumption = 0;
    }
    
    /*!
     *  \brief  constructor
     *  \note   this constructor is for checkpointing ops
     *  \param  api_id              specialized API index of the checkpointing op
     *  \param  pos_client          pointer to the POSClient instance
     *  \param  dag_vertex_id       reuse the previous op's dag_vertex_id
     */
    POSAPIContext_QE(
        uint64_t api_id,
        void* pos_client,
        uint64_t dag_vertex_id_
    )
        : client(pos_client), dag_vertex_id(dag_vertex_id_)
    {
        api_cxt = std::make_shared<POSAPIContext_t>(api_id);
        POS_CHECK_POINTER(api_cxt);
    }

    /*!
     *  \brief  deconstructor
     */
    ~POSAPIContext_QE(){
        std::map<pos_resource_typeid_t, std::vector<POSHandleView_t>*>::iterator iter;
        for(iter = handle_view_map.begin(); iter != handle_view_map.end(); iter++){
            if(likely(iter->second != nullptr)){ delete iter->second; }
        }

        // we debug here to make sure the POSAPIContext_QE is released on time, avoiding memory leak
        // POS_DEBUG_C(
        //     "released: client_id(%lu), api_inst_id(%lu), api_id(%lu)",
        //     client_id, api_inst_id, api_cxt->api_id
        // );
    }

    /*!
     *  \brief  record involved handles of this API instance
     *  \param  id              type id of the involved handle
     *  \param  handle_view     view of the API instance to use this handle
     */
    inline void record_handle(pos_resource_typeid_t id, POSHandleView_t handle_view){
        std::vector<POSHandleView_t>* dst_handle_vec;

        if(handle_view_map.count(id) == 0){
            dst_handle_vec = new std::vector<POSHandleView_t>();
            POS_CHECK_POINTER(dst_handle_vec);
            handle_view_map[id] = dst_handle_vec;
        } else {
            dst_handle_vec = handle_view_map[id];
        }

        dst_handle_vec->push_back(handle_view);
    }

    /*!
     *  \brief  obtain involved handles with specified direction
     *  \param  dir     expected direction
     *  \param  handles pointer to a list that stores the results
     */
    inline void get_handles_by_dir(pos_edge_direction_t dir, std::vector<POSHandle_ptr> *handles){
        uint64_t i;
        std::vector<POSHandleView_t>* vecs;
        typename std::map<pos_resource_typeid_t, std::vector<POSHandleView_t>*>::iterator iter;

        POS_CHECK_POINTER(handles);

        for(iter=handle_view_map.begin(); iter!=handle_view_map.end(); iter++){
            POS_CHECK_POINTER(vecs = iter->second);
            for(i=0; i<vecs->size(); i++){
                if((*vecs)[i].dir == dir){
                    handles->push_back(((*vecs)[i]).handle);
                }
            }
        }
    }

} POSAPIContext_QE_t;

#define pos_api_handle(qe_ptr, typeid, index)                                   \
    (((*(qe_ptr->handle_view_map[typeid]))[index]).handle)

#define pos_api_typed_handle(qe_ptr, typeid, cast_type, index)                  \
    std::dynamic_pointer_cast<cast_type>(pos_api_handle(qe_ptr, typeid, index))

#define pos_api_handle_view(qe_ptr, typeid, index)                              \
    ((*(qe_ptr->handle_view_map[typeid]))[index])

using POSAPIContext_QE_ptr = std::shared_ptr<POSAPIContext_QE_t>;
