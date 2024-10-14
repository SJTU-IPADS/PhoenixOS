#pragma once

#include "autogen_common.h"
#include "pos/cuda_impl/handle.h"


/*!
 *  \brief  obtain handle type id according to given string from yaml file
 *  \param  handle_type   given string
 *  \return the corresponding handle type id
 */
uint32_t get_handle_type_by_name(std::string& handle_type);
