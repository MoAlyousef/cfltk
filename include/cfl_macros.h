#ifndef __CFL_MACROS_H__
#define __CFL_MACROS_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Fl_Widget Fl_Widget;
typedef void(Fl_Callback)(Fl_Widget *, void *);
typedef int (*custom_handler_callback)(Fl_Widget *, int, void *);
typedef void (*custom_draw_callback)(Fl_Widget *, void *);

#define WIDGET_DECLARE(widget)                                                 \
    typedef struct widget widget;                                              \
    widget *widget##_new(                                                      \
        int x, int y, int width, int height, const char *title                 \
    );                                                                         \
    int widget##_x(widget *);                                                  \
    int widget##_y(widget *);                                                  \
    int widget##_width(widget *);                                              \
    int widget##_height(widget *);                                             \
    const char *widget##_label(widget *);                                      \
    void widget##_set_label(widget *, const char *title);                      \
    void widget##_redraw(widget *);                                            \
    void widget##_show(widget *);                                              \
    void widget##_hide(widget *);                                              \
    void widget##_activate(widget *);                                          \
    void widget##_deactivate(widget *);                                        \
    void widget##_redraw_label(widget *);                                      \
    void widget##_resize(widget *, int x, int y, int width, int height);       \
    void widget##_widget_resize(                                               \
        widget *, int x, int y, int width, int height                          \
    );                                                                         \
    const char *widget##_tooltip(widget *);                                    \
    void widget##_set_tooltip(widget *, const char *txt);                      \
    int widget##_get_type(widget *);                                           \
    void widget##_set_type(widget *, int typ);                                 \
    unsigned int widget##_color(widget *);                                     \
    void widget##_set_color(widget *, unsigned int color);                     \
    void widget##_measure_label(const widget *, int *, int *);                 \
    unsigned int widget##_label_color(widget *);                               \
    void widget##_set_label_color(widget *, unsigned int color);               \
    int widget##_label_font(widget *);                                         \
    void widget##_set_label_font(widget *, int font);                          \
    int widget##_label_size(widget *);                                         \
    void widget##_set_label_size(widget *, int sz);                            \
    int widget##_label_type(widget *);                                         \
    void widget##_set_label_type(widget *, int typ);                           \
    int widget##_box(widget *);                                                \
    void widget##_set_box(widget *, int typ);                                  \
    int widget##_changed(widget *);                                            \
    void widget##_set_changed(widget *);                                       \
    void widget##_clear_changed(widget *);                                     \
    int widget##_align(widget *);                                              \
    void widget##_set_align(widget *, int typ);                                \
    void widget##_delete(widget *);                                            \
    void widget##_set_image(widget *, void *);                                 \
    void widget##_handle(                                                      \
        widget *self, custom_handler_callback cb, void *data                   \
    );                                                                         \
    int widget##_handle_event(widget *self, int event);                        \
    void widget##_draw(widget *self, custom_draw_callback cb, void *data);     \
    void widget##_resize_callback(                                             \
        widget *self,                                                          \
        void (*cb)(Fl_Widget *, int x, int y, int w, int h, void *),           \
        void *data                                                             \
    );                                                                         \
    void widget##_set_when(widget *, int);                                     \
    int widget##_when(const widget *);                                         \
    const void *widget##_image(const widget *);                                \
    void *widget##_parent(const widget *self);                                 \
    unsigned int widget##_selection_color(widget *);                           \
    void widget##_set_selection_color(widget *, unsigned int color);           \
    void widget##_do_callback(widget *);                                       \
    int widget##_inside(const widget *self, void *);                           \
    void *widget##_window(const widget *);                                     \
    void *widget##_top_window(const widget *);                                 \
    int widget##_takes_events(const widget *);                                 \
    void *widget##_user_data(const widget *);                                  \
    int widget##_take_focus(widget *self);                                     \
    void widget##_set_visible_focus(widget *self);                             \
    void widget##_clear_visible_focus(widget *self);                           \
    void widget##_visible_focus(widget *self, int v);                          \
    unsigned int widget##_has_visible_focus(widget *self);                     \
    void widget##_set_user_data(widget *, void *data);                         \
    void *widget##_draw_data(const widget *self);                              \
    void *widget##_handle_data(const widget *self);                            \
    void widget##_set_draw_data(widget *self, void *data);                     \
    void widget##_set_handle_data(widget *self, void *data);                   \
    unsigned char widget##_damage(const widget *self);                         \
    void widget##_set_damage(widget *self, unsigned char flag);                \
    void widget##_set_damage_area(                                             \
        widget *self, unsigned char flag, int x, int y, int w, int h           \
    );                                                                         \
    void widget##_clear_damage(widget *self);                                  \
    void *widget##_as_window(widget *self);                                    \
    void *widget##_as_group(widget *self);                                     \
    void widget##_set_deimage(widget *, void *);                               \
    const void *widget##_deimage(const widget *);                              \
    void widget##_set_callback(widget *, Fl_Callback *, void *);               \
    void widget##_set_deleter(widget *, void (*)(void *));                     \
    int widget##_visible(const widget *self);                                  \
    int widget##_visible_r(const widget *self);                                \
    unsigned int widget##_active(const widget *self);                          \
    int widget##_active_r(const widget *self);                                 \
    Fl_Callback *widget##_callback(const widget *self);                        \
    void widget##_set_deletion_callback(                                       \
        widget *self, void (*)(Fl_Widget *, void *), void *data                \
    );                                                                         \
    widget *widget##_from_dyn_ptr(Fl_Widget *ptr);                             \
    widget *widget##_from_derived_dyn_ptr(Fl_Widget *ptr);                     \
    void widget##_super_draw(Fl_Widget *ptr, int flag);                        \
    void widget##_super_draw_first(Fl_Widget *ptr, int flag);                  \
    void widget##_super_handle_first(Fl_Widget *ptr, int flag);

#define WIDGET_CLASS(widget) using widget##_Derived = Widget_Derived<widget>;

#define WIDGET_DEFINE(widget)                                                  \
    widget *widget##_new(                                                      \
        int x, int y, int width, int height, const char *title                 \
    ) {                                                                        \
        LOCK(auto ret = new widget##_Derived(x, y, width, height, title));     \
        return ret;                                                            \
    }                                                                          \
    int widget##_x(widget *self) {                                             \
        LOCK(auto ret = self->x());                                            \
        return ret;                                                            \
    }                                                                          \
    int widget##_y(widget *self) {                                             \
        LOCK(auto ret = self->y());                                            \
        return ret;                                                            \
    }                                                                          \
    int widget##_width(widget *self) {                                         \
        LOCK(auto ret = self->w());                                            \
        return ret;                                                            \
    }                                                                          \
    int widget##_height(widget *self) {                                        \
        LOCK(auto ret = self->h());                                            \
        return ret;                                                            \
    }                                                                          \
    const char *widget##_label(widget *self) {                                 \
        LOCK(auto ret = self->label());                                        \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_label(widget *self, const char *title) {                 \
        LOCK(self->copy_label(title));                                         \
    }                                                                          \
    void widget##_redraw(widget *self) {                                       \
        LOCK(self->redraw());                                                  \
    }                                                                          \
    void widget##_show(widget *self) {                                         \
        LOCK(self->show());                                                    \
    }                                                                          \
    void widget##_hide(widget *self) {                                         \
        LOCK(self->hide());                                                    \
    }                                                                          \
    void widget##_activate(widget *self) {                                     \
        LOCK(self->activate());                                                \
    }                                                                          \
    void widget##_deactivate(widget *self) {                                   \
        LOCK(self->deactivate());                                              \
    }                                                                          \
    void widget##_redraw_label(widget *self) {                                 \
        LOCK(self->redraw_label());                                            \
    }                                                                          \
    void widget##_resize(widget *self, int x, int y, int width, int height) {  \
        LOCK(((widget##_Derived *)self)->resize(x, y, width, height));         \
    }                                                                          \
    void widget##_widget_resize(                                               \
        widget *self, int x, int y, int width, int height                      \
    ) {                                                                        \
        LOCK(((widget##_Derived *)self)->widget_resize(x, y, width, height))   \
    }                                                                          \
    const char *widget##_tooltip(widget *self) {                               \
        LOCK(auto ret = self->tooltip());                                      \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_tooltip(widget *self, const char *txt) {                 \
        LOCK(self->copy_tooltip(txt));                                         \
    }                                                                          \
    int widget##_get_type(widget *self) {                                      \
        LOCK(auto ret = self->type());                                         \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_type(widget *self, int typ) {                            \
        LOCK(self->type((decltype(self->type()))typ));                         \
    }                                                                          \
    unsigned int widget##_color(widget *self) {                                \
        LOCK(auto ret = self->color());                                        \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_color(widget *self, unsigned int color) {                \
        LOCK(self->color(color));                                              \
    }                                                                          \
    void widget##_measure_label(const widget *self, int *x, int *y) {          \
        LOCK(self->measure_label(*x, *y));                                     \
    }                                                                          \
    unsigned int widget##_label_color(widget *self) {                          \
        LOCK(auto ret = self->labelcolor());                                   \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_label_color(widget *self, unsigned int color) {          \
        LOCK(self->labelcolor(color));                                         \
    }                                                                          \
    int widget##_label_font(widget *self) {                                    \
        LOCK(auto ret = self->labelfont());                                    \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_label_font(widget *self, int font) {                     \
        LOCK(self->labelfont(font));                                           \
    }                                                                          \
    int widget##_label_size(widget *self) {                                    \
        LOCK(auto ret = self->labelsize());                                    \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_label_size(widget *self, int sz) {                       \
        LOCK(self->labelsize(sz));                                             \
    }                                                                          \
    int widget##_label_type(widget *self) {                                    \
        LOCK(auto ret = self->labeltype());                                    \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_label_type(widget *self, int typ) {                      \
        LOCK(self->labeltype(static_cast<Fl_Labeltype>(typ)));                 \
    }                                                                          \
    int widget##_box(widget *self) {                                           \
        LOCK(auto ret = self->box());                                          \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_box(widget *self, int typ) {                             \
        LOCK(self->box(static_cast<Fl_Boxtype>(typ)));                         \
    }                                                                          \
    int widget##_changed(widget *self) {                                       \
        LOCK(auto ret = self->changed());                                      \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_changed(widget *self) {                                  \
        LOCK(self->set_changed());                                             \
    }                                                                          \
    void widget##_clear_changed(widget *self) {                                \
        LOCK(self->clear_changed());                                           \
    }                                                                          \
    int widget##_align(widget *self) {                                         \
        LOCK(auto ret = self->align());                                        \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_align(widget *self, int typ) {                           \
        LOCK(self->align(typ));                                                \
    }                                                                          \
    void widget##_delete(widget *self) {                                       \
        delete ((widget##_Derived *)self);                                     \
    }                                                                          \
    void widget##_set_image(widget *self, void *image) {                       \
        LOCK(self->bind_image(image ? ((Fl_Image *)image)->copy() : nullptr)); \
    }                                                                          \
    void widget##_handle(                                                      \
        widget *self, custom_handler_callback cb, void *data                   \
    ) {                                                                        \
        LOCK(((widget##_Derived *)self)->ev_data_      = data;                 \
             ((widget##_Derived *)self)->inner_handler = cb);                  \
    }                                                                          \
    int widget##_handle_event(widget *self, int event) {                       \
        LOCK(auto ret = ((widget##_Derived *)self)->handle(event));            \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_when(widget *self, int val) {                            \
        LOCK(self->when(val));                                                 \
    }                                                                          \
    int widget##_when(const widget *self) {                                    \
        LOCK(auto ret = self->when());                                         \
        return ret;                                                            \
    }                                                                          \
    const void *widget##_image(const widget *self) {                           \
        LOCK(auto temp = self->image());                                       \
        return temp;                                                           \
    }                                                                          \
    void widget##_draw(widget *self, custom_draw_callback cb, void *data) {    \
        LOCK(((widget##_Derived *)self)->draw_data_   = data;                  \
             ((widget##_Derived *)self)->inner_drawer = cb);                   \
    }                                                                          \
    void widget##_resize_callback(                                             \
        widget *self,                                                          \
        void (*cb)(Fl_Widget *, int x, int y, int w, int h, void *),           \
        void *data                                                             \
    ) {                                                                        \
        LOCK(((widget##_Derived *)self)->resize_data_   = data;                \
             ((widget##_Derived *)self)->resize_handler = cb);                 \
    }                                                                          \
    void *widget##_parent(const widget *self) {                                \
        LOCK(auto ret = (Fl_Group *)self->parent());                           \
        return ret;                                                            \
    }                                                                          \
    unsigned int widget##_selection_color(widget *self) {                      \
        LOCK(auto ret = self->selection_color());                              \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_selection_color(widget *self, unsigned int color) {      \
        LOCK(self->selection_color(color));                                    \
    }                                                                          \
    void widget##_do_callback(widget *self) {                                  \
        LOCK(((Fl_Widget *)self)->do_callback());                              \
    }                                                                          \
    int widget##_inside(const widget *self, void *wid) {                       \
        LOCK(auto ret = self->inside((Fl_Widget *)wid));                       \
        return ret;                                                            \
    }                                                                          \
    void *widget##_window(const widget *self) {                                \
        LOCK(auto ret = (void *)self->window());                               \
        return ret;                                                            \
    }                                                                          \
    void *widget##_top_window(const widget *self) {                            \
        LOCK(auto ret = (void *)self->top_window());                           \
        return ret;                                                            \
    }                                                                          \
    int widget##_takes_events(const widget *self) {                            \
        LOCK(auto ret = self->takesevents());                                  \
        return ret;                                                            \
    }                                                                          \
    void *widget##_user_data(const widget *self) {                             \
        LOCK(auto ret = self->user_data());                                    \
        return ret;                                                            \
    }                                                                          \
    int widget##_take_focus(widget *self) {                                    \
        LOCK(auto ret = self->take_focus());                                   \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_visible_focus(widget *self) {                            \
        LOCK(self->set_visible_focus());                                       \
    }                                                                          \
    void widget##_clear_visible_focus(widget *self) {                          \
        LOCK(self->clear_visible_focus());                                     \
    }                                                                          \
    void widget##_visible_focus(widget *self, int v) {                         \
        LOCK(self->visible_focus(v));                                          \
    }                                                                          \
    unsigned int widget##_has_visible_focus(widget *self) {                    \
        LOCK(auto ret = self->visible_focus());                                \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_user_data(widget *self, void *data) {                    \
        LOCK(self->user_data(data));                                           \
    }                                                                          \
    void *widget##_draw_data(const widget *self) {                             \
        LOCK(auto ret = ((widget##_Derived *)self)->draw_data_);               \
        return ret;                                                            \
    }                                                                          \
    void *widget##_handle_data(const widget *self) {                           \
        LOCK(auto ret = ((widget##_Derived *)self)->ev_data_);                 \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_draw_data(widget *self, void *data) {                    \
        LOCK(((widget##_Derived *)self)->draw_data_ = data;)                   \
    }                                                                          \
    void widget##_set_handle_data(widget *self, void *data) {                  \
        LOCK(((widget##_Derived *)self)->ev_data_ = data;)                     \
    }                                                                          \
    unsigned char widget##_damage(const widget *self) {                        \
        LOCK(auto ret = self->damage());                                       \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_damage(widget *self, unsigned char flag) {               \
        LOCK(self->damage(flag));                                              \
    }                                                                          \
    void widget##_set_damage_area(                                             \
        widget *self, unsigned char flag, int x, int y, int w, int h           \
    ) {                                                                        \
        LOCK(self->damage(flag, x, y, w, h));                                  \
    }                                                                          \
    void widget##_clear_damage(widget *self) {                                 \
        LOCK(self->clear_damage());                                            \
    }                                                                          \
    void *widget##_as_window(widget *self) {                                   \
        LOCK(auto ret = self->as_window());                                    \
        return ret;                                                            \
    }                                                                          \
    void *widget##_as_group(widget *self) {                                    \
        LOCK(auto ret = self->as_group());                                     \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_deimage(widget *self, void *image) {                     \
        LOCK(self->bind_deimage(image ? ((Fl_Image *)image)->copy() : nullptr) \
        );                                                                     \
    }                                                                          \
    const void *widget##_deimage(const widget *self) {                         \
        LOCK(auto temp = self->deimage());                                     \
        return temp;                                                           \
    }                                                                          \
    void widget##_set_callback(widget *self, Fl_Callback *cb, void *data) {    \
        LOCK(self->callback(cb, data));                                        \
    }                                                                          \
    void widget##_set_deleter(widget *self, void (*deleter)(void *)) {         \
        LOCK(((widget##_Derived *)self)->deleter = deleter;)                   \
    }                                                                          \
    int widget##_visible(const widget *self) {                                 \
        LOCK(auto ret = ((Fl_Widget *)self)->visible());                       \
        return ret;                                                            \
    }                                                                          \
    int widget##_visible_r(const widget *self) {                               \
        LOCK(auto ret = self->visible_r());                                    \
        return ret;                                                            \
    }                                                                          \
    unsigned int widget##_active(const widget *self) {                         \
        LOCK(auto ret = self->active());                                       \
        return ret;                                                            \
    }                                                                          \
    int widget##_active_r(const widget *self) {                                \
        LOCK(auto ret = self->active_r());                                     \
        return ret;                                                            \
    }                                                                          \
    Fl_Callback *widget##_callback(const widget *self) {                       \
        LOCK(auto ret = self->callback());                                     \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_deletion_callback(                                       \
        widget *self, void (*cb)(Fl_Widget *, void *), void *data              \
    ) {                                                                        \
        LOCK(((widget##_Derived *)self)->deleter2      = cb;                   \
             ((widget##_Derived *)self)->deleter_data_ = data);                \
    }                                                                          \
    widget *widget##_from_dyn_ptr(Fl_Widget *ptr) {                            \
        return widget##_Derived::from_dyn_ptr(ptr);                            \
    }                                                                          \
    widget *widget##_from_derived_dyn_ptr(Fl_Widget *ptr) {                    \
        return widget##_Derived::from_derived_dyn_ptr(ptr);                    \
    }                                                                          \
    void widget##_super_draw(Fl_Widget *self, int flag) {                      \
        ((widget##_Derived *)self)->super_draw = flag;                         \
    }                                                                          \
    void widget##_super_draw_first(Fl_Widget *self, int flag) {                \
        ((widget##_Derived *)self)->super_draw_first = flag;                   \
    }                                                                          \
    void widget##_super_handle_first(Fl_Widget *self, int flag) {              \
        ((widget##_Derived *)self)->super_handle_first = flag;                 \
    }

#define GROUP_DECLARE(widget)                                                  \
    void widget##_begin(widget *self);                                         \
    void widget##_end(widget *self);                                           \
    int widget##_find(widget *self, const void *);                             \
    void widget##_add(widget *self, void *);                                   \
    void widget##_insert(widget *self, void *, int pos);                       \
    void widget##_remove(widget *self, void *wid);                             \
    void widget##_remove_by_index(widget *self, int idx);                      \
    void widget##_clear(widget *self);                                         \
    int widget##_children(widget *self);                                       \
    Fl_Widget *widget##_child(widget *, int index);                            \
    void widget##_resizable(widget *self, void *);                             \
    void widget##_set_clip_children(widget *self, int c);                      \
    int widget##_clip_children(widget *self);                                  \
    void widget##_init_sizes(widget *self);                                    \
    void widget##_draw_child(const widget *self, Fl_Widget *w);                \
    void widget##_update_child(const widget *self, Fl_Widget *w);              \
    void widget##_draw_outside_label(const widget *self, const Fl_Widget *w);  \
    void widget##_draw_children(widget *self);

#define GROUP_DEFINE(widget)                                                   \
    void widget##_begin(widget *self) {                                        \
        LOCK(self->begin());                                                   \
    }                                                                          \
    void widget##_end(widget *self) {                                          \
        LOCK(self->end());                                                     \
    }                                                                          \
    int widget##_find(widget *self, const void *wid) {                         \
        LOCK(auto ret = self->find((const Fl_Widget *)wid));                   \
        return ret;                                                            \
    }                                                                          \
    void widget##_add(widget *self, void *wid) {                               \
        LOCK(self->add((Fl_Widget *)wid));                                     \
    }                                                                          \
    void widget##_insert(widget *self, void *wid, int pos) {                   \
        LOCK(self->insert(*(Fl_Widget *)wid, pos));                            \
    }                                                                          \
    void widget##_remove(widget *self, void *wid) {                            \
        LOCK(self->remove(*(Fl_Widget *)wid));                                 \
    }                                                                          \
    void widget##_remove_by_index(widget *self, int idx) {                     \
        LOCK(self->remove(*self->child(idx)));                                 \
    }                                                                          \
    void widget##_clear(widget *self) {                                        \
        LOCK(self->clear());                                                   \
    }                                                                          \
    int widget##_children(widget *self) {                                      \
        LOCK(auto ret = self->children());                                     \
        return ret;                                                            \
    }                                                                          \
    Fl_Widget *widget##_child(widget *self, int index) {                       \
        LOCK(auto ret = self->child(index));                                   \
        return ret;                                                            \
    }                                                                          \
    void widget##_resizable(widget *self, void *wid) {                         \
        LOCK(self->resizable((Fl_Widget *)wid));                               \
    }                                                                          \
    void widget##_set_clip_children(widget *self, int c) {                     \
        LOCK(self->clip_children(c));                                          \
    }                                                                          \
    int widget##_clip_children(widget *self) {                                 \
        LOCK(auto ret = self->clip_children());                                \
        return ret;                                                            \
    }                                                                          \
    void widget##_init_sizes(widget *self) {                                   \
        LOCK(self->init_sizes());                                              \
    }                                                                          \
    void widget##_draw_child(const widget *self, Fl_Widget *w) {               \
        (void)self;                                                            \
        if (w->visible() && w->type() < 0xF0 &&                                \
            fl_not_clipped(w->x(), w->y(), w->w(), w->h())) {                  \
            LOCK(w->clear_damage(FL_DAMAGE_ALL); w->draw();                    \
                 w->clear_damage());                                           \
        }                                                                      \
    }                                                                          \
    void widget##_update_child(const widget *self, Fl_Widget *w) {             \
        (void)self;                                                            \
        if (w->damage() && w->visible() && w->type() < 0xF0 &&                 \
            fl_not_clipped(w->x(), w->y(), w->w(), w->h())) {                  \
            LOCK(w->draw(); w->clear_damage());                                \
        }                                                                      \
    }                                                                          \
    void widget##_draw_outside_label(const widget *self, const Fl_Widget *w) { \
        if (!w->visible())                                                     \
            return;                                                            \
        if (!(w->align() & 15) || (w->align() & FL_ALIGN_INSIDE))              \
            return;                                                            \
        Fl_Align a = w->align();                                               \
        int X      = w->x();                                                   \
        int Y      = w->y();                                                   \
        int W      = w->w();                                                   \
        int H      = w->h();                                                   \
        int wx, wy;                                                            \
        if (const_cast<widget *>(self)->as_window()) {                         \
            wx = wy = 0;                                                       \
        } else {                                                               \
            wx = self->x();                                                    \
            wy = self->y();                                                    \
        }                                                                      \
        if ((a & FL_ALIGN_POSITION_MASK) == FL_ALIGN_LEFT_TOP) {               \
            a = (a & (~FL_ALIGN_POSITION_MASK)) | FL_ALIGN_TOP_RIGHT;          \
            X = wx;                                                            \
            W = w->x() - X - 3;                                                \
        } else if ((a & FL_ALIGN_POSITION_MASK) == FL_ALIGN_LEFT_BOTTOM) {     \
            a = (a & (~FL_ALIGN_POSITION_MASK)) | FL_ALIGN_BOTTOM_RIGHT;       \
            X = wx;                                                            \
            W = w->x() - X - 3;                                                \
        } else if ((a & FL_ALIGN_POSITION_MASK) == FL_ALIGN_RIGHT_TOP) {       \
            a = (a & (~FL_ALIGN_POSITION_MASK)) | FL_ALIGN_TOP_LEFT;           \
            X = X + W + 3;                                                     \
            W = wx + self->w() - X;                                            \
        } else if ((a & FL_ALIGN_POSITION_MASK) == FL_ALIGN_RIGHT_BOTTOM) {    \
            a = (a & (~FL_ALIGN_POSITION_MASK)) | FL_ALIGN_BOTTOM_LEFT;        \
            X = X + W + 3;                                                     \
            W = wx + self->w() - X;                                            \
        } else if (a & FL_ALIGN_TOP) {                                         \
            a ^= FL_ALIGN_TOP;                                                 \
            a |= FL_ALIGN_BOTTOM;                                              \
            Y = wy;                                                            \
            H = w->y() - Y;                                                    \
        } else if (a & FL_ALIGN_BOTTOM) {                                      \
            a ^= FL_ALIGN_BOTTOM;                                              \
            a |= FL_ALIGN_TOP;                                                 \
            Y = Y + H;                                                         \
            H = wy + self->h() - Y;                                            \
        } else if (a & FL_ALIGN_LEFT) {                                        \
            a ^= FL_ALIGN_LEFT;                                                \
            a |= FL_ALIGN_RIGHT;                                               \
            X = wx;                                                            \
            W = w->x() - X - 3;                                                \
        } else if (a & FL_ALIGN_RIGHT) {                                       \
            a ^= FL_ALIGN_RIGHT;                                               \
            a |= FL_ALIGN_LEFT;                                                \
            X = X + W + 3;                                                     \
            W = wx + self->w() - X;                                            \
        }                                                                      \
        LOCK(w->draw_label(X, Y, W, H, (Fl_Align)a));                          \
    }                                                                          \
    void widget##_draw_children(widget *self) {                                \
        LOCK(                                                                  \
            Fl_Widget *const *a = self->array(); if (self->clip_children()) {  \
                fl_push_clip(                                                  \
                    self->x() + Fl::box_dx(self->box()),                       \
                    self->y() + Fl::box_dy(self->box()),                       \
                    self->w() - Fl::box_dw(self->box()),                       \
                    self->h() - Fl::box_dh(self->box())                        \
                );                                                             \
            } if (self->damage() & ~0x01) {                                    \
                for (int i = self->children(); i--;) {                         \
                    Fl_Widget &o = **a++;                                      \
                    widget##_draw_child(self, &o);                             \
                    widget##_draw_outside_label(self, &o);                     \
                }                                                              \
            } else {                                                           \
                for (int i = self->children(); i--;)                           \
                    widget##_update_child(self, *a++);                         \
            } if (self->clip_children()) fl_pop_clip()                         \
        );                                                                     \
    }

#ifdef __cplusplus
}
#endif
#endif
