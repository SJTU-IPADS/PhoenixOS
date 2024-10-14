#include <iostream>
#include "pos/include/common.h"
#include "pos/include/dag.h"
#include <cuda_runtime_api.h>
#include <cuda.h>
#include "pos/cuda_impl/handle.h"
#include "pos/cuda_impl/parser.h"
#include "pos/cuda_impl/client.h"
#include "pos/cuda_impl/api_context.h"

namespace ps_functions
{
namespace cuda_free
{
	POS_RT_FUNC_PARSER()
	{
		pos_retval_t retval = POS_SUCCESS;
		POSClient_CUDA *client;
		POSHandleManager_CUDA_Device *hm_device;
		POSHandle_CUDA_Device *device_handle_0;
		POSHandleManager_CUDA_Memory *hm_memory;
		POSHandle_CUDA_Memory *memory_handle_0;

		POS_CHECK_POINTER(wqe);
		POS_CHECK_POINTER(ws);

		client = (POSClient_CUDA*)(wqe->client);
		POS_CHECK_POINTER(client);

		#if POS_ENABLE_DEBUG_CHECK
		    // check whether given parameter is valid
		   if(unlikely(wqe->api_cxt->params.size() != 1)) {
		       POS_WARN(
		           "parse(cuda_free): failed to parse, given %lu params, 1 expected",
		           wqe->api_cxt->params.size()
		       );
		       retval = POS_FAILED_INVALID_INPUT;
		       goto exit;
		   }
		#endif

		// obtain handle manager of kPOS_ResourceTypeId_CUDA_Device
		hm_device = pos_get_client_typed_hm(
		   client, kPOS_ResourceTypeId_CUDA_Device, POSHandleManager_CUDA_Device
		);
		POS_CHECK_POINTER(hm_device);

		// obtain handle from hm
		POS_CHECK_POINTER(device_handle_0 = hm_device->latest_used_handle);

		// record the related handle to QE
		wqe->record_handle<kPOS_Edge_Direction_In>({
		   /* handle */ device_handle_0
		});

		// obtain handle manager of kPOS_ResourceTypeId_CUDA_Memory
		hm_memory = pos_get_client_typed_hm(
		   client, kPOS_ResourceTypeId_CUDA_Memory, POSHandleManager_CUDA_Memory
		);
		POS_CHECK_POINTER(hm_memory);

		// record the related handle to QE
		wqe->record_handle<kPOS_Edge_Direction_Delete>({
		   /* handle */ memory_handle_0,
		   /* param_index */ 0,
		   /* offset */ pos_api_param_value(wqe, 0, uint64_t) - (uint64_t)(memory_handle_0->client_addr)
		});

		// launch the op to the dag
		retval = client->dag.launch_op(wqe);

		// parser exit
		exit:

		return retval;

	}
} // namespace cuda_free
} // namespace ps_functions
