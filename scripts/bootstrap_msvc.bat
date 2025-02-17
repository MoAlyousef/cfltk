@echo off
setlocal enableextensions

cmake -B bin -S . ^
    -DCMAKE_BUILD_TYPE=Release ^
    -DFLTK_USE_SYSTEM_LIBPNG=OFF ^
    -DFLTK_USE_SYSTEM_LIBJPEG=OFF ^
    -DFLTK_USE_SYSTEM_LIBZLIB=OFF ^
    -DFLTK_BUILD_GL=ON ^
    -DCFLTK_USE_OPENGL=ON ^
    -DFLTK_BUILD_EXAMPLES=OFF ^
    -DFLTK_BUILD_TEST=OFF ^
    -DFLTK_OPTION_LARGE_FILE=ON ^
    -DFLTK_BUILD_HTML_DOCS=OFF ^
    -DFLTK_BUILD_PDF_DOCS=OFF ^
    -DFLTK_BUILD_FLUID=OFF ^
    -DFLTK_BUILD_FLTK_OPTIONS=OFF ^
    %*

cmake --build bin --config Release
cmake --install bin

echo.
echo Done!
endlocal