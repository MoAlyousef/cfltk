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
    using resizer          = void (*)(Fl_Widget *, int, int, int, int, void *);
    resizer resize_handler = nullptr;
    using deleter_fp       = void (*)(Fl_Widget *, void *);
    deleter_fp deleter     = nullptr;

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
            int ret = T::handle(event);
            // Both handlers always executed, T::handle executes first
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
        if (deleter) {
            deleter(this, deleter_data_);
        }
    }
};

#endif
