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

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/examples/basic/main.c")
    add_executable(basic_example examples/basic/main.c)
    target_link_libraries(basic_example PRIVATE fysics_engine)
    #output directory
    set_target_properties(basic_example PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/examples"
    )
endif()

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/examples/sdl/main.c")
    add_executable(sdl_example examples/sdl/main.c)
    target_link_libraries(sdl_example PRIVATE fysics_engine SDL2)
    #output directory
    set_target_properties(sdl_example PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/examples"
    )
endif()



 
message(STATUS "")
message(STATUS "=== Fysics Physics Engine Configuration ===")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "C Compiler: ${CMAKE_C_COMPILER}")
message(STATUS "SDL2 found: ${SDL2_FOUND}")
message(STATUS "OpenGL found: ${OPENGL_FOUND}")
message(STATUS "Source files found: ${PHYSICS_SOURCES}")
message(STATUS "==========================================")
message(STATUS "")
