# cmake version
cmake_minimum_required(VERSION 3.16.3)

# project info
project(pos_unittest LANGUAGES CXX CUDA)

# set executable output path
set(PATH_EXECUTABLE bin)
execute_process( COMMAND ${CMAKE_COMMAND} -E make_directory ../${PATH_EXECUTABLE})
SET(EXECUTABLE_OUTPUT_PATH ../${PATH_EXECUTABLE})

# find CUDA Toolkit Extension library
set(CUDA_TOOLKIT_ROOT_DIR /usr/local/cuda)
find_library(CUDA_NVTX_LIBRARY
  NAMES nvToolsExt nvTools nvtoolsext nvtools nvtx NVTX
  PATHS "${CUDA_CUDART_LIBRARY_DIR}" "${CUDA_TOOLKIT_ROOT_DIR}" ENV LD_LIBRARY_PATH
  PATH_SUFFIXES "lib64" "common/lib64" "common/lib" "lib"
  DOC "Location of the CUDA Toolkit Extension (NVTX) library"
  NO_DEFAULT_PATH
)

add_executable(vector_add ./main.cu)

set(TEST_TARGETS vector_add)

foreach( test_target ${TEST_TARGETS} )
    set_target_properties(${test_target} PROPERTIES LINKER_LANGUAGE CUDA)

    # target_link_libraries(${test_target} nvToolsExt -lcublas -lcurand)
    target_link_libraries(${test_target} -lcuda -lcublas -ldl -lpthread -lclang)
    # target_link_libraries(${test_target} Boost::serialization)

    target_include_directories(${test_target} PUBLIC ${CUDA_TOOLKIT_ROOT_DIR}/include)

    # important here to set cuda as dynamically linked
    set_target_properties(${test_target} PROPERTIES CUDA_RUNTIME_LIBRARY Shared)
    target_compile_features(${test_target} PUBLIC cxx_std_17)
    target_compile_options(
        ${test_target} PRIVATE
        $<$<COMPILE_LANGUAGE:CUDA>:SHELL: -gencode arch=compute_70,code=sm_70>
    )
endforeach( test_target ${TEST_TARGETS} )
