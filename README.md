# cfltk

C bindings for the FLTK gui library.

To add to your project, you can add this project as a submodule:
```
$ git submodule add https://github.com/moalyousef/cfltk
$ git submodule update --init --recursive
$ cd cfltk/fltk
$ git apply ../fltk.patch # Needed for Android builds or to disable building FLUID
```

You can build your project using cmake on the command line or gui:
```
$ cmake -B bin -S .
$ cmake --build bin
```

An example CMakeLists.txt file:
```cmake
cmake_minimum_required(VERSION 3.14)
project(app)
add_subdirectory(cfltk)
add_executable(main main.c)
target_include_directories(main PRIVATE cfltk/include)
target_link_libraries(main PRIVATE cfltk fltk fltk_images fltk_jpeg fltk_z fltk_png)

# for windows
target_link_libraries(main PRIVATE ws2_32 comctl32 gdi32 oleaut32 ole32 uuid shell32 advapi32 comdlg32 winspool user32 kernel32 odbc32)

# for apple
target_link_libraries(main PRIVATE -framework Cocoa)

# for linux
target_link_libraries(main PRIVATE pthread X11 Xext Xinerama Xcursor Xrender Xfixes Xft fontconfig pango-1.0 pangoxft-1.0 gobject-2.0 cairo pangocairo-1.0)

# for android
target_link_libraries(main PRIVATE log android c++_shared)
```

Options which can be use with cmake:
```
$ cmake -B bin -S . \
    -DCMAKE_BUILD_TYPE=Release \
    -DOPTION_USE_SYSTEM_LIBPNG=OFF \
    -DOPTION_USE_SYSTEM_LIBJPEG=OFF \
    -DOPTION_USE_SYSTEM_ZLIB=OFF \
    -DOPTION_USE_GL=OFF \
    -DFLTK_BUILD_EXAMPLES=OFF \
    -DFLTK_BUILD_TEST=OFF \
    -DFLTK_BUILD_FLUID=OFF \
    -DOPTION_USE_THREADS=ON \
    -DOPTION_LARGE_FILE=ON \
    -DOPTION_BUILD_HTML_DOCUMENTATION=OFF \
    -DOPTION_BUILD_PDF_DOCUMENTATION=OFF \
```
For pango support on linux (for rtl and cjk text), you can use -DOPTION_USE_PANGO=ON.

Otherwise, these options can be added to the CMakeLists.txt file:
```cmake
    set(OPTION_USE_SYSTEM_LIBPNG OFF CACHE BOOL " " FORCE)
    set(OPTION_USE_SYSTEM_LIBJPEG OFF CACHE BOOL " " FORCE)
    set(OPTION_USE_SYSTEM_ZLIB OFF CACHE BOOL " " FORCE)
    set(OPTION_USE_GL OFF CACHE BOOL " " FORCE)
    set(FLTK_BUILD_EXAMPLES OFF CACHE BOOL " " FORCE)
    set(FLTK_BUILD_TEST OFF CACHE BOOL " " FORCE)
    set(FLTK_BUILD_FLUID OFF CACHE BOOL " " FORCE)
    set(OPTION_USE_THREADS ON CACHE BOOL " " FORCE)
    set(OPTION_LARGE_FILE ON CACHE BOOL " " FORCE)
    set(OPTION_BUILD_HTML_DOCUMENTATION OFF CACHE BOOL " " FORCE)
    set(OPTION_BUILD_PDF_DOCUMENTATION OFF CACHE BOOL " " FORCE)
```
