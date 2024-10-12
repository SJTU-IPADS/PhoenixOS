#pragma once

#include <iostream>
#include <string>
#include <cctype>
#include <memory>
#include <stdexcept>

/*!
 *  \brief  cast camel-formated name to snake-formated name
 *  \param  camel   camel-formated name
 *  \return casted snake-formated name
 */
std::string posautogen_utils_camel2snake(const std::string& camel);
