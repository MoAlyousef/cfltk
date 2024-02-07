cmake_minimum_required(VERSION 3.0)
project(cfltk_examples)

set(FLTK_USE_SYSTEM_LIBPNG OFF CACHE BOOL " " FORCE)
set(FLTK_USE_SYSTEM_LIBJPEG OFF CACHE BOOL " " FORCE)
set(FLTK_USE_SYSTEM_ZLIB OFF CACHE BOOL " " FORCE)
set(FLTK_BUILD_GL OFF CACHE BOOL " " FORCE)
set(CFLTK_USE_OPENGL OFF CACHE BOOL " " FORCE)
set(FLTK_BUILD_EXAMPLES OFF CACHE BOOL " " FORCE)
set(FLTK_BUILD_TEST OFF CACHE BOOL " " FORCE)
set(FLTK_OPTION_LARGE_FILE ON CACHE BOOL " " FORCE)
set(FLTK_BUILD_HTML_DOCS OFF CACHE BOOL " " FORCE)
set(FLTK_BUILD_PDF_DOCS OFF CACHE BOOL " " FORCE)
if (${CMAKE_SYSTE_NAME} STREQUAL MATCHES "Linux")
    set(FLTK_USE_PANGO ON CACHE BOOL " " FORCE)
    set(FLTK_GRAPHICS_CAIRO ON CACHE BOOL " " FORCE)
    set(FLTK_BACKEND_WAYLAND OFF CACHE BOOL " " FORCE)
endif()

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/.. cfltk)

add_executable(hello hello.c)
target_link_libraries(hello PUBLIC cfltk fltk::fltk fltk::images fltk::png fltk::z)

add_executable(img img.c)
target_link_libraries(img PUBLIC cfltk fltk::fltk fltk::images fltk::png fltk::z)

add_executable(handler handler.c)
target_link_libraries(handler PUBLIC cfltk fltk::fltk fltk::images fltk::png fltk::z)

add_executable(handler2 handler2.c)
target_link_libraries(handler2 PUBLIC cfltk fltk::fltk fltk::images fltk::png fltk::z)

add_executable(counter counter.c)
target_link_libraries(counter PUBLIC cfltk fltk::fltk fltk::images fltk::png fltk::z)

add_executable(threads threads.cpp)
target_link_libraries(threads PUBLIC cfltk fltk::fltk fltk::images fltk::png fltk::z)

add_executable(cthreads cthreads.cpp)
target_link_libraries(cthreads PUBLIC cfltk fltk::fltk fltk::images fltk::png fltk::z)

add_executable(deleter deleter.c)
target_link_libraries(deleter PUBLIC cfltk fltk::fltk fltk::images fltk::png fltk::z)