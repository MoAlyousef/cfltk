#include <FL/Fl.H>
#include <FL/platform.H>

#if defined(FLTK_USE_WAYLAND)
#include <wayland-client.h>
#endif

extern "C" void cfltk_platform_hide(void *proxy) {
    #if defined(FLTK_USE_WAYLAND) && defined(FLTK_USE_X11)
    if (FLTK_USE_WAYLAND == 1 && fl_wl_display()) {
        wl_surface_attach((struct wl_surface *)proxy, NULL, 0, 0); 
        wl_surface_commit((struct wl_surface *)proxy); 
    } else if (FLTK_USE_X11 == 1 && fl_x11_display()) {
        XUnmapWindow(fl_x11_display(), (unsigned long)proxy);
    }
    #elif defined(FLTK_USE_WAYLAND)
    if (FLTK_USE_WAYLAND == 1 && fl_wl_display()) {
        wl_surface_attach((struct wl_surface *)proxy, NULL, 0, 0); 
        wl_surface_commit((struct wl_surface *)proxy); 
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