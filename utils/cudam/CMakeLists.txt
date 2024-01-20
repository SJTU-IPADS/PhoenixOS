# cmake version
cmake_minimum_required(VERSION 3.16.3)

# project info
project(cudam LANGUAGES CXX CUDA)

# set executable output path
set(PATH_EXECUTABLE bin)
execute_process( COMMAND ${CMAKE_COMMAND} -E make_directory ../${PATH_EXECUTABLE})
SET(EXECUTABLE_OUTPUT_PATH ../${PATH_EXECUTABLE})

# set library output path
set(PATH_LIBRARY lib)
execute_process( COMMAND ${CMAKE_COMMAND} -E make_directory ../${PATH_LIBRARY})
SET(LIBRARY_OUTPUT_PATH ../${PATH_LIBRARY})

# find CUDA path
set(CUDA_TOOLKIT_ROOT_DIR /usr/local/cuda-11.3)

# cudam library
# # 1: buffer analyzer
# file(GLOB_RECURSE BUFFER_ANALYZER_SRC_FILES "src/buffer_manager/**/*.cpp" "src/buffer_manager/**/*.cu" "src/*.cpp")
# add_library(cudam_buf_analyzer SHARED ${BUFFER_ANALYZER_SRC_FILES})
# target_compile_features(cudam_buf_analyzer PUBLIC cxx_std_17)
# target_compile_options(
#   cudam_buf_analyzer PUBLIC
#   $<$<COMPILE_LANGUAGE:CUDA>:-gencode arch=sm_70,code=sm_70>
# )
# target_include_directories(cudam_buf_analyzer PUBLIC "src/")
# target_include_directories(cudam_buf_analyzer PUBLIC ${CUDA_TOOLKIT_ROOT_DIR}/include)
# target_link_libraries(cudam_buf_analyzer -lpthread)

# 2: general cudam intercept logic
file(GLOB_RECURSE COMMON_SRC_FILES "src/utils.cpp")
file(GLOB_RECURSE API_COUNTER_SRC_FILES "src/api_counter/*.cpp")
file(GLOB_RECURSE INTERCEPTOR_SRC_FILES "api_interceptor_gen/outputs/*.cpp")

add_library(cudam SHARED ${COMMON_SRC_FILES} ${INTERCEPTOR_SRC_FILES} ${API_COUNTER_SRC_FILES})
target_compile_features(cudam PUBLIC cxx_std_17)
target_compile_options(
  cudam PUBLIC
  $<$<COMPILE_LANGUAGE:CUDA>:-gencode arch=sm_70,code=sm_70>
)
target_include_directories(cudam PUBLIC "src")
target_include_directories(cudam PUBLIC "src/api_counter")
target_include_directories(cudam PUBLIC ${CUDA_TOOLKIT_ROOT_DIR}/include)
target_compile_options(cudam PUBLIC -fpermissive)
