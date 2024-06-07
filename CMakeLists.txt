cmake_minimum_required(VERSION 3.0)
set(CFLTK_PROJECT_VERSION 1.4.31)

project(
  cfltk
  HOMEPAGE_URL https://github.com/MoAlyousef/cfltk
  DESCRIPTION "C Bindings for FLTK"
  VERSION ${CFLTK_PROJECT_VERSION})

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

option(CFLTK_BUILD_SHARED "Builds a shared library" OFF)
option(USE_SYSTEM_FLTK "Finds and uses the installed FLTK library" OFF)
option(CFLTK_USE_OPENGL "Uses OpenGL" OFF)
option(CFLTK_SINGLE_THREADED "Disable multithreaded support" OFF)
option(CFLTK_LINK_IMAGES "Links image libraries" ON)
option(CFLTK_CARGO_BUILD "cfltk is built using Cargo" OFF)
option(CFLTK_MSVC_CRT_STATIC "cfltk is built with crt-static" OFF)
option(CFLTK_USE_CAIROEXT "Uses CairoExt FLTK feature" OFF)

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
  find_package(FLTK REQUIRED NO_MODULE)
else()
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
    src/Fl_Simple_Terminal.cxx)

if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
  set(CFLTK_SRCS ${CFLTK_SRCS} src/cfl_nswindow.m)
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
  include_directories(cfltk PUBLIC ${CAIRO_INCLUDE_DIRS})
endif()

if(CFLTK_BUILD_SHARED)
  add_library(cfltk SHARED ${CFLTK_SRCS})
  if(CFLTK_CARGO_BUILD)
    add_custom_command(
      TARGET cfltk
      POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:cfltk>
              "${CMAKE_INSTALL_PREFIX}/../../../../$<TARGET_FILE_NAME:cfltk>")
  endif()
else()
  add_library(cfltk STATIC ${CFLTK_SRCS})
endif()

target_compile_features(cfltk PRIVATE cxx_std_17)

if(USE_SYSTEM_FLTK)
  target_include_directories(
    cfltk PUBLIC $<BUILD_INTERFACE:include ${FLTK_INCLUDE_DIRS}>
                 $<INSTALL_INTERFACE:include/cfltk>)
else()
  target_include_directories(
    cfltk
    PUBLIC $<BUILD_INTERFACE:include fltk ${CMAKE_CURRENT_BINARY_DIR}/fltk>
           $<INSTALL_INTERFACE:include/cfltk>)
endif()

set(CFLTK_LIBS fltk)
set(pc_req_private)
set(pc_libs_private "-lfltk")
set(other_c_flags)

if(CFLTK_LINK_IMAGES)
  set(CFLTK_LIBS ${CFLTK_LIBS} fltk_images fltk_z fltk_jpeg fltk_png)
  string(APPEND pc_libs_private
         " -lfltk_images -lfltk_z -lfltk_jpeg -lfltk_png")
endif()

if(CFLTK_USE_OPENGL)
  set(CFLTK_LIBS ${CFLTK_LIBS} fltk_gl)
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
endif()

if(CFLTK_SINGLE_THREADED)
  target_compile_definitions(cfltk PUBLIC CFLTK_SINGLE_THREADED)
  string(APPEND other_c_flags " -DCFLTK_SINGLE_THREADED")
endif()

if(CFLTK_BUILD_SHARED OR USE_SYSTEM_FLTK)
  target_link_libraries(cfltk PUBLIC ${CFLTK_LIBS})
  if(APPLE)
    target_link_libraries(cfltk PUBLIC "-framework Cocoa")
  endif()
  if(WIN32)
    target_link_libraries(
      cfltk
      PUBLIC ws2_32
             comctl32
             gdi32
             gdiplus
             oleaut32
             ole32
             uuid
             shell32
             advapi32
             comdlg32
             winspool
             user32
             kernel32
             odbc32)
  endif()
endif()

set_target_properties(cfltk PROPERTIES PUBLIC_HEADER "${CFLTK_HEADER_FILES}")

set_target_properties(cfltk PROPERTIES VERSION ${CFLTK_PROJECT_VERSION})

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/cfltkConfigVersion.cmake
  VERSION ${CFLTK_PROJECT_VERSION}
  COMPATIBILITY SameMajorVersion)

install(
  TARGETS cfltk
  EXPORT cfltkConfig
  ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
  LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_PREFIX}/include/cfltk)

export(
  TARGETS cfltk
  NAMESPACE cfltk::
  FILE "${CMAKE_CURRENT_BINARY_DIR}/cfltkConfig.cmake")

install(
  EXPORT cfltkConfig
  DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cmake/cfltk"
  NAMESPACE cfltk::)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/cfltkConfigVersion.cmake
        DESTINATION ${CMAKE_INSTALL_PREFIX}/share/cmake/cfltk)

# gen pkg-config
include(GNUInstallDirs)

if(UNIX AND NOT APPLE)
  string(
    APPEND
    pc_req_private
    " x11 xinerama xcursor xfixes xext xrender xft fontconfig cairo pango pangoxft pangocairo gobject-2.0 wayland-client wayland-cursor xkbcommon"
  )
  if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    string(APPEND pc_libs_private " -ldbus-1 -lsupc++ -ldl -pthread")
  elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    string(APPEND pc_libs_private " -ldbus-1 -lcxxrt")
  endif()
elseif(APPLE)
  string(
    APPEND
    pc_libs_private
    " -framework Cocoa -framework Carbon -framework ApplicationServices -framework OpenGL -lc++abi"
  )
elseif(WIN32)
  string(
    APPEND
    pc_libs_private
    " -lgdiplus -lws2_32 -lcomctl32 -lgdi32 -loleaut32 -lole32 -luuid -lshell32 -ladvapi32 -lcomdlg32 -lwinspool -luser32 -lkernel32 -lodbc32"
  )
  if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    string(APPEND pc_libs_private " -lgcc -lsupc++ -pthread")
  endif()
endif()

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/cfltk.pc.in
               ${CMAKE_CURRENT_BINARY_DIR}/cfltk.pc @ONLY)

install(
  FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.pc
  DESTINATION ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)
