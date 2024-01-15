#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <type_traits>
#include <fstream>
#include <iostream>
#include <string>
#include <memory>

#include <string.h>

#include "pos/include/common.h"
#include "pos/include/log.h"


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
    std::shared_ptr<T> data;
    pos_vertex_id_t id;
    POSBgVertex_t(T const& data, pos_vertex_id_t vid) : data(std::make_shared<T>(data)), id(vid) {}
};

using POSNeighborMap_t = std::map<pos_vertex_id_t, pos_edge_direction_t>;
using POSNeighborMap_ptr = std::shared_ptr<POSNeighborMap_t>;

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
    }

    ~POSBipartiteGraph(){
        typename std::map<pos_vertex_id_t, POSBgVertex_t<T1>*>::iterator t1_iter;
        typename std::map<pos_vertex_id_t, POSBgVertex_t<T2>*>::iterator t2_iter;
        typename std::map<pos_vertex_id_t, POSNeighborMap_ptr>::iterator topo_iter;

        for(t1_iter=_t1s.begin(); t1_iter!=_t1s.end(); t1_iter++){
            POS_CHECK_POINTER(t1_iter->second);
            delete t1_iter->second;
        }
        for(t2_iter=_t2s.begin(); t2_iter!=_t2s.end(); t2_iter++){
            POS_CHECK_POINTER(t2_iter->second);
            delete t2_iter->second;
        }

        _topo.clear();
        _topo_t1_cache.clear();

        // for(topo_iter=_topo.begin(); topo_iter!=_topo.end(); topo_iter++){
        //     POS_CHECK_POINTER(topo_iter->second);
        //     delete topo_iter->second;
        // }
    }

    /*!
     *  \brief  add vertex into the bipartite graph
     *  \tparam T           type of the added vertex, should be either T1 or T2
     *  \param  data        data payload within the added vertex
     *  \param  neighbor    neighbor of the added vertex
     *  \param  id          pointer to the variable to store the return index of the created vertex
     *  \return 1. POS_SUCCESS for successfully creating;
     *          2. POS_FAILED_NOT_EXIST for no neighbor vertex were founded with specified index
     */
    template<typename T>
    pos_retval_t add_vertex(
        T const& data, const POSNeighborMap_t& neighbor, pos_vertex_id_t* id
    ){
        static_assert((std::is_same_v<T, T1>) || (std::is_same_v<T, T2>),
            "try to add invalid type of vertex into the graph, this is a bug!"
        );

        pos_retval_t retval = POS_SUCCESS;
        POSBgVertex_t<T> *new_vertex;
        POSNeighborMap_ptr new_topo_map;
    
        POS_CHECK_POINTER(id);

        // make sure all provided neighbor idx are valid
    #if POS_ENABLE_DEBUG_CHECK
        typename POSNeighborMap_t::iterator n_iter;

        for(n_iter=neighbor.begin(); n_iter!=neighbor.end(); n_iter++){
            if constexpr (std::is_same_v<T, T1>){
                if(unlikely(_t2s.count(n_iter->first) == 0)){
                    POS_WARN_C_DETAIL(
                        "failed to create new vertex, no %s node with id %lu were founded",
                        typeid(T2).name(), n_iter->first
                    );
                    retval = POS_FAILED_NOT_EXIST;
                    goto exit;
                }
            } else { // T2
                if(unlikely(_t1s.count(n_iter->first) == 0)){
                    POS_WARN_C_DETAIL(
                        "failed to create new vertex, no %s node with id %lu were founded",
                        typeid(T1).name(), n_iter->first
                    );
                    retval = POS_FAILED_NOT_EXIST;
                    goto exit;
                }
            }
        }
    #endif

        if constexpr (std::is_same_v<T, T1>){
            *id = max_t1_id; max_t1_id += 1;
        } else { // T2
            *id = max_t2_id; max_t2_id += 1;
        }

        new_vertex = new POSBgVertex_t<T>(data, *id);
        POS_CHECK_POINTER(new_vertex);

        // add neighbor topology to corresponding list
        new_topo_map = std::make_shared<POSNeighborMap_t>();
        POS_CHECK_POINTER(new_topo_map.get());
        new_topo_map->insert(neighbor.begin(), neighbor.end());

        if constexpr (std::is_same_v<T, T1>){
            _t1s[*id] = new_vertex;
            _topo_t1_cache[*id] = new_topo_map;
        } else { // T2
            _t2s[*id] = new_vertex;
            _topo[*id] = new_topo_map;
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
    std::shared_ptr<T> get_vertex_by_id(pos_vertex_id_t id){
        static_assert((std::is_same_v<T, T1>) || (std::is_same_v<T, T2>),
            "try to get id of invalid type of vertex from the graph, this is a bug!"
        );
        if constexpr (std::is_same_v<T, T1>) {
            if(likely(_t1s.count(id) != 0)){ return _t1s[id]->data; } 
            else { return std::shared_ptr<T>(nullptr); }
        } else { // T2
            if(likely(_t2s.count(id) != 0)){ return _t2s[id]->data; } 
            else { return std::shared_ptr<T>(nullptr); }
        }
    }


    template<typename T>
    POSNeighborMap_ptr get_vertex_neighbors_by_id(pos_vertex_id_t id){
        static_assert((std::is_same_v<T, T1>) || (std::is_same_v<T, T2>),
            "try to get neighbor of invalid type of vertex from the graph, this is a bug!"
        );
        
        POSNeighborMap_ptr retval = nullptr;

        // NOTE: this must be slow, but how slow?
        __join_topo();

        if constexpr (std::is_same_v<T, T1>) {
            // TODO: we might need to store a transpose matrix of _topo to accelerate searching
            POS_ERROR_C_DETAIL("not implemented yet");
        } else { // T2
            if(likely(_topo.count(id) != 0)){ 
                POS_CHECK_POINTER(retval = _topo[id])
            } else { 
                POS_WARN_C_DETAIL("no topology record of T2 id %lu", id);
            }
        }
        
    exit:
        return retval;
    }


    /*!
     *  \brief  functions for serilze T1 and T2 node, for dumping the graph to file
     *  \param  vertex  the vertex to be dumped
     *  \param  result  dumping result, in string
     */
    using serilize_t1_func_t = void(*)(T1* vertex, std::string& result);
    using serilize_t2_func_t = void(*)(T2* vertex, std::string& result);

    /*!
     *  \brief  dump the captured graph to a file
     *  \param  file_path   path to store the dumped graph
     */
    void dump_graph_to_file(const char* file_path, serilize_t1_func_t serilize_t1, serilize_t2_func_t serilize_t2){
        std::ofstream output_file;
        typename std::map<pos_vertex_id_t, POSBgVertex_t<T1>*>::iterator t1s_iter;
        typename std::map<pos_vertex_id_t, POSBgVertex_t<T2>*>::iterator t2s_iter;
        typename std::map<pos_vertex_id_t, POSNeighborMap_ptr>::iterator topo_iter;
        typename POSNeighborMap_t::iterator dir_iter;
        pos_vertex_id_t vid, nvid;
        pos_edge_direction_t dir;
        POSNeighborMap_ptr direction_map;
        POSBgVertex_t<T1>* t1v;
        POSBgVertex_t<T2>* t2v;
        std::string serilization_result;

        // obtain comprehensive topology
        __join_topo();

        output_file.open(file_path, std::fstream::in | std::fstream::out | std::fstream::trunc);

        // first line: nb_t1s, nb_t2s, tsc_freq
        output_file << _t1s.size() << ", " << _t2s.size() << ", " << POS_TSC_FREQ << std::endl;

        // next nb_t1s line: info of t1s
        for(t1s_iter=_t1s.begin(); t1s_iter!=_t1s.end(); t1s_iter++){
            vid = t1s_iter->first;
            POS_CHECK_POINTER(t1v = t1s_iter->second);
            POS_CHECK_POINTER(t1v->data); POS_CHECK_POINTER(t1v->data.get());
            
            // serilize vertex data
            serilization_result.clear();
            serilize_t1(t1v->data.get(), serilization_result);
    
            output_file << serilization_result << std::endl;
        }

        // next nb_t2s line: info of t2s
        for(t2s_iter=_t2s.begin(); t2s_iter!=_t2s.end(); t2s_iter++){
            vid = t2s_iter->first;
            POS_CHECK_POINTER(t2v = t2s_iter->second);
            POS_CHECK_POINTER(t2v->data); POS_CHECK_POINTER(t2v->data.get());
            
            // serilize vertex data
            serilization_result.clear();
            serilize_t2(t2v->data.get(), serilization_result);
    
            output_file << serilization_result << std::endl;
        }

        /*!
         *  \note       next nb_t2s line: info of t2s' topology
         *  \example    vertex_id, #neighbor, n1, dir1, n2, dir2, ...
         */
        for(topo_iter=_topo.begin(); topo_iter!=_topo.end(); topo_iter++){
            vid = topo_iter->first;
            POS_CHECK_POINTER(direction_map = topo_iter->second);

            if(likely(direction_map->size() > 0)){
                output_file << vid << ", " << direction_map->size() << ", ";
            } else {
                output_file << vid << ", " << direction_map->size() << std::endl;
            }
            
            for(dir_iter=direction_map->begin(); dir_iter!=direction_map->end(); dir_iter++){
                nvid = dir_iter->first;
                dir = dir_iter->second;

                typename POSNeighborMap_t::iterator temp_iter = dir_iter;
                temp_iter++;

                if(unlikely(temp_iter == direction_map->end())){
                    output_file << nvid << ", " << dir << std::endl;
                } else {
                    output_file << nvid << ", " << dir << ", ";
                }
            }
        }

        output_file.close();
        POS_LOG("finish dump DAG file to %s", file_path);
    }

 private:
    pos_vertex_id_t max_t1_id, max_t2_id;
    std::map<pos_vertex_id_t, POSBgVertex_t<T1>*> _t1s;
    std::map<pos_vertex_id_t, POSBgVertex_t<T2>*> _t2s;
    
    /*!
     *  \brief  the final topology storage from the view of T2
     */
    std::map<pos_vertex_id_t, POSNeighborMap_ptr> _topo;

    /*!
     *  \brief  we cache the topology inserted while add T1 vertex here, to accelerate the insertion of T1;
     *  \note   this cache will be merged into _topo when _topo is needed, by invoking __join_topo
     */ 
    std::map<pos_vertex_id_t, POSNeighborMap_ptr> _topo_t1_cache;
    
    /*!
     *  \brief  start merging _topo_t1_cache into _topo if _topo_t1_cache isn't empty, to obtain comprehensive _topo
     */
    inline void __join_topo(){
        if(likely(_topo_t1_cache.size() != 0)){
            __merge_topo_cache();
        }
    }
    
    /*!
     *  \brief  merge _topo_t1_cache into _topo
     */
    inline void __merge_topo_cache(){
        typename std::map<pos_vertex_id_t, POSNeighborMap_ptr>::iterator outter_iter;
        typename POSNeighborMap_t::iterator inner_iter;
        pos_vertex_id_t t1_vid;
        POSNeighborMap_ptr t1_nmap, t2_nmap;

        for(outter_iter=_topo_t1_cache.begin(); outter_iter!=_topo_t1_cache.end(); outter_iter++){
            t1_vid = outter_iter->first;
            POS_CHECK_POINTER(t1_nmap = outter_iter->second);

            for(inner_iter=t1_nmap->begin(); inner_iter!=t1_nmap->end(); inner_iter++){
                POS_CHECK_POINTER(t2_nmap = _topo[inner_iter->first]);
                (*t2_nmap)[t1_vid] = inner_iter->second;
            }
        }

        _topo_t1_cache.clear();
    }
};
