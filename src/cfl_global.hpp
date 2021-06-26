#pragma once

#ifndef LOCK
#define LOCK(x)                                                                                    \
    Fl::lock();                                                                                    \
    x;                                                                                             \
    Fl::awake();                                                                                   \
    Fl::unlock();
#endif