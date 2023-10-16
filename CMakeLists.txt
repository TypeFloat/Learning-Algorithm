cmake_minimum_required(VERSION 3.16)
project(algo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(utils)

add_executable(main leetcode/main.cpp ${TARGET_FILE} utils/link.cpp utils/tree.cpp)
target_link_libraries(main ${GTEST_LIBRARIES})