#include <FL/Fl.H>
#include <FL/platform.H>

#if defined(FLTK_USE_WAYLAND)
extern "C" void wl_proxy_marshal(void *, unsigned int opcode, ...);
#endif

extern "C" void cfltk_platform_hide(void *proxy) {
    #if defined(FLTK_USE_WAYLAND) && defined(FLTK_USE_X11)
    if (FLTK_USE_WAYLAND == 1 && fl_wl_display()) {
        wl_proxy_marshal(proxy, 1, NULL, 0, 0); 
        wl_proxy_marshal(proxy, 6); 
    } else if (FLTK_USE_X11 == 1 && fl_x11_display()) {
        XUnmapWindow(fl_x11_display(), (unsigned long)proxy);
    }
    #elif defined(FLTK_USE_WAYLAND)
    if (FLTK_USE_WAYLAND == 1 && fl_wl_display()) {
        wl_proxy_marshal(proxy, 1, NULL, 0, 0); 
        wl_proxy_marshal(proxy, 6); 
    }
    #elif defined(FLTK_USE_X11)
    if (FLTK_USE_X11 == 1 && fl_x11_display()) {
        XUnmapWindow(fl_x11_display(), (unsigned long)proxy);
    }
    #else
    #endif
}

extern "C" void cfltk_platform_show(void *proxy) {
    #if defined(FLTK_USE_X11)
    if (FLTK_USE_X11 == 1 && fl_x11_display()) {
        XMapWindow(fl_x11_display(), (unsigned long)proxy);
    }
    #endif
}