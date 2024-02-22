#ifdef _WIN32
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0501
#include <windows.h>
#endif
#elif __APPLE__
extern "C" void cfltk_setWindowTransparency(void *, unsigned char);
#elif __ANDROID__
#elif FLTK_USE_X11
#include <X11/Xatom.h>
#include <X11/Xlib.h>
#else
#endif

#include <FL/Enumerations.H>
#define FL_INTERNALS

#include "cfl_lock.h"
#include "cfl_widget.hpp"
#include "cfl_window.h"

#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Image.H>
#include <FL/Fl_Menu_Window.H>
#include <FL/Fl_Overlay_Window.H>
#include <FL/Fl_RGB_Image.H>
#include <FL/Fl_Single_Window.H>
#include <FL/Fl_Window.H>
#include <FL/fl_draw.H>
#include <FL/platform.H>

#if defined(FLTK_USE_WAYLAND)
#include <cairo/cairo.h>
#endif

#include <stdint.h>
#include <stdlib.h>

template <typename Win>
struct Window_Derived : public Widget_Derived<Win> {
    unsigned char alpha_ = 255;

    Window_Derived(int x, int y, int w, int h, const char *title = nullptr)
        : Widget_Derived<Win>(x, y, w, h, title) {
    }

    operator Win *() {
        return (Win *)this;
    }

    unsigned char alpha() const {
        return alpha_;
    }

    void set_alpha(unsigned char alpha) {
#if defined(_WIN32)
        HWND hwnd        = fl_xid(this);
        LONG_PTR exstyle = GetWindowLongPtr(hwnd, GWL_EXSTYLE);
        if (!(exstyle & WS_EX_LAYERED)) {
            SetWindowLongPtr(hwnd, GWL_EXSTYLE, exstyle | WS_EX_LAYERED);
        }
        SetLayeredWindowAttributes(hwnd, 0, BYTE(alpha), LWA_ALPHA);
#elif defined(__APPLE__)
        cfltk_setWindowTransparency(
            (void *)fl_xid(this),
            alpha
        ); // definition in separate .m file
#elif defined(__ANDROID__)
        // Do nothing
#elif defined(FLTK_USE_X11)
        auto cardinal_alpha =
            (uint32_t)((UINT32_MAX * (((float)alpha) / 255.0)));
        Atom atom = XInternAtom(fl_display, "_NET_WM_WINDOW_OPACITY", False);
        XChangeProperty(
            fl_display,
            fl_xid(this),
            atom,
            XA_CARDINAL,
            32,
            PropModeReplace,
            (unsigned char *)&cardinal_alpha,
            1
        );
#elif defined(FLTK_USE_WAYLAND)
#else
#endif
        alpha_ = alpha;
    }

    void force_position(int flag) {
        Widget_Derived<Win>::force_position(flag);
    }

    // #if FLTK_USE_WAYLAND && !CFLTK_USE_GL
    //     void draw() override {
    //         auto col = this->color();
    //         double r = ((col >> 24) & 0xff) / 255.0;
    //         double g = ((col >> 16) & 0xff) / 255.0;
    //         double b = ((col >> 8) & 0xff) / 255.0;
    //         cairo_set_source_rgba(fl_wl_gc(), r, g, b, alpha_ / 255.0);
    //         fl_rectf(0, 0, this->w(), this->h());
    //         Widget_Derived<Win>::draw();
    //     }
    // #endif
};

#define WINDOW_CLASS(window) using window##_Derived = Window_Derived<window>;

#define WINDOW_DEFINE(widget)                                                  \
    void widget##_make_modal(widget *self, unsigned int boolean) {             \
        LOCK(                                                                  \
            if (boolean) { self->set_modal(); } else {                         \
                self->set_non_modal();                                         \
            }                                                                  \
        )                                                                      \
    }                                                                          \
    void widget##_fullscreen(widget *self, unsigned int boolean) {             \
        LOCK(                                                                  \
            if (boolean) { self->fullscreen(); } else {                        \
                self->fullscreen_off();                                        \
            }                                                                  \
        )                                                                      \
    }                                                                          \
    void widget##_make_current(widget *self) {                                 \
        LOCK(((Fl_Window *)self)->make_current());                             \
    }                                                                          \
    void widget##_set_icon(widget *self, const void *image) {                  \
        LOCK(self->icon((const Fl_RGB_Image *)((Fl_Image *)image)));           \
    }                                                                          \
    void *widget##_icon(const widget *self) {                                  \
        LOCK(auto ret = (Fl_Image *)self->icon());                             \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_cursor(widget *self, int cursor) {                       \
        LOCK(self->cursor((Fl_Cursor)cursor));                                 \
    }                                                                          \
    int widget##_shown(widget *self) {                                         \
        LOCK(auto ret = self->shown());                                        \
        return ret;                                                            \
    }                                                                          \
    void *widget##_raw_handle(const widget *w) {                               \
        LOCK(Window temp                              = fl_xid(w);             \
             if (!temp) { return nullptr; } auto *xid = new Window;            \
             if (!xid) return nullptr;                                         \
             memcpy(xid, &temp, sizeof(Window)));                              \
        return xid;                                                            \
    }                                                                          \
    void widget##_set_border(widget *self, int flag) {                         \
        LOCK(self->border(flag));                                              \
    }                                                                          \
    int widget##_border(const widget *self) {                                  \
        LOCK(auto ret = self->border());                                       \
        return ret;                                                            \
    }                                                                          \
    void *widget##_region(const widget *self) {                                \
        Fl_X *t = Fl_X::flx(self);                                             \
        if (!t)                                                                \
            return nullptr;                                                    \
        return t->region;                                                      \
    }                                                                          \
    void widget##_set_region(widget *self, void *r) {                          \
        LOCK(Fl_X *t   = Fl_X::flx(self); if (!t) return;                      \
             t->region = (Fl_Region)r;)                                        \
    }                                                                          \
    void widget##_iconize(widget *self) {                                      \
        LOCK(self->iconize())                                                  \
    }                                                                          \
    unsigned int widget##_fullscreen_active(const widget *self) {              \
        LOCK(auto ret = self->fullscreen_active());                            \
        return ret;                                                            \
    }                                                                          \
    void widget##_free_position(widget *self) {                                \
        LOCK(self->free_position())                                            \
    }                                                                          \
    int widget##_decorated_w(const widget *self) {                             \
        LOCK(auto ret = self->decorated_w());                                  \
        return ret;                                                            \
    }                                                                          \
    int widget##_decorated_h(const widget *self) {                             \
        LOCK(auto ret = self->decorated_h());                                  \
        return ret;                                                            \
    }                                                                          \
    void widget##_size_range(                                                  \
        widget *self, int minw, int minh, int maxw, int maxh                   \
    ) {                                                                        \
        LOCK(self->size_range(minw, minh, maxw, maxh))                         \
    }                                                                          \
    void widget##_hotspot(widget *self, Fl_Widget *wid) {                      \
        LOCK(self->hotspot(wid))                                               \
    }                                                                          \
    void widget##_set_shape(widget *self, const void *image) {                 \
        LOCK(auto old = self->shape(); if (!image) self->shape(nullptr);       \
             else self->shape(((Fl_Image *)image)->copy());                    \
             delete old;)                                                      \
    }                                                                          \
    const void *widget##_shape(widget *self) {                                 \
        LOCK(auto temp = self->shape());                                       \
        if (!temp)                                                             \
            return nullptr;                                                    \
        LOCK(auto ret = ((Fl_Image *)temp)->copy());                           \
        return ret;                                                            \
    }                                                                          \
    int widget##_x_root(const widget *self) {                                  \
        LOCK(auto ret = self->x_root());                                       \
        return ret;                                                            \
    }                                                                          \
    int widget##_y_root(const widget *self) {                                  \
        LOCK(auto ret = self->y_root());                                       \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_cursor_image(                                            \
        widget *self, const void *image, int hot_x, int hot_y                  \
    ) {                                                                        \
        LOCK(self->cursor((const Fl_RGB_Image *)image, hot_x, hot_y));         \
    }                                                                          \
    void widget##_default_cursor(widget *self, int cursor) {                   \
        LOCK(self->default_cursor((Fl_Cursor)cursor));                         \
    }                                                                          \
    int widget##_screen_num(widget *self) {                                    \
        LOCK(auto ret = self->screen_num());                                   \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_screen_num(widget *self, int screen_num) {               \
        LOCK(self->screen_num(screen_num));                                    \
    }                                                                          \
    void widget##_wait_for_expose(widget *self) {                              \
        LOCK(self->wait_for_expose());                                         \
    }                                                                          \
    void widget##_set_alpha(widget *self, unsigned char val) {                 \
        LOCK(((widget##_Derived *)self)->set_alpha(val));                      \
    }                                                                          \
    unsigned char widget##_alpha(const widget *self) {                         \
        LOCK(auto ret = ((widget##_Derived *)self)->alpha());                  \
        return ret;                                                            \
    }                                                                          \
    void widget##_force_position(widget *self, int flag) {                     \
        LOCK(((widget##_Derived *)self)->force_position(flag));                \
    }                                                                          \
    const char *widget##_default_xclass(void) {                                \
        LOCK(auto ret = widget::default_xclass());                             \
        return ret;                                                            \
    }                                                                          \
    const char *widget##_xclass(const widget *self) {                          \
        LOCK(auto ret = self->xclass());                                       \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_default_xclass(const char *s) {                          \
        LOCK(widget::default_xclass(s));                                       \
    }                                                                          \
    void widget##_set_xclass(widget *self, const char *s) {                    \
        LOCK(self->xclass(s));                                                 \
    }                                                                          \
    void widget##_clear_modal_states(widget *self) {                           \
        LOCK(self->clear_modal_states());                                      \
    }                                                                          \
    void widget##_set_override(widget *self) {                                 \
        LOCK(self->set_override());                                            \
    }                                                                          \
    int widget##_override(const widget *self) {                                \
        LOCK(auto ret = self->override());                                     \
        return ret;                                                            \
    }                                                                          \
    const char *widget##_icon_label(const widget *self) {                      \
        LOCK(auto ret = self->iconlabel());                                    \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_icon_label(widget *self, const char *label) {            \
        LOCK(self->iconlabel(label));                                          \
    }                                                                          \
    void widget##_set_icons(widget *w, const void *images[], int length) {     \
        w->icons((const Fl_RGB_Image **)images, length);                       \
    }                                                                          \
    void widget##_maximize(widget *w) {                                        \
        LOCK(w->maximize());                                                   \
    }                                                                          \
    void widget##_un_maximize(widget *w) {                                     \
        LOCK(w->un_maximize());                                                \
    }                                                                          \
    unsigned int widget##_maximize_active(const widget *w) {                   \
        LOCK(auto ret = w->maximize_active());                                 \
        return ret;                                                            \
    }

WINDOW_CLASS(Fl_Window)

WIDGET_DEFINE(Fl_Window)

GROUP_DEFINE(Fl_Window)

WINDOW_DEFINE(Fl_Window)

Fl_Window *Fl_Window_new_wh(int width, int height, const char *title) {
    LOCK(auto ret = new Fl_Window(width, height, title));
    return ret;
}

Fl_Window *Fl_Window_find_by_handle(void *handle) {
    LOCK(auto ret = fl_find(*(Window *)handle));
    return ret;
}

winid resolve_raw_handle(void *handle) {
    winid w;
#if defined(_WIN32) || defined(__APPLE__) || defined(__ANDROID__)
    w.opaque = *(Window *)handle;
#elif defined(FLTK_USE_WAYLAND)
    auto h   = fl_wl_surface((wld_window *)(*(Window *)handle));
    w.opaque = h;
#else
    w.x_id = *(Window *)handle;
#endif
    delete (Window *)handle;
    return w;
}

void *Fl_display(void) {
#if defined(__APPLE__) || defined(__ANDROID__)
    return 0;
#elif defined(FLTK_USE_WAYLAND)
    return fl_wl_display();
#else
    return fl_display;
#endif
}

void *Fl_gc(void) {
#if !defined(__ANDROID__) && !defined(FLTK_USE_WAYLAND)
    return fl_gc;
#endif
    return nullptr;
}

void Fl_Window_show_with_args(Fl_Window *w, int argc, char **argv) {
    LOCK(w->show(argc, argv));
}

void Fl_Window_set_raw_handle(Fl_Window *self, void *handle) {
    if (!handle)
        return;
#if !defined(_WIN32) && !defined(__APPLE__) && !defined(__ANDROID__) &&        \
    !defined(FLTK_USE_WAYLAND)
    LOCK(Fl_X::set_xid(self, *(Window *)handle));
#else
        // LOCK(Fl_X *xp = new Fl_X; if (!xp) return; Window h = *(Window
        // *)handle; xp->xid = h;
        //      xp->w = self; xp->next = Fl_X::first; xp->region = 0; Fl_X *i =
        //      Fl_X::flx(self); if (!i) return; i = xp; Fl_X::first = xp;)
#endif
}

WINDOW_CLASS(Fl_Single_Window)

WIDGET_DEFINE(Fl_Single_Window)

GROUP_DEFINE(Fl_Single_Window)

WINDOW_DEFINE(Fl_Single_Window)

WINDOW_CLASS(Fl_Double_Window)

WIDGET_DEFINE(Fl_Double_Window)

void Fl_Double_Window_flush(Fl_Double_Window *w) {
    LOCK(w->flush());
}

GROUP_DEFINE(Fl_Double_Window)

WINDOW_DEFINE(Fl_Double_Window)

WINDOW_CLASS(Fl_Menu_Window);

WIDGET_DEFINE(Fl_Menu_Window)

GROUP_DEFINE(Fl_Menu_Window)

WINDOW_DEFINE(Fl_Menu_Window)

struct Fl_Overlay_Window_Derived : public Window_Derived<Fl_Overlay_Window> {
    Fl_Overlay_Window_Derived(const Fl_Overlay_Window_Derived &) = delete;
    Fl_Overlay_Window_Derived(Fl_Overlay_Window_Derived &&)      = delete;
    Fl_Overlay_Window_Derived &operator=(const Fl_Overlay_Window_Derived &other
    )                                                            = delete;
    Fl_Overlay_Window_Derived &operator=(Fl_Overlay_Window_Derived &&other
    )                                                            = delete;
    void *overlay_draw_data_                                     = nullptr;

    typedef void (*drawer)(Fl_Widget *, void *data);
    drawer inner_overlay_drawer = nullptr;

    Fl_Overlay_Window_Derived(
        int x, int y, int w, int h, const char *title = nullptr
    )
        : Window_Derived<Fl_Overlay_Window>(x, y, w, h, title) {
    }

    operator Fl_Overlay_Window *() {
        return (Fl_Overlay_Window *)this;
    }

    void set_overlay_drawer(drawer h) {
        inner_overlay_drawer = h;
    }

    void set_overlay_drawer_data(void *data) {
        overlay_draw_data_ = data;
    }

    void draw_overlay() override {
        if (inner_overlay_drawer)
            inner_overlay_drawer(this, overlay_draw_data_);
        else {
        }
    }

    ~Fl_Overlay_Window_Derived() {
        if (overlay_draw_data_)
            deleter(overlay_draw_data_);
        overlay_draw_data_   = nullptr;
        inner_overlay_drawer = nullptr;
    }
};

WIDGET_DEFINE(Fl_Overlay_Window)

GROUP_DEFINE(Fl_Overlay_Window)

void Fl_Overlay_Window_draw_overlay(
    Fl_Overlay_Window *self, custom_draw_callback cb, void *data
) {
    LOCK(((Fl_Overlay_Window_Derived *)self)->overlay_draw_data_   = data;
         ((Fl_Overlay_Window_Derived *)self)->inner_overlay_drawer = cb);
}

void Fl_Overlay_Window_redraw_overlay(Fl_Overlay_Window *self) {
    LOCK(self->redraw_overlay());
}

int Fl_Overlay_Window_can_do_overlay(Fl_Overlay_Window *self) {
    LOCK(auto ret = self->can_do_overlay());
    return ret;
}

WINDOW_DEFINE(Fl_Overlay_Window)

#ifdef CFLTK_USE_GL

#include <FL/Fl_Gl_Window.H>
#include <FL/glut.H>

void Fl_gl_start(void) {
    gl_start();
}

void Fl_gl_finish(void) {
    gl_finish();
}

WINDOW_CLASS(Fl_Gl_Window)

WIDGET_DEFINE(Fl_Gl_Window)

GROUP_DEFINE(Fl_Gl_Window)

WINDOW_DEFINE(Fl_Gl_Window)

void Fl_Gl_Window_flush(Fl_Gl_Window *self) {
    LOCK(self->flush());
}

char Fl_Gl_Window_valid(const Fl_Gl_Window *self) {
    LOCK(auto ret = self->valid());
    return ret;
}

void Fl_Gl_Window_set_valid(Fl_Gl_Window *self, char v) {
    LOCK(self->valid(v));
}

char Fl_Gl_Window_context_valid(const Fl_Gl_Window *self) {
    LOCK(auto ret = self->context_valid());
    return ret;
}

void Fl_Gl_Window_set_context_valid(Fl_Gl_Window *self, char v) {
    LOCK(self->context_valid(v));
}

int Fl_Gl_Window_can_do(Fl_Gl_Window *self) {
    LOCK(auto ret = self->can_do());
    return ret;
}

void *Fl_Gl_Window_context(const Fl_Gl_Window *self) {
    LOCK(auto ret = self->context());
    return ret;
}

void Fl_Gl_Window_set_context(Fl_Gl_Window *self, void *ctx, int destroy_flag) {
    LOCK(self->context((GLContext)ctx, destroy_flag));
}

void Fl_Gl_Window_swap_buffers(Fl_Gl_Window *self) {
    LOCK(self->swap_buffers());
}

void Fl_Gl_Window_set_swap_interval(Fl_Gl_Window *self, int frames) {
    LOCK(self->swap_interval(frames));
}

int Fl_Gl_Window_swap_interval(const Fl_Gl_Window *self) {
    LOCK(auto ret = self->swap_interval());
    return ret;
}

void Fl_Gl_Window_ortho(Fl_Gl_Window *self) {
    LOCK(self->ortho());
}

int Fl_Gl_Window_can_do_overlay(Fl_Gl_Window *self) {
    LOCK(auto ret = self->can_do_overlay());
    return ret;
}

void Fl_Gl_Window_redraw_overlay(Fl_Gl_Window *self) {
    LOCK(self->redraw_overlay());
}

void Fl_Gl_Window_hide_overlay(Fl_Gl_Window *self) {
    LOCK(self->hide_overlay());
}

void Fl_Gl_Window_make_overlay_current(Fl_Gl_Window *self) {
    LOCK(self->make_overlay_current());
}

float Fl_Gl_Window_pixels_per_unit(Fl_Gl_Window *self) {
    LOCK(auto ret = self->pixels_per_unit());
    return ret;
}

int Fl_Gl_Window_pixel_w(Fl_Gl_Window *self) {
    LOCK(auto ret = self->pixel_w());
    return ret;
}

int Fl_Gl_Window_pixel_h(Fl_Gl_Window *self) {
    LOCK(auto ret = self->pixel_h());
    return ret;
}

int Fl_Gl_Window_mode(const Fl_Gl_Window *self) {
    LOCK(auto ret = self->mode());
    return ret;
}

void Fl_Gl_Window_set_mode(Fl_Gl_Window *self, int mode) {
    LOCK(self->mode(mode));
}

void *Fl_Gl_Window_get_proc_address(Fl_Gl_Window *self, const char *s) {
    LOCK(auto ret = (void *)glutGetProcAddress(s));
    return ret;
}

WINDOW_CLASS(Fl_Glut_Window)

WIDGET_DEFINE(Fl_Glut_Window)

GROUP_DEFINE(Fl_Glut_Window)

WINDOW_DEFINE(Fl_Glut_Window)

void Fl_Glut_Window_flush(Fl_Glut_Window *self) {
    LOCK(self->flush());
}

char Fl_Glut_Window_valid(const Fl_Glut_Window *self) {
    LOCK(auto ret = self->valid());
    return ret;
}

void Fl_Glut_Window_set_valid(Fl_Glut_Window *self, char v) {
    LOCK(self->valid(v));
}

char Fl_Glut_Window_context_valid(const Fl_Glut_Window *self) {
    LOCK(auto ret = self->context_valid());
    return ret;
}

void Fl_Glut_Window_set_context_valid(Fl_Glut_Window *self, char v) {
    LOCK(self->context_valid(v));
}

int Fl_Glut_Window_can_do(Fl_Glut_Window *self) {
    LOCK(auto ret = self->can_do());
    return ret;
}

void *Fl_Glut_Window_context(const Fl_Glut_Window *self) {
    LOCK(auto ret = self->context());
    return ret;
}

void Fl_Glut_Window_set_context(
    Fl_Glut_Window *self, void *ctx, int destroy_flag
) {
    LOCK(self->context((GLContext)ctx, destroy_flag));
}

void Fl_Glut_Window_swap_buffers(Fl_Glut_Window *self) {
    LOCK(self->swap_buffers());
}

void Fl_Glut_Window_set_swap_interval(Fl_Glut_Window *self, int frames) {
    LOCK(self->swap_interval(frames));
}

int Fl_Glut_Window_swap_interval(const Fl_Glut_Window *self) {
    LOCK(auto ret = self->swap_interval());
    return ret;
}

void Fl_Glut_Window_ortho(Fl_Glut_Window *self) {
    LOCK(self->ortho());
}

int Fl_Glut_Window_can_do_overlay(Fl_Glut_Window *self) {
    LOCK(auto ret = self->can_do_overlay());
    return ret;
}

void Fl_Glut_Window_redraw_overlay(Fl_Glut_Window *self) {
    LOCK(self->redraw_overlay());
}

void Fl_Glut_Window_hide_overlay(Fl_Glut_Window *self) {
    LOCK(self->hide_overlay());
}

void Fl_Glut_Window_make_overlay_current(Fl_Glut_Window *self) {
    LOCK(self->make_overlay_current());
}

float Fl_Glut_Window_pixels_per_unit(Fl_Glut_Window *self) {
    LOCK(auto ret = self->pixels_per_unit());
    return ret;
}

int Fl_Glut_Window_pixel_w(Fl_Glut_Window *self) {
    LOCK(auto ret = self->pixel_w());
    return ret;
}

int Fl_Glut_Window_pixel_h(Fl_Glut_Window *self) {
    LOCK(auto ret = self->pixel_h());
    return ret;
}

int Fl_Glut_Window_mode(const Fl_Glut_Window *self) {
    LOCK(auto ret = self->mode());
    return ret;
}

void Fl_Glut_Window_set_mode(Fl_Glut_Window *self, int mode) {
    LOCK(self->mode(mode));
}

void *Fl_Glut_Window_get_proc_address(Fl_Glut_Window *self, const char *s) {
    LOCK(auto ret = (void *)glutGetProcAddress(s));
    return ret;
}

#endif
