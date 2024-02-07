# cfltk

C89 bindings for the FLTK gui library, which can be used as basis for C applications or for other bindings in other languages.
- The official fltk [docs](https://www.fltk.org/doc-1.4/annotated.html).
- The official fltk [repo](https://github.com/fltk/fltk).

## Api

The cfltk api follows the FLTK api mostly, which would make it easier to refer to the FLTK docs. 
As an example:
```c++
Fl_Window *w = new Fl_Window(100, 100, 400, 300, "name");
w->end();
w->show();
```
becomes:
```c
Fl_Window *w = Fl_Window_new(100, 100, 400, 300, "name");
Fl_Window_end(w);
Fl_Window_show(w);
```
The fltk-rs repo shows an example wrapper around cfltk.

## Usage

To add to your project, you can add this project as a submodule:
```
$ git submodule add https://github.com/moalyousef/cfltk
$ git submodule update --init --recursive
$ cd cfltk/fltk
```
or by cloning the repo:
```
$ git clone https://github.com/moalyousef/cfltk
$ cd cfltk
$ git submodule update --init --recursive
```

You can build your project using cmake on the command line or gui:
```
$ cmake -B bin -S .
$ cmake --build bin --parallel
```

An example CMakeLists.txt file:
```cmake
cmake_minimum_required(VERSION 3.14)
project(app)

add_subdirectory(cfltk)

add_executable(main main.c)
target_include_directories(main PRIVATE cfltk/include)
target_link_libraries(main PRIVATE cfltk fltk::fltk fltk::images fltk::png fltk::z) # as needed

# for windows, might be needed in some setups like creating a library
target_link_libraries(main PRIVATE ws2_32 comctl32 gdi32 gdiplus oleaut32 ole32 uuid shell32 advapi32 comdlg32 winspool user32 kernel32 odbc32)

# for apple, might be needed in some setups like creating a library
target_link_libraries(main PRIVATE -framework Cocoa)

# for linux, might be needed in some setups like creating a library
target_link_libraries(main PRIVATE pthread X11 Xext Xinerama Xcursor Xrender Xfixes Xft fontconfig pango-1.0 pangoxft-1.0 gobject-2.0 cairo pangocairo-1.0)
```

Options which can be used with cmake:
```
$ cmake -B bin -S . \
    -DCMAKE_BUILD_TYPE=Release \
    -DFLTK_USE_SYSTEM_LIBPNG=OFF \
    -DFLTK_USE_SYSTEM_LIBJPEG=OFF \
    -DFLTK_USE_SYSTEM_ZLIB=OFF \
    -DFLTK_BUILD_GL=OFF \
    -DFLTK_BUILD_EXAMPLES=OFF \
    -DFLTK_BUILD_TEST=OFF \
    -DFLTK_OPTION_LARGE_FILE=ON \
    -DFLTK_BUILD_HTML_DOCS=OFF \
    -DFLTK_BUILD_PDF_DOCS=OFF \
```
For pango support on linux (for rtl and cjk text), you can use `-DFLTK_USE_PANGO=ON`.

Otherwise, these options can be added to the CMakeLists.txt file:
```cmake
    set(FLTK_USE_SYSTEM_LIBPNG OFF CACHE BOOL " " FORCE)
    set(FLTK_USE_SYSTEM_LIBJPEG OFF CACHE BOOL " " FORCE)
    set(FLTK_USE_SYSTEM_ZLIB OFF CACHE BOOL " " FORCE)
    set(FLTK_BUILD_GL OFF CACHE BOOL " " FORCE)
    set(FLTK_BUILD_EXAMPLES OFF CACHE BOOL " " FORCE)
    set(FLTK_BUILD_TEST OFF CACHE BOOL " " FORCE)
    set(OPTION_LARGE_FILE ON CACHE BOOL " " FORCE)
    set(FLTK_BUILD_HTML_DOCS OFF CACHE BOOL " " FORCE)
    set(FLTK_BUILD_PDF_DOCS OFF CACHE BOOL " " FORCE)
```

An example app:
```c
#include <cfl.h>
#include <cfl_button.h>
#include <cfl_image.h>
#include <cfl_widget.h>
#include <cfl_window.h>
#include <stdlib.h>

void cb(Fl_Widget *w, void *data) { Fl_Widget_set_label(w, "Works!"); }

int main(void) {
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

## Examples
More examples can be found in the examples directory.

- [counter](examples/counter.c) 
![alt_test](examples/flutter_like.jpg)

## Dependencies

CMake (version > 3.7), Git and a C++17 compiler need to be installed and in your PATH for a crossplatform build from source.

- Windows: 
    - MSVC: Windows SDK
    - Gnu: No dependencies
- MacOS: No dependencies.
- Linux: X11 and OpenGL development headers need to be installed for development. The libraries themselves are available on linux distros with a graphical user interface.

For Debian-based GUI distributions, that means running:
```
$ sudo apt-get install libx11-dev libxext-dev libxft-dev libxinerama-dev libxcursor-dev libxrender-dev libxfixes-dev libpango1.0-dev libgl1-mesa-dev libglu1-mesa-dev
```
For RHEL-based GUI distributions, that means running:
```
$ sudo yum groupinstall "X Software Development" && yum install pango-devel libXinerama-devel libstdc++-static
```
For Arch-based GUI distributions, that means running:
```
$ sudo pacman -S libx11 libxext libxft libxinerama libxcursor libxrender libxfixes pango cairo libgl mesa --needed
```
For Alpine linux:
```
$ apk add pango-dev fontconfig-dev libxinerama-dev libxfixes-dev libxcursor-dev mesa-gl
```

## Safety

Both FLTK and the wrapper are exception safe. Widget, image and Fl_Text_Buffer mutating wrapper functions are thread-safe. FLTK manages the lifetime of widgets, which would delete any child widgets when the parent is deleted. The wrapper also provides an Fl_Widget_Tracker object which can be used to prevent use-after-free errors. 
The wrapper itself doesn't perform null checks on pointers returned from FLTK nor on pointers passed to it. Allocation failure should also be checked manually by the consuming user of the wrapper.  
