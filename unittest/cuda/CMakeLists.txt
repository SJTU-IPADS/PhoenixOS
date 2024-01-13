# cmake version
cmake_minimum_required(VERSION 3.16.3)

# project info
project(pos_unittest LANGUAGES CXX CUDA)

# set executable output path
set(PATH_EXECUTABLE bin)
execute_process( COMMAND ${CMAKE_COMMAND} -E make_directory ../${PATH_EXECUTABLE})
SET(EXECUTABLE_OUTPUT_PATH ../${PATH_EXECUTABLE})

# find CUDA Toolkit Extension library
set(CUDA_TOOLKIT_ROOT_DIR /usr/local/cuda-11.3)
find_library(CUDA_NVTX_LIBRARY
  NAMES nvToolsExt nvTools nvtoolsext nvtools nvtx NVTX
  PATHS "${CUDA_CUDART_LIBRARY_DIR}" "${CUDA_TOOLKIT_ROOT_DIR}" ENV LD_LIBRARY_PATH
  PATH_SUFFIXES "lib64" "common/lib64" "common/lib" "lib"
  DOC "Location of the CUDA Toolkit Extension (NVTX) library"
  NO_DEFAULT_PATH
)

# common src file
SET(SRC_POS_UNITTEST_COMMON_SRC_PATH ./src)
file(GLOB_RECURSE SRC_POS_UNITTEST_COMMON_SRC ${SRC_POS_UNITTEST_COMMON_SRC_PATH}/*.cpp ${SRC_POS_UNITTEST_COMMON_SRC_PATH}/*.cu)

# per-API test
SET(SRC_POS_UNITTEST_PERAPI_SRC_PATH ./apis)
file(GLOB_RECURSE SRC_POS_UNITTEST_PERAPI_SRC ${SRC_POS_UNITTEST_PERAPI_SRC_PATH}/*.cpp ${SRC_POS_UNITTEST_PERAPI_SRC_PATH}/*.cu)
add_executable(per_api_test ./perapi.cu ${SRC_POS_UNITTEST_COMMON_SRC} ${SRC_POS_UNITTEST_PERAPI_SRC})

# hidden API test
# add_executable(hidden_api_test ./hidden.cpp ${SRC_POS_UNITTEST_COMMON_SRC})

# hidden API test
add_executable(kernel_parse ./kernel_parse/main.cpp ${SRC_POS_UNITTEST_COMMON_SRC})

# set(TEST_TARGETS per_api_test hidden_api_test)
set(TEST_TARGETS per_api_test kernel_parse)

foreach( test_target ${TEST_TARGETS} )
    set_target_properties(${test_target} PROPERTIES LINKER_LANGUAGE CUDA)

    # target_link_libraries(${test_target} nvToolsExt -lcublas -lcurand)
    target_link_libraries(${test_target} -lcuda -lcublas -ldl -lpthread -lclang)
    # target_link_libraries(${test_target} Boost::serialization)

    target_include_directories(${test_target} PUBLIC ${CUDA_TOOLKIT_ROOT_DIR}/include)

    # POS root path
    target_include_directories(${test_target} PUBLIC ../../)
    target_include_directories(${test_target} PUBLIC ../../build)

    # link POS
    find_library(pos_so NAMES pos HINTS ${CMAKE_CURRENT_SOURCE_DIR}/../../build)
    target_link_libraries(${test_target} ${pos_so})

    # include third party header
    target_include_directories(${test_target} PUBLIC ../../third_party/libclang-static-build/include)

    # important here to set cuda as dynamically linked
    set_target_properties(${test_target} PROPERTIES CUDA_RUNTIME_LIBRARY Shared)
    target_compile_features(${test_target} PUBLIC cxx_std_17)
    target_compile_options(
        ${test_target} PRIVATE
        $<$<COMPILE_LANGUAGE:CUDA>:SHELL:-gencode arch=compute_70,code=sm_70 -gencode arch=compute_86,code=sm_86>
    )
endforeach( test_target ${TEST_TARGETS} )
