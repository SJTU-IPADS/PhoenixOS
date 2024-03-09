#pragma once

#include <string>

#include "pos/include/common.h"
#include "pos/include/log.h"
#include "pos/include/handle.h"
#include "pos/include/api_context.h"
#include "pos/include/utils/bipartite_graph.h"

typedef struct pos_handle_meta {
    POSHandle *handle;
    uint64_t start_pc;
    uint64_t end_pc;

    pos_handle_meta(POSHandle* handle_, uint64_t start_pc_) 
        : handle(handle_), start_pc(start_pc_) {}

    pos_handle_meta(pos_handle_meta const& other_) 
        : handle(other_.handle), start_pc(other_.start_pc), end_pc(other_.end_pc) {}

} pos_handle_meta_t;

typedef struct pos_op_meta {
    POSAPIContext_QE *wqe;

    pos_op_meta(POSAPIContext_QE* wqe_) : wqe(wqe_) {}

    pos_op_meta(pos_op_meta const& other_) : wqe(other_.wqe) {}
} pos_op_meta_t;

class POSDag {
 private:
    /*!
     *  \brief  serialize metadata of an op on the DAG while dumping to file
     *  \param  meta    metadata of a OP (vertex on the DAG)
     *  \param  result  dump result
     */
    static void _serialize_op(pos_op_meta* meta, std::string& result){
        uint64_t i;
        POSAPIContext_QE *wqe;
        std::vector<std::function<void()>> dump_flow;

        POS_CHECK_POINTER(meta);
        POS_CHECK_POINTER(wqe = meta->wqe);
        
        dump_flow.insert(dump_flow.end(), {
            /* vid */                       [&](){ result += std::to_string(wqe->dag_vertex_id); },
            /* api_id */                    [&](){ result += std::to_string(wqe->api_cxt->api_id); },
            /* return_code */               [&](){ result += std::to_string(wqe->api_cxt->return_code); },
            /* create_tick */               [&](){ result += std::to_string(wqe->create_tick); },
            /* return_tick */               [&](){ result += std::to_string(wqe->return_tick); },
            /* runtime_s_tick */            [&](){ result += std::to_string(wqe->runtime_s_tick); },
            /* runtime_e_tick */            [&](){ result += std::to_string(wqe->runtime_e_tick); },
            /* worker_s_tick */             [&](){ result += std::to_string(wqe->worker_s_tick); },
            /* worker_e_tick */             [&](){ result += std::to_string(wqe->worker_e_tick); },
            /* queue_len_before_parse */    [&](){ result += std::to_string(wqe->queue_len_before_parse); },

            /* =========== checkpoint op specific fields =========== */
            /* nb_ckpt_handles */           [&](){ result += std::to_string(wqe->nb_ckpt_handles); },
            /* ckpt_size */                 [&](){ result += std::to_string(wqe->ckpt_size); },
            /* nb_abandon_handles */        [&](){ result += std::to_string(wqe->nb_abandon_handles); },
            /* abandon_ckpt_size */         [&](){ result += std::to_string(wqe->abandon_ckpt_size); },
            /* ckpt_memory_consumption */   
                                            [&](){ result += std::to_string(wqe->ckpt_memory_consumption); },
        });
        
        result.clear();
        for(i=0; i<dump_flow.size(); i++){
            dump_flow[i]();
            if(likely(i != dump_flow.size()-1)){
                result += std::string(", ");
            }
        }
    }

    /*!
     *  \brief  serialize metadata of an handle on the DAG while dumping to file
     *  \param  meta    metadata of a handle (vertex on the DAG)
     *  \param  result  dump result
     */
    static void _serialize_handle(pos_handle_meta* meta, std::string& result){
        uint64_t i;
        POSHandle *handle;
        char t[128] = {0};
        std::vector<std::function<void()>> dump_flow;

        POS_CHECK_POINTER(meta);
        POS_CHECK_POINTER(handle = meta->handle);
        
        dump_flow.insert(dump_flow.end(), {
            /* vid */               [&](){ result += std::to_string(handle->dag_vertex_id); },
            /* resource_type_id */  [&](){ result += std::to_string(handle->resource_type_id); },
            /* resource_name */     [&](){ result += handle->get_resource_name(); },
            /* client_addr */       [&](){ sprintf(t, "%p", handle->client_addr); result += std::string(t); },
            /* server_addr */       [&](){ sprintf(t, "%p", handle->server_addr); result += std::string(t); },
            /* status */            [&](){ result += std::to_string(handle->status); },
            /* size */              [&](){ result += std::to_string(handle->size); },
            /* parent_idx */        [&](){
                                        uint64_t i;
                                        result += std::to_string(handle->parent_handles.size());
                                        if(likely(handle->parent_handles.size() > 0)){
                                            result += std::string(", ");
                                        }
                                        for(i=0; i<handle->parent_handles.size(); i++){
                                            result += std::to_string(handle->parent_handles[i]->dag_vertex_id);
                                            if(likely(i != handle->parent_handles.size()-1)){
                                                result += std::string(", ");
                                            }
                                        }
                                    }
        });
        
        result.clear();
        for(i=0; i<dump_flow.size(); i++){
            dump_flow[i]();
            if(likely(i != dump_flow.size()-1)){
                result += std::string(", ");
            }
        }
    }

 public:
    POSDag(pos_client_uuid_t id) : _pc(0), _end_pc(0), _client_id(id) {}
    
    ~POSDag(){
        if(_pc > 0){
            _graph.dump_graph_to_file(
                /* file_path */ POS_LOG_FILE_PATH,
                /* serialize_t1 */ POSDag::_serialize_op,
                /* serialize_t2 */ POSDag::_serialize_handle
            );
        }
    };

    /*!
     *  \brief  block until the dag is drained out
     */
    void drain(){
        while(this->has_pending_op()){}
    }

    /*!
     *  \brief  add a new handle to the DAG
     *  \param  handle  pointer to the added handle
     *  \note   this function will be called by the runtime thread
     *  \return POS_SUCCESS for successfully adding handle
     */
    inline pos_retval_t allocate_handle(POSHandle* handle){
        pos_retval_t retval = POS_SUCCESS;
        pos_vertex_id_t vertex_id;
        POSNeighborList_t empty_neighbor_list;

        pos_handle_meta_t *h_meta = new pos_handle_meta_t(handle, _end_pc);
        POS_CHECK_POINTER(h_meta);

        if(unlikely(POS_SUCCESS != (retval =
            _graph.add_vertex<pos_handle_meta_t>(
                /* data */ h_meta,
                /* neighbor */ empty_neighbor_list,
                /* id */ &(handle->dag_vertex_id)
            )
        ))){
            POS_WARN_C_DETAIL("failed to add handle to the DAG graph");
            goto exit_POSDag_add_handle;
        }

        POS_DEBUG_C(
            "add new handle to the DAG: resource_type_id(%lu), pc(%lu), vertex_id(%lu)",
            handle->resource_type_id, _end_pc, handle->dag_vertex_id
        );

    exit_POSDag_add_handle:
        return retval;
    }
    
    /*!
     *  \brief  add a new operator to the DAG
     *  \param  wqe pointer to the work QE to be added
     *  \note   this function will be called by the runtime thread
     *  \return POS_SUCCESS for successfully adding operator
     */
    inline pos_retval_t launch_op(POSAPIContext_QE* wqe){
        uint64_t i;
        pos_retval_t retval = POS_SUCCESS;
        std::vector<POSHandleView_t>* handle_view_vec;
        std::map<pos_resource_typeid_t, std::vector<POSHandleView_t>*>::iterator map_iter;
        std::map<pos_vertex_id_t, pos_edge_direction_t> neighbor_map;

        pos_op_meta_t *o_meta = new pos_op_meta_t(wqe);
        POS_CHECK_POINTER(o_meta);

        uint64_t s_tick, e_tick;

        // s_tick = POSUtilTimestamp::get_tsc();

        retval =_graph.add_vertex<pos_op_meta_t>(
            /* data */ o_meta,
            /* neighbor */ wqe->dag_neighbors,
            /* id */ &(wqe->dag_vertex_id)
        );

        // e_tick = POSUtilTimestamp::get_tsc();
        // POS_LOG("add vertex duration: %lf us", POS_TSC_TO_USEC(e_tick-s_tick));

        if(unlikely(retval != POS_SUCCESS)){
            POS_WARN_C_DETAIL("failed to add op to the DAG graph");
            goto exit_POSDag_add_op;
        }

        // the vertex id of the op should be exactly the end pc
        POS_ASSERT(wqe->dag_vertex_id == _end_pc);

        POS_DEBUG_C(
            "add new op to the DAG: api_id(%lu), pc(%lu), vertex_id(%lu), #handles(%lu)",
            wqe->api_cxt->api_id, _end_pc, wqe->dag_vertex_id, neighbor_map.size()
        );

        /*!
         *  \brief  adding end_pc must locate here, as the worker thread will imediately detect the laucnhed op
         *          once this value is udpated
         */
        _end_pc += 1;

    exit_POSDag_add_op:
        return retval;
    }

    /*!
     *  \brief  obtain the earlist pending op from the DAG
     *  \param  wqe             pointer to work QE of the earlist pending op
     *                          (could be nullptr for no pending op exist)
     *  \param  nb_pending_ops  pointer to variable that stores #pending_ops in
     *                          the DAG currently
     *  \note   this function will be called by the worker thread
     *  \return POS_SUCCESS for successfully obtain;
     *          POS_FAILED_NOT_READY for no pending op exist
     */
    pos_retval_t get_next_pending_op(POSAPIContext_QE** wqe, uint64_t* nb_pending_ops=nullptr){
        pos_retval_t retval = POS_SUCCESS;
        pos_op_meta_t *op_meta;
        POS_CHECK_POINTER(wqe);
        
        if(likely(nb_pending_ops != nullptr)){
            *nb_pending_ops = _end_pc - _pc;
        }

        if(unlikely(_pc == _end_pc)){
            // no op is pending
            *wqe = nullptr;
            return POS_FAILED_NOT_READY;
        }

        op_meta = _graph.get_vertex_by_id<pos_op_meta_t>(_pc);
        if(unlikely(op_meta == nullptr)){
            POS_WARN_C_DETAIL("failed to obtain op: vertex_id(%lu)", _pc);
            retval = POS_FAILED_NOT_EXIST;
        } else {
            *wqe = op_meta->wqe;
            POS_ASSERT((*wqe)->dag_vertex_id == _pc);
        }
        
        return retval;
    }

    /*!
     *  \brief  forward the pc of the DAG
     */
    inline void forward_pc(){ if(likely(_pc < _end_pc)) _pc++; }

    /*!
     *  \brief  identify whether current DAG has pending op
     *  \return identify result
     */
    inline bool has_pending_op(){ return _end_pc > _pc; }

    /*!
     *  \brief  obtain the number of pending operators in the DAG
     *  \return the number of pending operators in the DAG result
     */
    inline uint64_t get_nb_pending_op(){ return _end_pc - _pc; }

    /*!
     *  \brief  obtain the current version
     *  \note   must be called runtime function
     *  \return the current version
     */
    inline uint64_t get_current_pc_runtime(){ return _end_pc; }

    /*!
     *  \brief  obtain the current version
     *  \note   must be called worker function
     *  \return the current version
     */
    inline uint64_t get_current_pc_worker(){ return _pc; }

 private:
    // underlying bipartite graph
    POSBipartiteGraph<pos_op_meta_t, pos_handle_meta_t> _graph;

    /*!
     *  \brief  final pc of the DAG
     *  \note   this field should be wrote by runtime thread, read by worker thread,
     *          hence should be updated at the end of launch_op
     */
    uint64_t _end_pc;
    
    /*!
     *  \brief  current pc of the DAG
     *  \note   this field should be both wrote and read by worker thread
     */
    uint64_t _pc;

    pos_client_uuid_t _client_id;
};
