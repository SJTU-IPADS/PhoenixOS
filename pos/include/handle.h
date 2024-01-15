#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <type_traits>

#include <stdint.h>
#include <assert.h>

#include "pos/include/common.h"
#include "pos/include/log.h"
#include "pos/include/utils/bipartite_graph.h"
#include "pos/include/checkpoint.h"

#define kPOS_HandleDefaultSize   (1<<4)

/*!
 *  \brief  idx of base resource types
 */
enum pos_handle_type_id_t : uint64_t {
    kPOS_ResourceTypeId_Unknown = 0,
    kPOS_ResourceTypeId_Device,
    kPOS_ResourceTypeId_Memory,
    kPOS_ResourceTypeId_Num_Base_Type
};

/*!
 *  \brief  status of a handle instance
 */
enum pos_handle_status_t : uint8_t {
    /*!
     *  \brief  the resource behind this handle is active 
     *          on the XPU device, if an op rely on this 
     *          handle, it's ok to launch
     */
    kPOS_HandleStatus_Active = 0,

    /*!
     *  \brief  the resource behind this handle has been
     *          released manually by the client
     *  \note   this status is marked under worker function
     */
    kPOS_HandleStatus_Deleted,

    /*!
     *  \brief  the resource behind this handle are going
     *          to be deleted
     *  \note   this status is marked under runtime function
     *  \note   once the handle is marked as this status in
     *          the runtime function, subsequent runtime
     *          function won't obtain this handle under
     *          get_handle_by_client_addr
     *  \note   it's ok for collect_broken_handles to skip
     *          such handle, as they still active currently
     *          (will be deleted under subsequent op)   
     */
    kPOS_HandleStatus_Delete_Pending,

    /*!
     *  \brief  the resource behind this handle is pending
     *          to be created on XPU
     */
    kPOS_HandleStatus_Create_Pending,

    /*!
     *  \brief  the resource behind this handle is broken
     *          on the XPU device, one need to restore the
     *          resource before launching any op that rely
     *          on it
     */
    kPOS_HandleStatus_Broken
};


// forward declaration
template<class T_POSHandle>
class POSHandleManager;


/*!
 *  \brief  a mapping of client-side and server-side handle, along with its metadata
 */
class POSHandle {
 public:
    /*!
     *  \param  client_addr_    the mocked client-side address of the handle
     *  \param  size_           size of the handle it self
     *  \param  hm              handle manager which this handle belongs to
     *  \param  state_size_     size of the resource state behind this handle
     *  \note   this constructor is for software resource, whose client-side address
     *          and server-side address could be seperated
     */
    POSHandle(
        void *client_addr_, size_t size_, void* hm, size_t state_size_=0
    ) : client_addr(client_addr_), server_addr(nullptr), size(size_),
        dag_vertex_id(0), resource_type_id(kPOS_ResourceTypeId_Unknown),
        status(kPOS_HandleStatus_Create_Pending), state_size(state_size_),
        ckpt_bag(nullptr), _hm(hm) {}
    
    /*!
     *  \param  size_           size of the resources represented by this handle
     *  \param  hm              handle manager which this handle belongs to
     *  \param  state_size_     size of the resource state behind this handle
     *  \note   this constructor is for hardware resource, whose client-side address
     *          and server-side address should be equal (e.g., memory)
     */
    POSHandle(size_t size_, void* hm, size_t state_size_=0)
        :   client_addr(nullptr), server_addr(nullptr), size(size_),
            dag_vertex_id(0), resource_type_id(kPOS_ResourceTypeId_Unknown),
            status(kPOS_HandleStatus_Create_Pending), state_size(state_size_),
            ckpt_bag(nullptr), _hm(hm) {}
    
    virtual ~POSHandle() = default;

    /*!
     *  \brief  setting the server-side address of the handle after finishing allocation
     *  \param  addr  the server-side address of the handle
     */
    inline void set_server_addr(void *addr){ server_addr = addr; }
    
    /*!
     *  \brief  setting both the client-side and server-side address of the handle 
     *          after finishing allocation
     *  \param  addr        the setting address of the handle
     *  \param  handle_ptr  shared pointer to current handle
     *  \return POS_SUCCESS for successfully setting
     *          POS_FAILED_ALREADY_EXIST for duplication failed;
     */
    pos_retval_t set_passthrough_addr(void *addr, std::shared_ptr<POSHandle> handle_ptr);

    /*!
    *  \brief  record a new parent handle of current handle
    */
    inline void record_parent_handle(std::shared_ptr<POSHandle> parent){
        POS_CHECK_POINTER(parent);
        parent_handles.push_back(parent);
    }

    struct _pos_broken_handle_list_iter;

    /*!
     *  \brief  wrapper map to store broken handles
     */
    typedef struct pos_broken_handle_list {
        /*!
         *  \brief  list of broken handles
         *  \note   outter index: layer id
         */
        std::vector<std::vector<POSHandle*>*> _broken_handles;
        inline uint16_t get_nb_layers(){ return _broken_handles.size(); }

        /*!
         *  \brief  add new broken handle to the map
         *  \param  layer_id    index of the layer that this broken handle locates in
         *  \param  handle      pointer to the broken handle
         */
        inline void add_handle(uint16_t layer_id, POSHandle* handle){
            std::vector<POSHandle*> *vec;

            while(layer_id >= _broken_handles.size()){
                POS_CHECK_POINTER(vec = new std::vector<POSHandle*>());
                _broken_handles.push_back(vec);
            }

            _broken_handles[layer_id]->push_back(handle);
        }

        /*!
         *  \brief  reset this map (i.e., clear all recorded broken handles)
         */
        inline void reset(){
            uint16_t i;
            for(i=0; i<_broken_handles.size(); i++){
                if(likely(_broken_handles[i] != nullptr)){
                    _broken_handles[i]->clear();
                }
            }
        }

        /*!
         *  \brief  repeatly call this function to traverse the current list
         *  \param  layer_id_keeper     keeping the intermedia traverse layer id
         *                              [default value should be the return value of get_nb_layers()]
         *  \param  handle_id_keeper    keeping the intermedia traverse handle id within the layer
         *                              [default value should be 0]
         *  \return non-nullptr for the obtained handle; nullptr for reaching the end of traversing
         */
        inline POSHandle* reverse_get_handle(uint16_t& layer_id_keeper, uint64_t& handle_id_keeper){
            POSHandle *retval = nullptr;
            
            POS_CHECK_POINTER(_broken_handles[layer_id_keeper]);

            if(unlikely(handle_id_keeper >= _broken_handles[layer_id_keeper]->size())){
                if(layer_id_keeper == 0){
                    goto exit;
                } else {
                    layer_id_keeper -= 1;
                    handle_id_keeper = 0;
                }
            }

            POS_CHECK_POINTER(_broken_handles[layer_id_keeper]);

            if(_broken_handles[layer_id_keeper]->size() > 0)
                retval = (*(_broken_handles[layer_id_keeper]))[handle_id_keeper];
            
            handle_id_keeper += 1;

        exit:
            return retval;
        }

        /*!
         *  \brief  deconstructor
         */
        ~pos_broken_handle_list(){
            uint16_t i;
            for(i=0; i<_broken_handles.size(); i++){
                if(likely(_broken_handles[i] != nullptr))
                   delete _broken_handles[i];
            }
        }
    } pos_broken_handle_list_t;

    /*!
     *  \brief  collect all broken handles along the handle trees
     *  \note   this function will call recursively, aware of performance issue!
     *  \param  broken_handle_list  list of broken handles, 
     *  \param  layer_id            index of the layer at this call
     */
    inline void collect_broken_handles(pos_broken_handle_list_t *broken_handle_list, uint16_t layer_id = 0){
        uint64_t i;

        POS_CHECK_POINTER(broken_handle_list);

        // insert itself to the nonactive_handles map if itsn't active
        if(unlikely(status != kPOS_HandleStatus_Active && status != kPOS_HandleStatus_Delete_Pending)){
            broken_handle_list->add_handle(layer_id, this);
        }
        
        // iterate over its parent
        for(i=0; i<parent_handles.size(); i++){
            parent_handles[i]->collect_broken_handles(broken_handle_list, layer_id+1);
        }
    }

    /*!
     *  \brief  identify whether a given address is located within the resource
     *          that current handle represents
     *  \param  addr    the given address
     *  \param  offset  pointer to store the offset of the given address from the base
     *                  address, if the given address is located within the resource
     *                  that current handle represents
     *  \return identify result
     */
    inline bool is_client_addr_in_range(void *addr, uint64_t *offset=nullptr){
        bool result;

        result = ((uint64_t)client_addr <= (uint64_t)addr) && ((uint64_t)addr < (uint64_t)(client_addr)+size);

        if(result && offset != nullptr){
            *offset = (uint64_t)addr - (uint64_t)client_addr;
        }

        return result;
    }

    /*!
     *  \brief  mark the status of this handle
     *  \param  status the status to mark
     *  \note   this function would call the inner function within the corresponding handle manager
     */
    void mark_status(pos_handle_status_t status);


    /*!
     *  \brief  record host value of the handle under specific version
     *  \param  data    pointer to the remoting buffer, which contains the host-side value
     *  \param  size    size of the host-side value
     *  \param  version version (pc index) of the host-side value
     */
    inline void record_host_value(void* data, uint64_t size, uint64_t version){
        POSMem_ptr host_value;

        POS_CHECK_POINTER(data);
        POS_ASSERT(size > 0);

        host_value = std::make_unique<uint8_t[]>(size);
        POS_CHECK_POINTER(host_value);
        memcpy(host_value.get(), data, size);

        host_value_map[version] = { host_value, size };
    }

    /*!
     *  \brief  checkpoint the state of the resource behind this handle
     *  \note   only handle of stateful resource should implement this method
     *  \param  version_id  version of this checkpoint
     *  \param  stream_id   index of the stream to do this checkpoint
     *  \return POS_SUCCESS for successfully checkpointed
     */
    virtual pos_retval_t checkpoint(uint64_t version_id, uint64_t stream_id=0){ 
        return POS_FAILED_NOT_IMPLEMENTED; 
    }

    /*!
     *  \brief  restore the current handle when it becomes broken status
     *  \return POS_SUCCESS for successfully restore
     */
    virtual pos_retval_t restore(){ return POS_FAILED_NOT_IMPLEMENTED; }
    
    /*!
    *  \brief  the typeid of the resource kind which this handle represents
    *  \note   the children class of this base class should replace this value
    *          with their own typeid
    */
    pos_resource_typeid_t resource_type_id;

    /*!
     *  \brief  obtain the resource name begind this handle
     *  \return resource name begind this handle
     */
    virtual std::string get_resource_name(){ return std::string("unknown"); }

    // status of the resource behind this handle
    pos_handle_status_t status;

    // the mocked client-side address of the handle
    void *client_addr;

    // the actual server-side address of the handle
    void *server_addr;

    // pointer to the instance of parent handle
    std::vector<std::shared_ptr<POSHandle>> parent_handles;

    // id of the DAG vertex of this handle
    pos_vertex_id_t dag_vertex_id;

    /*!
    *  \brief    size of the resources represented by this handle
    *  \example  the size of the buffer represented by current handler 
    *            (i.e., a device memory pointer)
    *  \note     for some handles (e.g., cudaStream_t), this value should remain
    *            constant —— kPOS_HandleDefaultSize
    */
    size_t size;

    /*!
     *  \brief  size of the resource state behind this handle
     */
    size_t state_size;

    /*!
     *  \brief  bag of checkpoints, implemented by different ckpt optimization level
     *  \note   it must be initialized by different implementations of stateful handle,
     *          as they might require different allocators and deallocators, see function
     *          init_ckpt_bag
     */
    POSCheckpointBag *ckpt_bag;

    /*!
     *  \brief  map between (1) dag pc to (2) host-side new value of 
     *          the resource behind this handle
     *  \note   1. for those APIs which bring new value to handle from the host-side,
     *          we need to cache the host-side value in case we would reply this
     *          API call later
     *  \note   2. we might need to cache multiple versions of host-side new values,
     *          so we use a map here
     */
    std::map<uint64_t, std::pair<POSMem_ptr, uint64_t>> host_value_map;

 protected:
    void *_hm;

    /*!
     *  \brief  initialize checkpoint bag of this handle
     *  \note   it must be implemented by different implementations of stateful 
     *          handle, as they might require different allocators and deallocators
     *  \return POS_SUCCESS for successfully initialization
     */
    virtual pos_retval_t init_ckpt_bag(){ return POS_FAILED_NOT_IMPLEMENTED; }
};
using POSHandle_ptr = std::shared_ptr<POSHandle>;

/*!
 *  \brief   manager for handles of a specific kind of resource
 *  \tparam  T_POSHandle  specific handle class for the resource
 */
template<class T_POSHandle>
class POSHandleManager {
 public:
    // range of the mocked client-side address
    #define kPOS_ResourceBaseAddr   0x555500000000
    #define kPOS_ResourceEndAddr    0xFFFFFFFFFFF0

    /*!
     *  \brief  constructor
     *  \param  passthrough indicate whether the handle's client-side and server-side address
     *                      are equal (true for hardware resource, false for software resource)
     */
    POSHandleManager(bool passthrough = false) 
        : _base_ptr(kPOS_ResourceBaseAddr), _passthrough(passthrough) {}

    ~POSHandleManager() = default;
    
    /*!
     *  \brief  allocate new mocked resource within the manager
     *  \param  handle          pointer to the mocked handle of the newly allocated resource
     *  \param  related_handles all related handles for helping allocate the mocked resource
     *                          (note: these related handles might be other types)
     *  \param  size            size of the newly allocated resource
     *  \param  expected_addr   the expected mock addr to allocate the resource (optional)
     *  \param  state_size      size of resource state behind this handle  
     *  \return POS_FAILED_DRAIN for run out of virtual address space; 
     *          POS_SUCCESS for successfully allocation
     */
    virtual pos_retval_t allocate_mocked_resource(
        std::shared_ptr<T_POSHandle>* handle, std::map</* type */ uint64_t,
        std::vector<std::shared_ptr<POSHandle>>> related_handles,
        size_t size = kPOS_HandleDefaultSize,
        uint64_t expected_addr = 0,
        uint64_t state_size = 0
    );
    
    /*!
     *  \brief  record a new handle that will be modified
     *  \param  handle  the handle that will be modified
     */
    inline void record_modified_handle(std::shared_ptr<T_POSHandle> handle){
        POS_CHECK_POINTER(handle.get());
        _modified_handles_map[(uint64_t)(handle->client_addr)] = handle;
    }

    /*!
     *  \brief  clear all records of modified handles
     */
    inline void clear_modified_handle(){ 
        _modified_handles_map.clear();
    }

    /*!
     *  \brief  get all records of modified handles
     *  \return all records of modified handles
     */
    inline std::map<uint64_t, std::shared_ptr<T_POSHandle>>& get_modified_handles(){
        return _modified_handles_map;
    }

    /*!
     *  \brief  obtain a handle by given client-side address
     *  \param  client_addr the given client-side address
     *  \param  handle      the resulted handle
     *  \param  offset      pointer to store the offset of the given address from the base address
     *  \return POS_FAILED_NOT_EXIST for no corresponding handle exists;
     *          POS_SUCCESS for successfully founded
     */
    virtual pos_retval_t get_handle_by_client_addr(void* client_addr, std::shared_ptr<T_POSHandle>* handle, uint64_t* offset=nullptr);

    /*!
     *  \brief    last-used handle
     *  \example  for device handle manager, one need to record the last-used device for later usage
     *            (e.g., cudaGetDevice, cudaMalloc)
     */
    std::shared_ptr<T_POSHandle> latest_used_handle;

    /*!
     *  \brief  obtain the number of recorded handles
     *  \return the number of recorded handles
     */
    inline uint64_t get_nb_handles(){ return _handles.size(); }

    /*!
     *  \brief  obtain a handle by given index
     *  \param  id  the specified index
     *  \return pointer to the founed handle or nullptr
     */
    inline std::shared_ptr<T_POSHandle> get_handle_by_id(uint64_t id){
        if(unlikely(id >= this->get_nb_handles())){
            return std::shared_ptr<T_POSHandle>(nullptr);
        } else {
            return _handles[id];
        }
    }

    inline pos_retval_t mark_handle_status(std::shared_ptr<T_POSHandle> handle, pos_handle_status_t status){
        POS_CHECK_POINTER(handle.get());
        return mark_handle_status(handle.get(), status);
    }

    inline pos_retval_t mark_handle_status(T_POSHandle *handle, pos_handle_status_t status){
        typename std::map<uint64_t, std::shared_ptr<T_POSHandle>>::iterator handle_map_iter;
        
        POS_CHECK_POINTER(handle);
        
        switch (status)
        {
        case kPOS_HandleStatus_Active:
            handle->status = kPOS_HandleStatus_Active;
            POS_DEBUG_C(
                "mark handle as \"Active\" status: client_addr(%p), server_addr(%p)",
                handle->client_addr, handle->server_addr
            );
            break;

        case kPOS_HandleStatus_Broken:
            handle->status = kPOS_HandleStatus_Broken;
            POS_DEBUG_C(
                "mark handle as \"Broken\" status: client_addr(%p), server_addr(%p)",
                handle->client_addr, handle->server_addr
            );
            break;

        case kPOS_HandleStatus_Create_Pending:
            handle->status = kPOS_HandleStatus_Create_Pending;
            POS_DEBUG_C(
                "mark handle as \"Create_Pending\" status: client_addr(%p), server_addr(%p)",
                handle->client_addr, handle->server_addr
            );
            break;

        case kPOS_HandleStatus_Delete_Pending:
            handle->status = kPOS_HandleStatus_Delete_Pending;

            // remove the handle from the address map
            handle_map_iter = _handle_address_map.find((uint64_t)(handle->client_addr));
            if (likely(handle_map_iter != _handle_address_map.end())) {
                _deleted_handle_address_map.insert({
                    /* client_addr */ (uint64_t)(handle->client_addr),
                    /* handle_ptr */ handle_map_iter->second
                });
                _handle_address_map.erase((uint64_t)(handle->client_addr));   
            }

            POS_DEBUG_C(
                "mark handle as \"Delete_Pending\" status: client_addr(%p), server_addr(%p)",
                handle->client_addr, handle->server_addr
            );
            break;

        case kPOS_HandleStatus_Deleted:
            handle->status = kPOS_HandleStatus_Deleted;

            // remove the handle from the address map (should be already deleted in the last case)
            handle_map_iter = _handle_address_map.find((uint64_t)(handle->client_addr));
            if (unlikely(handle_map_iter != _handle_address_map.end())) {
                POS_WARN_C_DETAIL("remove handle from address map when mark it as deleted, is this a bug?");
                _deleted_handle_address_map.insert({
                    /* client_addr */ (uint64_t)(handle->client_addr),
                    /* handle_ptr */ handle_map_iter->second
                });
                _handle_address_map.erase((uint64_t)(handle->client_addr));
            }

            POS_DEBUG_C(
                "mark handle as \"Deleted\" status: client_addr(%p), server_addr(%p)",
                handle->client_addr, handle->server_addr
            );
            break;
        
        default:
            POS_ERROR_C_DETAIL("unknown status %u", status);
        }
    }

    /*!
     *  \brief  record handle address to the address map
     *  \note   this function should be called right after a handle obtain its client-side address:
     *          (1) for non-passthrough handle: called within __allocate_mocked_resource;
     *          (2) for passthrough handle: called within handle->set_server_addr
     *  \param  addr    client-side address of the handle
     *  \param  handle  the handle to be recorded
     *  \return POS_SUCCESS for successfully recorded;
     *          POS_FAILED_ALREADY_EXIST for duplication failed
     */
    inline pos_retval_t record_handle_address(void* addr, std::shared_ptr<T_POSHandle> handle){
        pos_retval_t retval = POS_SUCCESS;
        std::shared_ptr<T_POSHandle> __tmp;
        uint64_t addr_u64 = (uint64_t)(addr);

        POS_CHECK_POINTER(handle.get());

        if(likely(POS_FAILED_NOT_EXIST == __get_handle_by_client_addr(addr, &__tmp))){
            _handle_address_map[addr_u64] = handle;
        } else {
            POS_CHECK_POINTER(__tmp.get());

            /*!
             *  \note   no need to be failed here, some handle will record duplicated resources on purpose, 
             *          e.g., CUFunction
             */
            // POS_WARN_C(
            //     "try to record duplicated handle to the manager: new_addr(%p), new_size(%lu), old_addr(%p), old_size(%lu)",
            //     addr, handle->size, __tmp->client_addr, __tmp->size
            // );
            // retval = POS_FAILED_ALREADY_EXIST;
        }

    exit:
        return retval;
    }

 protected:
    uint64_t _base_ptr;
    
    /*!
     *  \brief  indicate whether the handle's client-side and server-side address are 
     *          equal (true for hardware resource, false for software resource)
     */
    bool _passthrough;

    std::vector<std::shared_ptr<T_POSHandle>> _handles;

    /*!
     *  \brief  this map records all modified buffers since last checkpoint, 
     *          will be updated during parsing, and cleared during launching
     *          checkpointing op
     */
    std::map<uint64_t, std::shared_ptr<T_POSHandle>> _modified_handles_map;

    /*!
     *  \brief  allocate new mocked resource within the manager
     *  \param  handle          pointer to the mocked handle of the newly allocated resource
     *  \param  size            size of the newly allocated resource
     *  \param  expected_addr   the expected mock addr to allocate the resource (optional)
     *  \note   this function should be internally invoked by allocate_mocked_resource, which leave 
     *          to children class to implement
     *  \return POS_FAILED_DRAIN for run out of virtual address space; 
     *          POS_SUCCESS for successfully allocation
     */
    pos_retval_t __allocate_mocked_resource(
        std::shared_ptr<T_POSHandle>* handle, size_t size=kPOS_HandleDefaultSize, uint64_t expected_addr=0, uint64_t state_size = 0
    );

    /*!
     *  \brief  obtain a handle by given client-side address
     *  \param  client_addr the given client-side address
     *  \param  handle      the resulted handle
     *  \param  offset      pointer to store the offset of the given address from the base address
     *  \note   this function should be internally invoked by get_handle_by_client_addr, which leave 
     *          to children class to implement
     *  \return POS_FAILED_NOT_EXIST for no corresponding handle exists;
     *          POS_SUCCESS for successfully founded
     */
    pos_retval_t __get_handle_by_client_addr(void* client_addr, std::shared_ptr<T_POSHandle>* handle, uint64_t* offset=nullptr);

 private:
    std::map<uint64_t, std::shared_ptr<T_POSHandle>> _handle_address_map;
    std::unordered_map<uint64_t, std::shared_ptr<T_POSHandle>> _deleted_handle_address_map;
};


/*!
 *  \brief  allocate new mocked resource within the manager
 *  \param  handle          pointer to the mocked handle of the newly allocated resource
 *  \param  size            size of the newly allocated resource
 *  \param  related_handles all related handles for helping allocate the mocked resource
 *                          (note: these related handles might be other types)
 *  \param  expected_addr   the expected mock addr to allocate the resource (optional)
 *  \return POS_FAILED_DRAIN for run out of virtual address space; 
 *          POS_SUCCESS for successfully allocation
 */
template<class T_POSHandle>
pos_retval_t POSHandleManager<T_POSHandle>::allocate_mocked_resource(
    std::shared_ptr<T_POSHandle>* handle,
    std::map</* type */ uint64_t, std::vector<POSHandle_ptr>> related_handles,
    size_t size,
    uint64_t expected_addr,
    uint64_t state_size
){
    return __allocate_mocked_resource(handle, size, state_size);
}

/*!
 *  \brief  allocate new mocked resource within the manager
 *  \param  handle          pointer to the mocked handle of the newly allocated resource
 *  \param  size            size of the newly allocated resource
 *  \param  expected_addr   the expected mock addr to allocate the resource (optional)
 *  \note   this function should be internally invoked by allocate_mocked_resource, which leave to children class to implement
 *  \return POS_FAILED_DRAIN for run out of virtual address space;
 *          POS_FAILED_ALREADY_EXIST for duplication failed;
 *          POS_SUCCESS for successfully allocation
 */
template<class T_POSHandle>
pos_retval_t POSHandleManager<T_POSHandle>::__allocate_mocked_resource(
    std::shared_ptr<T_POSHandle>* handle,
    size_t size,
    uint64_t expected_addr,
    uint64_t state_size
){
    pos_retval_t retval = POS_SUCCESS;

    POS_CHECK_POINTER(handle);

    if(this->_passthrough){
        *handle = std::make_shared<T_POSHandle>(size, this, state_size);
        POS_CHECK_POINTER((*handle).get());
    } else {
        // if one want to create on an expected address, we directly move the pointer forward
        if(unlikely(expected_addr != 0)){
            _base_ptr = expected_addr;
        }

        // make sure the resource to be allocated won't exceed the range
        if(unlikely(kPOS_ResourceEndAddr - _base_ptr < size)){
            POS_WARN_C(
                "failed to allocate new resource, exceed range: request %lu bytes, yet %lu bytes left",
                size, kPOS_ResourceEndAddr - _base_ptr
            );
            retval = POS_FAILED_DRAIN;
            *handle = nullptr;
            goto exit;
        }

        *handle = std::make_shared<T_POSHandle>((void*)_base_ptr, size, this, state_size);
        POS_CHECK_POINTER((*handle).get());

        // record client-side address to the map
        retval = record_handle_address((void*)(_base_ptr), *handle);
        if(unlikely(POS_SUCCESS != retval)){
            goto exit;
        }

        _base_ptr += size;
    }

    POS_DEBUG_C(
        "allocate new resource: _base_ptr(%p), size(%lu), POSHandle.resource_type_id(%u)",
        _base_ptr, size, (*handle)->resource_type_id
    );

    _handles.push_back(*handle);

  exit:
    return retval;
}

/*!
 *  \brief  obtain a handle by given client-side address
 *  \param  client_addr the given client-side address
 *  \param  handle      the resulted handle
 *  \param  offset      pointer to store the offset of the given address from the base address
 *  \TODO:  we need to accelerate this function!
 *  \return POS_FAILED_NOT_EXIST for no corresponding handle exists;
 *          POS_SUCCESS for successfully founded
 */
template<class T_POSHandle>
pos_retval_t POSHandleManager<T_POSHandle>::get_handle_by_client_addr(void* client_addr, std::shared_ptr<T_POSHandle>* handle, uint64_t* offset){
    return __get_handle_by_client_addr(client_addr, handle, offset);
}

/*!
 *  \brief  obtain a handle by given client-side address
 *  \param  client_addr the given client-side address
 *  \param  handle      the resulted handle
 *  \param  offset      pointer to store the offset of the given address from the base address
 *  \TODO:  we need to accelerate this function!
 *  \note   this function should be internally invoked by get_handle_by_client_addr, which leave to children class to implement
 *  \return POS_FAILED_NOT_EXIST for no corresponding handle exists;
 *          POS_SUCCESS for successfully founded
 */
template<class T_POSHandle>
pos_retval_t POSHandleManager<T_POSHandle>::__get_handle_by_client_addr(void* client_addr, std::shared_ptr<T_POSHandle>* handle, uint64_t* offset){
    pos_retval_t ret = POS_SUCCESS;
    std::shared_ptr<T_POSHandle> handle_ptr;
    uint64_t i;
    uint64_t client_addr_u64 = (uint64_t)(client_addr);

    // std::map<uint64_t, std::shared_ptr<T_POSHandle>> _handle_address_map;
    typename std::map<uint64_t, std::shared_ptr<T_POSHandle>>::iterator handle_map_iter;

    POS_CHECK_POINTER(handle);
    
    /*!
     *  \note   direct case: the given address is exactly the base address
     */
    if(likely(this->_handle_address_map.count(client_addr_u64) > 0)){
        *handle = this->_handle_address_map[client_addr_u64];

        /*!
         *  \note   those handle that has been deleted (i.e., kPOS_HandleStatus_Deleted) and 
         *          are going to be deleted (i.e., kPOS_HandleStatus_Delete_Pending) must be
         *          not in the map! 
         */
        POS_ASSERT(
            (*handle)->status != kPOS_HandleStatus_Deleted 
            && (*handle)->status != kPOS_HandleStatus_Delete_Pending
        );

        if(unlikely(offset != nullptr)){
            *offset = 0;
        }
        goto exit;
    }
    
    /*!
     *  \brief  indirect case: the given address is beyond the base address
     */

    // get the first handle less than the given address
    handle_map_iter = this->_handle_address_map.lower_bound(client_addr_u64);
    if(handle_map_iter != this->_handle_address_map.begin()){
        handle_map_iter--;
        handle_ptr = handle_map_iter->second;

        POS_ASSERT(
            handle_ptr->status != kPOS_HandleStatus_Deleted 
            && handle_ptr->status != kPOS_HandleStatus_Delete_Pending
        );

        if(
            (uint64_t)(handle_ptr->client_addr) <= client_addr_u64 
            && client_addr_u64 < (uint64_t)(handle_ptr->client_addr) + handle_ptr->size
        ){
            *handle = handle_ptr;
            goto exit;
        }
    }

not_found:
    *handle = nullptr;
    ret = POS_FAILED_NOT_EXIST;

exit:
    return ret;
}

typedef struct pos_ckpt_overlap_scheme {
    // ckpt step index -> handles to be ckpted
    std::vector<std::vector<POSHandle_ptr>> *_final_scheme;

    // deadline index -> handles to be ckpted
    std::vector<std::vector<POSHandle_ptr>> *_initial_scheme;

    uint64_t _overlap_batch_size;
    
    inline void refresh(uint64_t overlap_batch_size){        
        if(likely(_final_scheme != nullptr)){ delete _final_scheme; _final_scheme = nullptr; }
        _final_scheme = new std::vector<std::vector<POSHandle_ptr>>(
            /* capacity */ overlap_batch_size,
            /* initial_value */ std::vector<POSHandle_ptr>()
        );
        POS_CHECK_POINTER(_final_scheme);

        if(likely(_initial_scheme != nullptr)){ delete _initial_scheme; _initial_scheme = nullptr; }
        _initial_scheme = new std::vector<std::vector<POSHandle_ptr>>(
            /* capacity */ overlap_batch_size,
            /* initial_value */ std::vector<POSHandle_ptr>()
        );
        POS_CHECK_POINTER(_initial_scheme);

        _overlap_batch_size = overlap_batch_size;
    }

    inline void add_new_handle_for_distribute(uint64_t relative_deadline_position, POSHandle_ptr handle){
        POS_ASSERT(relative_deadline_position < _overlap_batch_size);
        (*_initial_scheme)[relative_deadline_position].push_back(handle);
    }

    inline void schedule(){
        uint64_t i, j;
        std::vector<POSHandle_ptr> handles;
        std::vector<uint64_t> op_ckpt_budget(
            /* capacity */ _overlap_batch_size,
            /* initial_value */ 0
        );
        typename std::vector<uint64_t>::iterator op_ckpt_budget_iter;
        uint64_t min_burden_op_pos;

        auto get_overall_state_size = [](std::vector<POSHandle_ptr> &handles) -> uint64_t {
            uint64_t overall_state_size = 0;
            for(auto& handle : handles){ overall_state_size += handle->state_size; }
            return overall_state_size;
        };

        for(i=0; i<_overlap_batch_size; i++){
            handles = (*_initial_scheme)[i];

            /*!
             *  \note   for handles must be immediately ckpted by current ckpt op, we don't 
             *          need to do the distribution scheduling below, just directly assign
             */
            if(unlikely(i == 0)){
                (*_final_scheme)[i] = (*_initial_scheme)[i];
                op_ckpt_budget[i] += get_overall_state_size(handles);
                continue;
            }

            for(auto& handle: handles){
                op_ckpt_budget_iter = std::min_element(op_ckpt_budget.begin(), op_ckpt_budget.begin() + i);
                min_burden_op_pos = std::distance(op_ckpt_budget.begin(), op_ckpt_budget_iter);
                (*_final_scheme)[min_burden_op_pos].push_back(handle);
                op_ckpt_budget[min_burden_op_pos] += handle->state_size;
            }            
        }
    }

    inline std::vector<POSHandle_ptr>* get_overlap_scheme_by_ckpt_step_id(uint64_t ckpt_step_id){
        if(unlikely(ckpt_step_id >= _overlap_batch_size)){
            POS_WARN_DETAIL("ckpt step exceed range: ckpt_step_id(%lu)", ckpt_step_id);
            return nullptr;
        } else {
            return &((*_final_scheme)[ckpt_step_id]);
        }
    }

    pos_ckpt_overlap_scheme() : _overlap_batch_size(0), _final_scheme(nullptr), _initial_scheme(nullptr) {}
    ~pos_ckpt_overlap_scheme() = default;
} pos_ckpt_overlap_scheme_t;
