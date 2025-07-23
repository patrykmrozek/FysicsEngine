cmake_minimum_required(VERSION 3.10)
project(fysics LANGUAGES C)

#global settings
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -g")


#subdirectories
add_subdirectory(external)
add_subdirectory(src)
add_subdirectory(tests)
