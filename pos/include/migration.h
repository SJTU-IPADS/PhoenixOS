#pragma once

#include <iostream>
#include <thread>
#include <set>

#include "pos/include/common.h"
#include "pos/include/log.h"
#include "pos/include/dag.h"
#include "pos/include/handle.h"

enum pos_migration_stage_t : uint8_t {
    // ckpt
    kPOS_MigrationStage_Ease = 0,
    kPOS_MigrationStage_Init,
    kPOS_MigrationStage_Wait_Precopy,
    kPOS_MigrationStage_Block,

    // restore (tmp)
    kPOS_MigrationStage_RestoreCtx
};

class POSClient;

/*!
 *  \brief  context of migration job for transferring a client
 */
class POSMigrationCtx {
 public:

    POSMigrationCtx(POSClient* client) 
        : _client(client), _migration_stage(kPOS_MigrationStage_Ease), 
        _precopy_thread(nullptr), _is_precopy_thread_active(false),
        _ondemand_reload_thread(nullptr), _is_ondemand_reload_thread_active(false)
    {}

    /*!
     *  \brief  launch a migration job
     *  \param  remote_ipv4 IPv4 address of the destination POS server process
     *  \param  p2p_port    transportation port for P2P memcpy
     */
    inline void start(uint32_t remote_ipv4, uint32_t p2p_port){
        this->reset();

        this->_remote_ipv4 = remote_ipv4;
        this->_p2p_port = p2p_port;

        this->_migration_stage = kPOS_MigrationStage_Init;
    }

    inline void restore(){
        this->_migration_stage = kPOS_MigrationStage_RestoreCtx;
    }

    /*!
     *  \brief  reset this migration context
     */
    inline void reset(){
        this->_remote_ipv4 = 0;
        this->_p2p_port = 0;
        this->_is_precopy_thread_active = false;
        this->invalidated_handles.clear();
        this->precopy_handles.clear();

        this->_migration_stage = kPOS_MigrationStage_Ease;
    }

    /*!
     *  \brief  check whether current migration context is active
     */
    inline bool is_precopying(){ return _is_precopy_thread_active; }
    inline bool is_blocking() { return _migration_stage == kPOS_MigrationStage_Block; }
    inline bool is_ondemand_reloading() { return _is_ondemand_reload_thread_active; }

    /*!
     *  \brief  watch dog of this migration context, should be invoked within worker thread
     *  \param  pc  program counter value when call this watch dog
     *  \return POS_SUCCESS for succesfully corresponding processing
     *          POS_FAILED for failed corresponding processing
     *          POS_FAILED_NOT_READY for migration not enabled
     *          POS_WARN_BLOCKED for blocking worker thread
     */
    pos_retval_t watch_dog(pos_vertex_id_t pc);


    /* ========== pre-copy fields ========== */

    // all conflict handles during migration process
    std::set<POSHandle*> invalidated_handles;

    // handles that finished by precopies
    std::set<POSHandle*> precopy_handles;

    // all host-side stateful handles
    std::set<POSHandle*> __TMP__host_handles;

    /* ========== on-demand reload fields ========== */
    std::set<POSHandle*> odr_invalidated_handles;
    
 private:
    /* ====== common fields ====== */
    // client for this migration job
    POSClient *_client;

    // migration stage
    pos_migration_stage_t _migration_stage;

    // transport information
    uint32_t _remote_ipv4;
    uint32_t _p2p_port;
    
    // start pc of the precopy stage
    pos_vertex_id_t _precopy_start_pc;

    // thread handle for conducting pre-copy
    std::thread *_precopy_thread;
    bool _is_precopy_thread_active;
    
    std::thread *_ondemand_reload_thread;
    bool _is_ondemand_reload_thread_active;

    /* ====== trace fields ====== */

    /*!
     *  \brief  async thread for conducting precopy
     */
    void __precopy_async_thread();

    /*!
     *  \brief  async thread for on-demand reload
     */
    void __ondemand_reload_async_thread();
};
