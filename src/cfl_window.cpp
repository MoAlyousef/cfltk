#ifdef _WIN32
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0501
#include <windows.h>
#endif
#elif __APPLE__
extern "C" void setWindowTransparency(void *, unsigned char);
#elif __ANDROID__
#else
#include <X11/Xatom.h>
#include <X11/Xlib.h>
#endif

#include <FL/Enumerations.H>
#define FL_INTERNALS

#include "cfl_lock.hpp"
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

#include <stdint.h>
#include <stdlib.h>

#define WINDOW_DEFINE(widget)                                                                      \
    void widget##_make_modal(widget *self, unsigned int boolean) {                                 \
        LOCK(                                                                                      \
            if (boolean) { self->set_modal(); } else { self->set_non_modal(); })                   \
    }                                                                                              \
    void widget##_fullscreen(widget *self, unsigned int boolean) {                                 \
        LOCK(                                                                                      \
            if (boolean) { self->fullscreen(); } else { self->fullscreen_off(); })                 \
    }                                                                                              \
    void widget##_make_current(widget *self) {                                                     \
        LOCK(((Fl_Window *)self)->make_current());                                                 \
    }                                                                                              \
    void widget##_set_icon(widget *self, const void *image) {                                      \
        LOCK(self->icon((const Fl_RGB_Image *)((Fl_Image *)image)));                               \
    }                                                                                              \
    void *widget##_icon(const widget *self) {                                                      \
        LOCK(auto ret = (Fl_Image *)self->icon());                                                 \
        return ret;                                                                                \
    }                                                                                              \
    void widget##_set_cursor(widget *self, int cursor) {                                           \
        LOCK(self->cursor((Fl_Cursor)cursor));                                                     \
    }                                                                                              \
    int widget##_shown(widget *self) {                                                             \
        LOCK(auto ret = self->shown());                                                            \
        return ret;                                                                                \
    }                                                                                              \
    void *widget##_raw_handle(const widget *w) {                                                   \
        LOCK(Window temp = fl_xid(w);                                                              \
             if (!temp) { return NULL; } Window *xid = (Window *)malloc(sizeof(Window));           \
             if (!xid) return NULL; memcpy(xid, &temp, sizeof(Window)));                           \
        return xid;                                                                                \
    }                                                                                              \
    void widget##_set_border(widget *self, int flag) {                                             \
        LOCK(self->border(flag));                                                                  \
    }                                                                                              \
    int widget##_border(const widget *self) {                                                      \
        LOCK(auto ret = self->border());                                                           \
        return ret;                                                                                \
    }                                                                                              \
    void *widget##_region(const widget *self) {                                                    \
        Fl_X *t = Fl_X::i(self);                                                                   \
        if (!t)                                                                                    \
            return NULL;                                                                           \
        return t->region;                                                                          \
    }                                                                                              \
    void widget##_set_region(widget *self, void *r) {                                              \
        LOCK(Fl_X *t = Fl_X::i(self); if (!t) return; t->region = (Fl_Region)r;)                   \
    }                                                                                              \
    void widget##_iconize(widget *self) {                                                          \
        LOCK(self->iconize())                                                                      \
    }                                                                                              \
    unsigned int widget##_fullscreen_active(const widget *self) {                                  \
        LOCK(auto ret = self->fullscreen_active());                                                \
        return ret;                                                                                \
    }                                                                                              \
    void widget##_free_position(widget *self) {                                                    \
        LOCK(self->free_position())                                                                \
    }                                                                                              \
    int widget##_decorated_w(const widget *self) {                                                 \
        LOCK(auto ret = self->decorated_w());                                                      \
        return ret;                                                                                \
    }                                                                                              \
    int widget##_decorated_h(const widget *self) {                                                 \
        LOCK(auto ret = self->decorated_h());                                                      \
        return ret;                                                                                \
    }                                                                                              \
    void widget##_size_range(widget *self, int minw, int minh, int maxw, int maxh) {               \
        LOCK(self->size_range(minw, minh, maxw, maxh))                                             \
    }                                                                                              \
    void widget##_hotspot(widget *self, Fl_Widget *wid) {                                          \
        LOCK(self->hotspot(wid))                                                                   \
    }                                                                                              \
    void widget##_set_shape(widget *self, const void *image) {                                     \
        LOCK(auto old = self->shape(); if (!image) self->shape(NULL);                              \
             else self->shape(((Fl_Image *)image)->copy()); delete old;)                           \
    }                                                                                              \
    const void *widget##_shape(widget *self) {                                                     \
        LOCK(auto temp = self->shape());                                                           \
        if (!temp)                                                                                 \
            return NULL;                                                                           \
        LOCK(auto ret = ((Fl_Image *)temp)->copy());                                               \
        return ret;                                                                                \
    }                                                                                              \
    int widget##_x_root(const widget *self) {                                                      \
        LOCK(auto ret = self->x_root());                                                           \
        return ret;                                                                                \
    }                                                                                              \
    int widget##_y_root(const widget *self) {                                                      \
        LOCK(auto ret = self->y_root());                                                           \
        return ret;                                                                                \
    }                                                                                              \
    void widget##_set_cursor_image(widget *self, const void *image, int hot_x, int hot_y) {        \
        LOCK(self->cursor((const Fl_RGB_Image *)image, hot_x, hot_y));                             \
    }                                                                                              \
    void widget##_default_cursor(widget *self, int cursor) {                                       \
        LOCK(self->default_cursor((Fl_Cursor)cursor));                                             \
    }                                                                                              \
    int widget##_screen_num(widget *self) {                                                        \
        LOCK(auto ret = self->screen_num());                                                       \
        return ret;                                                                                \
    }                                                                                              \
    void widget##_set_screen_num(widget *self, int screen_num) {                                   \
        LOCK(self->screen_num(screen_num));                                                        \
    }

#ifdef __APPLE__
int scale_factor = 2; // assume retina!
#else
int scale_factor = 1;
#endif

WIDGET_CLASS(Fl_Window)

WIDGET_DEFINE(Fl_Window)

GROUP_DEFINE(Fl_Window)

WINDOW_DEFINE(Fl_Window)

Fl_Window *Fl_Window_find_by_handle(void *handle) {
    LOCK(auto ret = fl_find(*(Window *)handle));
    return ret;
}

winid resolve_raw_handle(void *handle) {
    winid w;
#if defined(_WIN32) || defined(__APPLE__) || defined(__ANDROID__)
    w.opaque = *(Window *)handle;
#else
    w.x_id = *(Window *)handle;
#endif
    free(handle);
    return w;
}

void *Fl_display(void) {
#if defined(__APPLE__) || defined(__ANDROID__)
    return 0;
#else
    return fl_display;
#endif
}

void *Fl_gc(void) {
#if !defined(__ANDROID__)
    return fl_gc;
#endif
    return NULL;
}

void Fl_Window_show_with_args(Fl_Window *w, int argc, char **argv) {
    LOCK(w->show(argc, argv));
}

void Fl_Window_set_raw_handle(Fl_Window *self, void *handle) {
    if (!handle)
        return;
#if !defined(_WIN32) && !defined(__APPLE__) && !defined(__ANDROID__)
    LOCK(Fl_X::set_xid(self, *(Window *)handle));
#else
    LOCK(Fl_X *xp = new Fl_X; if (!xp) return; Window h = *(Window *)handle; xp->xid = h;
         xp->w = self; xp->next = Fl_X::first; xp->region = 0; Fl_X *i = Fl_X::i(self);
         if (!i) return; i = xp; Fl_X::first = xp;)
#endif
}

WIDGET_CLASS(Fl_Single_Window)

WIDGET_DEFINE(Fl_Single_Window)

GROUP_DEFINE(Fl_Single_Window)

WINDOW_DEFINE(Fl_Single_Window)

struct Fl_Double_Window_Derived : public Fl_Double_Window {
    unsigned char alpha_ = 255;
    void *ev_data_ = NULL;
    void *draw_data_ = NULL;
    void *overlay_draw_data_ = NULL;
    typedef int (*handler)(Fl_Widget *, int, void *data);
    handler inner_handler = NULL;
    typedef void (*drawer)(Fl_Widget *, void *data);
    drawer inner_drawer = NULL;
    typedef void (*deleter_fp)(void *);
    deleter_fp deleter = NULL;

    Fl_Double_Window_Derived(int x, int y, int w, int h, const char *title = 0)
        : Fl_Double_Window(x, y, w, h, title) {
    }

    operator Fl_Double_Window *() {
        return (Fl_Double_Window *)this;
    }

    unsigned char alpha() const {
        return alpha_;
    }

    void set_alpha(unsigned char alpha) {
#if defined(_WIN32)
        HWND hwnd = fl_xid(this);
        LONG_PTR exstyle = GetWindowLongPtr(hwnd, GWL_EXSTYLE);
        if (!(exstyle & WS_EX_LAYERED)) {
            SetWindowLongPtr(hwnd, GWL_EXSTYLE, exstyle | WS_EX_LAYERED);
        }
        SetLayeredWindowAttributes(hwnd, 0, BYTE(alpha), LWA_ALPHA);
#elif defined(__APPLE__)
        setWindowTransparency((void *)fl_xid(this), alpha); // definition in separate .m file
#elif defined(__ANDROID__)
        // Do nothing
#else
        uint32_t cardinal_alpha = (uint32_t)((UINT32_MAX * (((float)alpha) / 255.0)));
        Atom atom = XInternAtom(fl_display, "_NET_WM_WINDOW_OPACITY", False);
        XChangeProperty(fl_display, fl_xid(this), atom, XA_CARDINAL, 32, PropModeReplace,
                        (unsigned char *)&cardinal_alpha, 1);
#endif
        alpha_ = alpha;
    }

    void widget_resize(int x, int y, int w, int h) {
        Fl_Widget::resize(x, y, w, h);
        redraw();
    }

    virtual void resize(int x, int y, int w, int h) override {
        Fl_Double_Window::resize(x, y, w, h);
        if (this->as_window() == this->top_window()) {
            LOCK(Fl::handle(28, this->top_window()))
        }
    }

    void set_handler(handler h) {
        inner_handler = h;
    }

    void set_handler_data(void *data) {
        ev_data_ = data;
    }

    int handle(int event) override {
        int local = 0;
        if (inner_handler) {
            local = inner_handler(this, event, ev_data_);
            if (local == 0)
                return Fl_Double_Window::handle(event);
            else
                return Fl_Double_Window::handle(event) | local;
        } else {
            return Fl_Double_Window::handle(event);
        }
    }

    void set_drawer(drawer h) {
        inner_drawer = h;
    }

    void set_drawer_data(void *data) {
        draw_data_ = data;
    }

    void draw() override {
        Fl_Double_Window::draw();
        if (inner_drawer)
            inner_drawer(this, draw_data_);
        else {
        }
    }

    ~Fl_Double_Window_Derived() {
        if (ev_data_)
            deleter(ev_data_);
        ev_data_ = NULL;
        inner_handler = NULL;
        if (draw_data_)
            deleter(draw_data_);
        draw_data_ = NULL;
        inner_drawer = NULL;
        if (user_data())
            deleter(user_data());
        user_data(NULL);
        callback((void (*)(Fl_Widget *, void *))NULL);
    }
};

WIDGET_DEFINE(Fl_Double_Window)

void Fl_Double_Window_flush(Fl_Double_Window *w) {
    LOCK(w->flush());
}

void Fl_Double_Window_set_alpha(Fl_Double_Window *self, unsigned char val) {
    LOCK(((Fl_Double_Window_Derived *)self)->set_alpha(val));
}

unsigned char Fl_Double_Window_alpha(const Fl_Double_Window *self) {
    LOCK(auto ret = ((Fl_Double_Window_Derived *)self)->alpha());
    return ret;
}

GROUP_DEFINE(Fl_Double_Window)

WINDOW_DEFINE(Fl_Double_Window)

WIDGET_CLASS(Fl_Menu_Window)

WIDGET_DEFINE(Fl_Menu_Window)

GROUP_DEFINE(Fl_Menu_Window)

WINDOW_DEFINE(Fl_Menu_Window)

struct Fl_Overlay_Window_Derived : public Fl_Overlay_Window {
    void *ev_data_ = NULL;
    void *draw_data_ = NULL;
    void *overlay_draw_data_ = NULL;
    typedef int (*handler)(Fl_Widget *, int, void *data);
    handler inner_handler = NULL;
    typedef void (*drawer)(Fl_Widget *, void *data);
    drawer inner_drawer = NULL;
    typedef void (*overlay_drawer)(Fl_Widget *, void *data);
    drawer inner_overlay_drawer = NULL;
    typedef void (*deleter_fp)(void *);
    deleter_fp deleter = NULL;

    Fl_Overlay_Window_Derived(int x, int y, int w, int h, const char *title = 0)
        : Fl_Overlay_Window(x, y, w, h, title) {
    }

    operator Fl_Overlay_Window *() {
        return (Fl_Overlay_Window *)this;
    }

    void widget_resize(int x, int y, int w, int h) {
        Fl_Widget::resize(x, y, w, h);
        redraw();
    }

    virtual void resize(int x, int y, int w, int h) override {
        Fl_Overlay_Window::resize(x, y, w, h);
        if (this->as_window() == this->top_window()) {
            LOCK(Fl::handle(28, this->top_window()))
        }
    }

    void set_handler(handler h) {
        inner_handler = h;
    }

    void set_handler_data(void *data) {
        ev_data_ = data;
    }

    int handle(int event) override {
        int local = 0;
        if (inner_handler) {
            local = inner_handler(this, event, ev_data_);
            if (local == 0)
                return Fl_Overlay_Window::handle(event);
            else
                return Fl_Overlay_Window::handle(event) | local;
        } else {
            return Fl_Overlay_Window::handle(event);
        }
    }

    void set_drawer(drawer h) {
        inner_drawer = h;
    }

    void set_drawer_data(void *data) {
        draw_data_ = data;
    }

    void set_overlay_drawer(drawer h) {
        inner_overlay_drawer = h;
    }

    void set_overlay_drawer_data(void *data) {
        overlay_draw_data_ = data;
    }

    void draw() override {
        Fl_Overlay_Window::draw();
        if (inner_drawer)
            inner_drawer(this, draw_data_);
        else {
        }
    }

    void draw_overlay() override {
        if (inner_overlay_drawer)
            inner_overlay_drawer(this, overlay_draw_data_);
        else {
        }
    }

    ~Fl_Overlay_Window_Derived() {
        if (ev_data_)
            deleter(ev_data_);
        ev_data_ = NULL;
        inner_handler = NULL;
        if (draw_data_)
            deleter(draw_data_);
        draw_data_ = NULL;
        inner_drawer = NULL;
        if (overlay_draw_data_)
            deleter(overlay_draw_data_);
        overlay_draw_data_ = NULL;
        inner_overlay_drawer = NULL;
        if (user_data())
            deleter(user_data());
        user_data(NULL);
        callback((void (*)(Fl_Widget *, void *))NULL);
    }
};

WIDGET_DEFINE(Fl_Overlay_Window)

GROUP_DEFINE(Fl_Overlay_Window)

void Fl_Overlay_Window_draw_overlay(Fl_Overlay_Window *self, custom_draw_callback cb, void *data) {
    LOCK(((Fl_Overlay_Window_Derived *)self)->set_overlay_drawer_data(data);
         ((Fl_Overlay_Window_Derived *)self)->set_overlay_drawer(cb));
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

WIDGET_CLASS(Fl_Gl_Window)

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

WIDGET_CLASS(Fl_Glut_Window)

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

void Fl_Glut_Window_set_context(Fl_Glut_Window *self, void *ctx, int destroy_flag) {
    LOCK(self->context((GLContext)ctx, destroy_flag));
}

void Fl_Glut_Window_swap_buffers(Fl_Glut_Window *self) {
    LOCK(self->swap_buffers());
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
