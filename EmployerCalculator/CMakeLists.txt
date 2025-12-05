# CMakeLists.txt

cmake_minimum_required(VERSION 3.27)
project(EmployerCalculator CXX)

set(CMAKE_CXX_STANDARD 17)

# Додайте ці прапори для підтримки UTF-8 у компіляторі MinGW
add_compile_options(-finput-charset=UTF-8)
add_compile_options(-fexec-charset=UTF-8)

add_executable(EmployerCalculator main.cpp)