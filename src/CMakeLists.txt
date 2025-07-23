#collect all source files recursively
file(GLOB_RECURSE SRC_FILES
    "*.c"
    "*.h"
)

#main physics engine static library
add_library(fysics STATIC
    ${SRC_FILES}
)

#set include paths for the library
target_include_directories(fysics PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}             #current src dir
    ${CMAKE_CURRENT_SOURCE_DIR}/../include  #project-wide headers
)

#link dependencies
target_link_libraries(fysics PRIVATE
    glad
    SDL2::SDL2
    cglm
)
