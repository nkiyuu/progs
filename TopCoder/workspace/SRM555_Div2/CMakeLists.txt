cmake_minimum_required(VERSION 3.5)
project(SRM555_Div2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES CuttingBitString.cpp)
add_executable(SRM555_Div2 ${SOURCE_FILES})