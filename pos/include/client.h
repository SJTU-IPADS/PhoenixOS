#pragma once

#include <iostream>
#include <map>

#include <stdint.h>
#include <assert.h>

class POSClient;

#include "pos/include/common.h"
#include "pos/include/client.h"
#include "pos/include/handle.h"
#include "pos/include/dag.h"


/*!
 *  \brief  context of the client
 */
typedef struct pos_client_cxt {
    // api id of the checkpoint operation
    uint64_t checkpoint_api_id;
} pos_client_cxt_t;


#define POS_CLIENT_CXT_HEAD pos_client_cxt cxt_base;


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
            _api_inst_pc(0), 
            _cxt(cxt)
    {}

    POSClient() : id(0), dag({ .checkpoint_api_id = 0 }) {
        POS_ERROR_C("shouldn't call, just for passing compilation");
    }
    
    ~POSClient(){}
    
    /*!
     *  \brief  initialize of the client
     *  \note   this part can't be in the constructor as we will invoke functions
     *          that implemented by derived class
     */
    void init(){
        this->init_handle_managers();
        this->init_dag();
        this->init_restore_resources();
    }

    /*!
     *  \brief  deinit the client
     *  \note   this part can't be in the deconstructor as we will invoke functions
     *          that implemented by derived class
     */
    void deinit(){
        this->deinit_dump_handle_managers();

        // drain out the dag, and dump checkpoint to file
        this->dag.drain();
        this->deinit_dump_checkpoints();
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
    virtual void init_dag(){};

    /*!
     *  \brief  restore resources from checkpointed file
     */
    virtual void init_restore_resources(){}


    /*!
     *  \brief      deinit handle manager for all used resources
     *  \example    CUDA function manager should export the metadata of functions
     */
    virtual void deinit_dump_handle_managers(){}

    /*!
     *  \brief  dump checkpoints to file
     */
    virtual void deinit_dump_checkpoints(){}

    // client identifier
    uint64_t id;

    /*!
     *  \brief  all hande managers of this client
     *  \note   key:    typeid of the resource represented by the handle
     *          value:  pointer to the corresponding hande manager
     */
    std::map<pos_resource_typeid_t, void*> handle_managers;

    // the execution dag
    POSDag dag;

    /*!
     *  \brief  obtain the current pc, and update it
     *  \return the current pc
     */
    inline uint64_t get_and_move_api_inst_pc(){ _api_inst_pc++; return (_api_inst_pc-1); }

 protected:
    // api instance pc
    uint64_t _api_inst_pc;

    // context to initialize this client
    pos_client_cxt_t _cxt;
};

#define pos_get_client_typed_hm(client, resource_id, hm_type)  \
    (hm_type*)(client->handle_managers[resource_id])
