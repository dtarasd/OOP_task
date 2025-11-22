cmake_minimum_required(VERSION 3.26)
project(root_project)

set(CMAKE_CXX_STANDARD 17)

add_executable(main_program
        main.cpp
        root.cpp
)

add_executable(print_name
        name.cpp
)

add_executable(age_program
        age.cpp
)