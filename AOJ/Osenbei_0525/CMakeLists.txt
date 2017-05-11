cmake_minimum_required(VERSION 3.5)
project(Osenbei_0525)

set (PATH=%PATH:...C:\\MinGW\\bin=%)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Osenbei_0525 ${SOURCE_FILES})