#include "cfl_widget.h"
#include "cfl_lock.h"
#include "cfl_widget.hpp"

#include <FL/Fl.H>
#include <FL/Fl_Image.H>
#include <FL/Fl_Widget.H>

struct Fl_Widget_Derived : public Fl_Widget {
    Fl_Widget_Derived(const Fl_Widget_Derived &) = delete;
    Fl_Widget_Derived(Fl_Widget_Derived &&) = delete;
    Fl_Widget_Derived &operator=(const Fl_Widget_Derived &other) = delete;
    Fl_Widget_Derived &operator=(Fl_Widget_Derived &&other) = delete;
    void *ev_data_ = nullptr;
    void *draw_data_ = nullptr;
    void *resize_data_ = nullptr;
    void *deleter_data_ = nullptr;
    bool super_draw = true;

    using handler = int (*)(Fl_Widget *, int, void *data);
    handler inner_handler = nullptr;
    using drawer = void (*)(Fl_Widget *, void *);
    drawer inner_drawer = nullptr;
    using deleter_fp = void (*)(void *);
    deleter_fp deleter = nullptr;
    using resizer = void (*)(Fl_Widget *, int, int, int, int, void *);
    resizer resize_handler = nullptr;
    using deleter_fp2 = void (*)(Fl_Widget *, void *);
    deleter_fp2 deleter2 = nullptr;

    Fl_Widget_Derived(int x, int y, int w, int h, const char *title = nullptr)
        : Fl_Widget(x, y, w, h, title) {
    }

    operator Fl_Widget *() {
        return (Fl_Widget *)this;
    }

    static Fl_Widget *from_dyn_ptr(Fl_Widget *ptr) {
        return dynamic_cast<Fl_Widget *>(ptr);
    }

    void widget_resize(int x, int y, int w, int h) {
        Fl_Widget::resize(x, y, w, h);
        redraw();
    }

    void resize(int x, int y, int w, int h) override {
        Fl_Widget::resize(x, y, w, h);
        if (resize_handler)
            resize_handler(this, x, y, w, h, resize_data_);
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

    void set_resizer(resizer h) {
        resize_handler = h;
    }

    void set_resizer_data(void *data) {
        resize_data_ = data;
    }

    int handle(int event) override {
        int local = 0;
        if (inner_handler) {
            local = inner_handler(this, event, ev_data_);
            if (local == 0)
                return Fl_Widget::handle(event);
            else
                return Fl_Widget::handle(event) | local;
        } else {
            return Fl_Widget::handle(event);
        }
    }

    void set_drawer(drawer h) {
        inner_drawer = h;
    }

    void set_drawer_data(void *data) {
        draw_data_ = data;
    }

    void draw() override {
        if (inner_drawer)
            inner_drawer(this, draw_data_);
        else {
        }
    }

    ~Fl_Widget_Derived() {
        if (deleter2 && deleter_data_) {
            deleter2(this, deleter_data_);
        } else if (deleter) {
            if (ev_data_)
                deleter(ev_data_);
            ev_data_ = nullptr;
            if (resize_data_)
                deleter(resize_data_);
            resize_data_ = nullptr;
            inner_handler = nullptr;
            if (draw_data_)
                deleter(draw_data_);
            draw_data_ = nullptr;
            inner_drawer = nullptr;
            if (user_data())
                deleter(user_data());
            user_data(nullptr);
            callback((void (*)(Fl_Widget *, void *)) nullptr);
        }
    }
};

WIDGET_DEFINE(Fl_Widget)
