cmake_minimum_required(VERSION 3.28)
set(CFLTK_PROJECT_VERSION 1.5.20)

project(
  cfltk
  HOMEPAGE_URL https://github.com/MoAlyousef/cfltk
  DESCRIPTION "C Bindings for FLTK"
  VERSION ${CFLTK_PROJECT_VERSION}
  LANGUAGES C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

include(GNUInstallDirs)

if(APPLE)
  enable_language(OBJC)
endif()

option(CFLTK_BUILD_SHARED "Builds a shared library" OFF)
option(USE_SYSTEM_FLTK "Finds and uses the installed FLTK library" OFF)
option(CFLTK_USE_OPENGL "Uses OpenGL" OFF)
option(CFLTK_SINGLE_THREADED "Disable multithreaded support" OFF)
option(CFLTK_LINK_IMAGES "Links image libraries" ON)
option(CFLTK_CARGO_BUILD "cfltk is built using Cargo" OFF)
option(CFLTK_MSVC_CRT_STATIC "cfltk is built with crt-static" OFF)
option(CFLTK_USE_CAIROEXT "Uses CairoExt FLTK feature" OFF)
option(CFLTK_USE_FPIC "Compile code with -fPIC to allow incorporation into shared lib." OFF)

if (CFLTK_USE_FPIC OR CFLTK_BUILD_SHARED)
  set(CMAKE_POSITION_INDEPENDENT_CODE ON)
endif()

if(MSVC)
  string(REGEX REPLACE "/EHsc" "/EHs-c-" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
  add_definitions("/D_CRT_SECURE_NO_WARNINGS /wd4099 /wd4996")
  if(CFLTK_MSVC_CRT_STATIC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Release>:Release>")
    string(REGEX REPLACE "/MD" "/MT" CMAKE_CXX_FLAGS_RELEASE
                         "${CMAKE_CXX_FLAGS_RELEASE}")
    string(REGEX REPLACE "/MD" "/MT" CMAKE_C_FLAGS_RELEASE
                         "${CMAKE_C_FLAGS_RELEASE}")
  endif()
elseif(ANDROID)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -frtti")
else()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-exceptions")
endif()

# If cmake can't find the installed fltk, you might have to set the FLTK_DIR
# enviromental variable, export FLTK_DIR=/path/to/fltk
if(USE_SYSTEM_FLTK)
  find_package(FLTK 1.4 CONFIG REQUIRED)
else()
  file(GLOB RESULT "fltk")
  list(LENGTH RESULT RES_LEN)
  if(RES_LEN EQUAL 0)
    message(FATAL_ERROR "fltk submodule not initialized! Run: git submodule update --init --recursive")
  endif()
  add_subdirectory(fltk)
endif()

file(GLOB_RECURSE CFLTK_HEADER_FILES "include/*.h*")

set(CFLTK_SRCS
    src/cfl_new.cpp
    src/cfl_lock.cpp
    src/cfl.cpp
    src/cfl_window.cpp
    src/cfl_button.cpp
    src/cfl_widget.cpp
    src/cfl_group.cpp
    src/cfl_text.cpp
    src/cfl_box.cpp
    src/cfl_input.cpp
    src/cfl_menu.cpp
    src/cfl_dialog.cpp
    src/cfl_valuator.cpp
    src/cfl_browser.cpp
    src/cfl_misc.cpp
    src/cfl_image.cpp
    src/cfl_draw.cpp
    src/cfl_table.cpp
    src/cfl_tree.cpp
    src/cfl_surface.cpp
    src/cfl_font.cpp
    src/cfl_utils.cpp
    src/cfl_prefs.cpp
    src/Fl_Simple_Terminal.cxx
    src/cfl_term.cpp
    )

if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
  set(CFLTK_SRCS ${CFLTK_SRCS} src/cfl_nswindow.m)
endif()

if(UNIX AND NOT APPLE)
  set(CFLTK_SRCS ${CFLTK_SRCS} src/cfl_platform.cpp)
endif()

if(NOT ANDROID)
  set(CFLTK_SRCS ${CFLTK_SRCS} src/cfl_printer.cpp)
endif()

if(CFLTK_USE_OPENGL)
  set(CFLTK_SRCS ${CFLTK_SRCS} src/glad.c)
endif()

if(CFLTK_USE_CAIROEXT)
  find_package(PkgConfig REQUIRED)
  pkg_check_modules(CAIRO REQUIRED IMPORTED_TARGET "cairo")
endif()

if(CFLTK_BUILD_SHARED)
  add_library(cfltk SHARED)
else()
  add_library(cfltk STATIC)
endif()

add_library(cfltk::cfltk ALIAS cfltk)

target_sources(
  cfltk
  PRIVATE ${CFLTK_SRCS}
  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS ${CMAKE_CURRENT_LIST_DIR}/include
    FILES ${CFLTK_HEADER_FILES}
)

if(CFLTK_CARGO_BUILD AND CFLTK_BUILD_SHARED)
  add_custom_command(
    TARGET cfltk
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:cfltk>
            "${CMAKE_INSTALL_PREFIX}/../../../../$<TARGET_FILE_NAME:cfltk>")
endif()

# if(CFLTK_CARGO_BUILD AND (UNIX OR MSYS OR MINGW))
#   add_custom_command(
#     TARGET cfltk
#     POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_INSTALL_PREFIX}/bin/fltk-config
#             "${CMAKE_INSTALL_PREFIX}/../../../../fltk-config")
# endif()

target_compile_features(cfltk PRIVATE cxx_std_17)

set(CFLTK_LIBS fltk::fltk)
set(pc_req_private)
set(pc_libs_private "-lfltk")
set(other_c_flags)

if(CFLTK_LINK_IMAGES)
  set(CFLTK_LIBS ${CFLTK_LIBS} fltk::images fltk::z fltk::jpeg fltk::png)
  string(APPEND pc_libs_private
         " -lfltk_images -lfltk_z -lfltk_jpeg -lfltk_png")
endif()

if(CFLTK_USE_OPENGL)
  set(CFLTK_LIBS ${CFLTK_LIBS} fltk::gl)
  target_compile_definitions(cfltk PUBLIC CFLTK_USE_GL)
  string(APPEND pc_libs_private " -lfltk_gl")
  string(APPEND other_c_flags "-DCFLTK_USE_GL")
  if(UNIX AND NOT APPLE)
    string(APPEND pc_req_private " glx glu gl wayland-egl EGL")
  elseif(APPLE)
    string(APPEND pc_libs_private " -framework OpenGL")
  elseif(WIN32)
    string(APPEND pc_libs_private " -lopengl32 -lglu32")
  endif()
endif()

if(CFLTK_USE_CAIROEXT)
  if(WIN32 OR APPLE)
    string(APPEND pc_req_private " cairo")
  endif()
  target_link_libraries(cfltk PUBLIC PkgConfig::CAIRO)
endif()

if(CFLTK_SINGLE_THREADED)
  target_compile_definitions(cfltk PUBLIC CFLTK_SINGLE_THREADED)
  string(APPEND other_c_flags " -DCFLTK_SINGLE_THREADED")
endif()

target_link_libraries(cfltk PUBLIC ${CFLTK_LIBS})

set_target_properties(cfltk PROPERTIES VERSION ${CFLTK_PROJECT_VERSION})

include(CMakePackageConfigHelpers)

set(cfltk_INSTALL_CMAKEDIR "${CMAKE_INSTALL_LIBDIR}/cmake/cfltk")

install(
  TARGETS cfltk
  EXPORT cfltkTargets
  FILE_SET HEADERS DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(
  EXPORT cfltkTargets
  FILE cfltkTargets.cmake
  NAMESPACE cfltk::
  DESTINATION "${cfltk_INSTALL_CMAKEDIR}"
)

configure_package_config_file(
  "${CMAKE_CURRENT_LIST_DIR}/cmake/cfltkConfig.cmake.in"
  "${CMAKE_CURRENT_BINARY_DIR}/cfltkConfig.cmake"
  INSTALL_DESTINATION "${cfltk_INSTALL_CMAKEDIR}"
  NO_CHECK_REQUIRED_COMPONENTS_MACRO
)

write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/cfltkConfigVersion.cmake"
  VERSION       ${CFLTK_PROJECT_VERSION}
  COMPATIBILITY SameMajorVersion
)

install(
  FILES
    "${CMAKE_CURRENT_BINARY_DIR}/cfltkConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/cfltkConfigVersion.cmake"
  DESTINATION "${cfltk_INSTALL_CMAKEDIR}"
)

include(${CMAKE_CURRENT_LIST_DIR}/cmake/cfltk-pkgconfig.cmake)
