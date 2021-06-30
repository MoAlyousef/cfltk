#pragma once

struct Mutex {    
    static void lock();
    static void unlock();
};

#ifndef LOCK
#define LOCK(x)                                                                                    \
    Mutex::lock();                                                                                 \
    x;                                                                                             \
    Fl::awake();                                                                                   \
    Mutex::unlock();
#endif