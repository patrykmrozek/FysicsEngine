enable_testing() #activates cmakes built-in testing CTest

#external dependency tests 
add_executable(sdl_test external/sdl_test.c)
target_link_libraries(sdl_test PRIVATE SDL2::SDL2)
add_test(NAME sdl_test COMMAND sdl_test)

# ctest --output-on-failure
