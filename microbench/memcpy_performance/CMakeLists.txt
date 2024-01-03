# cmake version
cmake_minimum_required(VERSION 3.16.3)

# project info
project(CUDAop LANGUAGES CXX CUDA)

# set executable output path
set(PATH_EXECUTABLE bin)
execute_process( COMMAND ${CMAKE_COMMAND} -E make_directory ../${PATH_EXECUTABLE})
SET(EXECUTABLE_OUTPUT_PATH ../${PATH_EXECUTABLE})

# set library output path
set(PATH_LIBRARY lib)
execute_process( COMMAND ${CMAKE_COMMAND} -E make_directory ../${PATH_LIBRARY})
SET(LIBRARY_OUTPUT_PATH ../${PATH_LIBRARY})

# find CUDA Toolkit Extension library
set(CUDA_TOOLKIT_ROOT_DIR /usr/local/cuda-11.3)
find_library(CUDA_NVTX_LIBRARY
  NAMES nvToolsExt nvTools nvtoolsext nvtools nvtx NVTX
  PATHS "${CUDA_CUDART_LIBRARY_DIR}" "${CUDA_TOOLKIT_ROOT_DIR}" ENV LD_LIBRARY_PATH
  PATH_SUFFIXES "lib64" "common/lib64" "common/lib" "lib"
  DOC "Location of the CUDA Toolkit Extension (NVTX) library"
  NO_DEFAULT_PATH
)


# ====================== PROFILING PROGRAM ======================
# >>> vector addition
add_executable(memcpy_performance_test main.cu)

# >>> global configuration
set(PROFILING_TARGETS memcpy_performance_test)
foreach( profiling_target ${PROFILING_TARGETS} )
  target_link_libraries(${profiling_target} nvToolsExt -lcublas -lcurand)
  target_compile_features(${profiling_target} PUBLIC cxx_std_11)
  target_include_directories(${profiling_target} PUBLIC ../)
  target_compile_options(
    ${profiling_target} PRIVATE
    # v100 and a100
    $<$<COMPILE_LANGUAGE:CUDA>:-gencode arch=compute_80,code=sm_80>
  )
endforeach( profiling_target ${PROFILING_TARGETS} )
