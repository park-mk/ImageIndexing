cmake_minimum_required(VERSION 3.2)
project(ImageIndexing)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11 -O2")

aux_source_directory(src SOURCE_FILES)
add_executable(ImageIndexing ${SOURCE_FILES})
