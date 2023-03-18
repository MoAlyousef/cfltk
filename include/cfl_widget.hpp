#ifndef __CFL_WIDGET_HPP__
#define __CFL_WIDGET_HPP__

#include <FL/Fl_Widget.H>

template <typename T>
struct Widget_Derived : public T {
    Widget_Derived(const Widget_Derived &) = delete;
    Widget_Derived(Widget_Derived &&) = delete;
    Widget_Derived &operator=(const Widget_Derived &other) = delete;
    Widget_Derived &operator=(Widget_Derived &&other) = delete;
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

    Widget_Derived(int x, int y, int w, int h, const char *title = nullptr) : T(x, y, w, h, title) {
    }
    operator T *() {
        return (T *)this;
    }

    static T *from_dyn_ptr(Fl_Widget *ptr) {
        return dynamic_cast<T *>(ptr);
    }

    void widget_resize(int x, int y, int w, int h) {
        Fl_Widget::resize(x, y, w, h);
        this->redraw();
    }
    void resize(int x, int y, int w, int h) override {
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
        if (super_draw) T::draw();
        if (inner_drawer)
            inner_drawer(this, draw_data_);
        else {
        }
    }

    ~Widget_Derived() {
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
            if (this->user_data())
                deleter(this->user_data());
            this->user_data(nullptr);
            this->callback((void (*)(Fl_Widget *, void *))nullptr);
        }
    }
};

#endif