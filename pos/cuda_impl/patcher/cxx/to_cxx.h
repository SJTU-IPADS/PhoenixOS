#pragma once

#include <memory>
#include <string>
#include <vector>

#include "rust/cxx.h"

std::unique_ptr<std::vector<uint8_t>> to_cxx_vec(rust::Slice<const uint8_t> vec);
std::unique_ptr<std::string> to_cxx_string(rust::Str s);
