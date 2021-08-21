cmake_minimum_required(VERSION 3.0)
set(CFLTK_PROJECT_VERSION 1.1.9)
project(cfltk VERSION ${CFLTK_PROJECT_VERSION})

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    string(REGEX REPLACE "/GR" "/GR-" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    string(REGEX REPLACE "/EHsc" "/EHs-c-" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    add_definitions("/D_CRT_SECURE_NO_WARNINGS /wd4099 /wd4996")
elseif(ANDROID)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -frtti")
else()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti -fno-exceptions")
endif()

option(CFLTK_BUILD_SHARED "Builds a shared library" OFF)
option(USE_SYSTEM_FLTK "Finds and uses the installed FLTK library" OFF)
option(CFLTK_USE_OPENGL "Uses OpenGL" OFF)
option(CFLTK_LINK_IMAGES "Links image libraries" ON)

# If cmake can't find the installed fltk, you might have to set the FLTK_DIR enviromental variable,
# export FLTK_DIR=/path/to/fltk
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
    src/cfl_output.cpp
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
    )

if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(CFLTK_SRCS ${CFLTK_SRCS} src/cfl_nswindow.m)
endif()

if(NOT ANDROID)
    set(CFLTK_SRCS ${CFLTK_SRCS} src/cfl_printer.cpp)
endif()

if(CFLTK_BUILD_SHARED)
    add_library(cfltk SHARED ${CFLTK_SRCS})
else()
    add_library(cfltk STATIC ${CFLTK_SRCS})
endif()

if(USE_SYSTEM_FLTK)
    target_include_directories(cfltk PUBLIC 
    $<BUILD_INTERFACE:include ${FLTK_INCLUDE_DIRS}>  
    $<INSTALL_INTERFACE:include/cfltk>
    )
else()
    target_include_directories(cfltk PUBLIC 
    $<BUILD_INTERFACE:include fltk ${CMAKE_CURRENT_BINARY_DIR}/fltk>  
    $<INSTALL_INTERFACE:include/cfltk>
    )
endif()

set(CFLTK_LIBS fltk)

if (CFLTK_USE_OPENGL)
    set(CFLTK_LIBS ${CFLTK_LIBS} fltk_gl)
    target_compile_definitions(cfltk PUBLIC CFLTK_USE_GL)
endif()

if (CFLTK_LINK_IMAGES)
    set(CFLTK_LIBS ${CFLTK_LIBS} fltk_images fltk_z fltk_jpeg)
    if(UNIX AND NOT APPLE AND NOT ANDROID)
        set(CFLTK_LIBS ${CFLTK_LIBS} png)
    else()
        set(CFLTK_LIBS ${CFLTK_LIBS} fltk_png)
    endif()
endif()

if(CFLTK_BUILD_SHARED OR USE_SYSTEM_FLTK)
    target_link_libraries(cfltk PUBLIC ${CFLTK_LIBS})
endif()

set_target_properties(cfltk PROPERTIES PUBLIC_HEADER "${CFLTK_HEADER_FILES}")

set_target_properties(cfltk PROPERTIES VERSION ${CFLTK_PROJECT_VERSION})

include(CMakePackageConfigHelpers)

write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/cfltkConfigVersion.cmake
                                 VERSION ${CFLTK_PROJECT_VERSION}
                                 COMPATIBILITY SameMajorVersion)

install(TARGETS cfltk
    EXPORT cfltkConfig
    ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
    LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_PREFIX}/include/cfltk
    )

export(TARGETS
        cfltk
    NAMESPACE cfltk::
    FILE "${CMAKE_CURRENT_BINARY_DIR}/cfltkConfig.cmake"
    )

install(EXPORT
        cfltkConfig
    DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cmake/cfltk"
    NAMESPACE cfltk::
    )

install(
    FILES ${CMAKE_CURRENT_BINARY_DIR}/cfltkConfigVersion.cmake DESTINATION ${CMAKE_INSTALL_PREFIX}/share/cmake/cfltk
    )
