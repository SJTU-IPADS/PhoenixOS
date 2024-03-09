#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <memory>

#include <string.h>
#include <stdint.h>
#include <assert.h>

#include "pos/include/common.h"
#include "pos/include/log.h"
#include "pos/include/utils/timestamp.h"
#include "pos/include/utils/serializer.h"
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

    // overall size of all parameters
    uint64_t overall_param_size;

    // pointer to the area to store the return result
    void *ret_data;

    // return code of the API
    int return_code;

    uint64_t retval_size;

    /*!
     *  \brief  obtain serialize size of current api context
     *  \return serialize size of current api context
     */
    inline uint64_t get_serialize_size(){
        uint64_t nb_params;

        nb_params = params.size();

        return (
            /* api id */        sizeof(uint64_t)
            /* nb_params */     + sizeof(uint64_t)
            /* param_sizes */   + nb_params * sizeof(uint64_t)
            /* param_data */    + overall_param_size
        );
    }

    /*!
     *  \brief  serialize the current current api context into the binary area
     *  \param  serialized_area  pointer to the binary area
     */
    inline void serialize(void* serialized_area){
        void *ptr = serialized_area;
        uint64_t i, nb_params;
        POSAPIParam_t *param;

        POS_CHECK_POINTER(ptr);

        nb_params = params.size();

        POSUtil_Serializer::write_field(&ptr, &(api_id), sizeof(uint64_t));
        POSUtil_Serializer::write_field(&ptr, &(nb_params), sizeof(uint64_t));

        for(i=0; i<nb_params; i++){
            POS_CHECK_POINTER(param = params[i]);
            POSUtil_Serializer::write_field(&ptr, &(param->param_size), sizeof(uint64_t));
            POSUtil_Serializer::write_field(&ptr, param->param_value, param->param_size);
        }
    }

    /*!
     *  \brief  constructor
     *  \param  id              index of the called API
     *  \param  param_desps     descriptors of all involved parameters
     *  \param  ret_data_       pointer to the memory area that store the returned value
     *  \param  retval_size_    size of the return value
     */
    POSAPIContext(uint64_t id, std::vector<POSAPIParamDesp_t>& param_desps, void* ret_data_=nullptr, uint64_t retval_size_=0) 
        : api_id(id), ret_data(ret_data_), retval_size(retval_size_)
    {
        POSAPIParam_t *param;

        overall_param_size = 0;
        params.reserve(16);

        // insert parameters
        for(auto& param_desp : param_desps){
            POS_CHECK_POINTER(param = new POSAPIParam_t(param_desp.value, param_desp.size));
            params.push_back(param);
            overall_param_size += param_desp.size;
        }
    }

    /*!
     *  \brief  constructor
     *  \note   this constructor is for checkpointing ops
     *  \param  id  specialized API index of the checkpointing op
     */
    POSAPIContext(uint64_t id) : api_id(id), overall_param_size(0) {}

    ~POSAPIContext(){
        for(auto param : params){ POS_CHECK_POINTER(param); delete param; }
    }
} POSAPIContext_t;


/*!
 *  \brief  view of the api instance to use the handle
 */
typedef struct POSHandleView {
    // pointer to the used handle
    POSHandle *handle;

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
     *  \brief  obtain serialize size of handle view
     *  \return serialize size of handle view
     */
    static inline uint64_t get_serialize_size(){
        return (
            /* handle_dag_id */ sizeof(pos_vertex_id_t)
            /* param_index */   + sizeof(uint64_t)
            /* offset */        + sizeof(uint64_t)
        );
    }

    /*!
     *  \brief  serialize the current handle view into the binary area
     *  \param  serialized_area  pointer to the binary area
     */
    inline void serialize(void* serialized_area){
        void *ptr = serialized_area;
        POS_CHECK_POINTER(ptr);

        POS_CHECK_POINTER(handle);

        POSUtil_Serializer::write_field(&ptr, &(handle->dag_vertex_id), sizeof(pos_vertex_id_t));
        POSUtil_Serializer::write_field(&ptr, &(param_index), sizeof(uint64_t));
        POSUtil_Serializer::write_field(&ptr, &(offset), sizeof(uint64_t));
    }

    /*!
     *  \brief  constructor
     *  \param  handle_             pointer to the handle which is view targeted on
     *  \param  param_index_        index of the corresponding parameter of this handle view
     *  \param  offset_             offset from the base address of the handle
     */
    POSHandleView(
        POSHandle* handle_, uint64_t param_index_ = 0, uint64_t offset_ = 0
    ) : handle(handle_), param_index(param_index_), offset(offset_){}
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
    POSAPIContext *api_cxt;
    
    // execution status of the API call
    pos_api_execute_status_t status;

    // id of the DAG vertex of this api instance (aka, op)
    pos_vertex_id_t dag_vertex_id;

    // all involved handle during the processing of this API instance
    std::vector<POSHandleView_t> input_handle_views;
    std::vector<POSHandleView_t> output_handle_views;
    std::vector<POSHandleView_t> create_handle_views;
    std::vector<POSHandleView_t> delete_handle_views;
    std::vector<POSHandleView_t> inout_handle_views;

    // flatten recording of involved handles of this wqe (to accelerate launch_op)
    POSNeighborList_t dag_neighbors;

    /* =========== profiling fields =========== */
    uint64_t create_tick, return_tick;
    uint64_t runtime_s_tick, runtime_e_tick, worker_s_tick, worker_e_tick;
    uint64_t queue_len_before_parse;
    /* ======= end of profiling fields ======== */

    /* =========== checkpoint op specific fields =========== */
    // number of handles this checkpoint op checkpointed
    uint64_t nb_ckpt_handles;
    uint64_t nb_abandon_handles;

    // size of state this checkpoint op checkpointed
    uint64_t ckpt_size;
    uint64_t abandon_ckpt_size;

    // checkpoint memory consumption after this checkpoint op
    uint64_t ckpt_memory_consumption;

    // handles that will be checkpointed by this checkpoint op
    // std::map<pos_resource_typeid_t, std::set<POSHandle*>> checkpoint_handles;
    std::set<POSHandle*> checkpoint_handles;

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
        uint64_t api_id, pos_client_uuid_t uuid, std::vector<POSAPIParamDesp_t>& param_desps,
        uint64_t inst_id, void* retval_data, uint64_t retval_size, void* pos_client, void* pos_transport
    ) : client_id(uuid), client(pos_client), transport(pos_transport),
        status(kPOS_API_Execute_Status_Init), dag_vertex_id(0), api_inst_id(inst_id)
    {
        POS_CHECK_POINTER(pos_client);
        api_cxt = new POSAPIContext_t(api_id, param_desps, retval_data, retval_size);
        POS_CHECK_POINTER(api_cxt);
        create_tick = POSUtilTimestamp::get_tsc();
        runtime_s_tick = runtime_e_tick = worker_s_tick = worker_e_tick = 0;

        // initialization of checkpoint op specific fields
        nb_ckpt_handles = 0;
        nb_abandon_handles = 0;
        ckpt_size = 0;
        abandon_ckpt_size = 0;
        ckpt_memory_consumption = 0;

        // reserve space
        input_handle_views.reserve(5);
        output_handle_views.reserve(5);
        inout_handle_views.reserve(5);
        create_handle_views.reserve(1);
        delete_handle_views.reserve(1);
        dag_neighbors.reserve(5);
    }
    
    /*!
     *  \brief  constructor
     *  \note   this constructor is for checkpointing ops
     *  \param  api_id              specialized API index of the checkpointing op
     *  \param  pos_client          pointer to the POSClient instance
     */
    POSAPIContext_QE(uint64_t api_id, void* pos_client) : client(pos_client) {
        api_cxt = new POSAPIContext_t(api_id);
        POS_CHECK_POINTER(api_cxt);

        // initialization of checkpoint op specific fields
        nb_ckpt_handles = 0;
        nb_abandon_handles = 0;
        ckpt_size = 0;
        abandon_ckpt_size = 0;
        ckpt_memory_consumption = 0;
    }

    /*!
     *  \brief  deconstructor
     */
    ~POSAPIContext_QE(){
        // TODO: release handle views
    }
    
    /*!
     *  \brief  obtain the size of serialize area of this api conetxt
     *  \return size of serialize area of this api conetxt
     */
    inline uint64_t get_serialize_size(){
        uint64_t nb_handle_views = 0;
            
        nb_handle_views += input_handle_views.size();
        nb_handle_views += output_handle_views.size();
        nb_handle_views += inout_handle_views.size();
        nb_handle_views += create_handle_views.size();
        nb_handle_views += delete_handle_views.size();

        POS_CHECK_POINTER(api_cxt);

        return (
            // part 1: base field
            /* dag_vertex_id */             sizeof(pos_vertex_id_t)

            // part 2: api context
            /* api context */               + api_cxt->get_serialize_size()

            // part 3: handle views
            /* nb of input handle views */  + sizeof(uint64_t)
            /* nb of output handle views */ + sizeof(uint64_t)
            /* nb of inout handle views */  + sizeof(uint64_t)
            /* nb of create handle views */ + sizeof(uint64_t)
            /* nb of delete handle views */ + sizeof(uint64_t)
            /* handle_views */              + nb_handle_views * POSHandleView_t::get_serialize_size()
        );
    }

    /*!
     *  \brief  serialize this api context
     *  \param  serialized_area pointer to the area that stores the serialized data
     */
    inline void serialize(void** serialized_area){
        void *ptr;

        // serialize one type of handle views
        auto __serialize_handle_views = [](void** ptr, std::vector<POSHandleView_t>& hv_vector){
            uint64_t nb_handle_views;
            nb_handle_views = hv_vector.size();

            POSUtil_Serializer::write_field(ptr, &(nb_handle_views), sizeof(uint64_t));
            for(auto &hv : hv_vector){
                hv.serialize(*ptr);
                (*ptr) += POSHandleView_t::get_serialize_size();
            }
        };

        POS_CHECK_POINTER(serialized_area);

        uint64_t allocate_size = get_serialize_size();
        
        *serialized_area = malloc(allocate_size);
        POS_CHECK_POINTER(*serialized_area);
        
        ptr = *serialized_area;

        // part 1: base field
        POSUtil_Serializer::write_field(&ptr, &(dag_vertex_id), sizeof(pos_vertex_id_t));

        // part 2: serialize api context
        api_cxt->serialize(ptr);
        ptr += api_cxt->get_serialize_size();

        // part 3: serialize handle views
        __serialize_handle_views(&ptr, input_handle_views);
        __serialize_handle_views(&ptr, output_handle_views);
        __serialize_handle_views(&ptr, inout_handle_views);
        __serialize_handle_views(&ptr, create_handle_views);
        __serialize_handle_views(&ptr, delete_handle_views);
    }

    /*!
     *  \brief  record involved handles of this API instance
     *  \param  id              type id of the involved handle
     *  \param  handle_view     view of the API instance to use this handle
     */
    template<pos_edge_direction_t dir>
    inline void record_handle(POSHandleView_t&& handle_view){
        if constexpr (dir == kPOS_Edge_Direction_In){
            input_handle_views.emplace_back(handle_view);
            dag_neighbors.push_back({.d_vid = handle_view.handle->dag_vertex_id, .dir = kPOS_Edge_Direction_In});
        } else if (dir == kPOS_Edge_Direction_Out){
            output_handle_views.emplace_back(handle_view);
            dag_neighbors.push_back({.d_vid = handle_view.handle->dag_vertex_id, .dir = kPOS_Edge_Direction_Out});
        } else if (dir == kPOS_Edge_Direction_Create){
            create_handle_views.emplace_back(handle_view);
            dag_neighbors.push_back({.d_vid = handle_view.handle->dag_vertex_id, .dir = kPOS_Edge_Direction_Create});
        } else if (dir == kPOS_Edge_Direction_Delete){
            delete_handle_views.emplace_back(handle_view);
            dag_neighbors.push_back({.d_vid = handle_view.handle->dag_vertex_id, .dir = kPOS_Edge_Direction_Delete});
        } else { // inout
            inout_handle_views.emplace_back(handle_view);
            dag_neighbors.push_back({.d_vid = handle_view.handle->dag_vertex_id, .dir = kPOS_Edge_Direction_InOut});
        }
    }

    /*!
     *  \brief  record all handles that need to be checkpointed within this checkpoint op
     *  \param  id          resource type index
     *  \param  handle_set  sets of handles
     */
    inline void record_checkpoint_handles(std::set<POSHandle*>& handle_set){
        checkpoint_handles.insert(handle_set.begin(), handle_set.end());
    }

    /*!
     *  \brief  obtain involved handles with specified direction
     *  \param  dir     expected direction
     *  \param  handles pointer to a list that stores the results
     */
    inline void get_handles_by_dir(pos_edge_direction_t dir, std::vector<POSHandle*> *handles){
        POS_ERROR_C_DETAIL("not implemented");
    }

} POSAPIContext_QE_t;

#define pos_api_output_handle(qe_ptr, index)            \
    (qe_ptr->output_handle_views[index].handle)

#define pos_api_input_handle(qe_ptr, index)             \
    (qe_ptr->input_handle_views[index].handle)

#define pos_api_create_handle(qe_ptr, index)            \
    (qe_ptr->create_handle_views[index].handle)

#define pos_api_delete_handle(qe_ptr, index)            \
    (qe_ptr->delete_handle_views[index].handle)

#define pos_api_inout_handle(qe_ptr, index)            \
    (qe_ptr->inout_handle_views[index].handle)
