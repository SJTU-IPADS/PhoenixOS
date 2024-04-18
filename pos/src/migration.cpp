#include <iostream>

#include "pos/include/common.h"
#include "pos/include/log.h"
#include "pos/include/client.h"
#include "pos/include/migration.h"
#include "pos/include/utils/timestamp.h"


/*!
 *  \brief  watch dog of this migration context, should be invoked within worker thread
 *  \param  pc  program counter value when call this watch dog
 *  \return POS_SUCCESS for succesfully corresponding processing
 *          POS_FAILED for failed corresponding processing
 *          POS_FAILED_NOT_READY for migration not enabled
 *          POS_WARN_BLOCKED for blocking worker thread
 */
pos_retval_t POSMigrationCtx::watch_dog(pos_vertex_id_t pc){
    pos_retval_t retval = POS_FAILED_NOT_READY;
    
    uint64_t eff_nb_precopy_handles = 0, eff_precopy_size = 0, all_precopy_size = 0;
    uint64_t eff_nb_deltacopy_handles = 0, eff_deltacopy_size = 0, all_deltacopy_size = 0;
    uint64_t s_tick, e_tick;

    typename std::set<POSHandle*>::iterator set_iter;
    POSHandle *handle;

    switch(this->_migration_stage){
        /*!
         *  \note   [case]  no migration is onging
         */
        case kPOS_MigrationStage_Ease: {
            break;
        }

    #define __TMP__context_pool_include_module true

        /*!
         *  \note   [case]  the migration just start
         */
        case kPOS_MigrationStage_Init: {
        #if POS_MIGRATION_OPT_LEVEL == 1
            // drain
            if(unlikely( (retval = this->_client->worker->sync()) != POS_SUCCESS )){
                POS_WARN_C_DETAIL("failed to synchornize before pre-copy");
                goto exit;
            }
            
            // dump all buffers
            this->_client->__TMP__migration_allcopy();
            this->_migration_stage = kPOS_MigrationStage_Block;
            
            // TMP: for exp
            // mark all handles to be broken
            this->_client->__TMP__migration_tear_context(__TMP__context_pool_include_module);
            POS_LOG("[migration] tear context, and lock worker thread");
        #elif POS_MIGRATION_OPT_LEVEL == 2
            // generate the copy plan, and remote malloc
            this->_client->__TMP__migration_remote_malloc();

            // drain
            if(unlikely( (retval = this->_client->worker->sync()) != POS_SUCCESS )){
                POS_WARN_C_DETAIL("failed to synchornize before pre-copy");
                goto exit;
            }

            this->_precopy_start_pc = pc;

            // raise pre-copy thread
            this->_precopy_thread = new std::thread(&POSMigrationCtx::__precopy_async_thread, this);
            POS_CHECK_POINTER(this->_precopy_thread);
            this->_is_precopy_thread_active = true;
            
            this->_migration_stage = kPOS_MigrationStage_Wait_Precopy;
        #endif
        
            retval = POS_SUCCESS;
            break;
        }

        

        /*!
        *  \note   [case]  the pre-copy thread has been launched, we wait until it finished, and
        *                  conduct delta-copy
        */
        case kPOS_MigrationStage_Wait_Precopy: {
            // check whether precopy thread has finished
            POS_CHECK_POINTER(this->_precopy_thread);
            if(this->_is_precopy_thread_active == true){
                // case: the precopy thread is still active
                retval = POS_SUCCESS;
                goto exit;
            } else {
                this->_precopy_thread->join();
            }

            // drain again for delta-copy
            if(unlikely( (retval = this->_client->worker->sync()) != POS_SUCCESS )){
                POS_WARN_C_DETAIL("failed to synchornize after pre-copy");
                goto exit;
            }

            // delta-copy
            this->_client->__TMP__migration_deltacopy();

            // lock worker thread
            this->_migration_stage = kPOS_MigrationStage_Block;

            // calculate how many pre-copy mem is efficient
            for(set_iter = this->precopy_handles.begin(); set_iter != this->precopy_handles.end(); set_iter++){
                POS_CHECK_POINTER(handle = *set_iter);
                if(this->invalidated_handles.count(handle) == 0){
                    eff_nb_precopy_handles += 1;
                    eff_precopy_size += handle->state_size;
                }
                all_precopy_size += handle->state_size;
            }

            // calculate how many delta-copy mem is new
            for(set_iter = this->invalidated_handles.begin(); set_iter != this->invalidated_handles.end(); set_iter++){
                POS_CHECK_POINTER(handle = *set_iter);
                if(this->precopy_handles.count(handle) == 0){
                    eff_nb_deltacopy_handles += 1;
                    eff_deltacopy_size += handle->state_size;
                }
                all_deltacopy_size += handle->state_size;
            }

            // TMP: for exp
            // invalidate host buffer state, to trigger on-demand reload on restoring
            for(set_iter = this->__TMP__host_handles.begin(); set_iter != this->__TMP__host_handles.end(); set_iter++){
                POS_CHECK_POINTER(handle = *set_iter);
                handle->state_status = kPOS_HandleStatus_StateMiss;
            }

            // TMP: for exp
            // mark all handles to be broken
            this->_client->__TMP__migration_tear_context(__TMP__context_pool_include_module);

            POS_LOG("[migration] tear context, and lock worker thread");
            POS_LOG(
                "#eff_precopy_handle(%lu), #eff_precopy_size(%lu bytes), precopy_eff_rate(%lf)",
                eff_nb_precopy_handles, eff_precopy_size, (double)(eff_precopy_size)/(double)(all_precopy_size)
            );
            POS_LOG(
                "#eff_deltacopy_handle(%lu), #eff_deltacopy_size(%lu bytes), deltacopy_eff_rate(%lf)",
                eff_nb_deltacopy_handles, eff_deltacopy_size, (double)(eff_deltacopy_size)/(double)(all_deltacopy_size)
            );

            retval = POS_SUCCESS;
            break;
        }


        case kPOS_MigrationStage_Block: {
            retval = POS_WARN_BLOCKED;
            break;
        }
            

        case kPOS_MigrationStage_RestoreCtx: {
            s_tick = POSUtilTimestamp::get_tsc();
            this->_client->__TMP__migration_restore_context(__TMP__context_pool_include_module);
            e_tick = POSUtilTimestamp::get_tsc();

            POS_LOG("restore context: %lf us", POS_TSC_TO_USEC(e_tick-s_tick));

        #if POS_MIGRATION_OPT_LEVEL == 1
            this->_client->__TMP__migration_allreload();
        #elif POS_MIGRATION_OPT_LEVEL == 2
            // raise on-demand reload thread (no need, we duplicate on the CPU-side)
            // this->_ondemand_reload_thread = new std::thread(&POSMigrationCtx::__ondemand_reload_async_thread, this);
            // POS_CHECK_POINTER(this->_ondemand_reload_thread);
            // this->_is_ondemand_reload_thread_active = true;
            // POS_LOG("launched on-demand restore");
        #endif

            retval = POS_SUCCESS;
            this->_migration_stage = kPOS_MigrationStage_Ease;

            break;
        }

        default:
            POS_ERROR_C_DETAIL("unknown migration stage %d, this is a bug", this->_migration_stage);
    }

exit:
    return retval;
}

void POSMigrationCtx::__precopy_async_thread(){
    /*!
     *  \note   currently we mock the transfer by copy to another device in the same process,
     *          we should support RoCE in the future           
     */
    this->_client->__TMP__migration_precopy();
exit:
    this->_is_precopy_thread_active = false;
}

void POSMigrationCtx::__ondemand_reload_async_thread(){
    this->_client->__TMP__migration_ondemand_reload();
exit:
    this->_is_ondemand_reload_thread_active = false;
}
