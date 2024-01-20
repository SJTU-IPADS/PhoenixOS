#include <iostream>
#include <vector>
#include <cuda.h>
#include <dlfcn.h>
#include <cuda_runtime.h>
#include <csignal>

#include "cudam.h"
#include "utils.h"
#include "buffer_manager.h"

#if !defined(CUDAM_ANALYZER_MODE)
    BufferManager bufferManager(/* do_hijack */ 1);
#endif

/* add buffer relation */
uint8_t Buffer::addRelation(Buffer *peer_buffer, const void *peer_base_addr, const void *local_base_addr, uint64_t size, bool isIn){
    // check whether the provided base addresses are in range
    if(!peer_buffer->isInRange(peer_base_addr, /* isExclusive */ false)){
        CUDAM_ERROR(
            "failed to add %s relation between buffers (peer_base: %p, local_base: %p, size: %lu), provided peer base address doesn't locate in the peer buffer",
            isIn ? "in" : "out", peer_base_addr, local_base_addr, size
        );
        return RETVAL_ERROR_INVALID;
    }
    if(!isInRange(local_base_addr, /* isExclusive */ false)){
        CUDAM_ERROR(
            "failed to add %s relation between buffers (peer_base: %p, local_base: %p, size: %lu), provided local base address doesn't locate in the local buffer",
            isIn ? "in" : "out", peer_base_addr, local_base_addr, size
        );
        return RETVAL_ERROR_INVALID;
    }
    
    // check whether relation already exist
    BufferRelation *pre_relation = getRelation(peer_base_addr, local_base_addr, size, isIn);
    if(pre_relation != nullptr){
        /* don't print, it's too annoying... */
        // CUDAM_WARNING(
        //     "failed to add %s relation between buffers (peer_base: %p, local_base: %p, size: %lu), relation already exists",
        //     isIn ? "in" : "out", peer_base_addr, local_base_addr, size
        // );
        return RETVAL_ERROR_ALREADY_EXIST;
    }

    // record new relation
    BufferRelation *new_relation = new BufferRelation(peer_buffer, peer_base_addr, local_base_addr, size);
    if(isIn){
        _in_relations.push_back(new_relation);
    } else {
        _out_relations.push_back(new_relation);
    }

    CUDAM_DEBUG_MESSAGE(
        "add %s relation between buffers (peer_base: %p, peer_rl_base: %p, local_base: %p, local_rl_base: %p, size: %lu)",
        isIn ? "in" : "out", peer_buffer->getAddr(), peer_base_addr, getAddr(), local_base_addr, size
    );

    return RETVAL_SUCCESS;
}

/* add buffer relation */
uint8_t Buffer::addRelation(BufferRelation *relation, bool isIn){
    // check whether relation already exist
    BufferRelation *pre_relation = getRelation(
        relation->getPeerBaseAddr(), relation->getLocalBaseAddr(), relation->getPeerSize(), isIn
    );
    if(pre_relation != nullptr){
        /* don't print, it's too annoying... */
        // CUDAM_WARNING(
        //     "failed to add %s relation between buffers (peer_base: %p, local_base: %p, size: %lu), relation already exists",
        //     isIn ? "in" : "out", 
        //     relation.getPeerBaseAddr(), relation.getLocalBaseAddr(), relation.getPeerSize()
        // );
        return RETVAL_ERROR_ALREADY_EXIST;
    }

    if(isIn){
        _in_relations.push_back(relation);
    } else {
        _out_relations.push_back(relation);
    }
    return RETVAL_SUCCESS;
}

/* get buffer relation by peer base address */
BufferRelation* Buffer::getRelation(const void *peer_base_addr, const void *local_base_addr, uint64_t peer_size, bool isIn){
    std::vector<BufferRelation*>::iterator it;

    auto isPeer = [&](BufferRelation *relation){
        if(peer_base_addr != nullptr && local_base_addr != nullptr)
            return relation->getPeerBaseAddr() == peer_base_addr 
                && relation->getLocalBaseAddr() == local_base_addr
                && relation->getPeerSize() == peer_size;
        else if(peer_base_addr != nullptr && local_base_addr == nullptr)
            return relation->getPeerBaseAddr() == peer_base_addr
                && relation->getPeerSize() == peer_size;
        else
            return false;
    };

    if(isIn){
        it = std::find_if(_in_relations.begin(), _in_relations.end(), isPeer);
        return it == _in_relations.end() ? nullptr : *it;
    } else {
        it = std::find_if(_out_relations.begin(), _out_relations.end(), isPeer);
        return it == _out_relations.end() ? nullptr : *it;
    }
}   

/* obtain the checksum of the buffer */
uint8_t Buffer::getChecksum(const void *base, uint64_t size, uint32_t *checksum){
    int result = RETVAL_SUCCESS;
    uint8_t *__data;
    cudaError_t lretval;
    cudaError_t (*lcudaMemcpy) (void *, void const *, size_t, cudaMemcpyKind);

    assert(_has_freed != true);
    assert((uint8_t*)base >= _addr && (uint8_t*)base <= (uint8_t*)_addr+_size);
    assert((uint8_t*)base+size >= _addr && (uint8_t*)base+size <= (uint8_t*)_addr+_size);
    
    if(_device_id == BUFFER_DEVICE_ID_CPU || _device_id == BUFFER_DEVICE_ID_UNIFIED){
        try {
            /*!
             * \note    1.  cpu buffer, we can directly obtain the content checksum;
             *          2.  the buffer could be already freed by libc free(), so we 
             *              need to catch the SIGSEGV signal here, and recover from it
             */
            *checksum = utils_crc32b((const uint8_t*)base, size);
        } catch (std::exception& e){
            setFreed();
            CUDAM_WARNING_MESSAGE("catch SIGSEGV while accessing buffer %p, set as freed", base);
            // std::cerr << "Exception caught: " << e.what() << std::endl;
        }
    } else {
        /* device buffer need to obtain data from device, then calculate checksum */
        __data = (uint8_t*)malloc(sizeof(uint8_t)*_size);
        assert(__data != nullptr);

        lcudaMemcpy = (cudaError_t (*)(void *, void const *, size_t, cudaMemcpyKind))dlsym(RTLD_NEXT, "cudaMemcpy");
        lretval = lcudaMemcpy(__data, base, size, cudaMemcpyDeviceToHost);

        if(lretval == cudaSuccess){
            *checksum = utils_crc32b(__data, size);
        } else {
            CUDAM_ERROR("failed to retreive data from device");
            result = RETVAL_ERROR_INTERNAL_ERROR;
        }

        free(__data);
    }

    return result;
}

/* record new buffer in the manager */
uint8_t BufferManager::recordBuffer(void **ptr, const void *addr, uint64_t size, int16_t device_id, bool is_page_locked, bool is_unified){
    void **new_ptr = ptr;
    const void *new_base_addr = addr;
    uint64_t new_size = size;

    // setp 1: check whether the base address locates at any previous-recorded buffer
    Buffer *pre_left_buffer = getBufferByAddr(addr, device_id);
    if(pre_left_buffer != nullptr && !pre_left_buffer->hasFreed()){
        // if so, update ptr, base addr and size
        new_ptr = pre_left_buffer->getPtr();
        new_base_addr = pre_left_buffer->getAddr();
        new_size = size + ((uint8_t*)addr - (uint8_t*)new_base_addr);
        CUDAM_DEBUG_MESSAGE(
            "detect the left-overlapped buffer, extend buffer base from %p to %p, buffer size from %lu to %lu",
            addr, new_base_addr, size, new_size
        );
    }

    // setp 2: check whether the tail address locates at any previous-recorded buffer
    Buffer *pre_right_buffer = getBufferByAddr((uint8_t*)addr + size, device_id);
    if(pre_right_buffer != nullptr && !pre_right_buffer->hasFreed()){
        // if so, update size
        uint64_t temp_new_size = new_size;
        new_size += (
            ((uint8_t*)pre_right_buffer->getAddr() + pre_right_buffer->getSize()) - ((uint8_t*)addr + size)
        );
        CUDAM_DEBUG_MESSAGE(
            "detect the right-overlapped buffer, extend buffer tail from %p to %p, buffer size from %lu to %lu",
            ((uint8_t*)addr + size), ((uint8_t*)pre_right_buffer->getAddr() + pre_right_buffer->getSize()), 
            temp_new_size, new_size
        );
    }

    // step 3: find all buffers to be merged
    std::vector<Buffer*> merged_buffer_list = getFullBuffersByRange(
        /* base_addr */ new_base_addr,
        /* size */ new_size,
        /* isExclusive */ false,
        /* device_id */ device_id
    );

    // expel those buffers that don't have the same properties
    auto not_same_properties = [&](Buffer* buffer){
        bool doExpel = (
            buffer->getDeviceId() != device_id
            || buffer->isUnified() != is_unified
            || buffer->isPageLocked() != is_page_locked
        );

        if(doExpel){
            CUDAM_WARNING(
                "denied buffers that not matched to be merged (device id: (%d/%d), unified: (%d/%d), page-locked: (%d/%d))",
                buffer->getDeviceId(), device_id, buffer->isUnified(), is_unified, buffer->isPageLocked(), is_page_locked
            );
        }

        return doExpel;
    };
    merged_buffer_list.erase(
        std::remove_if(merged_buffer_list.begin(), merged_buffer_list.end(), not_same_properties),
        merged_buffer_list.end()
    );

    // step 4: create a new buffer
    Buffer *new_buffer 
        = new Buffer(new_ptr, new_base_addr, new_size, device_id, is_page_locked, is_unified);
    assert(new_buffer != nullptr);
    _buffers.push_back(new_buffer);

    CUDAM_DEBUG_MESSAGE(
        "record new %s buffer (%p-%p, size: %lu)",
        convertBufferPosToString(device_id, is_page_locked, is_unified),
        new_base_addr, (uint8_t*)new_base_addr+new_size, new_size
    );

    // step 5: update all peer buffers associated with buffers in merged_buffer_list,
    //         specifically, update their peer buffer to be the new buffer
    for(Buffer *merged_buffer : merged_buffer_list){
        // update all peer buffers within in-relation
        for (BufferRelation *in_br : merged_buffer->getAllRelations(/* isIn */ true)){
            Buffer *peer_buffer = in_br->getPeerBuffer();
            
            // update their out relation
            for (BufferRelation *peer_out_br : peer_buffer->getAllRelations(/* isIn */ false)){
                if(peer_out_br->getPeerBuffer() == merged_buffer){
                    peer_out_br->setPeerBuffer(new_buffer);
                }
            }

            // THIS IS TRICKY!
            // if the buffer has relationship to itself, we need to manually update 
            // the related in-relation here, because the following loop won't update 
            // it as we have already change the out-relation above
            if(peer_buffer == merged_buffer){
                for (BufferRelation *peer_in_br : peer_buffer->getAllRelations(/* isIn */ true)){
                    if(peer_in_br->getPeerBuffer() == merged_buffer){
                        peer_in_br->setPeerBuffer(new_buffer);
                    }
                }
            }
        }
        
        // update all peer buffers within out-relation
        for (BufferRelation *out_br : merged_buffer->getAllRelations(/* isIn */ false)){            
            Buffer *peer_buffer = out_br->getPeerBuffer();

            // update their in relation
            for (BufferRelation *peer_in_br : peer_buffer->getAllRelations(/* isIn */ true)){
                if(peer_in_br->getPeerBuffer() == merged_buffer){
                    peer_in_br->setPeerBuffer(new_buffer);
                }
            }
        }
    }

    // step 6: borrow all BufferRelation from these merged buffers to the new big buffer
    for(Buffer *merged_buffer : merged_buffer_list){
        for (BufferRelation *in_br : merged_buffer->getAllRelations(/* isIn */ true)){
            new_buffer->addRelation(in_br, true);
        }
        for (BufferRelation *out_br : merged_buffer->getAllRelations(/* isIn */ false)){
            new_buffer->addRelation(out_br, false);
        }
    }

    // step optional: log these merge operation
    if(merged_buffer_list.size() > 0){
        uint64_t buffer_index = 1;
        CUDAM_DEBUG_MESSAGE("merged %lu buffer(s) while recording new buffer, details:", merged_buffer_list.size());
        CUDAM_DEBUG_MESSAGE(
            "new buffer: base=%p, size=%lu, device=%d",
            new_base_addr, new_size, new_buffer->getDeviceId()
        );
        for(Buffer *merged_buffer : merged_buffer_list){
            CUDAM_DEBUG_MESSAGE(
                "    %luth buffer: base=%p, size=%lu, device=%d",
                buffer_index, merged_buffer->getAddr(), merged_buffer->getSize(), merged_buffer->getDeviceId()
            );
            buffer_index += 1;
            assert(merged_buffer->getDeviceId() == new_buffer->getDeviceId());
        }
    }
    
    // step 7: free all merged buffers
    for(Buffer *merged_buffer : merged_buffer_list){
        _buffers.erase(
            std::remove(
                _buffers.begin(),
                _buffers.end(),
                merged_buffer
            )
        );
        
        delete merged_buffer;
    }

    return RETVAL_SUCCESS;
}

/* mark the buffer as freed */
uint8_t BufferManager::markBufferFreed(void *addr){
    // obtain the 
    Buffer *pre_buffer = getBufferByAddr(addr, BUFFER_DEVICE_ID_UNKOWN);
    if(pre_buffer == nullptr){
        // CUDAM_WARNING("failed to mark buffer as freed (base: %p), no such buffer exist\n", addr);
        return RETVAL_ERROR_NOT_FOUND;
    }

    if(pre_buffer->hasFreed()){
        CUDAM_WARNING("failed to mark buffer as freed (base: %p), buffer already marked as freed\n", addr);
        return RETVAL_ERROR_ALREADY_EXIST;
    }

    if(pre_buffer->getAddr() != addr){
        CUDAM_WARNING(
            "try to free address %p within buffer (base: %p, size: %lu) without using base address\n",
            addr, pre_buffer->getAddr(), pre_buffer->getSize()
        );
    }

    pre_buffer->setFreed();
    CUDAM_DEBUG_MESSAGE(
        "mark %s buffer (base: %p, size: %lu) as freed\n",
        convertBufferPosToString(pre_buffer->getDeviceId(), pre_buffer->isPageLocked(), pre_buffer->isUnified()),
        pre_buffer->getAddr(), pre_buffer->getSize()
    );

    return RETVAL_SUCCESS;
}

/* printf all buffer for debug */
void BufferManager::printAllBuffers(){
    uint64_t i=0;
    uint32_t local_checksum, remote_checksum;
    for(Buffer *buffer : _buffers){
        if(buffer->hasFreed()){
            continue;
        }

        CUDAM_DEBUG_MESSAGE(
            "%luth buffer: base=%p, size=%lu, tail=%p",
            i, buffer->getAddr(), buffer->getSize(),
            (uint8_t*)(buffer->getAddr()) + buffer->getSize()
        );

        for(BufferRelation *out_relations : buffer->getAllRelations(/* isIn */ false)){
            if(out_relations->getPeerBuffer()->hasFreed()){
                continue;
            }

            buffer->getChecksum(out_relations->getLocalBaseAddr(), out_relations->getPeerSize(), &local_checksum);
            out_relations->getPeerBuffer()->getChecksum(out_relations->getPeerBaseAddr(), out_relations->getPeerSize(), &remote_checksum);

            CUDAM_DEBUG_MESSAGE(
                "    -> local base/tail = %p/%p (crc: %u), remote base/tail = %p/%p (crc: %u), size=%lu",
                out_relations->getLocalBaseAddr(), (uint8_t*)out_relations->getLocalBaseAddr()+out_relations->getPeerSize(),
                local_checksum,
                out_relations->getPeerBaseAddr(), (uint8_t*)out_relations->getPeerBaseAddr()+out_relations->getPeerSize(),
                remote_checksum,
                out_relations->getPeerSize()
            );
        }
        i += 1;
    }
}

/* obtain the one-and-only buffer that include the given address */
Buffer* BufferManager::getBufferByAddr(const void *addr, int16_t device_id){
    std::vector<Buffer*> *buffer_list = new std::vector<Buffer*>;
    for(Buffer *buffer : _buffers){
        if(buffer->hasFreed()){
            continue;
        }
        
        // ignore those buffers that locate on different device
        // (if given device_id)
        if(device_id != BUFFER_DEVICE_ID_UNKOWN && buffer->getDeviceId() != device_id){
            continue;
        }

        if(buffer->isInRange(addr, /* isExclusive */ false)){
            buffer_list->push_back(buffer);
        }
    }

    if(buffer_list->size() > 1){
        CUDAM_WARNING("find multiple buffers contain address %p, it's not normal!", addr);
    }
    
    if(buffer_list->size() == 0){
        delete buffer_list;
        return nullptr;
    } else {
        Buffer* ret_buffer = (*buffer_list)[0];
        delete buffer_list;
        return ret_buffer;
    }
}

/* obtain buffers that partially locate within the given range */
std::vector<Buffer*> BufferManager::getPartialBuffersByRange(const void *base_addr, uint64_t size, bool isExclusive, int16_t device_id){
    std::vector<Buffer*> buffer_list;

     auto inclusiveContain = [&](Buffer *buffer) -> bool {
        return buffer->getAddr() <= ((uint8_t*)base_addr+size)
            && ((uint8_t*)buffer->getAddr()+buffer->getSize()) >= base_addr;
    };

    auto exclusiveContain = [&](Buffer *buffer) -> bool {
        return buffer->getAddr() < ((uint8_t*)base_addr+size)
            && ((uint8_t*)buffer->getAddr()+buffer->getSize()) > base_addr;
    };
    
    for(Buffer *buffer : _buffers){
        if(buffer->hasFreed()){
            continue;
        }

        // ignore those buffers that locate on different device
        // (if given device_id)
        if(device_id != BUFFER_DEVICE_ID_UNKOWN && buffer->getDeviceId() != device_id){
            continue;
        }

        if(isExclusive){
            if(exclusiveContain(buffer)){
                buffer_list.push_back(buffer);
            }
        } else {
            if(inclusiveContain(buffer)){
                buffer_list.push_back(buffer);
            }
        }
    }

    return buffer_list;
}

/* obtain buffers that totally locate within the given range */
std::vector<Buffer*> BufferManager::getFullBuffersByRange(const void *base_addr, uint64_t size, bool isExclusive, int16_t device_id){
    std::vector<Buffer*> buffer_list;

    auto inclusiveContain = [&](Buffer *buffer) -> bool {
        return buffer->getAddr() >= base_addr 
            && ((uint8_t*)buffer->getAddr()+buffer->getSize()) <= ((uint8_t*)base_addr+size);
    };

    auto exclusiveContain = [&](Buffer *buffer) -> bool {
        return buffer->getAddr() > base_addr 
            && ((uint8_t*)buffer->getAddr()+buffer->getSize()) < ((uint8_t*)base_addr+size);
    };

    for(Buffer *buffer : _buffers){
        if(buffer->hasFreed()){
            continue;
        }

        // ignore those buffers that locate on different device
        // (if given device_id)
        if(device_id != BUFFER_DEVICE_ID_UNKOWN && buffer->getDeviceId() != device_id){
            continue;
        }

        if(isExclusive){
            if(exclusiveContain(buffer)){
                buffer_list.push_back(buffer);
            }
        } else {
            if(inclusiveContain(buffer)){
                buffer_list.push_back(buffer);
            }
        }
    }

    return buffer_list;
}

/* profiling thread */
void BufferManager::profiling_thread_func(){    
    while(1){
        /* execute profiling routine */
        if(!_terminated)
            _profiling_routine();
        else 
            break;

        /* sleep for PROFILING_INTERVAL_MICROSECOND */
        std::this_thread::sleep_for(std::chrono::microseconds(PROFILING_INTERVAL_MICROSECOND));
    }
}

/* execution logic of profiling thread */
void BufferManager::_profiling_routine(){
    uint8_t result;
    uint32_t checksum, peer_checksum;
    uint64_t i, current_time;
    uint64_t buffer_id=0, nb_buffers=0, nb_active_buffer=0, nb_dup_buffer=0;
    uint64_t overall_buffer_size=0, overall_active_buffer_size=0, overall_dup_buffer_size=0;
    uint64_t nb_device_buffer=0, nb_cpu_buffer=0, nb_unified_buffer=0;
    uint64_t overall_device_buffer_size=0, overall_cpu_buffer_size=0, overall_unified_buffer_size=0;

    Buffer *peer_buffer;

    char print_buffer[4096] = {0};
    assert(_checkpoint_file_fd != NULL);

    // do profiling
    lockProfilingMtx();
    CUDAM_DEBUG_MESSAGE("[profiling routine] start checkpointing...");

    // obtain current timestamp
    current_time = utils_timestamp_ns();
    
    // travese all buffers
    nb_buffers = _buffers.size();
    for(Buffer *buffer : _buffers){
        CUDAM_DEBUG_MESSAGE_WITHOUT_NEWLINE(
            /* is_last_call */ nb_buffers == buffer_id+1,
            "[profiling routine] anayzing buffer %lu/%lu", buffer_id+1, nb_buffers
        );
        buffer_id += 1;

        // update overall buffer size
        overall_buffer_size += buffer->getSize();

        // if the buffer has been freed, continue
        if(buffer->hasFreed()){
            continue;
        }
        
        // update active buffer metadata
        nb_active_buffer += 1;
        overall_active_buffer_size += buffer->getSize();
        
        // get checksum of the each buffer, and identify duplication buffer
        // we only check the cpu buffer here
        if(buffer->getDeviceId() == BUFFER_DEVICE_ID_CPU){
            nb_cpu_buffer += 1;
            overall_cpu_buffer_size += buffer->getSize();

            // we traverse all out buffer here, to get their checksum, and compare
            for(BufferRelation *out_relation : buffer->getAllRelations(/* isIn */ false)){
                // get local checksum
                if(buffer->getChecksum(out_relation->getLocalBaseAddr(), out_relation->getPeerSize(), &checksum) != RETVAL_SUCCESS){
                    continue;
                }

                // get peer checksum
                peer_buffer = out_relation->getPeerBuffer();
                if(peer_buffer->hasFreed()){
                    continue;
                }

                if(peer_buffer->getChecksum(out_relation->getPeerBaseAddr(), out_relation->getPeerSize(), &peer_checksum) != RETVAL_SUCCESS){
                    continue;
                }

                // if checksum is the same, then duplication buffers they are
                if(peer_checksum == checksum){
                    overall_dup_buffer_size += out_relation->getPeerSize();
                    nb_dup_buffer += 1;
                }
            }
        } else if(buffer->getDeviceId() == BUFFER_DEVICE_ID_UNIFIED){
            nb_unified_buffer += 1;
            overall_unified_buffer_size += buffer->getSize();
        } else {
            nb_device_buffer += 1;
            overall_device_buffer_size += buffer->getSize();
        }
    }

    sprintf(
        print_buffer, 
        "%lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu\n",
        /* timestamp */ current_time,
        /* number of buffer */ nb_buffers,
        /* number of active buffer */ nb_active_buffer,
        /* number of duplication buffer */ nb_dup_buffer,
        /* numbver of cpu buffer */ nb_cpu_buffer,
        /* number of device buffer */ nb_device_buffer,
        /* number of unified buffer */ nb_unified_buffer,
        /* overall buffer size*/ overall_buffer_size,
        /* overall active buffer size */ overall_active_buffer_size,
        /* overall duplication buffer size */ overall_dup_buffer_size,
        /* overall cpu buffer size */ overall_cpu_buffer_size,
        /* overall device buffer size */ overall_device_buffer_size,
        /* overall unified buffer size */ overall_unified_buffer_size
    );

    fputs(print_buffer, _checkpoint_file_fd);
    fflush(_checkpoint_file_fd);
    CUDAM_DEBUG_MESSAGE("[profiling routine] result: %s", print_buffer);
    
    // output statistics
    // *_checkpoint_file_ofs 
    //     << /* timestamp */ current_time << " "
    //     << /* number of buffer */ nb_buffers << " "
    //     << /* number of active buffer */ nb_active_buffer << " "
    //     << /* number of duplication buffer */ nb_dup_buffer << " "
    //     << /* numbver of cpu buffer */ nb_cpu_buffer << " "
    //     << /* number of device buffer */ nb_device_buffer << " "
    //     << /* number of unified buffer */ nb_unified_buffer << " "
    //     << /* overall buffer size*/ overall_buffer_size << " "
    //     << /* overall active buffer size */ overall_active_buffer_size << " "
    //     << /* overall duplication buffer size */ overall_dup_buffer_size << " "
    //     << /* overall cpu buffer size */ overall_cpu_buffer_size << " "
    //     << /* overall device buffer size */ overall_device_buffer_size << " "
    //     << /* overall unified buffer size */ overall_unified_buffer_size
    //     << std::endl;
    // _checkpoint_file_ofs->flush();

    CUDAM_DEBUG_MESSAGE("[profiling routine] finished checkpointing...");
    unlockProfilingMtx();
}