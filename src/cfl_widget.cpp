#include "cfl_widget.h"

#include <FL/Fl.H>
#include <FL/Fl_Image.H>
#include <FL/Fl_Widget.H>

struct Fl_Widget_Derived : public Fl_Widget {
    void *ev_data_ = NULL;
    void *draw_data_ = NULL;

    typedef int (*handler)(Fl_Widget *, int, void *data);
    handler inner_handler = NULL;
    typedef void (*drawer)(Fl_Widget *, void *data);
    drawer inner_drawer = NULL;
    typedef void (*deleter_fp)(void *);
    deleter_fp deleter = NULL;

    Fl_Widget_Derived(int x, int y, int w, int h, const char *title = 0)
        : Fl_Widget(x, y, w, h, title) {
    }

    operator Fl_Widget *() {
        return (Fl_Widget *)this;
    }

    void widget_resize(int x, int y, int w, int h) {
        Fl_Widget::resize(x, y, w, h);
        redraw();
    }

    virtual void resize(int x, int y, int w, int h) override {
        Fl_Widget::resize(x, y, w, h);
        if (this->as_window() == this->top_window()) {
            Fl::lock();
            Fl::handle(28, this->top_window());
            Fl::unlock();
            Fl::awake();
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
                return Fl_Widget::handle(event);
            else
                return Fl_Widget::handle(event) * local;
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

WIDGET_DEFINE(Fl_Widget)
