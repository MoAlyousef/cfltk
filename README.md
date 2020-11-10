# cfltk

C89 bindings for the FLTK gui library, which can be used as basis for C applications or for other bindings in other languages.

To add to your project, you can add this project as a submodule:
```
$ git submodule add https://github.com/moalyousef/cfltk
$ git submodule update --init --recursive
$ cd cfltk/fltk
$ git apply ../fltk.patch # Needed for Android builds or to disable building FLUID
$ cd ../..
```
or by cloning the repo:
```
$ git clone add https://github.com/moalyousef/cfltk
$ cd cfktk
$ git submodule update --init --recursive
$ cd fltk
$ git apply ../fltk.patch # Needed for Android builds or to disable building FLUID
$ cd ../..
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
target_link_libraries(main PRIVATE cfltk fltk fltk_images fltk_jpeg fltk_z fltk_png) # as needed

# for windows-msvc, for windows-gnu, no need
target_link_libraries(main PRIVATE ws2_32 comctl32 gdi32 oleaut32 ole32 uuid shell32 advapi32 comdlg32 winspool user32 kernel32 odbc32)

# for apple
target_link_libraries(main PRIVATE -framework Cocoa)

# for linux
target_link_libraries(main PRIVATE pthread X11 Xext Xinerama Xcursor Xrender Xfixes Xft fontconfig pango-1.0 pangoxft-1.0 gobject-2.0 cairo pangocairo-1.0)

# for android
target_link_libraries(main PRIVATE log android c++_shared)
```

Options which can be used with cmake:
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
For pango support on linux (for rtl and cjk text), you can use `-DOPTION_USE_PANGO=ON`.

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

## Dependencies

CMake (version > 3.0), Git and a C++11 compiler need to be installed and in your PATH for a crossplatform build from source.

- Windows: No dependencies.
- MacOS: No dependencies.
- Linux: X11 and OpenGL development headers need to be installed for development. The libraries themselves are available on linux distros with a graphical user interface.

For Debian-based GUI distributions, that means running:
```
$ sudo apt-get install libx11-dev libxext-dev libxft-dev libxinerama-dev libxcursor-dev libxrender-dev libxfixes-dev libpango1.0-dev libgl1-mesa-dev libglu1-mesa-dev
```
For RHEL-based GUI distributions, that means running:
```
$ sudo yum groupinstall "X Software Development" 
```
For Arch-based GUI distributions, that means running:
```
$ sudo pacman -S libx11 libxext libxft libxinerama libxcursor libxrender libxfixes pango libgl mesa --needed
```
For Alpine linux:
```
$ apk add pango-dev fontconfig-dev libxinerama-dev libxfixes-dev libxcursor-dev
```
- Android: Android Studio, Android Sdk, Android Ndk.

## Usage
```c
#include <cfl.h>
#include <cfl_button.h>
#include <cfl_image.h>
#include <cfl_window.h>
#include <stdlib.h>

void cb(Fl_Widget *w, void *data) { Fl_Widget_set_label(w, "Works!"); }

int main() {
    Fl_init_all(); // init all styles
    Fl_register_images(); // necessary for image support
    Fl_lock(); // necessary for multithreaded support
    Fl_Window *w = Fl_Window_new(100, 100, 400, 300, NULL);
    Fl_Button *b = Fl_Button_new(160, 210, 80, 40, "Click me");
    Fl_Window_end(w);
    Fl_Window_show(w);
    Fl_Button_set_callback(b, cb, NULL);
    return Fl_run();
}
```
