# cmake version
cmake_minimum_required(VERSION 3.16.3)

# project info
project(pos_unittest LANGUAGES CXX)

# set executable output path
set(PATH_EXECUTABLE bin)
execute_process( COMMAND ${CMAKE_COMMAND} -E make_directory ../${PATH_EXECUTABLE})
SET(EXECUTABLE_OUTPUT_PATH ../${PATH_EXECUTABLE})

add_executable(migrate ./migrate.cpp)
add_executable(restore ./restore.cpp)

set(TEST_TARGETS migrate restore)

foreach( test_target ${TEST_TARGETS} )
    # POS root path
    target_include_directories(${test_target} PUBLIC ../)
    target_include_directories(${test_target} PUBLIC ../build)

    # link POS
    find_library(pos_so NAMES pos HINTS ${CMAKE_CURRENT_SOURCE_DIR}/../build)
    target_link_libraries(${test_target} ${pos_so})

    # important here to set cuda as dynamically linked
    set_target_properties(${test_target} PROPERTIES CUDA_RUNTIME_LIBRARY Shared)
    target_compile_features(${test_target} PUBLIC cxx_std_17)
endforeach( test_target ${TEST_TARGETS} )
