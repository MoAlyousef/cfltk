#ifndef __CFL_WIDGET_HPP__
#define __CFL_WIDGET_HPP__

#include <FL/Fl_Widget.H>

template <class T, class U>
struct is_same {
    constexpr static inline bool value = false;
};

template <class T>
struct is_same<T, T> {
    constexpr static inline bool value = true;
};

struct Deleter {
    void (*deleter)(void *d);
    void *d[4];
};

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
    bool super_draw_first = true;

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

    Widget_Derived(int x, int y, int w, int h, const char *title = nullptr)
        : T(x, y, w, h, title) {
    }
    operator T *() {
        return (T *)this;
    }

    static T *from_dyn_ptr(Fl_Widget *ptr) {
        return dynamic_cast<T *>(ptr);
    }

    static Widget_Derived *from_derived_dyn_ptr(Fl_Widget *ptr) {
        return dynamic_cast<Widget_Derived *>(ptr);
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
    void draw() override {
        if constexpr (!is_same<T, Fl_Widget>::value) {
            if (super_draw && super_draw_first)
                T::draw();
        }
        if (inner_drawer)
            inner_drawer(this, draw_data_);
        else {
        }
        if constexpr (!is_same<T, Fl_Widget>::value) {
            if (super_draw && !super_draw_first)
                T::draw();
        }
    }

    ~Widget_Derived() {
        if (deleter2 && deleter_data_) {
            deleter2(this, deleter_data_);
        } else if (deleter) {
            auto user_data = this->user_data();
            this->user_data(nullptr);
            this->callback((void (*)(Fl_Widget *, void *)) nullptr);
            void *d[4] = {user_data, this->ev_data_, this->draw_data_,
                          this->resize_data_};
            auto data = new Deleter{};
            data->deleter = deleter;
            memcpy(data->d, d, sizeof(d));
            Fl::add_timeout(
                0.0,
                [](void *d) {
                    auto w = (Deleter *)d;
                    for (int i = 0; i < 4; i++) {
                        if (w->d[i])
                            w->deleter(w->d[i]);
                    }
                    delete w;
                },
                data);
        }
    }
};

#endif
