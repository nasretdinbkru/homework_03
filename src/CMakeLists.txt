cmake_minimum_required(VERSION 3.28)

set(CMAKE_CXX_STANDARD 17)

project(guess_num)

add_executable(guess_num
        main.cpp
        includes/helpers.cpp
)
target_include_directories(guess_num PUBLIC includes)