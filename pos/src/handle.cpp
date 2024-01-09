#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <type_traits>

#include <stdint.h>
#include <assert.h>

#include "pos/include/common.h"
#include "pos/include/log.h"
#include "pos/include/handle.h"

/*!
 *  \brief  setting both the client-side and server-side address of the handle 
 *          after finishing allocation
 *  \param  addr        the setting address of the handle
 *  \param  handle_ptr  shared pointer to current handle
 *  \return POS_SUCCESS for successfully setting
 *          POS_FAILED_ALREADY_EXIST for duplication failed;
 */
pos_retval_t POSHandle::set_passthrough_addr(void *addr, std::shared_ptr<POSHandle> handle_ptr){ 
    using handle_type = typename std::decay<decltype(*this)>::type;

    pos_retval_t retval = POS_SUCCESS;
    client_addr = addr;
    server_addr = addr;
    POSHandleManager<handle_type> *hm_cast = (POSHandleManager<handle_type>*)_hm;

    POS_CHECK_POINTER(hm_cast);
    POS_ASSERT(handle_ptr.get() == this);

    // record client-side address to the map
    retval = hm_cast->record_handle_address(addr, handle_ptr);

exit:
    return retval;
}

/*!
 *  \brief  mark the status of this handle
 *  \param  status the status to mark
 *  \note   this function would call the inner function within the corresponding handle manager
 */
void POSHandle::mark_status(pos_handle_status_t status){
    using handle_type = typename std::decay<decltype(*this)>::type;
    POSHandleManager<handle_type> *hm_cast = (POSHandleManager<handle_type>*)this->_hm;
    POS_CHECK_POINTER(hm_cast);
    hm_cast->mark_handle_status(this, status);
}
