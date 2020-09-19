# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.10)

# Set the project name
project (VecterSortTest)

aux_source_directory(${PROJECT_SOURCE_DIR} DIR_SRCS)

add_executable(VecterSortTest ${DIR_SRCS})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})