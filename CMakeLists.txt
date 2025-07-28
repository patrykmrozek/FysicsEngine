cmake_minimum_required(VERSION 3.16)
project(fysics LANGUAGES C)

#C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

#compiler flags
set(CMAKE_C_FLAGS_DEBUG "-g -O2 -Wall -Wextra")
set(CMAKE_C_FLAGS_RELEASE "-O3 -DddNDEBUG")

#default debug
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

#external libs
find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2 REQUIRED sdl2)
find_package(OpenGL REQUIRED)

#physics engine lib
#src files
file(GLOB PHYSICS_SOURCES 
    src/core/body.c
    src/core/world.c
    src/math/vector2.c
    src/collision/collision_detection.c
    src/collision/aabb.c
    src/collision/shape.c
)

#create main physics lib
add_library(fysics_engine STATIC ${PHYSICS_SOURCES})

#add include dirs
target_include_directories(fysics_engine PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    ${SDL2_INCLUDE_DIRS}
)

#link libraries to physics engine
target_link_libraries(fysics_engine PUBLIC
    ${SDL2_LIBRARIES}
    ${OPENGL_LIBRARIES}
)

#compiler flags
target_compile_options(fysics_engine PRIVATE ${SDL2_CFLAGS_OTHER})


#examples
#basic
add_executable(example_basic examples/basic/main.c)
target_link_libraries(example_basic PRIVATE fysics_engine)
#sdl
add_executable(example_sdl examples/sdl/main.c)
target_link_libraries(example_sdl PRIVATE fysics_engine SDL2)


#tests
#fyAABB
add_executable(test_fyAABB test/fyAABB/main.c)
target_link_libraries(test_fyAABB PRIVATE fysics_engine SDL2)
#circlevscircle
add_executable(test_circlevscircle test/collision/circlevscircle/main.c)
target_link_libraries(test_circlevscircle PRIVATE fysics_engine SDL2)



 
message(STATUS "")
message(STATUS "=== Fysics Physics Engine Configuration ===")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "C Compiler: ${CMAKE_C_COMPILER}")
message(STATUS "SDL2 found: ${SDL2_FOUND}")
message(STATUS "OpenGL found: ${OPENGL_FOUND}")
message(STATUS "Source files found: ${PHYSICS_SOURCES}")
message(STATUS "==========================================")
message(STATUS "")
