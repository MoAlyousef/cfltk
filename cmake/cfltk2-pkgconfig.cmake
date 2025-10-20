# gen pkg-config

include_guard(GLOBAL)

if(UNIX AND NOT APPLE)
  string(
    APPEND
    pc_req_private
    " x11 xinerama xcursor xfixes xext xrender xft fontconfig cairo pango pangoxft pangocairo gobject-2.0 wayland-client wayland-cursor xkbcommon"
  )
  if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    string(APPEND pc_libs_private " -ldbus-1 -lsupc++ -ldl -pthread")
  elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    string(APPEND pc_libs_private " -ldbus-1 -lc++")
  endif()
elseif(APPLE)
  string(
    APPEND
    pc_libs_private
    " -framework Cocoa -framework Carbon -framework ApplicationServices -framework OpenGL -lc++"
  )
elseif(WIN32)
  string(
    APPEND
    pc_libs_private
    " -lgdiplus -lws2_32 -lcomctl32 -lgdi32 -loleaut32 -lole32 -luuid -lshell32 -ladvapi32 -lcomdlg32 -lwinspool -luser32 -lkernel32 -lodbc32"
  )
  if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    string(APPEND pc_libs_private " -lgcc -lstdc++ -pthread")
  endif()
endif()

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/cfltk2.pc.in
               ${CMAKE_CURRENT_BINARY_DIR}/cfltk2.pc @ONLY)

install(
  FILES ${CMAKE_CURRENT_BINARY_DIR}/cfltk2.pc
  DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)