#!/bin/sh

set -e

COMMON_ARGS="
-DCMAKE_BUILD_TYPE=Release
-DFLTK_USE_SYSTEM_LIBPNG=OFF
-DFLTK_USE_SYSTEM_LIBJPEG=OFF
-DFLTK_USE_SYSTEM_LIBZLIB=OFF
-DFLTK_BUILD_GL=ON
-DCFLTK_USE_OPENGL=ON
-DFLTK_BUILD_EXAMPLES=OFF
-DFLTK_BUILD_TEST=OFF
-DFLTK_OPTION_LARGE_FILE=ON
-DFLTK_BUILD_HTML_DOCS=OFF
-DFLTK_BUILD_PDF_DOCS=OFF
-DFLTK_BUILD_FLUID=OFF
-DFLTK_BUILD_FLTK_OPTIONS=OFF
"

# Linux/BSD gets these extras
LINUX_ARGS="
-DFLTK_USE_PANGO=ON
-DFLTK_GRAPHICS_CAIRO=ON
-DFLTK_USE_LIBDECOR_GTK=OFF
"

###############################################
# 3. Detect environment and configure + build #
###############################################

if [ -n "$MSYSTEM" ]; then
  ###########################
  # MSYS2 / MinGW (Windows) #
  ###########################
  echo "Detected MSYS2/MinGW environment..."

  cmake -B bin -S . \
    $COMMON_ARGS \
    "$@"

elif [ "$(uname -s)" = "Darwin" ]; then
  ###########
  # macOS   #
  ###########
  echo "Detected macOS environment..."

  cmake -B bin -S . \
    $COMMON_ARGS \
    "$@"

else
  #################################
  # Linux or BSD (default branch) #
  #################################
  echo "Detected Linux or BSD environment..."

  cmake -B bin -S . \
    $COMMON_ARGS \
    $LINUX_ARGS \
    "$@"
fi

cmake --build bin --parallel --config Release
cmake --install bin --config Release
