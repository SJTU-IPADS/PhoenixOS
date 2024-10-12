#include <iostream>
#include "pos/include/common.h"
#include "pos/include/dag.h"
#include "pos/cuda_impl/handle.h"
#include "pos/cuda_impl/parser.h"
#include "pos/cuda_impl/client.h"
#include "pos/cuda_impl/api_context.h"
#include <cuda_runtime_api.h>

namespace ps_functions
{
namespace cuda_malloc
{
	POS_RT_FUNC_PARSER()
	{
		pos_retval_t retval = POS_SUCCESS;
		POSClient_CUDA *client;

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

	}
} // namespace cuda_malloc
} // namespace ps_functions
