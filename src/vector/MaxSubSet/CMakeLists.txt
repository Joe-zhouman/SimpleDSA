cmake_minimum_required(VERSION 3.10)

project (MaxSubSet)

include_directories(${PROJECT_SOURCE_DIR}/include)

aux_source_directory(${PROJECT_SOURCE_DIR}/src DIR_SRCS)

add_executable(MaxSubSet.demo ${DIR_SRCS})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)