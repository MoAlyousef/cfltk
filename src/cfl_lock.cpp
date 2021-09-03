#include "cfl_lock.hpp"

#include <FL/Fl.H>

void Mutex::lock() {
#ifndef CFLTK_SINGLE_THREADED
    Fl::lock();
#endif
}

void Mutex::unlock() {
#ifndef CFLTK_SINGLE_THREADED
    Fl::unlock();
#endif
}
