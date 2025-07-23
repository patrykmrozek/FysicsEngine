#GLAD 
add_subdirectory(glad/cmake)
#SDL2
#forces to build as a static library instead of a DLL
set(SDL_SHARED OFF CACHE BOOL "Disabled shared library build")
set(SDL_STATIC ON CACHE BOOL "Enable static linking")
add_subdirectory(sdl2)
#cglm
#Compiles cglm as a static library
set(CGML_STATIC ON CACHE BOOL "Build static library")
#Nuklear (header only)
add_library(nuklear INTERFACE)
target_include_directories(nuklear INTERFACE nuklear)



