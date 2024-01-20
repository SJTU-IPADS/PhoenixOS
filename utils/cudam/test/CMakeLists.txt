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

# find CUDA Toolkit Extension library
set(CUDA_TOOLKIT_ROOT_DIR /usr/local/cuda-11.4)
find_library(CUDA_NVTX_LIBRARY
  NAMES nvToolsExt nvTools nvtoolsext nvtools nvtx NVTX
  PATHS "${CUDA_CUDART_LIBRARY_DIR}" "${CUDA_TOOLKIT_ROOT_DIR}" ENV LD_LIBRARY_PATH
  PATH_SUFFIXES "lib64" "common/lib64" "common/lib" "lib"
  DOC "Location of the CUDA Toolkit Extension (NVTX) library"
  NO_DEFAULT_PATH
)

# test program
add_executable(main main.cu)

set(TEST_TARGETS main)

foreach( test_target ${TEST_TARGETS} )
  # target_link_libraries(${test_target} nvToolsExt -lcublas -lcurand)
  target_link_libraries(${test_target} -lcuda -ldl -lpthread)
  # target_link_libraries(${test_target} Boost::serialization)

  target_include_directories(${test_target} PUBLIC ${CUDA_TOOLKIT_ROOT_DIR}/include)

  # important here to set cuda as dynamically linked
  set_target_properties(${test_target} PROPERTIES CUDA_RUNTIME_LIBRARY Shared)
  target_compile_features(${test_target} PUBLIC cxx_std_11)
  target_compile_options(
    ${test_target} PRIVATE
    # 编译器前后端: arch -> IR, code -> 后端 binary (针对硬件的二进制，小版本号兼容 sm_80 -> sm_86)
    $<$<COMPILE_LANGUAGE:CUDA>:SHELL:-gencode arch=compute_70,code=sm_70 -gencode arch=compute_86,code=sm_86>
  )
endforeach( test_target ${TEST_TARGETS} )