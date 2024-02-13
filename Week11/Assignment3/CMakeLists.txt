cmake_minimum_required(VERSION 3.26)
project(Assignment3 C)

set(CMAKE_C_STANDARD 11)

add_executable(Assignment3 main.c functions.h functions.c)

target_compile_options(Assignment3 PRIVATE -Wall -Wextra -pedantic -Werror)