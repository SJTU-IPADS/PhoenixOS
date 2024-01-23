#pragma once

#include <iostream>
#include <map>

#include <stdint.h>
#include <assert.h>

class POSClient;

#include "pos/include/client.h"
#include "pos/include/handle.h"
#include "pos/include/dag.h"

/*!
 *  \brief  base state of a remote client
 */
class POSClient {
 public:
    /*!
     *  \param  id  client identifier
     */
    POSClient(uint64_t id) : id(id), _api_inst_pc(0), dag(id) {}

    POSClient() : id(0), dag(0) {}
    
    ~POSClient(){}
    
    /*!
     *  \brief  initialize of the client
     *  \note   this part can't be in the constructor as we will invoke functions
     *          that implemented by derived class
     */
    void init(){
        this->init_handle_managers();
        this->init_dag();
    }

    /*!
     *  \brief  deinit the client
     *  \note   this part can't be in the deconstructor as we will invoke functions
     *          that implemented by derived class
     */
    void deinit(){
        this->deinit_handle_managers();
    }

    /*!
     *  \brief  instantiate handle manager for all used resources
     *  \note   the children class should replace this method to initialize their 
     *          own needed handle managers
     */
    virtual void init_handle_managers(){}

    /*!
     *  \brief      deinit handle manager for all used resources
     *  \example    CUDA function manager should export the metadata of functions
     */
    virtual void deinit_handle_managers(){}

    /*!
     *  \brief  initialization of the DAG
     *  \note   insert initial handles to the DAG (e.g., default CUcontext, CUStream, etc.)
     */
    virtual void init_dag();

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
};
