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
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <type_traits>
#include <thread>
#include <future>
#include <atomic>

#include <stdint.h>
#include <assert.h>

#include "pos/include/common.h"
#include "pos/include/log.h"
#include "pos/include/utils/serializer.h"
#include "pos/include/checkpoint.h"

#define kPOS_HandleDefaultSize   (1<<4)

/*!
 *  \brief  idx of base resource types
 */
enum : pos_resource_typeid_t {
    kPOS_ResourceTypeId_Unknown = 0,
    kPOS_ResourceTypeId_Device,
    kPOS_ResourceTypeId_Memory,
    kPOS_ResourceTypeId_Num_Base_Type
};

/*!
 *  \brief  status of a handle instance
 */
enum pos_handle_status_t : uint8_t {
    /* ========= Status of Handle Existance ========= */
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
     *  \note   this status is marked under parser function
     *  \note   once the handle is marked as this status in
     *          the parser function, subsequent parser
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
    kPOS_HandleStatus_Broken,

    /* ========= Status of Handle State ========= */
    /*!
     *  \brief  the state of resource behind this handle is
     *          ready on the XPU device
     */
    kPOS_HandleStatus_StateReady,

    /*!
     *  \brief  the state of resource behind this handle is
     *          missing on the XPU device, one need to reload
     *          the state before executing ops rely on it
     */
    kPOS_HandleStatus_StateMiss,

    /*!
     *  \brief  the state of this handle is pending to reload
     */
    kPOS_HandleStatus_StateReloadPending
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
     *  \param  id_             index of this handle in the handle manager list
     *  \param  state_size_     size of the resource state behind this handle
     *  \note   this constructor is for software resource, whose client-side address
     *          and server-side address could be seperated
     */
    POSHandle(
        void *client_addr_, size_t size_, void* hm, pos_u64id_t id_, size_t state_size_=0
    ) : client_addr(client_addr_),
        server_addr(nullptr),
        size(size_),
        id(id_),
        resource_type_id(kPOS_ResourceTypeId_Unknown),
        status(kPOS_HandleStatus_Create_Pending),
        state_status(kPOS_HandleStatus_StateReady), 
        state_size(state_size_),
        latest_version(0),
        ckpt_bag(nullptr),
        _hm(hm),
        _persist_thread(nullptr),
        _persist_promise(nullptr)
    {
        this->_state_preserve_counter.store(0);
    }
    

    /*!
     *  \param  size_           size of the resources represented by this handle
     *  \param  hm              handle manager which this handle belongs to
     *  \param  id_             index of this handle in the handle manager list
     *  \param  state_size_     size of the resource state behind this handle
     *  \note   this constructor is for hardware resource, whose client-side address
     *          and server-side address should be equal (e.g., memory)
     */
    POSHandle(
        size_t size_, void* hm, pos_u64id_t id_, size_t state_size_=0
    ) : client_addr(nullptr),
        server_addr(nullptr),
        size(size_),
        id(id_),
        resource_type_id(kPOS_ResourceTypeId_Unknown),
        status(kPOS_HandleStatus_Create_Pending),
        state_status(kPOS_HandleStatus_StateReady), 
        state_size(state_size_),
        latest_version(0),
        ckpt_bag(nullptr),
        _hm(hm),
        _persist_thread(nullptr),
        _persist_promise(nullptr)
    {
        this->_state_preserve_counter.store(0);
    }


    /*!
     *  \param  hm  handle manager which this handle belongs to
     *  \note   this constructor is invoked during restore process, where the content of 
     *          the handle will be resume by deserializing from checkpoint binary
     */
    POSHandle(
        void* hm
    ) : client_addr(nullptr),
        server_addr(nullptr),
        size(0),
        id(0),
        resource_type_id(kPOS_ResourceTypeId_Unknown),
        status(kPOS_HandleStatus_Create_Pending),
        state_status(kPOS_HandleStatus_StateMiss),
        state_size(0),
        latest_version(0),
        ckpt_bag(nullptr),
        _hm(hm),
        _persist_thread(nullptr),
        _persist_promise(nullptr)
    {
        this->_state_preserve_counter.store(0);
    }

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
     *  \param  handle_ptr  pointer to current handle
     *  \return POS_SUCCESS for successfully setting
     *          POS_FAILED_ALREADY_EXIST for duplication failed;
     */
    pos_retval_t set_passthrough_addr(void *addr, POSHandle* handle_ptr);


    /*!
    *  \brief  record a new parent handle of current handle
    */
    inline void record_parent_handle(POSHandle* parent){
        POS_CHECK_POINTER(parent);
        parent_handles.push_back(parent);
    }


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
    void collect_broken_handles(pos_broken_handle_list_t *broken_handle_list, uint16_t layer_id = 0);


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
     *  \brief  mark the status of state of the resource behind this handle
     *  \param  status the state status to mark
     */
    inline void mark_state_status(pos_handle_status_t status){
        POS_ASSERT(status == kPOS_HandleStatus_StateReady || status == kPOS_HandleStatus_StateMiss);
        this->state_status = status;
    }


    /*!
     *  \brief  restore the current handle when it becomes broken status
     *  \return POS_SUCCESS for successfully restore
     */
    pos_retval_t restore();


    /*!
     *  \brief  restore the current handle REMOTELY when it becomes broken status
     *  \return POS_SUCCESS for successfully restore
     */
    virtual pos_retval_t remote_restore(){ return POS_FAILED_NOT_IMPLEMENTED; }
    

    /*!
     *  \brief  reload the state behind current handle to the device
     *  \param  stream_id   stream for reloading the state
     *  \return POS_SUCCESS for successfully restore
     */
    pos_retval_t reload_state(uint64_t stream_id=0);


    /*!
     *  \brief  obtain the resource name begind this handle
     *  \return resource name begind this handle
     */
    virtual std::string get_resource_name(){ return std::string("unknown"); }


    /*!
     *  \brief  serialize the state of current handle into the binary area
     *  \param  serialized_area  pointer to the binary area
     *  \return POS_SUCCESS for successfully serilization
     */
    pos_retval_t serialize(void** serialized_area);


    /*!
     *  \brief  obtain the size of the serialize area of this handle
     *  \return size of the serialize area of this handle
     */
    inline uint64_t get_serialize_size(){
        return (
            /* size of basic field */   sizeof(uint64_t)
            /* basic field */           + this->__get_basic_serialize_size() 
            /* extra field */           + this->__get_extra_serialize_size()
        );
    }

    /*!
     *  \brief  reload checkpoint data to device
     *  \param  version     version of the checkpoint to be reloaded
     *  \param  load_latest whether to load the latest checkpoint to the GPU
     *                      (if this option is enabled, version param will be invalidated)
     *  \return POS_SUCCESS for successfully reloading
     */
    virtual pos_retval_t reload_state_to_device(pos_u64id_t version, bool load_latest=false){
        return POS_FAILED_NOT_IMPLEMENTED;
    }

    /*!
     *  \brief  deserialize the state of current handle from binary area
     *  \param  raw_area    raw data area
     *  \return POS_SUCCESS for successfully serialization
     */
    pos_retval_t deserialize(void* raw_area);


    /*!
     *  \brief  restore the current handle when it becomes broken status
     *  \return POS_SUCCESS for successfully restore
     */
    virtual pos_retval_t __restore(){
        return POS_FAILED_NOT_IMPLEMENTED;
    }


    /*!
    *  \brief  the typeid of the resource kind which this handle represents
    *  \note   the children class of this base class should replace this value
    *          with their own typeid
    */
    pos_resource_typeid_t resource_type_id;

    // exitance and state status of the resource behind this handle
    pos_handle_status_t status;
    pos_handle_status_t state_status;

    // the mocked client-side address of the handle
    void *client_addr;

    // the actual server-side address of the handle
    void *server_addr;
    
    // remote sserver address on the backup device
    void *remote_server_addr;

    // pointer to the instance of parent handle
    std::vector<POSHandle*> parent_handles;

    /*!
     *  \brief  resource type and handle indices of parent handles of this handle
     *  \note   this field is filled during restore process, for temporily store the indices
     *          of all parent handles of this handle
     */
    std::vector<std::pair<pos_resource_typeid_t, pos_u64id_t>> parent_handles_waitlist;

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
     *  \brief  latest modified version of this handle
     *  \note   this field should be updated after the succesful execution of API within worker thread
     *          (and the API inout/output this handle)
     */
    pos_u64id_t latest_version;
    
    /*!
     *  \brief  identify whether current handle is the latest used handle in the manager
     *  \note   this field is only used during restore phrase
     */
    bool is_lastest_used_handle;

    // index of this handle in the handle list of handle manager
    pos_u64id_t id;
 

    /* ==================== checkpoint add/commit/persist ==================== */
 public:
    /*!
     *  \brief  bag of checkpoints, implemented by different ckpt optimization level
     *  \note   it must be initialized by different implementations of stateful handle,
     *          as they might require different allocators and deallocators, see function
     *          init_ckpt_bag
     */
    POSCheckpointBag *ckpt_bag;

    /*!
     *  \brief  reset the state preserve counter to zero, to start a new checkpoint round
     */
    void reset_preserve_counter();

    /*!
     *  \brief  checkpoint the state of the resource behind this handle (sync)
     *  \note   only handle of stateful resource should implement this method
     *  \param  version_id  version of this checkpoint
     *  \param  ckpt_dir    directory to store checkpoint
     *  \param  stream_id   index of the stream to do this checkpoint
     *  \return POS_SUCCESS for successfully checkpointed
     */
    pos_retval_t checkpoint_sync(uint64_t version_id, std::string ckpt_dir="", uint64_t stream_id=0) const;

    /*!
     *  \brief  commit the state of the resource behind this handle
     *  \param  version_id  version of this checkpoint
     *  \param  stream_id   index of the stream to do this checkpoint
     *  \return POS_SUCCESS for successfully checkpointed
     */

    pos_retval_t checkpoint_commit(uint64_t version_id, uint64_t stream_id=0);

    /*!
     *  \brief  add the state of the resource behind this handle to another on-device resource syncly
     *  \param  version_id  version of this checkpoint
     *  \param  stream_id   index of the stream to do this checkpoint
     *  \return POS_SUCCESS for successfully checkpointed
     */
    pos_retval_t checkpoint_add(uint64_t version_id, uint64_t stream_id=0);

    /*!
     *  \brief  synchronize the persisting process
     *  \return POS_SUCCESS for successfully persist
     */
    pos_retval_t sync_persist();

 protected:
    // counter for exclude copy-on-write and checkpoint process
    std::atomic<uint8_t> _state_preserve_counter;

    // thread to persist checkpoint of the current handle
    std::thread *_persist_thread;
    std::promise<pos_retval_t> *_persist_promise;

    /*!
     *  \brief  commit the state of the resource behind this handle
     *  \param  version_id  version of this checkpoint
     *  \param  stream_id   index of the stream to do this checkpoint
     *  \param  from_cow    whether to dump from on-device cow buffer
     *  \param  is_sync     whether the commit process should be sync
     *  \return POS_SUCCESS for successfully checkpointed
     */
    virtual pos_retval_t __commit(uint64_t version_id, uint64_t stream_id=0, bool from_cow=false, bool is_sync=false) const { 
        return POS_FAILED_NOT_IMPLEMENTED;
    }

    /*!
     *  \brief  add the state of the resource behind this handle to on-device memory
     *  \param  version_id  version of this checkpoint
     *  \param  stream_id   index of the stream to do this checkpoint
     *  \note   the add process must be sync
     *  \return POS_SUCCESS for successfully checkpointed
     */
    virtual pos_retval_t __add(uint64_t version_id, uint64_t stream_id=0) const { 
        return POS_FAILED_NOT_IMPLEMENTED;
    }

    /*!
     *  \brief  persist the checkpoint to file system
     *  \param  ckpt_slot   the checkopoint slot which stores the host-side checkpoint
     *  \param  ckpt_dir    directory to store the checkpoint
     *  \param  stream_id   index of the stream on which checkpoint is commited
     *  \return POS_SUCCESS for successfully persist
     */
    pos_retval_t __persist(POSCheckpointSlot* ckpt_slot, std::string& ckpt_dir, uint64_t stream_id=0);

    /*!
     *  \brief  async thread to persist the checkpoint to file system
     *  \param  ckpt_slot   the checkopoint slot which stores the host-side checkpoint
     *  \param  ckpt_dir    directory to store the checkpoint
     *  \param  stream_id   index of the stream on which checkpoint is commited
     *  \return POS_SUCCESS for successfully persist
     */
    virtual pos_retval_t __persist_async_thread(POSCheckpointSlot* ckpt_slot, std::string& ckpt_dir, uint64_t stream_id=0){
        return POS_FAILED_NOT_IMPLEMENTED;
    }
    /* ==================== checkpoint add/commit/persist ==================== */



 protected:
    /*!
     *  \note   the belonging handle manager
     */
    void *_hm;

    /*!
     *  \brief  reload state of this handle back to the device
     *  \param  data        source data to be reloaded
     *  \param  offset      offset from the base address of this handle to be reloaded
     *  \param  size        reload size
     *  \param  stream_id   stream for reloading the state
     *  \param  on_device   whether the source data is on device
     */
    virtual pos_retval_t __reload_state(void* data, uint64_t offset, uint64_t size, uint64_t stream_id, bool on_device){
        return POS_FAILED_NOT_IMPLEMENTED;
    }

    /*!
     *  \brief  obtain the serilization size of basic fields of POSHandle
     *  \return the serilization size of basic fields of POSHandle
     */
    uint64_t __get_basic_serialize_size();


    /*!
     *  \brief  obtain the serilization size of extra fields of specific POSHandle type
     *  \return the serilization size of extra fields of POSHandle
     */
    virtual uint64_t __get_extra_serialize_size(){ return 0; }


    /*!
     *  \brief  serialize the basic state of current handle into the binary area
     *  \param  serialized_area  pointer to the binary area
     *  \return POS_SUCCESS for successfully serilization
     */
    pos_retval_t __serialize_basic(void* serialized_area);


    /*!
     *  \brief  serialize the extra state of current handle into the binary area
     *  \param  serialized_area  pointer to the binary area
     *  \return POS_SUCCESS for successfully serilization
     */
    virtual pos_retval_t __serialize_extra(void* serialized_area){
        return POS_SUCCESS;
    }


    /*!
     *  \brief  deserialize basic field of this handle
     *  \param  raw_data    raw data area that store the serialized data
     *  \return POS_SUCCESS for successfully deserialize
     */
    pos_retval_t __deserialize_basic(void* raw_data);


    /*!
     *  \brief  deserialize extra field of this handle
     *  \param  sraw_data    raw data area that store the serialized data
     *  \return POS_SUCCESS for successfully deserilization
     */
    virtual pos_retval_t __deserialize_extra(void* raw_data){
        return POS_SUCCESS;
    }

    /*!
     *  \brief  initialize checkpoint bag of this handle
     *  \note   it must be implemented by different implementations of stateful 
     *          handle, as they might require different allocators and deallocators
     *  \return POS_SUCCESS for successfully initialization
     */
    virtual pos_retval_t init_ckpt_bag(){ return POS_FAILED_NOT_IMPLEMENTED; }
};

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
     *  \param  is_stateful indicate whether the resource behind such handle conatains state
     */
    POSHandleManager(bool passthrough = false, bool is_stateful = false)
        : _base_ptr(kPOS_ResourceBaseAddr), _passthrough(passthrough), _is_stateful(is_stateful)
    {}

    ~POSHandleManager() = default;
    
    /*!
     *  \brief  allocate and restore handles for provision, for fast restore
     *  \param  amount  amount of handles for pooling
     *  \return POS_SUCCESS for successfully preserving
     */
    virtual pos_retval_t preserve_pooled_handles(uint64_t amount){
        pos_retval_t retval = POS_SUCCESS;
        uint64_t i=0;
        T_POSHandle *handle = nullptr;
        
        for(i=0; i<amount; i++){
            retval = this->__allocate_mocked_resource(&handle, false);
            POS_CHECK_POINTER(handle);
            if(unlikely(retval != POS_SUCCESS)){
                POS_WARN_C("failed to preserve %s handle for fast restoring", handle->get_resource_name().c_str());
                retval = POS_FAILED;
                goto exit;
            }

            retval = handle->__restore();
            if(unlikely(retval != POS_SUCCESS)){
                POS_WARN_C("failed to restore %s handle after allocation for fast restoring", handle->get_resource_name().c_str());
                retval = POS_FAILED;
                goto exit;
            }

            this->_pooled_handles.insert(handle);
        }

    exit:
        return retval;
    }

    /*!
     *  \brief  restore handle from pool
     *  \param  handle  the handle to be restored
     *  \return POS_SUCCESS for successfully restoring
     *          POS_FAILED for failed pooled restoring, should fall back to normal path
     */
    virtual pos_retval_t try_restore_from_pool(T_POSHandle* handle){
        pos_retval_t retval = POS_SUCCESS;
        POSHandle *preserved_handle;

        POS_CHECK_POINTER(handle);

        if(unlikely(this->_pooled_handles.size() == 0)){
            retval = POS_FAILED;
            goto exit;
        }

        preserved_handle = (*(this->_pooled_handles.begin()));
        POS_CHECK_POINTER(preserved_handle);
        this->_pooled_handles.erase(this->_pooled_handles.begin());

        //! \todo   is simply reasssign server-side address enough?
        handle->server_addr = preserved_handle->server_addr;
        handle->status = kPOS_HandleStatus_Active;

    exit:
        return retval;
    }

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
        T_POSHandle** handle, 
        std::map</* type */ uint64_t, std::vector<POSHandle*>> related_handles,
        size_t size = kPOS_HandleDefaultSize,
        uint64_t expected_addr = 0,
        uint64_t state_size = 0
    );

    /*!
     *  \brief  allocate new mocked resource within the manager, based on checkpoint in the binary
     *  \note   this function is invoked during restore process
     *  \param  ckpt_raw_data   pointer to the checkpoint binary
     *  \return pointer to the newly allocated handle if successfully allocated
     *          nullptr is failed to allocate
     */
    T_POSHandle* allocate_mocked_resource_from_binary(void* ckpt_raw_data){
        T_POSHandle *handle = nullptr;

        POS_CHECK_POINTER(ckpt_raw_data);

        handle = new T_POSHandle(this);
        POS_CHECK_POINTER(handle);

        if(likely(handle->deserialize(ckpt_raw_data) == POS_SUCCESS)){
            this->_handles.push_back(handle);
            if(likely((uint64_t)(handle->client_addr) > this->_base_ptr)){
                this->_base_ptr = (uint64_t)(handle->client_addr);
            }
        } else {
            POS_WARN_C("failed to deserialize handle");
            delete handle;
        }
        
        if(handle->is_lastest_used_handle){
            this->latest_used_handle = handle;
        }

    exit:
        return handle;
    }
    
    /*!
     *  \brief  record a new handle that will be modified
     *  \param  handle  the handle that will be modified
     */
    inline void record_modified_handle(T_POSHandle* handle){
        POS_CHECK_POINTER(handle);
        _modified_handles.insert(handle);

        if(_host_stateful_handles.count(handle) > 0){
            _host_stateful_handles.erase(handle);
        }
    }

    inline void record_host_stateful_handle(T_POSHandle* handle){
        _host_stateful_handles.insert(handle);
    }

    inline bool is_host_stateful_handle(T_POSHandle* handle){
        return _host_stateful_handles.count(handle) > 0;
    }

    /*!
     *  \brief  clear all records of modified handles
     */
    inline void clear_modified_handle(){ 
        _modified_handles.clear();
    }

    /*!
     *  \brief  get all records of modified handles
     *  \return all records of modified handles
     */
    inline std::set<T_POSHandle*>& get_modified_handles(){
        return _modified_handles;
    }

    /*!
     *  \brief  obtain a handle by given client-side address
     *  \param  client_addr the given client-side address
     *  \param  handle      the resulted handle
     *  \param  offset      pointer to store the offset of the given address from the base address
     *  \return POS_FAILED_NOT_EXIST for no corresponding handle exists;
     *          POS_SUCCESS for successfully founded
     */
    virtual pos_retval_t get_handle_by_client_addr(void* client_addr, T_POSHandle** handle, uint64_t* offset=nullptr);

    /*!
     *  \brief    last-used handle
     *  \example  for device handle manager, one need to record the last-used device for later usage
     *            (e.g., cudaGetDevice, cudaMalloc)
     */
    T_POSHandle* latest_used_handle;

    //! \todo  mock
    void* backup_base_memory;

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
    inline T_POSHandle* get_handle_by_id(uint64_t id){
        if(unlikely(id >= this->get_nb_handles())){
            return nullptr;
        } else {
            return _handles[id];
        }
    }

    inline pos_retval_t mark_handle_status(T_POSHandle *handle, pos_handle_status_t status){
        typename std::map<uint64_t, T_POSHandle*>::iterator handle_map_iter;
        
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
                    /* handle */ handle_map_iter->second
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
                    /* handle */ handle_map_iter->second
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
    inline pos_retval_t record_handle_address(void* addr, T_POSHandle* handle){
        pos_retval_t retval = POS_SUCCESS;
        T_POSHandle *__tmp;
        uint64_t addr_u64 = (uint64_t)(addr);

        POS_CHECK_POINTER(handle);

        if(likely(POS_FAILED_NOT_EXIST == __get_handle_by_client_addr(addr, &__tmp))){
            _handle_address_map[addr_u64] = handle;
        } else {
            POS_CHECK_POINTER(__tmp);

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

    /*!
     *  \brief  indicate whether the resource behind such handle contains state
     */
    bool _is_stateful;

    std::vector<T_POSHandle*> _handles;
    
    /*!
     *  \brief  this map records all modified buffers since last checkpoint, 
     *          will be updated during parsing, and cleared during launching
     *          checkpointing op
     */
    std::set<T_POSHandle*> _modified_handles;

    /*!
     *  \brief  all staful handles, whose statee come from host, and never been modified
     */
    std::set<T_POSHandle*> _host_stateful_handles;

    /*!
     *  \brief  pooled active handles for fast restore
     */
    std::set<T_POSHandle*> _pooled_handles;

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
        T_POSHandle** handle, bool do_put = true, size_t size=kPOS_HandleDefaultSize, uint64_t expected_addr=0, uint64_t state_size = 0
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
    pos_retval_t __get_handle_by_client_addr(void* client_addr, T_POSHandle** handle, uint64_t* offset=nullptr);

 private:
    std::map<uint64_t, T_POSHandle*> _handle_address_map;
    std::unordered_map<uint64_t, T_POSHandle*> _deleted_handle_address_map;
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
    T_POSHandle** handle,
    std::map</* type */ uint64_t, std::vector<POSHandle*>> related_handles,
    size_t size,
    uint64_t expected_addr,
    uint64_t state_size
){
    return __allocate_mocked_resource(handle, true, size, state_size);
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
    T_POSHandle** handle,
    bool do_put,
    size_t size,
    uint64_t expected_addr,
    uint64_t state_size
){
    pos_retval_t retval = POS_SUCCESS;

    POS_CHECK_POINTER(handle);

    if(this->_passthrough){
        *handle = new T_POSHandle(
            /* size_ */ size,
            /* hm */ this,
            /* id_ */ this->_handles.size(),
            /* state_size_ */ state_size
        );
        POS_CHECK_POINTER(*handle);
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

        *handle = new T_POSHandle(
            /* client_addr */ (void*)_base_ptr,
            /* size_ */ size,
            /* hm */ this,
            /* id_ */ this->_handles.size(),
            /* state_size_ */ state_size
        );
        POS_CHECK_POINTER(*handle);

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

    if(do_put)
        this->_handles.push_back(*handle);

  exit:
    return retval;
}

/*!
 *  \brief  obtain a handle by given client-side address
 *  \param  client_addr the given client-side address
 *  \param  handle      the resulted handle
 *  \param  offset      pointer to store the offset of the given address from the base address
 *  \return POS_FAILED_NOT_EXIST for no corresponding handle exists;
 *          POS_SUCCESS for successfully founded
 */
template<class T_POSHandle>
pos_retval_t POSHandleManager<T_POSHandle>::get_handle_by_client_addr(void* client_addr, T_POSHandle** handle, uint64_t* offset){
    return __get_handle_by_client_addr(client_addr, handle, offset);
}

/*!
 *  \brief  obtain a handle by given client-side address
 *  \param  client_addr the given client-side address
 *  \param  handle      the resulted handle
 *  \param  offset      pointer to store the offset of the given address from the base address
 *  \note   this function should be internally invoked by get_handle_by_client_addr, which leave to children class to implement
 *  \return POS_FAILED_NOT_EXIST for no corresponding handle exists;
 *          POS_SUCCESS for successfully founded
 */
template<class T_POSHandle>
pos_retval_t POSHandleManager<T_POSHandle>::__get_handle_by_client_addr(void* client_addr, T_POSHandle** handle, uint64_t* offset){
    pos_retval_t ret = POS_SUCCESS;
    T_POSHandle *handle_ptr;
    uint64_t i;
    uint64_t client_addr_u64 = (uint64_t)(client_addr);

    typename std::map<uint64_t, T_POSHandle*>::iterator handle_map_iter;

    POS_CHECK_POINTER(handle);
    
    /*!
     *  \note   direct case: the given address is exactly the base address
     */
    if(unlikely(this->_handle_address_map.count(client_addr_u64) > 0)){
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
     *  \note   most of query will fall back to this part
     */
    handle_map_iter = this->_handle_address_map.lower_bound(client_addr_u64);
    if(handle_map_iter != this->_handle_address_map.begin()){
        // get the first handle less than the given address
        handle_map_iter--;
        handle_ptr = handle_map_iter->second;

        POS_ASSERT(
            handle_ptr->status != kPOS_HandleStatus_Deleted && handle_ptr->status != kPOS_HandleStatus_Delete_Pending
        );

        if(likely(
            (uint64_t)(handle_ptr->client_addr) <= client_addr_u64 
            && client_addr_u64 < (uint64_t)(handle_ptr->client_addr) + handle_ptr->size
        )){
            *handle = handle_ptr;

            if(offset != nullptr){
                *offset = client_addr_u64 - (uint64_t)(handle_ptr->client_addr);
            }

            goto exit;
        }
    }

not_found:
    *handle = nullptr;
    ret = POS_FAILED_NOT_EXIST;

exit:
    return ret;
}
