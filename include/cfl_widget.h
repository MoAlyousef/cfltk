#ifndef __CFL_WIDGET_H__
#define __CFL_WIDGET_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Fl_Widget Fl_Widget;
typedef void(Fl_Callback)(Fl_Widget *, void *);
typedef int (*custom_handler_callback)(Fl_Widget *, int, void *);
typedef void (*custom_draw_callback)(Fl_Widget *, void *);

#define WIDGET_DECLARE(widget)                                                                     \
    typedef struct widget widget;                                                                  \
    widget *widget##_new(int x, int y, int width, int height, const char *title);                  \
    int widget##_x(widget *);                                                                      \
    int widget##_y(widget *);                                                                      \
    int widget##_width(widget *);                                                                  \
    int widget##_height(widget *);                                                                 \
    const char *widget##_label(widget *);                                                          \
    void widget##_set_label(widget *, const char *title);                                          \
    void widget##_redraw(widget *);                                                                \
    void widget##_show(widget *);                                                                  \
    void widget##_hide(widget *);                                                                  \
    void widget##_activate(widget *);                                                              \
    void widget##_deactivate(widget *);                                                            \
    void widget##_redraw_label(widget *);                                                          \
    void widget##_resize(widget *, int x, int y, int width, int height);                           \
    void widget##_widget_resize(widget *, int x, int y, int width, int height);                    \
    const char *widget##_tooltip(widget *);                                                        \
    void widget##_set_tooltip(widget *, const char *txt);                                          \
    int widget##_get_type(widget *);                                                               \
    void widget##_set_type(widget *, int typ);                                                     \
    unsigned int widget##_color(widget *);                                                         \
    void widget##_set_color(widget *, unsigned int color);                                         \
    void widget##_measure_label(const widget *, int *, int *);                                     \
    unsigned int widget##_label_color(widget *);                                                   \
    void widget##_set_label_color(widget *, unsigned int color);                                   \
    int widget##_label_font(widget *);                                                             \
    void widget##_set_label_font(widget *, int font);                                              \
    int widget##_label_size(widget *);                                                             \
    void widget##_set_label_size(widget *, int sz);                                                \
    int widget##_label_type(widget *);                                                             \
    void widget##_set_label_type(widget *, int typ);                                               \
    int widget##_box(widget *);                                                                    \
    void widget##_set_box(widget *, int typ);                                                      \
    int widget##_changed(widget *);                                                                \
    void widget##_set_changed(widget *);                                                           \
    void widget##_clear_changed(widget *);                                                         \
    int widget##_align(widget *);                                                                  \
    void widget##_set_align(widget *, int typ);                                                    \
    void widget##_delete(widget *);                                                                \
    void widget##_set_image(widget *, void *);                                                     \
    void widget##_handle(widget *self, custom_handler_callback cb, void *data);                    \
    void widget##_draw(widget *self, custom_draw_callback cb, void *data);                         \
    void widget##_set_when(widget *, int);                                                         \
    int widget##_when(const widget *);                                                             \
    void *widget##_image(const widget *);                                                          \
    void *widget##_parent(const widget *self);                                                     \
    unsigned int widget##_selection_color(widget *);                                               \
    void widget##_set_selection_color(widget *, unsigned int color);                               \
    void widget##_do_callback(widget *);                                                           \
    int widget##_inside(const widget *self, void *);                                               \
    void *widget##_window(const widget *);                                                         \
    void *widget##_top_window(const widget *);                                                     \
    int widget##_takes_events(const widget *);                                                     \
    void *widget##_user_data(const widget *);                                                      \
    int widget##_take_focus(widget *self);                                                         \
    void widget##_set_visible_focus(widget *self);                                                 \
    void widget##_clear_visible_focus(widget *self);                                               \
    void widget##_visible_focus(widget *self, int v);                                              \
    unsigned int widget##_has_visible_focus(widget *self);                                         \
    void widget##_set_user_data(widget *, void *data);                                             \
    void *widget##_draw_data(const widget *self);                                                  \
    void *widget##_handle_data(const widget *self);                                                \
    void widget##_set_draw_data(widget *self, void *data);                                         \
    void widget##_set_handle_data(widget *self, void *data);                                       \
    unsigned char widget##_damage(const widget *self);                                             \
    void widget##_set_damage(widget *self, unsigned char flag);                                    \
    void widget##_clear_damage(widget *self);                                                      \
    void *widget##_as_window(widget *self);                                                        \
    void *widget##_as_group(widget *self);                                                         \
    void widget##_set_deimage(widget *, void *);                                                   \
    void *widget##_deimage(const widget *);                                                        \
    void widget##_set_callback(widget *, Fl_Callback *, void *);                                   \
    void widget##_set_deleter(widget *, void (*)(void *));                                         \
    int widget##_visible(const widget *self);                                                      \
    int widget##_visible_r(const widget *self);                                                    \
    unsigned int widget##_active(const widget *self);                                              \
    int widget##_active_r(const widget *self);                                                     \
    Fl_Callback *widget##_callback(const widget *self);

#define WIDGET_CLASS(widget)                                                                       \
    struct widget##_Derived : public widget {                                                      \
        void *ev_data_ = NULL;                                                                     \
        void *draw_data_ = NULL;                                                                   \
                                                                                                   \
        typedef int (*handler)(Fl_Widget *, int, void *data);                                      \
        handler inner_handler = NULL;                                                              \
        typedef void (*drawer)(Fl_Widget *, void *data);                                           \
        drawer inner_drawer = NULL;                                                                \
        typedef void (*deleter_fp)(void *);                                                        \
        deleter_fp deleter = NULL;                                                                 \
        widget##_Derived(int x, int y, int w, int h, const char *title = 0)                        \
            : widget(x, y, w, h, title) {                                                          \
        }                                                                                          \
        operator widget *() {                                                                      \
            return (widget *)this;                                                                 \
        }                                                                                          \
        void widget_resize(int x, int y, int w, int h) {                                           \
            Fl_Widget::resize(x, y, w, h);                                                         \
            redraw();                                                                              \
        }                                                                                          \
        virtual void resize(int x, int y, int w, int h) override {                                 \
            widget::resize(x, y, w, h);                                                            \
            if (this->as_window() == this->top_window()) {                                         \
                LOCK(Fl::handle(28, this->top_window());)                                          \
            }                                                                                      \
        }                                                                                          \
        void set_handler(handler h) {                                                              \
            inner_handler = h;                                                                     \
        }                                                                                          \
        void set_handler_data(void *data) {                                                        \
            ev_data_ = data;                                                                       \
        }                                                                                          \
        int handle(int event) override {                                                           \
            int local = 0;                                                                         \
            if (inner_handler) {                                                                   \
                local = inner_handler(this, event, ev_data_);                                      \
                if (local == 0)                                                                    \
                    return widget::handle(event);                                                  \
                else                                                                               \
                    return widget::handle(event) | local;                                          \
            } else {                                                                               \
                return widget::handle(event);                                                      \
            }                                                                                      \
        }                                                                                          \
        void set_drawer(drawer h) {                                                                \
            inner_drawer = h;                                                                      \
        }                                                                                          \
        void set_drawer_data(void *data) {                                                         \
            draw_data_ = data;                                                                     \
        }                                                                                          \
        void draw() override {                                                                     \
            widget::draw();                                                                        \
            if (inner_drawer)                                                                      \
                inner_drawer(this, draw_data_);                                                    \
            else {                                                                                 \
            }                                                                                      \
        }                                                                                          \
        ~widget##_Derived() {                                                                      \
            if (ev_data_)                                                                          \
                deleter(ev_data_);                                                                 \
            ev_data_ = NULL;                                                                       \
            inner_handler = NULL;                                                                  \
            if (draw_data_)                                                                        \
                deleter(draw_data_);                                                               \
            draw_data_ = NULL;                                                                     \
            inner_drawer = NULL;                                                                   \
            if (user_data())                                                                       \
                deleter(user_data());                                                              \
            user_data(NULL);                                                                       \
            callback((void (*)(Fl_Widget *, void *))NULL);                                         \
        }                                                                                          \
    };

#define WIDGET_DEFINE(widget)                                                                      \
    widget *widget##_new(int x, int y, int width, int height, const char *title) {                 \
        LOCK(auto ret = new widget##_Derived(x, y, width, height, title));                         \
        return ret;                                                                                \
    }                                                                                              \
    int widget##_x(widget *self) {                                                                 \
        LOCK(auto ret = self->x());                                                                \
        return ret;                                                                                \
    }                                                                                              \
    int widget##_y(widget *self) {                                                                 \
        LOCK(auto ret = self->y());                                                                \
        return ret;                                                                                \
    }                                                                                              \
    int widget##_width(widget *self) {                                                             \
        LOCK(auto ret = self->w());                                                                \
        return ret;                                                                                \
    }                                                                                              \
    int widget##_height(widget *self) {                                                            \
        LOCK(auto ret = self->h());                                                                \
        return ret;                                                                                \
    }                                                                                              \
    const char *widget##_label(widget *self) {                                                     \
        LOCK(auto ret = self->label());                                                            \
        return ret;                                                                                \
    }                                                                                              \
    void widget##_set_label(widget *self, const char *title) {                                     \
        LOCK(self->copy_label(title);)                                                             \
    }                                                                                              \
    void widget##_redraw(widget *self) {                                                           \
        LOCK(self->redraw();)                                                                      \
    }                                                                                              \
    void widget##_show(widget *self) {                                                             \
        LOCK(self->show();)                                                                        \
    }                                                                                              \
    void widget##_hide(widget *self) {                                                             \
        LOCK(self->hide();)                                                                        \
    }                                                                                              \
    void widget##_activate(widget *self) {                                                         \
        LOCK(self->activate();)                                                                    \
    }                                                                                              \
    void widget##_deactivate(widget *self) {                                                       \
        LOCK(self->deactivate();)                                                                  \
    }                                                                                              \
    void widget##_redraw_label(widget *self) {                                                     \
        LOCK(self->redraw_label();)                                                                \
    }                                                                                              \
    void widget##_resize(widget *self, int x, int y, int width, int height) {                      \
        LOCK(((widget##_Derived *)self)->resize(x, y, width, height);)                             \
    }                                                                                              \
    void widget##_widget_resize(widget *self, int x, int y, int width, int height) {               \
        LOCK(((widget##_Derived *)self)->widget_resize(x, y, width, height))                       \
    }                                                                                              \
    const char *widget##_tooltip(widget *self) {                                                   \
        LOCK(auto ret = self->tooltip());                                                          \
        return ret;                                                                                \
    }                                                                                              \
    void widget##_set_tooltip(widget *self, const char *txt) {                                     \
        LOCK(self->copy_tooltip(txt);)                                                             \
    }                                                                                              \
    int widget##_get_type(widget *self) {                                                          \
        LOCK(auto ret = self->type());                                                             \
        return ret;                                                                                \
    }                                                                                              \
    void widget##_set_type(widget *self, int typ) {                                                \
        LOCK(self->type((decltype(self->type()))typ);)                                             \
    }                                                                                              \
    unsigned int widget##_color(widget *self) {                                                    \
        LOCK(auto ret = self->color());                                                            \
        return ret;                                                                                \
    }                                                                                              \
    void widget##_set_color(widget *self, unsigned int color) {                                    \
        LOCK(self->color(color);)                                                                  \
    }                                                                                              \
    void widget##_measure_label(const widget *self, int *x, int *y) {                              \
        LOCK(self->measure_label(*x, *y);)                                                         \
    }                                                                                              \
    unsigned int widget##_label_color(widget *self) {                                              \
        LOCK(auto ret = self->labelcolor());                                                       \
        return ret;                                                                                \
    }                                                                                              \
    void widget##_set_label_color(widget *self, unsigned int color) {                              \
        LOCK(self->labelcolor(color);)                                                             \
    }                                                                                              \
    int widget##_label_font(widget *self) {                                                        \
        LOCK(auto ret = self->labelfont());                                                        \
        return ret;                                                                                \
    }                                                                                              \
    void widget##_set_label_font(widget *self, int font) {                                         \
        LOCK(self->labelfont(font);)                                                               \
    }                                                                                              \
    int widget##_label_size(widget *self) {                                                        \
        LOCK(auto ret = self->labelsize());                                                        \
        return ret;                                                                                \
    }                                                                                              \
    void widget##_set_label_size(widget *self, int sz) {                                           \
        LOCK(self->labelsize(sz);)                                                                 \
    }                                                                                              \
    int widget##_label_type(widget *self) {                                                        \
        LOCK(auto ret = self->labeltype());                                                        \
        return ret;                                                                                \
    }                                                                                              \
    void widget##_set_label_type(widget *self, int typ) {                                          \
        LOCK(self->labeltype(static_cast<Fl_Labeltype>(typ));)                                     \
    }                                                                                              \
    int widget##_box(widget *self) {                                                               \
        LOCK(auto ret = self->box());                                                              \
        return ret;                                                                                \
    }                                                                                              \
    void widget##_set_box(widget *self, int typ) {                                                 \
        LOCK(self->box(static_cast<Fl_Boxtype>(typ));)                                             \
    }                                                                                              \
    int widget##_changed(widget *self) {                                                           \
        LOCK(auto ret = self->changed());                                                          \
        return ret;                                                                                \
    }                                                                                              \
    void widget##_set_changed(widget *self) {                                                      \
        LOCK(self->set_changed();)                                                                 \
    }                                                                                              \
    void widget##_clear_changed(widget *self) {                                                    \
        LOCK(self->clear_changed();)                                                               \
    }                                                                                              \
    int widget##_align(widget *self) {                                                             \
        LOCK(auto ret = self->align());                                                            \
        return ret;                                                                                \
    }                                                                                              \
    void widget##_set_align(widget *self, int typ) {                                               \
        LOCK(self->align(typ);)                                                                    \
    }                                                                                              \
    void widget##_delete(widget *self) {                                                           \
        delete ((widget##_Derived *)self);                                                         \
    }                                                                                              \
    void widget##_set_image(widget *self, void *image) {                                           \
        LOCK(auto old = self->image(); if (!image) self->image(NULL);                              \
             else self->image(((Fl_Image *)image)->copy()); delete old;)                           \
    }                                                                                              \
    void widget##_handle(widget *self, custom_handler_callback cb, void *data) {                   \
        LOCK(((widget##_Derived *)self)->set_handler_data(data);                                   \
             ((widget##_Derived *)self)->set_handler(cb);)                                         \
    }                                                                                              \
    void widget##_set_when(widget *self, int val) {                                                \
        LOCK(self->when(val);)                                                                     \
    }                                                                                              \
    int widget##_when(const widget *self) {                                                        \
        LOCK(auto ret = self->when());                                                             \
        return ret;                                                                                \
    }                                                                                              \
    void *widget##_image(const widget *self) {                                                     \
        LOCK(auto temp = self->image();)                                                           \
        if (!temp)                                                                                 \
            return NULL;                                                                           \
        LOCK(auto ret = ((Fl_Image *)temp)->copy());                                               \
        return ret;                                                                                \
    }                                                                                              \
    void widget##_draw(widget *self, custom_draw_callback cb, void *data) {                        \
        LOCK(((widget##_Derived *)self)->set_drawer_data(data);                                    \
             ((widget##_Derived *)self)->set_drawer(cb);)                                          \
    }                                                                                              \
    void *widget##_parent(const widget *self) {                                                    \
        LOCK(auto ret = (Fl_Group *)self->parent());                                               \
        return ret;                                                                                \
    }                                                                                              \
    unsigned int widget##_selection_color(widget *self) {                                          \
        LOCK(auto ret = self->selection_color());                                                  \
        return ret;                                                                                \
    }                                                                                              \
    void widget##_set_selection_color(widget *self, unsigned int color) {                          \
        LOCK(self->selection_color(color);)                                                        \
    }                                                                                              \
    void widget##_do_callback(widget *self) {                                                      \
        LOCK(((Fl_Widget *)self)->do_callback();)                                                  \
    }                                                                                              \
    int widget##_inside(const widget *self, void *wid) {                                           \
        LOCK(auto ret = self->inside((Fl_Widget *)wid));                                           \
        return ret;                                                                                \
    }                                                                                              \
    void *widget##_window(const widget *self) {                                                    \
        LOCK(auto ret = (void *)self->window());                                                   \
        return ret;                                                                                \
    }                                                                                              \
    void *widget##_top_window(const widget *self) {                                                \
        LOCK(auto ret = (void *)self->top_window());                                               \
        return ret;                                                                                \
    }                                                                                              \
    int widget##_takes_events(const widget *self) {                                                \
        LOCK(auto ret = self->takesevents());                                                      \
        return ret;                                                                                \
    }                                                                                              \
    void *widget##_user_data(const widget *self) {                                                 \
        LOCK(auto ret = self->user_data());                                                        \
        return ret;                                                                                \
    }                                                                                              \
    int widget##_take_focus(widget *self) {                                                        \
        LOCK(auto ret = self->take_focus());                                                       \
        return ret;                                                                                \
    }                                                                                              \
    void widget##_set_visible_focus(widget *self) {                                                \
        LOCK(self->set_visible_focus();)                                                           \
    }                                                                                              \
    void widget##_clear_visible_focus(widget *self) {                                              \
        LOCK(self->clear_visible_focus();)                                                         \
    }                                                                                              \
    void widget##_visible_focus(widget *self, int v) {                                             \
        LOCK(self->visible_focus(v);)                                                              \
    }                                                                                              \
    unsigned int widget##_has_visible_focus(widget *self) {                                        \
        LOCK(auto ret = self->visible_focus());                                                    \
        return ret;                                                                                \
    }                                                                                              \
    void widget##_set_user_data(widget *self, void *data) {                                        \
        LOCK(self->user_data(data);)                                                               \
    }                                                                                              \
    void *widget##_draw_data(const widget *self) {                                                 \
        LOCK(auto ret = ((widget##_Derived *)self)->draw_data_);                                   \
        return ret;                                                                                \
    }                                                                                              \
    void *widget##_handle_data(const widget *self) {                                               \
        LOCK(auto ret = ((widget##_Derived *)self)->ev_data_);                                     \
        return ret;                                                                                \
    }                                                                                              \
    void widget##_set_draw_data(widget *self, void *data) {                                        \
        LOCK(((widget##_Derived *)self)->draw_data_ = data;)                                       \
    }                                                                                              \
    void widget##_set_handle_data(widget *self, void *data) {                                      \
        LOCK(((widget##_Derived *)self)->ev_data_ = data;)                                         \
    }                                                                                              \
    unsigned char widget##_damage(const widget *self) {                                            \
        LOCK(auto ret = self->damage());                                                           \
        return ret;                                                                                \
    }                                                                                              \
    void widget##_set_damage(widget *self, unsigned char flag) {                                   \
        LOCK(self->damage(flag);)                                                                  \
    }                                                                                              \
    void widget##_clear_damage(widget *self) {                                                     \
        LOCK(self->clear_damage();)                                                                \
    }                                                                                              \
    void *widget##_as_window(widget *self) {                                                       \
        LOCK(auto ret = self->as_window());                                                        \
        return ret;                                                                                \
    }                                                                                              \
    void *widget##_as_group(widget *self) {                                                        \
        LOCK(auto ret = self->as_group());                                                         \
        return ret;                                                                                \
    }                                                                                              \
    void widget##_set_deimage(widget *self, void *image) {                                         \
        LOCK(auto old = self->deimage(); if (!image) self->deimage(NULL);                          \
             else self->deimage(((Fl_Image *)image)->copy()); delete old;)                         \
    }                                                                                              \
    void *widget##_deimage(const widget *self) {                                                   \
        LOCK(auto temp = self->deimage();)                                                         \
        if (!temp)                                                                                 \
            return NULL;                                                                           \
        LOCK(auto ret = ((Fl_Image *)temp)->copy());                                               \
        return ret;                                                                                \
    }                                                                                              \
    void widget##_set_callback(widget *self, Fl_Callback *cb, void *data) {                        \
        LOCK(self->callback(cb, data);)                                                            \
    }                                                                                              \
    void widget##_set_deleter(widget *self, void (*deleter)(void *)) {                             \
        LOCK(((widget##_Derived *)self)->deleter = deleter;)                                       \
    }                                                                                              \
    int widget##_visible(const widget *self) {                                                     \
        LOCK(auto ret = ((Fl_Widget *)self)->visible());                                           \
        return ret;                                                                                \
    }                                                                                              \
    int widget##_visible_r(const widget *self) {                                                   \
        LOCK(auto ret = self->visible_r());                                                        \
        return ret;                                                                                \
    }                                                                                              \
    unsigned int widget##_active(const widget *self) {                                             \
        LOCK(auto ret = self->active());                                                           \
        return ret;                                                                                \
    }                                                                                              \
    int widget##_active_r(const widget *self) {                                                    \
        LOCK(auto ret = self->active_r());                                                         \
        return ret;                                                                                \
    }                                                                                              \
    Fl_Callback *widget##_callback(const widget *self) {                                           \
        LOCK(auto ret = self->callback());                                                         \
        return ret;                                                                                \
    }

WIDGET_DECLARE(Fl_Widget)

#ifdef __cplusplus
}
#endif
#endif
