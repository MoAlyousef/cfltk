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
    Widget_Derived(const Widget_Derived &)                 = delete;
    Widget_Derived(Widget_Derived &&)                      = delete;
    Widget_Derived &operator=(const Widget_Derived &other) = delete;
    Widget_Derived &operator=(Widget_Derived &&other)      = delete;
    void *ev_data_                                         = nullptr;
    void *draw_data_                                       = nullptr;
    void *resize_data_                                     = nullptr;
    void *deleter_data_                                    = nullptr;
    bool super_draw                                        = true;
    bool super_draw_first                                  = true;
    bool super_handle_first                                = true;

    using handler          = int (*)(Fl_Widget *, int, void *data);
    handler inner_handler  = nullptr;
    using drawer           = void (*)(Fl_Widget *, void *);
    drawer inner_drawer    = nullptr;
    using deleter_fp       = void (*)(void *);
    deleter_fp deleter     = nullptr;
    using resizer          = void (*)(Fl_Widget *, int, int, int, int, void *);
    resizer resize_handler = nullptr;
    using deleter_fp2      = void (*)(Fl_Widget *, void *);
    deleter_fp2 deleter2   = nullptr;

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
        if (this->as_window() == this->top_window()) {
            LOCK(Fl::handle(28, this->top_window()));
        }
        if (resize_handler)
            resize_handler(this, x, y, w, h, resize_data_);
    }

    // Widget event handler. Manages execution of both event handlers:
    //   inner_handler is the handler defined by end-user program, and may not
    //   exist T::handle is the built-in handler in the fltk widget
    int handle(int event) override {
        if (super_handle_first) {
            // Both handlers always executed, T::handle executes first
            int ret = T::handle(event);
            if (inner_handler) {
                int local = inner_handler(this, event, ev_data_);
                return ret | local;
            } else {
                return ret;
            }
        } else {
            // inner_handler executes first. T::handle only executes if
            // inner_handler returns false
            if (inner_handler) {
                if (inner_handler(this, event, ev_data_))
                    return 1; // Local handler consumed the event
            }
            return T::handle(event); // Try the default handler
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
            if (!Fl::wait()) {
                resize_handler = nullptr;
                inner_handler  = nullptr;
                if (ev_data_)
                    deleter(ev_data_);
                ev_data_ = nullptr;
                if (resize_data_)
                    deleter(resize_data_);
                resize_data_ = nullptr;
                if (draw_data_)
                    deleter(draw_data_);
                draw_data_   = nullptr;
                inner_drawer = nullptr;
                if (this->user_data())
                    deleter(this->user_data());
                this->user_data(nullptr);
                this->callback((void (*)(Fl_Widget *, void *)) nullptr);
            } else {
                void *d[4] = {
                    this->user_data(),
                    this->ev_data_,
                    this->draw_data_,
                    this->resize_data_
                };
                auto data     = new Deleter{};
                data->deleter = deleter;
                memcpy(data->d, d, sizeof(d));
                Fl::add_timeout(
                    0.0001,
                    [](void *d) {
                        auto w = (Deleter *)d;
                        for (auto &i : w->d) {
                            if (i)
                                w->deleter(i);
                        }
                        delete w;
                    },
                    data
                );
            }
        }
    }
};

#endif
