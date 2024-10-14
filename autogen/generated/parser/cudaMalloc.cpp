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
namespace cuda_malloc
{
	POS_RT_FUNC_PARSER()
	{
		pos_retval_t retval = POS_SUCCESS;
		POSClient_CUDA *client;
		POSHandleManager_CUDA_Device *hm_device
		POSHandle_CUDA_Device *device_handle_0
		POSHandleManager_CUDA_Memory *hm_memory
		POSHandle_CUDA_Memory *memory_handle_0

		POS_CHECK_POINTER(wqe);
		POS_CHECK_POINTER(ws);

		client = (POSClient_CUDA*)(wqe->client);
		POS_CHECK_POINTER(client);

		#if POS_ENABLE_DEBUG_CHECK
		    // check whether given parameter is valid
		   if(unlikely(wqe->api_cxt->params.size() != 2)) {
		       POS_WARN(
		           "parse(cuda_malloc): failed to parse, given %lu params, 2 expected",
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

		// create handle in the hm
		retval = hm_memory->allocate_mocked_resource(
		   /* handle */ &memory_handle_0,
		   /* related_handles */ std::map<uint64_t, std::vector<POSHandle*>>({
		        {
		            /* id */ kPOS_ResourceTypeId_CUDA_Device,
		            /* handles */ std::vector<POSHandle*>({
		                 device_handle_0
		            })
		        }
		   }),
		   /* size */ kPOS_HandleDefaultSize,
		   /* expected_addr */ 0,
		   /* state_size */ pos_api_param_value(wqe, 1, uint64_t)
		);
		if(unlikely(retval != POS_SUCCESS)){
		   POS_WARN("parse(cuda_malloc): failed to allocate mocked POSHandle_CUDA_Memory resource within the handler manager");
		   memset(pos_api_param_addr(wqe, 0), 0, sizeof(uint64_t));
		   goto exit;
		} else {
		   memcpy(pos_api_param_addr(wqe, 0), &(memory_handle_0->client_addr), sizeof(uint64_t));
		}

		// record the related handle to QE
		wqe->record_handle<kPOS_Edge_Direction_Create>({
		   /* handle */ memory_handle_0,
		   /* param_index */ 0,
		   /* offset */ pos_api_param_value(wqe, 0, uint64_t) - (uint64_t)(memory_handle_0->client_addr)
		});

		retval = client->dag.allocate_handle(memory_handle_0);
		if(unlikely(retval != POS_SUCCESS)){ goto exit; }

		// launch the op to the dag
		retval = client->dag.launch_op(wqe);

		exit:

		wqe->status = kPOS_API_Execute_Status_Return_After_Parse;

		return retval;

	}
} // namespace cuda_malloc
} // namespace ps_functions
