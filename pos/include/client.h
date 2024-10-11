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
#pragma once

#include <iostream>
#include <map>
#include <set>

#include <stdint.h>
#include <assert.h>

class POSClient;

#include "pos/include/common.h"
#include "pos/include/worker.h"
#include "pos/include/parser.h"
#include "pos/include/handle.h"
#include "pos/include/dag.h"
#include "pos/include/transport.h"
#include "pos/include/migration.h"
#include "pos/include/utils/timestamp.h"

#define pos_get_client_typed_hm(client, resource_id, hm_type)  \
    (hm_type*)(client->handle_managers[resource_id])

/*!
 *  \brief  context of the client
 */
typedef struct pos_client_cxt {
    // api id of the checkpoint operation
    uint64_t checkpoint_api_id;

    // name of the job
    std::string job_name;

    // kernel meta path
    std::string kernel_meta_path;
    bool is_load_kernel_from_cache;

    // checkpoint file path (if any)
    std::string checkpoint_file_path;

    // indices of stateful handle type
    std::vector<uint64_t> stateful_handle_type_idx;
} pos_client_cxt_t;

#define POS_CLIENT_CXT_HEAD pos_client_cxt cxt_base;

/*!
 * \brief   status of POS client
 */
enum pos_client_status_t : uint8_t {
    kPOS_ClientStatus_CreatePending = 0,
    kPOS_ClientStatus_Active,
    kPOS_ClientStatus_Hang
};


/*!
 *  \brief  station to store the checkpointed data
 */
typedef struct pos_client_ckpt_station {
    std::vector<std::pair<void*, uint64_t>> __chunks;
    uint64_t byte_size;

    /*!
     *  \brief  clear this station
     */
    inline void clear(){
        uint64_t i;
        void *chunk;
        for(i=0; i<__chunks.size(); i++){
            POS_CHECK_POINTER(chunk = __chunks[i].first);
            free(chunk);
        }
        __chunks.clear();
        byte_size = 0;
    }

    /*!
     *  \brief  load value to this station
     *  \tparam T   type of the value to be load
     *  \param  val value to be load
     */
    template<typename T>
    inline void load_value(const T& val){
        void *chunk;
        POS_CHECK_POINTER(chunk = malloc(sizeof(T)));
        memcpy(chunk, &val, sizeof(T));
        __chunks.push_back(std::pair<void*,uint64_t>(chunk, sizeof(T)));
        byte_size += sizeof(T);
    }

    /*!
     *  \brief  load memory area via pointer to this station
     *  \param  area    pointer to the memory area to be loaded
     *  \param  size    size of the memory area to be loaded
     */
    inline void load_mem_area(void* area, uint64_t size){
        POS_CHECK_POINTER(area);
        __chunks.push_back(std::pair<void*,uint64_t>(area, size));
        byte_size += size;
    }

    /*!
     *  \brief  dump checkpoints to binary image file
     *  \param  file_path   path of the binary image file to be dumped
     *  \return POS_SUCCESS for successfully dumpping
     *          POS_FAILED for fail to open the file
     */
    inline pos_retval_t collapse_to_image_file(std::string& file_path){
        pos_retval_t retval = POS_SUCCESS;
        uint64_t i, chunk_size;
        void *chunk;
        std::ofstream output_file;
        
        output_file.open(file_path.c_str(), std::ios::binary);
        if(unlikely(output_file.is_open() == false)){
            POS_WARN("failed to collapse checkpoint to binary file: file_path(%s)", file_path.c_str());
            retval = POS_FAILED;
            goto exit;
        }

        for(i=0; i<__chunks.size(); i++){
            POS_CHECK_POINTER(chunk = __chunks[i].first);
            chunk_size = __chunks[i].second;
            output_file.write((const char*)(chunk), chunk_size);
        }

        output_file.flush();
        output_file.close();

    exit:
        return retval;
    }

    pos_client_ckpt_station() : byte_size(0) {}

} pos_client_ckpt_station_t;


/*!
 *  \brief  base state of a remote client
 */
class POSClient {
 public:
    /*!
     *  \param  id  client identifier
     *  \param  cxt context to initialize this client
     */
    POSClient(uint64_t id, pos_client_cxt_t cxt) 
        :   id(id),
            dag({ .checkpoint_api_id = cxt.checkpoint_api_id }),
            migration_ctx(this),
            status(kPOS_ClientStatus_CreatePending),
            _api_inst_pc(0), 
            _cxt(cxt),
            _last_ckpt_tick(0)
    {}

    POSClient() 
        :   id(0),
            dag({ .checkpoint_api_id = 0 }),
            migration_ctx(this),
            status(kPOS_ClientStatus_CreatePending),
            _last_ckpt_tick(0)
    {
        POS_ERROR_C("shouldn't call, just for passing compilation");
    }
    
    ~POSClient(){}
    

    /*!
     *  \brief  initialize of the client
     *  \note   this part can't be in the constructor as we will invoke functions
     *          that implemented by derived class
     */
    void init(){
        std::map<pos_vertex_id_t, POSAPIContext_QE_t*> apicxt_sequence_map;
        std::multimap<pos_vertex_id_t, POSHandle*> missing_handle_map;

        this->init_handle_managers();
        this->init_dag();

        if(this->_cxt.checkpoint_file_path.size() > 0){
            this->init_restore_load_resources();
            this->init_restore_generate_recompute_scheme(apicxt_sequence_map, missing_handle_map);
            this->init_restore_recreate_handles(apicxt_sequence_map, missing_handle_map);
        }
    }


    /*!
     *  \brief  deinit the client
     *  \note   this part can't be in the deconstructor as we will invoke functions
     *          that implemented by derived class
     */
    void deinit(){
        pos_retval_t tmp_retval;
        POSAPIContext_QE *ckpt_wqe;
        uint64_t s_tick, e_tick;

    #if POS_CKPT_OPT_LEVEL > 0
        // drain out both the parser and worker
        // TODO: the way to drain is not correct!
        // s_tick = POSUtilTimestamp::get_tsc();
        // this->dag.drain_by_dest_id(this->_api_inst_pc-1);
        // e_tick = POSUtilTimestamp::get_tsc();
        // POS_LOG("preempt checkpoint: drain(%lf us)", POS_TSC_TO_USEC(e_tick-s_tick));
    #endif

    #if POS_CKPT_OPT_LEVEL > 0
        // dump checkpoint to file
        // TODO: remember to decomment this!
        // if(this->_cxt.checkpoint_file_path.size() == 0){
        //     this->deinit_dump_checkpoints();
        // }
    #endif

        this->deinit_dump_handle_managers();

    exit:
        ;
    }
    

    /*!
     *  \brief  instantiate handle manager for all used resources
     *  \note   the children class should replace this method to initialize their 
     *          own needed handle managers
     */
    virtual void init_handle_managers(){}

    /*!
     *  \brief  initialization of the DAG
     *  \note   insert initial handles to the DAG (e.g., default CUcontext, CUStream, etc.)
     */
    virtual void init_dag(){}
    
    /*!
     *  \brief  initialization of transport utilities for migration  
     *  \return POS_SUCCESS for successfully initialization
     */
    virtual pos_retval_t init_transport(){}

    /*!
     *  \brief  restore resources from checkpointed file
     */
    void init_restore_load_resources();


    /*!
     *  \brief  generate recompute wqe sequence
     *  \param  apicxt_sequence_map     the generated recompute sequence
     *  \param  missing_handle_map      the generated all missing handles
     *  \todo   this algorithm need to be reconsidered
     */
    void init_restore_generate_recompute_scheme(
        std::map<pos_vertex_id_t, POSAPIContext_QE_t*>& apicxt_sequence_map,
        std::multimap<pos_vertex_id_t, POSHandle*>& missing_handle_map
    );


    /*!
     *  \brief  recreate handles and their state via reloading / recompute
     *  \param  apicxt_sequence_map     recompute sequence
     *  \param  missing_handle_map      all missing handles that need to be restored
     */
    void init_restore_recreate_handles(
        std::map<pos_vertex_id_t, POSAPIContext_QE_t*>& apicxt_sequence_map,
        std::multimap<pos_vertex_id_t, POSHandle*>& missing_handle_map
    );


    /*!
     *  \brief      deinit handle manager for all used resources
     *  \example    CUDA function manager should export the metadata of functions
     */
    virtual void deinit_dump_handle_managers(){}

    /*! 
     *  \brief  temp function used by migration
     */
    virtual void __TMP__migration_remote_malloc(){}
    virtual void __TMP__migration_precopy(){}
    virtual void __TMP__migration_deltacopy(){}
    virtual void __TMP__migration_tear_context(bool do_tear_module){}
    virtual void __TMP__migration_restore_context(bool do_restore_module){}
    virtual void __TMP__migration_ondemand_reload(){}
    virtual void __TMP__migration_allcopy(){}
    virtual void __TMP__migration_allreload(){}


    /*!
     *  \brief  get whether it's time to checkpoint this client
     *  \return the state identify whether it's time to checkpoint this client
     */
    inline bool is_time_for_ckpt(){
        bool retval = false;
        uint64_t current_tick = POSUtilTimestamp::get_tsc();

        if(unlikely(current_tick - this->_last_ckpt_tick >= POS_MESC_TO_TSC(POS_CKPT_INTERVAL))){
            retval = true;
            this->_last_ckpt_tick = current_tick;
        }

        return retval;
    }


    /*!
     *  \brief  dump checkpoints to file
     */
    void deinit_dump_checkpoints();


    /*!
     *  \brief  obtain the current pc, and update it
     *  \return the current pc
     */
    inline uint64_t get_and_move_api_inst_pc(){ _api_inst_pc++; return (_api_inst_pc-1); }
    
    
    /*!
     *  \brief  all hande managers of this client
     *  \note   key:    typeid of the resource represented by the handle
     *          value:  pointer to the corresponding hande manager
     */
    std::map<pos_resource_typeid_t, void*> handle_managers;

    // client identifier
    uint64_t id;

    // the execution dag
    POSDag dag;
    
    // context of migration
    POSMigrationCtx migration_ctx;

    pos_client_status_t status;

    // parser thread handle
    POSParser *parser;

    // worker thread handle
    POSWorker *worker;
    
 protected:
    // api instance pc
    uint64_t _api_inst_pc;

    // context to initialize this client
    pos_client_cxt_t _cxt;

    // transport endpoint
    POSTransport</* is_server */ false> *_transport;

    /*!
     *  \brief  allocate mocked resource in the handle manager according to given type
     *  \note   this function is used during restore phrase
     *  \param  type_id specified resource type index
     *  \param  bin_ptr pointer to the binary area
     *  \return POS_SUCCESS for successfully allocated
     */
    virtual pos_retval_t __allocate_typed_resource_from_binary(pos_resource_typeid_t type_id, void* bin_ptr){
        return POS_FAILED_NOT_IMPLEMENTED;
    }


    /*!
     *  \brief  obtain all resource type indices of this client
     *  \return all resource type indices of this client
     */
    virtual std::set<pos_resource_typeid_t> __get_resource_idx(){
        return std::set<pos_resource_typeid_t>();
    }

    
    /*!
     *  \brief  get handle manager by given resource index
     *  \param  rid    resource index
     *  \return specified handle manager
     */
    POSHandleManager<POSHandle>* __get_handle_manager_by_resource_id(pos_resource_typeid_t rid){
        if(unlikely(this->handle_managers.count(rid) == 0)){
            POS_ERROR_C_DETAIL(
                "no handle manager with specified type registered, this is a bug: type_id(%lu)", rid
            );
        }
        return static_cast<POSHandleManager<POSHandle>*>(this->handle_managers[rid]);
    }

 private:
    /*!
     *  \brief  station of the checkpoint data, might be dumpped to file, or transmit via network
     *          to other machine
     */
    pos_client_ckpt_station_t __ckpt_station;

    /*!
     *  \brief  last time to do ckpt of this client
     */
    uint64_t _last_ckpt_tick;

    /*!
     *  \brief  launch checkpoint ops to checkpoint all stateful resources
     *  \note   this function should be invoked during the preemption
     *  \param  the issued checkpoint wqe
     */
    pos_retval_t __preempt_checkpoint_all_resource(POSAPIContext_QE **ckpt_wqe){
        pos_retval_t retval = POS_SUCCESS;
        POSHandleManager<POSHandle> *hm;
        uint64_t nb_handles, i;
        POSHandle *handle;

        POS_CHECK_POINTER(ckpt_wqe);
        *ckpt_wqe = new POSAPIContext_QE_t(
            /* api_id*/ this->_cxt.checkpoint_api_id,
            /* client */ this
        );
        POS_CHECK_POINTER(*ckpt_wqe);

        retval = this->dag.launch_op(*ckpt_wqe);

    exit:
        return retval;
    }
};
