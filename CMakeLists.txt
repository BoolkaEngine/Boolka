cmake_minimum_required(VERSION 3.16)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

project(boolka)

include(utils)
include(platform)

add_subdirectory(thirdparty)
add_subdirectory(src)
