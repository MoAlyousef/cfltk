#!/usr/bin/env bash

set -e  # Exit immediately on error

# Detect environment
if [ -n "$MSYSTEM" ]; then
  ###########################
  # MSYS2 / MinGW (Windows) #
  ###########################
  echo "Detected MSYS2/MinGW environment..."

  cmake -B bin -S . \
    -DCMAKE_INSTALL_PREFIX="$MINGW_PREFIX" \
    -DCMAKE_BUILD_TYPE=Release \
    -DFLTK_USE_SYSTEM_LIBPNG=OFF \
    -DFLTK_USE_SYSTEM_LIBJPEG=OFF \
    -DFLTK_USE_SYSTEM_ZLIB=OFF \
    -DFLTK_BUILD_GL=ON \
    -DCFLTK_USE_OPENGL=ON \
    -DFLTK_BUILD_EXAMPLES=OFF \
    -DFLTK_BUILD_TEST=OFF \
    -DFLTK_OPTION_LARGE_FILE=ON \
    -DFLTK_BUILD_HTML_DOCS=OFF \
    -DFLTK_BUILD_PDF_DOCS=OFF \
    -GNinja \
    -DFLTK_BUILD_FLUID=OFF \
    -DFLTK_BUILD_FLTK_OPTIONS=OFF

  cmake --build bin --config Release
  cmake --install bin

elif [[ "$(uname -s)" == "Darwin" ]]; then
  ###########
  # macOS   #
  ###########
  echo "Detected macOS environment..."

  cmake -B bin -S . \
    -DCMAKE_BUILD_TYPE=Release \
    -DFLTK_USE_SYSTEM_LIBPNG=OFF \
    -DFLTK_USE_SYSTEM_LIBJPEG=OFF \
    -DFLTK_USE_SYSTEM_ZLIB=OFF \
    -DFLTK_BUILD_GL=ON \
    -DCFLTK_USE_OPENGL=ON \
    -DFLTK_BUILD_EXAMPLES=OFF \
    -DFLTK_BUILD_TEST=OFF \
    -DFLTK_OPTION_LARGE_FILE=ON \
    -DFLTK_BUILD_HTML_DOCS=OFF \
    -DFLTK_BUILD_PDF_DOCS=OFF \
    -DFLTK_BUILD_FLUID=OFF \
    -DFLTK_BUILD_FLTK_OPTIONS=OFF

  cmake --build bin --parallel
  sudo cmake --install bin

else
  #################################
  # Linux or BSD (default branch) #
  #################################
  echo "Detected Linux or BSD environment..."

  cmake -B bin -S . \
    -DCMAKE_BUILD_TYPE=Release \
    -DFLTK_USE_SYSTEM_LIBPNG=OFF \
    -DFLTK_USE_SYSTEM_LIBJPEG=OFF \
    -DFLTK_USE_SYSTEM_ZLIB=OFF \
    -DFLTK_BUILD_GL=ON \
    -DCFLTK_USE_OPENGL=ON \
    -DFLTK_BUILD_EXAMPLES=OFF \
    -DFLTK_BUILD_TEST=OFF \
    -DFLTK_OPTION_LARGE_FILE=ON \
    -DFLTK_BUILD_HTML_DOCS=OFF \
    -DFLTK_BUILD_PDF_DOCS=OFF \
    -DFLTK_USE_PANGO=ON \
    -DFLTK_GRAPHICS_CAIRO=ON \
    -DFLTK_USE_LIBDECOR_GTK=OFF \
    -DFLTK_BUILD_FLUID=OFF \
    -DFLTK_BUILD_FLTK_OPTIONS=OFF \
    -DFLTK_BACKEND_WAYLAND=OFF

  cmake --build bin --parallel
  # On most Linux/BSD systems, 'sudo' is typically available. If you prefer 'doas' on BSD, you can adjust here.
  sudo cmake --install bin
fi