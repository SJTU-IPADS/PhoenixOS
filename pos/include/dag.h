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

#include <string>

#include "pos/include/common.h"
#include "pos/include/log.h"
#include "pos/include/handle.h"
#include "pos/include/api_context.h"
#include "pos/include/utils/bipartite_graph.h"
#include "pos/include/utils/lockfree_queue.h"

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


typedef struct pos_dag_cxt {
    int something;
} pos_dag_cxt_t;


class POSDag {
 public:
    POSDag(pos_dag_cxt cxt) : _cxt(cxt), _pc(0), _end_pc(0) {
        _api_cxts.reserve(65536);
    }

    ~POSDag(){
        // if(_pc > 0){
        //     _graph.dump_graph_to_file(
        //         /* file_path */ POS_LOG_FILE_PATH,
        //         /* serialize_t1 */ POSDag::_serialize_op,
        //         /* serialize_t2 */ POSDag::_serialize_handle
        //     );
        // }
    };

    /*!
     *  \brief  block until the dag is drained out
     */
    void drain(){
        while(this->has_pending_op()){}
    }

    /*!
     *  \brief  block until the end_pc reach the given destination id
     *  \param  dest_id the given destination api instance id
     *  \note   this function is used for drain out both parser and worker of 
     *          current client, the dest_id is recorded inside the client
     */
    void drain_by_dest_id(uint64_t dest_id){
        while(_pc < dest_id){}
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
     *  \note   this function will be called by the parser thread
     *  \return POS_SUCCESS for successfully adding operator
     */
    inline pos_retval_t launch_op(POSAPIContext_QE* wqe){
        uint64_t i;
        pos_retval_t retval = POS_SUCCESS;
        std::vector<POSHandleView_t>* handle_view_vec;
        std::map<pos_resource_typeid_t, std::vector<POSHandleView_t>*>::iterator map_iter;
        std::map<pos_vertex_id_t, pos_edge_direction_t> neighbor_map;

        POS_CHECK_POINTER(wqe);

        pos_op_meta_t *o_meta = new pos_op_meta_t(wqe);
        POS_CHECK_POINTER(o_meta);

        uint64_t s_tick, e_tick;

        // record the API context to the DAG
        retval =_graph.add_vertex<pos_op_meta_t>(
            /* data */ o_meta,
            /* neighbor */ wqe->dag_neighbors,
            /* id */ &(wqe->dag_vertex_id)
        );
        if(unlikely(retval != POS_SUCCESS)){
            POS_WARN_C_DETAIL("failed to add op to the DAG graph");
            goto exit_POSDag_add_op;
        }

        // the vertex id of the op should be exactly the end pc
        POS_ASSERT(wqe->dag_vertex_id == _end_pc);

        // push the API context to the queue
        _api_cxts_queue.push(wqe);

        // record the api context to the list
        // if(likely(wqe->api_cxt->api_id != _cxt.checkpoint_api_id)){
        //     _api_cxts.push_back(wqe);
        // } else {
        //     latest_checkpoint_version = wqe->dag_vertex_id;
        // }

        POS_DEBUG_C(
            "add new op to the DAG: api_id(%lu), pc(%lu), vertex_id(%lu), #handles(%lu)",
            wqe->api_cxt->api_id, _end_pc, wqe->dag_vertex_id, neighbor_map.size()
        );

        /*!
         *  \note   adding end_pc must locate here, as the worker thread will imediately detect the laucnhed op
         *          once this value is udpated
         */
        _end_pc += 1;

    exit_POSDag_add_op:
        return retval;
    }


    /*!
     *  \brief  record an operator to the DAG
     *  \note   this function is invoked during restore phrase
     *  \param  wqe pointer to the work QE to be added
     */
    inline void record_op(POSAPIContext_QE* wqe){
        POS_CHECK_POINTER(wqe);
        _api_cxts.push_back(wqe);
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

        *wqe = *( (POSAPIContext_QE**)(_api_cxts_queue.peek()) );
        if(unlikely((*wqe) == nullptr)){
            POS_WARN_C_DETAIL("failed to obtain op: vertex_id(%lu)", _pc);
            retval = POS_FAILED_NOT_EXIST;
        } else {
            POS_ASSERT((*wqe)->dag_vertex_id == _pc);
        }
        
        return retval;
    }

    /*!
     *  \brief  forward the pc of the DAG
     */
    inline void forward_pc(){
        if(unlikely(false == _api_cxts_queue.pop())){
            POS_ERROR_C_DETAIL("failed to pop op: vertex_id(%lu)", _pc);
        }

        if(likely(_pc < _end_pc)){ _pc++; }
    }

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
     *  \note   must be called parser function
     *  \return the current version
     */
    inline uint64_t get_current_pc_parser(){ return _end_pc; }

    /*!
     *  \brief  obtain the current version
     *  \note   must be called worker function
     *  \return the current version
     */
    inline uint64_t get_current_pc_worker(){ return _pc; }

    /*!
     *  \brief  obtain the number of API context within this DAG
     *  \return number of API context within this DAG
     */
    inline uint64_t get_nb_api_cxt(){ return _api_cxts.size(); }

    /*!
     *  \brief  obtain the api context by given index
     *  \param  id  index of the api context
     *  \return the obtained api context
     */
    inline POSAPIContext_QE_t* get_api_cxt_by_id(uint64_t id){
        POS_ASSERT(id < _api_cxts.size());
        return _api_cxts[id];
    }

    /*!
     *  \brief  obtain a api context wqe by given dag index
     *  \todo   this function is slow!
     *  \param  vid  the specified dag index
     *  \return pointer to the founed api context wqe or nullptr
     */
    inline POSAPIContext_QE_t* get_api_cxt_by_dag_id(pos_vertex_id_t vid){
        POSAPIContext_QE_t *retval = nullptr;
        uint64_t i;

        for(i=0; i<_api_cxts.size(); i++){
            POS_CHECK_POINTER(_api_cxts[i]);
            if(unlikely(_api_cxts[i]->dag_vertex_id == vid)){
                retval = _api_cxts[i];
                break;
            }
        }

        return retval;
    }

    /*!
     *  \brief  check whether a specified handle is missing checkpoint, return the missing version if it's
     *  \param  handle_vid  dag vertex index of the handle to be checked
     *  \param  vh          latest checkpoint version of this handle
     *  \param  vg          global latest checkpoint version
     *  \param  is_missing  identify whether the specified handle is missing checkpoint
     *  \param  vo          missing checkpoint version
     *  \note   vh < vo < vg  
     */
    void check_missing_ckpt(pos_vertex_id_t handle_vid, pos_vertex_id_t vh, pos_vertex_id_t vg, bool& is_missing, pos_vertex_id_t& vo){
        uint64_t i;
        POSNeighborList_t *neighbor_list;
        POSAPIContext_QE_t *wqe;

        POS_ASSERT(vh <= vg);

        POS_CHECK_POINTER(neighbor_list = this->_graph.get_neighbor_list(handle_vid));

        // no api context operate on this handle, so it wouldn't miss checkpoint
        if(unlikely(neighbor_list->size() == 0)){
            is_missing = false;
            goto exit;
        }

        // traverse the neighbor list in reverse order
        for(i=neighbor_list->size()-1; i>=0; i--){
            POSBgEdge_t &edge = (*neighbor_list)[i];
            if(edge.d_vid <= vh){
                is_missing = false;
                goto exit;
            }

            if(edge.dir == kPOS_Edge_Direction_Out || edge.dir == kPOS_Edge_Direction_InOut){
                if(edge.d_vid <= vg){
                    is_missing = true;
                    vo = edge.d_vid;
                    goto exit;
                }
            }
        }

    exit:
        ;
    }

    /*!
     *  \brief  obtain the upstream api context that modified (inout / output) the specified handle, by given deadline version
     *  \param  handle_vid  dag vertex index of the handle to be checked
     *  \param  ddl_vid     deadline version index
     *  \return pointer to the founed api context wqe or nullptr
     */
    POSAPIContext_QE_t* get_handle_upstream_api_cxt_by_ddl(pos_vertex_id_t handle_vid, pos_vertex_id_t ddl_vid){
        POSAPIContext_QE_t *retval = nullptr;
        uint64_t i;
        POSNeighborList_t *neighbor_list;
        POS_CHECK_POINTER(neighbor_list = this->_graph.get_neighbor_list(handle_vid));
        
        // no api context operate on this handle
        if(unlikely(neighbor_list->size() == 0)){
            goto exit;
        }

        // traverse the neighbor list in reverse order
        for(i=neighbor_list->size()-1; i>=0; i--){
            POSBgEdge_t &edge = (*neighbor_list)[i];

            if(edge.dir == kPOS_Edge_Direction_Out || edge.dir == kPOS_Edge_Direction_InOut){
                if(edge.d_vid <= ddl_vid){
                    POS_CHECK_POINTER(retval = this->get_api_cxt_by_dag_id(edge.d_vid));
                    break;
                }
            }
        }

    exit:
        return retval;
    }

    /*!
     *  \brief  obtain serialize size of current dag topo
     *  \return serialize size of current dag topo
     */
    uint64_t get_serialize_size(){
        return (
            /* latest_checkpoint_version*/  sizeof(pos_vertex_id_t)
            /* graph topo */                + _graph.get_serialize_size()
        );
    }

    /*!
     *  \brief  serialize the current current dag topo into the binary area
     *  \param  serialized_area  pointer to the binary area
     */
    inline void serialize(void** serialized_area){
        void *ptr;

        POS_CHECK_POINTER(serialized_area);
        *serialized_area = malloc(get_serialize_size());
        POS_CHECK_POINTER(*serialized_area);
        
        ptr = *serialized_area;

        // field: latest_checkpoint_version
        POSUtil_Serializer::write_field(&ptr, &(latest_checkpoint_version), sizeof(pos_vertex_id_t));

        // field: graph topo
        _graph.serialize(ptr);
    }


    /*!
     *  \brief  deserialize this dag topo
     *  \param  raw_data    raw data area that store the serialized data
     */
    inline void deserialize(void* raw_data){
        void *ptr = raw_data;
        POS_CHECK_POINTER(ptr);

        // field: latest_checkpoint_version
        POSUtil_Deserializer::read_field(&(this->latest_checkpoint_version), &ptr, sizeof(pos_vertex_id_t));

        // field: graph topo
        _graph.deserialize(ptr);
    }

    // dag vertex id of latest checkpoint op
    pos_vertex_id_t latest_checkpoint_version;

 private:
    // context of this dag
    pos_dag_cxt_t _cxt;

    // underlying bipartite graph
    POSBipartiteGraph<pos_op_meta_t, pos_handle_meta_t> _graph;

    /*!
     *  \brief  final pc of the DAG
     *  \note   this field should be wrote by runtime thread, read by worker thread,
     *          hence should be updated at the end of launch_op
     */
    uint64_t _end_pc;
    
    // context of all normal apis record in to the dag
    std::vector<POSAPIContext_QE*> _api_cxts;

    /*!
     *  \brief  queue of pending API context
     *  \note   API context should be enqueued by parser thread, and 
     *          dequeued by worker thread
     */
    POSLockFreeQueue<POSAPIContext_QE_t*> _api_cxts_queue;

    /*!
     *  \brief  current pc of the DAG
     *  \note   this field should be both wrote and read by worker thread
     */
    uint64_t _pc;

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
};
