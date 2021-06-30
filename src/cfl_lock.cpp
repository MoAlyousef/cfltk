#include "cfl_lock.hpp"

#include <FL/Fl.H>

void Mutex::lock() {
    Fl::lock();
}

void Mutex::unlock() {
    Fl::unlock();
}