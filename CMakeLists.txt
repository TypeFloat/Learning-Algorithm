cmake_minimum_required(VERSION 3.16)
project(algo)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

include_directories(utils)
aux_source_directory(utils, DIR_SRC)

add_executable(main ${TARGET_FILE} ${DIR_SRC})
