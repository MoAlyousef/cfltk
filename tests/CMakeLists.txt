cmake_minimum_required(VERSION 3.28)
project(cfltk_tests LANGUAGES C CXX)

enable_testing()
add_subdirectory(.. cfltk)

add_executable(browser_icons browser_icons.cpp)
target_link_libraries(browser_icons PRIVATE cfltk::cfltk)
add_test(NAME browser_icons COMMAND browser_icons)
