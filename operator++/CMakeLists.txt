cmake_minimum_required(VERSION 4.0)
project(operator__)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -finput-charset=UTF-8 -fexec-charset=UTF-8")
add_executable(operator__ main.cpp)
