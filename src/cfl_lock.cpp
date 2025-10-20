#include <cfltk2/cfl_lock.h>
#include <cfltk2/cfl_widget.hpp>

#include <FL/Fl.H>

void Fl_mutex_lock() {
#ifndef CFLTK_SINGLE_THREADED
    Fl::lock();
#endif
}

void Fl_mutex_unlock() {
#ifndef CFLTK_SINGLE_THREADED
    Fl::unlock();
#endif
}
