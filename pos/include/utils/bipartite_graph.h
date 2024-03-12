#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <type_traits>
#include <fstream>
#include <iostream>
#include <string>
#include <memory>
#include <mutex>

#include <string.h>

#include "pos/include/common.h"
#include "pos/include/log.h"
#include "pos/include/utils/timestamp.h"
#include "pos/include/utils/serializer.h"

using pos_vertex_id_t = uint64_t;


/*!
 *  \brief  edge attributes for POS DAG
 */
enum pos_edge_direction_t : uint8_t {
    kPOS_Edge_Direction_In = 0,
    kPOS_Edge_Direction_Out,
    kPOS_Edge_Direction_InOut,
    kPOS_Edge_Direction_Create,
    kPOS_Edge_Direction_Delete
};


/*!
 *  \brief  vertex for bipartite graph of POS
 */
template<typename T>
struct POSBgVertex_t {
    // pointer to the actual payload
    T* data;
    pos_vertex_id_t id;
    POSBgVertex_t() : data(nullptr), id(0) {}
    POSBgVertex_t(T* data_, pos_vertex_id_t vid) : data(data_), id(vid) {}
};

/*!
 *  \brief  edge for bipartite graph of POS
 */
typedef struct POSBgEdge_t {
    // index of the destination vertex of this edge
    pos_vertex_id_t d_vid;

    // direction of this edge
    pos_edge_direction_t dir;
};

using POSNeighborList_t = std::vector<POSBgEdge_t>;


/*!
 *  \note   T1 and T2 should be different, or this class will have unexpected behaviour
 */
template<typename T1, typename T2>
class POSBipartiteGraph {
 public:
    POSBipartiteGraph() : max_t1_id(0), max_t2_id(0) {
        static_assert(!std::is_same_v<T1, T2>,
            "POSBipartiteGraph couldn't support only one type of node exist in the graph"
        );

        uint64_t i;
        
        POSBgVertex_t<T1> *reserved_vertex_t1;
        POSBgVertex_t<T2> *reserved_vertex_t2;
        POSNeighborList_t *reserved_neighbor_list;

        /*!
         *  \brief  prefill is important, otherwise the runtime performance will significantly decrease
         */
        _t1s.reserve(POS_NB_PREFILL_DAG_VERTEX);
        _t2s.reserve(POS_NB_PREFILL_DAG_VERTEX);
        _topo_t2.reserve(POS_NB_PREFILL_DAG_VERTEX);

        for(i=0; i<POS_NB_PREFILL_DAG_VERTEX; i++){
            reserved_vertex_t1 = new POSBgVertex_t<T1>();
            POS_CHECK_POINTER(reserved_vertex_t1);
            _t1s.push_back(reserved_vertex_t1);

            reserved_vertex_t2 = new POSBgVertex_t<T2>();
            POS_CHECK_POINTER(reserved_vertex_t2);
            _t2s.push_back(reserved_vertex_t2);

            reserved_neighbor_list = new POSNeighborList_t();
            POS_CHECK_POINTER(reserved_neighbor_list);
            reserved_neighbor_list->reserve(POS_NB_PREFILL_DAG_VERTEX_NEIGHBOR);
            _topo_t2.push_back(reserved_neighbor_list);
        }
        POS_DEBUG("pos bipartite graph prefill done");
    }

    ~POSBipartiteGraph(){
        uint64_t i;

        for(i=0; i<_t1s.size(); i++){
            if(likely(_t1s[i] != nullptr)){ delete _t1s[i]; }
        }

        for(i=0; i<_t2s.size(); i++){
            if(likely(_t2s[i] != nullptr)){ delete _t2s[i]; }
        }

        for(i=0; i<_topo_t2.size(); i++){
            if(likely(_topo_t2[i] != nullptr)){ delete _topo_t2[i]; }
        }
    }

    /*!
     *  \brief  add vertex into the bipartite graph
     *  \tparam T           type of the added vertex, should be either T1 or T2
     *  \param  data        data payload within the added vertex
     *  \param  neighbors   list of neighbors of the added vertex
     *  \param  id          pointer to the variable to store the return index of the created vertex
     *  \return 1. POS_SUCCESS for successfully creating;
     *          2. POS_FAILED_NOT_EXIST for no neighbor vertex were founded with specified index
     */
    template<typename T>
    pos_retval_t add_vertex(
        void* data, POSNeighborList_t& neighbors, pos_vertex_id_t* id
    ){
        static_assert((std::is_same_v<T, T1>) || (std::is_same_v<T, T2>),
            "try to add invalid type of vertex into the graph, this is a bug!"
        );

        pos_retval_t retval = POS_SUCCESS;
        POSBgVertex_t<T> *new_vertex;
        uint64_t i;
        POSNeighborList_t *new_neighbor_list;

        POS_CHECK_POINTER(id);

        // make sure all provided neighbor idx are valid
    #if POS_ENABLE_DEBUG_CHECK

        for(i=0; i<neighbors.size(); i++){
            POSBgEdge_t &edge = neighbors[i];
            if constexpr (std::is_same_v<T, T1>){
                if(unlikely(_t2s.size() < edge.d_vid)){
                    POS_WARN_C_DETAIL(
                        "failed to create new vertex, no %s node with id %lu were founded",
                        typeid(T2).name(), edge.d_vid
                    );
                    retval = POS_FAILED_NOT_EXIST;
                    goto exit;
                }
            } else { // T2
                if(unlikely(_t1s.size() < edge.d_vid)){
                    POS_WARN_C_DETAIL(
                        "failed to create new vertex, no %s node with id %lu were founded",
                        typeid(T1).name(), edge.d_vid
                    );
                    retval = POS_FAILED_NOT_EXIST;
                    goto exit;
                }
            }
        }
    #endif

        // update maximum index of the vertex
        if constexpr (std::is_same_v<T, T1>){
            *id = max_t1_id; max_t1_id += 1;
        } else { // T2
            *id = max_t2_id; max_t2_id += 1;
        }

        // obtain / create vertex instance
        if(unlikely(*id >= POS_NB_PREFILL_DAG_VERTEX)){
            POS_CHECK_POINTER(new_vertex = new POSBgVertex_t<T>());
            if constexpr (std::is_same_v<T, T1>){
                _t1s.push_back(new_vertex);
            } else {
                // add vertex
                _t2s.push_back(new_vertex);

                // add neighbor list
                new_neighbor_list = new POSNeighborList_t();
                POS_CHECK_POINTER(new_neighbor_list);
                new_neighbor_list->reserve(POS_NB_PREFILL_DAG_VERTEX_NEIGHBOR);
                _topo_t2.push_back(new_neighbor_list);
            }
        } else {
            if constexpr (std::is_same_v<T, T1>){
                new_vertex = _t1s[*id];
            } else {
                new_vertex = _t2s[*id];
            }
        }
       
        // setup metadata of the vertex
        new_vertex->data = (T*)data;
        new_vertex->id = *id;
        
        /*!
         *  \note  the performance of this part is good
         */
        if constexpr (std::is_same_v<T, T1>){
            for(i=0; i < neighbors.size(); i++){
                POSBgEdge_t &edge = neighbors[i];
                POS_CHECK_POINTER(_topo_t2[edge.d_vid]);
                _topo_t2[edge.d_vid]->push_back({.d_vid = *id, .dir = edge.dir});
            }
        } else {
            _topo_t2[*id]->clear();
            _topo_t2[*id]->insert(_topo_t2[*id]->end(), neighbors.begin(), neighbors.end());
        }

    exit:
        return retval;
    }


    /*!
     *  \brief  obtain vertex based on specified index
     *  \tparam T   type of the added vertex, should be either T1 or T2
     *  \param  id  the specified index
     *  \return 1. non-nullptr for corresponding data of the founded vertex;
     *          2. nullptr for no vertex founded;
     */
    template<typename T>
    T* get_vertex_by_id(pos_vertex_id_t id){
        static_assert((std::is_same_v<T, T1>) || (std::is_same_v<T, T2>),
            "try to get id of invalid type of vertex from the graph, this is a bug!"
        );
        if constexpr (std::is_same_v<T, T1>) {
            if(likely(id < _t1s.size())){ return _t1s[id]->data; } 
            else { return nullptr; }
        } else { // T2
            if(likely(id < _t2s.size())){ return _t2s[id]->data; } 
            else { nullptr; }
        }
    }


    /*!
     *  \brief  functions for serilze T1 and T2 node, for dumping the graph to file
     *  \param  vertex  the vertex to be dumped
     *  \param  result  dumping result, in string
     *  \todo   remove this function, as we will dump graph as binary file instead of text file
     */
    using serialize_t1_func_t = void(*)(T1* vertex, std::string& result);
    using serialize_t2_func_t = void(*)(T2* vertex, std::string& result);

    /*!
     *  \brief  dump the captured graph to a file
     *  \param  file_path   path to store the dumped graph
     */
    void dump_graph_to_file(const char* file_path, serialize_t1_func_t serialize_t1, serialize_t2_func_t serialize_t2){
        std::ofstream output_file;
        typename std::map<pos_vertex_id_t, POSBgVertex_t<T1>*>::iterator t1s_iter;
        typename std::map<pos_vertex_id_t, POSBgVertex_t<T2>*>::iterator t2s_iter;
        pos_vertex_id_t vid, nvid;
        pos_edge_direction_t dir;
        POSBgVertex_t<T1>* t1v;
        POSBgVertex_t<T2>* t2v;
        std::string serilization_result;
        uint64_t i;
        
        output_file.open(file_path, std::fstream::in | std::fstream::out | std::fstream::trunc);

        // first line: nb_t1s, nb_t2s, tsc_freq
        output_file << max_t1_id << ", " << max_t2_id << ", " << POS_TSC_FREQ << std::endl;

        // next nb_t1s line: info of t1s
        for(i=0;i<max_t1_id; i++){
            POS_CHECK_POINTER(t1v = _t1s[i]);
            if(unlikely(t1v->data == nullptr)){
                continue;
            }
            
            // serialize vertex data
            serilization_result.clear();
            serialize_t1(t1v->data, serilization_result);
    
            output_file << serilization_result << std::endl;
        }

        // next nb_t2s line: info of t2s
        for(i=0;i<max_t2_id; i++){
            POS_CHECK_POINTER(t2v = _t2s[i]);
            if(unlikely(t2v->data == nullptr)){
                continue;
            }
            
            // serialize vertex data
            serilization_result.clear();
            serialize_t2(t2v->data, serilization_result);
    
            output_file << serilization_result << std::endl;
        }

        /*!
         *  \note       next nb_t2s line: info of t2s' topology
         *  \example    vertex_id, #neighbor, n1, dir1, n2, dir2, ...
         */
        // TODO:
        // for(i=0; i<_topo_t2.size(); i++){
        //     POSBgEdge_t &edge = _topo_t2[i];
        //     vid = topo_iter->first;
        //     POS_CHECK_POINTER(direction_map = topo_iter->second);
            
        //     if(unlikely(vid >= max_t2_id)){
        //         break;
        //     }

        //     if(likely(direction_map->size() > 0)){
        //         output_file << vid << ", " << direction_map->size() << ", ";
        //     } else {
        //         output_file << vid << ", " << direction_map->size() << std::endl;
        //     }
            
        //     for(dir_iter=direction_map->begin(); dir_iter!=direction_map->end(); dir_iter++){
        //         nvid = dir_iter->first;
        //         dir = dir_iter->second;

        //         typename POSNeighborMap_t::iterator temp_iter = dir_iter;
        //         temp_iter++;

        //         if(unlikely(temp_iter == direction_map->end())){
        //             output_file << nvid << ", " << dir << std::endl;
        //         } else {
        //             output_file << nvid << ", " << dir << ", ";
        //         }
        //     }
        // }

        output_file.close();
        POS_LOG("finish dump DAG file to %s", file_path);
    }

    /*!
     *  \brief  obtain serialize size of current graph
     *  \return serialize size of current graph
     */
    uint64_t get_serialize_size(){
        uint64_t i, nb_edges = 0;
        POSNeighborList_t *neighbor_list;

        for(i=0; i<_topo_t2.size(); i++){
            POS_CHECK_POINTER(neighbor_list = _topo_t2[i]);
            nb_edges += neighbor_list->size();
        }

        return (
            /* nb_t2_v */   sizeof(uint64_t)
            /* nb_edges */  + _topo_t2.size() * sizeof(uint64_t)
            /* edges */     + nb_edges * sizeof(POSBgEdge_t)
        );
    }

    /*!
     *  \brief  serialize the current current graph into the binary area
     *  \param  serialized_area  pointer to the binary area
     */
    inline void serialize(void* serialized_area){
        void *ptr;
        uint64_t i, j, nb_t2_v, nb_edges;
        POSNeighborList_t *neighbor_list;
        
        POS_CHECK_POINTER(serialized_area);

        ptr = serialized_area;

        // field: nb_t2_v
        nb_t2_v = max_t2_id;
        POSUtil_Serializer::write_field(&ptr, &(nb_t2_v), sizeof(uint64_t));

        for(i=0; i<_topo_t2.size(); i++){
            POS_CHECK_POINTER(neighbor_list = _topo_t2[i]);

            // field: nb_edges
            nb_edges = neighbor_list->size();
            POSUtil_Serializer::write_field(&ptr, &(nb_edges), sizeof(uint64_t));

            // field: edges
            for(j=0; j<nb_edges; j++){
                POSUtil_Serializer::write_field(&ptr, &((*neighbor_list)[j]), sizeof(POSBgEdge_t));
            }
        }
    }


    /*!
     *  \brief  deserialize basic field of this graph
     *  \param  raw_data    raw data area that store the serialized data
     */
    inline void deserialize(void* raw_data){
        void *ptr = raw_data;
        uint64_t i, j, fill_size, nb_edges;
        POSNeighborList_t *neighbor_list;
        POSBgEdge_t restored_edge;

        POS_CHECK_POINTER(ptr);

        // field: nb_t2_v
        POSUtil_Deserializer::read_field(&(this->max_t2_id), &ptr, sizeof(uint64_t));

        // we need to deal with large handle set
        fill_size = this->max_t2_id > _topo_t2.size() ? this->max_t2_id - _topo_t2.size() : 0;
        if(unlikely(fill_size > 0)){
            neighbor_list = new POSNeighborList_t();
            POS_CHECK_POINTER(neighbor_list);
            neighbor_list->reserve(POS_NB_PREFILL_DAG_VERTEX_NEIGHBOR);
            _topo_t2.push_back(neighbor_list);
        }

        for(i=0; i<this->max_t2_id; i++){
            POS_CHECK_POINTER(neighbor_list = _topo_t2[i]);

            // field: nb_edges
            POSUtil_Deserializer::read_field(&(nb_edges), &ptr, sizeof(uint64_t));

            // field: edges
            for(j=0; j<nb_edges; j++){
                POSUtil_Deserializer::read_field(&(restored_edge), &ptr, sizeof(POSBgEdge_t));
                neighbor_list->push_back(restored_edge);
            }
        }
    }


    /*!
     *  \brief  obtain neighbor list of specified vertex of type T2
     *  \param  t2_vid  specified index of the T2 vertex
     *  \return neighbor list of specified vertex of type T2
     */
    inline POSNeighborList_t* get_neighbor_list(pos_vertex_id_t t2_vid){
        POSNeighborList_t *retval = nullptr;

        if(unlikely(t2_vid >= max_t2_id)){
            POS_WARN_C_DETAIL("failed to obtain neighbor list, vertex index exceed range: t2_vid(%lu), max_t2_id(%lu)", t2_vid, max_t2_id);
        } else {
            POS_CHECK_POINTER(retval = _topo_t2[t2_vid])
        }

    exit:
        return retval;
    }


 private:
    pos_vertex_id_t max_t1_id, max_t2_id;
    std::vector<POSBgVertex_t<T1>*> _t1s;
    std::vector<POSBgVertex_t<T2>*> _t2s;
    
    /*!
     *  \brief  the final topology storage from the view of T2
     */
    std::vector<POSNeighborList_t*> _topo_t2;
};
