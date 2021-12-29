#ifndef __CFL_WIDGET_HPP__
#define __CFL_WIDGET_HPP__

#include <FL/Fl_Widget.H>

template <typename T>
struct Widget_Derived : public T {
    void *ev_data_ = NULL;
    void *draw_data_ = NULL;
    void *resize_data_ = NULL;

    typedef int (*handler)(Fl_Widget *, int, void *data);
    handler inner_handler = NULL;
    typedef void (*drawer)(Fl_Widget *, void *data);
    drawer inner_drawer = NULL;
    typedef void (*deleter_fp)(void *);
    deleter_fp deleter = NULL;
    typedef void (*resizer)(Fl_Widget *, int, int, int, int, void *data);
    resizer resize_handler = NULL;

    Widget_Derived(int x, int y, int w, int h, const char *title = 0) : T(x, y, w, h, title) {
    }
    operator T *() {
        return (T *)this;
    }
    void widget_resize(int x, int y, int w, int h) {
        Fl_Widget::resize(x, y, w, h);
        this->redraw();
    }
    virtual void resize(int x, int y, int w, int h) override {
        T::resize(x, y, w, h);
        if (resize_handler)
            resize_handler(this, x, y, w, h, resize_data_);
        if (this->as_window() == this->top_window()) {
            LOCK(Fl::handle(28, this->top_window()));
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
                return T::handle(event);
            else
                return T::handle(event) | local;
        } else {
            return T::handle(event);
        }
    }
    void set_drawer(drawer h) {
        inner_drawer = h;
    }
    void set_drawer_data(void *data) {
        draw_data_ = data;
    }
    void draw() override {
        T::draw();
        if (inner_drawer)
            inner_drawer(this, draw_data_);
        else {
        }
    }
    ~Widget_Derived() {
        if (ev_data_)
            deleter(ev_data_);
        ev_data_ = NULL;
        if (resize_data_)
            deleter(resize_data_);
        resize_data_ = NULL;
        inner_handler = NULL;
        if (draw_data_)
            deleter(draw_data_);
        draw_data_ = NULL;
        inner_drawer = NULL;
        if (this->user_data())
            deleter(this->user_data());
        this->user_data(NULL);
        this->callback((void (*)(Fl_Widget *, void *))NULL);
    }
};

#endif