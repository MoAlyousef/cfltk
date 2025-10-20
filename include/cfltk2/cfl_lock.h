#ifndef __CFL_LOCK_H__
#define __CFL_LOCK_H__

#ifdef __cplusplus
extern "C" {
#endif

void Fl_mutex_lock(void);
void Fl_mutex_unlock(void);

#ifndef LOCK
#define LOCK(x)                                                                \
    Fl_mutex_lock();                                                           \
    x;                                                                         \
    Fl_mutex_unlock();
#endif

#ifdef __cplusplus
}
#endif
#endif