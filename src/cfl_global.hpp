#pragma once

#ifndef LOCK
#define LOCK(x)                                                                                    \
    Fl::lock();                                                                                    \
    x;                                                                                             \
    Fl::unlock();                                                                                  \
    Fl::awake();
#endif