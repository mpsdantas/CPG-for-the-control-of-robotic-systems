cmake_minimum_required(VERSION 3.8)
project(Cpg)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Cpg.cpp Cpg.h)
add_executable(Cpg ${SOURCE_FILES})