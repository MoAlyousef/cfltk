#include <FL/Fl.H> // Has to be the first include!

#include "cfl.h"

#include <FL/Enumerations.H>
#include <FL/Fl_File_Icon.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Window.H>
#include <FL/platform.H>

#ifndef LOCK
#define LOCK(x)                                                                \
    Fl::lock();                                                                \
    x;                                                                         \
    Fl::unlock();
#endif

#ifdef __ANDROID__
#include <queue>
#include <thread>

class Buffer {
  private:
    using item = void *;
    std::queue<item> queue_;
    std::mutex m_;
    std::condition_variable cv_;

  public:
    void send(const item &i) {
        std::unique_lock<std::mutex> lock(m_);
        queue_.push(i);
        cv_.notify_one();
    }

    item recv(void) {
        if (!queue_.empty()) {
            std::unique_lock<std::mutex> lock(m_);
            cv_.wait(lock, [&](void) { return !queue_.empty(); });
            item result = queue_.front();
            queue_.pop();
            return result;
        } else {
            return nullptr;
        }
    }
} android_buffer;
#endif

int Fl_run(void) {
    return Fl::run();
}

int Fl_check(void) {
    return Fl::check();
}

int Fl_ready(void) {
    return Fl::ready();
}

void Fl_release(void) {
    Fl::release();
}

int Fl_reload_scheme(void) {
    return Fl::reload_scheme();
}

int Fl_menu_linespacing(void) {
    return Fl::menu_linespacing();
}

void Fl_set_menu_linespacing(int H) {
    Fl::menu_linespacing(H);
}

int Fl_lock(void) {
    return Fl::lock();
}

void Fl_unlock(void) {
    Fl::unlock();
}

int Fl_awake_callback(Fl_Awake_Handler handler, void *data) {
    return Fl::awake(handler, data);
}

void Fl_awake(void) {
    Fl::awake();
}

void Fl_set_scrollbar_size(int v) {
    Fl::scrollbar_size(v);
}

int Fl_scrollbar_size(void) {
    return Fl::scrollbar_size();
}

void *Fl_grab(void) {
    return Fl::grab();
}

void Fl_set_grab(void *v) {
    Fl::grab((Fl_Window *)v);
}

int Fl_event(void) {
    return Fl::event();
}

int Fl_event_key(void) {
    return Fl::event_key();
}

int Fl_event_original_key(void) {
    return Fl::event_original_key();
}

int Fl_event_key_down(int key) {
    return Fl::event_key(key);
}

const char *Fl_event_text(void) {
    return Fl::event_text();
}

int Fl_event_button(void) {
    return Fl::event_button();
}

int Fl_event_clicks(void) {
    return Fl::event_clicks();
}

int Fl_event_x(void) {
    return Fl::event_x();
}

int Fl_event_y(void) {
    return Fl::event_y();
}

int Fl_event_x_root(void) {
    return Fl::event_x_root();
}

int Fl_event_y_root(void) {
    return Fl::event_y_root();
}
int Fl_event_dx(void) {
    return Fl::event_dx();
}

int Fl_event_dy(void) {
    return Fl::event_dy();
}

void Fl_get_mouse(int *x, int *y) {
    Fl::get_mouse(*x, *y);
}

int Fl_event_is_click(void) {
    return Fl::event_is_click();
}

int Fl_event_length(void) {
    return Fl::event_length();
}

int Fl_event_state(void) {
    return Fl::event_state();
}

int Fl_w(void) {
    return Fl::w();
}

int Fl_h(void) {
    return Fl::h();
}

int Fl_screen_x(void) {
    return Fl::x();
}

int Fl_screen_y(void) {
    return Fl::y();
}

int Fl_screen_h(void) {
    return Fl::h();
}

int Fl_screen_w(void) {
    return Fl::w();
}

int Fl_compose(int *del) {
    int temp = 0;
    auto ret = Fl::compose(temp);
    *del     = temp;
    return ret;
}

void Fl_compose_reset(void) {
    Fl::compose_reset();
}

int Fl_compose_state(void) {
    return Fl::compose_state;
}

void Fl_copy(const char *stuff, int len, int destination) {
    Fl::copy(stuff, len, destination);
}

void Fl_paste_text(Fl_Widget *widget, int src) {
    Fl::paste(*widget, src, Fl::clipboard_plain_text);
}

void Fl_paste_image(Fl_Widget *widget, int src) {
    Fl::paste(*widget, src, Fl::clipboard_image);
}

int Fl_set_scheme(const char *scheme) {
    return Fl::scheme(scheme);
}

int Fl_scheme(void) {
    const char *v = Fl::scheme();
    if (!strcmp(v, "base")) {
        return 0;
    } else if (!strcmp(v, "gtk+")) {
        return 1;
    } else if (!strcmp(v, "gleam")) {
        return 2;
    } else if (!strcmp(v, "oxy")) {
        return 3;
    } else {
        return 4;
    }
}

const char *Fl_scheme_string(void) {
    return Fl::scheme();
}

int Fl_visible_focus(void) {
    return Fl::visible_focus();
}

void Fl_set_visible_focus(int f) {
    Fl::visible_focus(f);
}

void Fl_set_box_type(int o, int n) {
    Fl::set_boxtype((Fl_Boxtype)o, (Fl_Boxtype)n);
}

int Fl_box_shadow_width(void) {
    return Fl::box_shadow_width();
}

void Fl_set_box_shadow_width(int W) {
    Fl::box_shadow_width(W);
}

int Fl_box_border_radius_max(void) {
    return Fl::box_border_radius_max();
}

void Fl_set_box_border_radius_max(int R) {
    Fl::box_border_radius_max(R);
}

unsigned int
Fl_get_rgb_color(unsigned char r, unsigned char g, unsigned char b) {
    return fl_rgb_color(r, g, b);
}

void Fl_set_color(
    unsigned int c, unsigned char r, unsigned char g, unsigned char b
) {
    Fl::set_color(c, r, g, b);
}

void Fl_set_color_with_alpha(
    unsigned int c,
    unsigned char r,
    unsigned char g,
    unsigned char b,
    unsigned char a
) {
    Fl::set_color(c, r, g, b, a);
}

const char *Fl_get_font(int idx) {
    return Fl::get_font(idx);
}

const char *Fl_get_font_name(int idx) {
    return Fl::get_font_name(idx);
}

const char *Fl_get_font_name2(int idx, int *attributes) {
    return Fl::get_font_name(idx, attributes);
}

int Fl_get_font_sizes(int font, int **sizep) {
    return Fl::get_font_sizes(font, *sizep);
}

int Fl_set_fonts(const char *c) {
    return Fl::set_fonts(c);
}

void Fl_set_font(int o, int n) {
    Fl::set_font(o, n);
}

void Fl_set_font2(int o, const char *n) {
    Fl::set_font(o, n);
}

void Fl_set_font_size(int sz) {
    LOCK(FL_NORMAL_SIZE = sz)
}

int Fl_font_size(void) {
    LOCK(int ret = FL_NORMAL_SIZE);
    return ret;
}

void Fl_add_handler(int (*ev_handler)(int ev)) {
    LOCK(Fl::add_handler(ev_handler));
}

void Fl_open_display(void) {
    fl_open_display();
}

void Fl_close_display(void) {
    fl_close_display();
}

int Fl_box_dx(int boxtype) {
    return Fl::box_dx((Fl_Boxtype)boxtype);
}

int Fl_box_dy(int boxtype) {
    return Fl::box_dy((Fl_Boxtype)boxtype);
}

int Fl_box_dw(int boxtype) {
    return Fl::box_dw((Fl_Boxtype)boxtype);
}

int Fl_box_dh(int boxtype) {
    return Fl::box_dh((Fl_Boxtype)boxtype);
}

void Fl_awake_msg(void *msg) {
#ifndef __ANDROID__
    LOCK(Fl::awake(msg));
#else
    android_buffer.send(msg);
#endif
}

void *Fl_thread_msg(void) {
#ifndef __ANDROID__
    return Fl::thread_message();
#else
    return android_buffer.recv();
#endif
}

int Fl_wait(void) {
    return Fl::wait();
}

double Fl_wait_for(double dur) {
    return Fl::wait(dur);
}

void Fl_add_timeout(double t, void (*timeout_h)(void *), void *data) {
    LOCK(Fl::add_timeout(t, timeout_h, data));
}

void Fl_repeat_timeout(double t, void (*timeout_h)(void *), void *data) {
    LOCK(Fl::repeat_timeout(t, timeout_h, data));
}

void Fl_remove_timeout(void (*timeout_h)(void *), void *data) {
    LOCK(Fl::remove_timeout(timeout_h, data));
}

int Fl_has_timeout(void (*cb)(void *), void *arg) {
    LOCK(auto ret = Fl::has_timeout(cb, arg));
    return ret;
}

int Fl_dnd(void) {
    return Fl::dnd();
}

void *Fl_first_window(void) {
    return (void *)Fl::first_window();
}

void *Fl_next_window(const void *prev) {
    return (void *)Fl::next_window((Fl_Window *)prev);
}

void *Fl_modal(void) {
    return (void *)Fl::modal();
}

int Fl_should_program_quit(void) {
    return Fl::program_should_quit();
}

void Fl_program_should_quit(int flag) {
    Fl::program_should_quit(flag);
}

int Fl_event_inside(int x, int y, int w, int h) {
    return Fl::event_inside(x, y, w, h);
}

Fl_Widget *Fl_belowmouse(void) {
    return Fl::belowmouse();
}

void Fl_set_belowmouse(Fl_Widget *w) {
    Fl::belowmouse(w);
}

void Fl_delete_widget(Fl_Widget *w) {
    Fl::delete_widget(w);
}

Fl_Widget_Tracker *Fl_Widget_Tracker_new(Fl_Widget *w) {
    return new Fl_Widget_Tracker(w);
}

int Fl_Widget_Tracker_deleted(Fl_Widget_Tracker *self) {
    LOCK(auto ret = self->deleted());
    return ret;
}

void Fl_Widget_Tracker_delete(Fl_Widget_Tracker *self) {
    delete self;
}

void Fl_init_all(void) {
    fl_define_FL_ROUND_UP_BOX();
    fl_define_FL_SHADOW_BOX();
    fl_define_FL_ROUNDED_BOX();
    fl_define_FL_RFLAT_BOX();
    fl_define_FL_RSHADOW_BOX();
    fl_define_FL_DIAMOND_BOX();
    fl_define_FL_OVAL_BOX();
    fl_define_FL_PLASTIC_UP_BOX();
    fl_define_FL_GTK_UP_BOX();
    fl_define_FL_GLEAM_UP_BOX();
    fl_define_FL_SHADOW_LABEL();
    fl_define_FL_ENGRAVED_LABEL();
    fl_define_FL_EMBOSSED_LABEL();
    fl_define_FL_MULTI_LABEL();
    fl_define_FL_ICON_LABEL();
    fl_define_FL_IMAGE_LABEL();
    Fl::use_high_res_GL(1);
}

void Fl_redraw(void) {
    Fl::redraw();
}

int Fl_event_shift(void) {
    return Fl::event_shift();
}

int Fl_event_ctrl(void) {
    return Fl::event_ctrl();
}

int Fl_event_command(void) {
    return Fl::event_command();
}

int Fl_event_alt(void) {
    return Fl::event_alt();
}

void Fl_set_damage(int flag) {
    Fl::damage(flag);
}

int Fl_damage(void) {
    return Fl::damage();
}

int Fl_visual(int mode) {
    return Fl::visual(mode);
}

void Fl_own_colormap(void) {
    Fl::own_colormap();
}

Fl_Widget *Fl_pushed(void) {
    return Fl::pushed();
}

Fl_Widget *Fl_focus(void) {
    return Fl::focus();
}

void Fl_set_focus(void *wid) {
    Fl::focus((Fl_Widget *)wid);
}

double Fl_version(void) {
    return Fl::version();
}

int Fl_api_version(void) {
    return Fl::api_version();
}

int Fl_abi_version(void) {
    return Fl::abi_version();
}

void Fl_foreground(unsigned char r, unsigned char g, unsigned char b) {
    Fl::foreground(r, g, b);
}

void Fl_background(unsigned char r, unsigned char g, unsigned char b) {
    Fl::background(r, g, b);
}

void Fl_background2(unsigned char r, unsigned char g, unsigned char b) {
    Fl::background2(r, g, b);
}

void Fl_selection_color(unsigned char r, unsigned char g, unsigned char b) {
    Fl::set_color(FL_SELECTION_COLOR, r, g, b);
}

void Fl_inactive_color(unsigned char r, unsigned char g, unsigned char b) {
    Fl::set_color(FL_INACTIVE_COLOR, r, g, b);
}

void Fl_get_system_colors(void) {
    Fl::get_system_colors();
}

int Fl_handle(int ev, void *win) {
    LOCK(auto ret = Fl::handle(ev, (Fl_Window *)win));
    return ret;
}

int Fl_handle_(int ev, void *win) {
    LOCK(auto ret = Fl::handle_(ev, (Fl_Window *)win));
    return ret;
}

void Fl_add_idle(void (*cb)(void *), void *arg) {
    LOCK(Fl::add_idle(cb, arg));
}

int Fl_has_idle(void (*cb)(void *), void *arg) {
    LOCK(auto ret = Fl::has_idle(cb, arg));
    return ret;
}

void Fl_remove_idle(void (*cb)(void *), void *arg) {
    LOCK(Fl::remove_idle(cb, arg));
}

void Fl_add_check(void (*cb)(void *), void *arg) {
    LOCK(Fl::add_check(cb, arg));
}

int Fl_has_check(void (*cb)(void *), void *arg) {
    LOCK(auto ret = Fl::has_check(cb, arg));
    return ret;
}

void Fl_remove_check(void (*cb)(void *), void *arg) {
    LOCK(Fl::remove_check(cb, arg));
}

void Fl_flush(void) {
    Fl::flush();
}

void Fl_set_screen_scale(int n, float val) {
    Fl::screen_scale(n, val);
}

float Fl_screen_scale(int n) {
    return Fl::screen_scale(n);
}

int Fl_screen_scaling_supported(void) {
    return Fl::screen_scaling_supported();
}

int Fl_screen_count(void) {
    return Fl::screen_count();
}

int Fl_screen_num(int x, int y) {
    return Fl::screen_num(x, y);
}

int Fl_screen_num_inside(int x, int y, int w, int h) {
    return Fl::screen_num(x, y, w, h);
}

void Fl_screen_xywh(int *X, int *Y, int *W, int *H, int n) {
    Fl::screen_xywh(*X, *Y, *W, *H, n);
}

void Fl_screen_xywh_at(int *X, int *Y, int *W, int *H, int mx, int my) {
    Fl::screen_xywh(*X, *Y, *W, *H, mx, my);
}

void Fl_screen_xywh_inside(
    int *X, int *Y, int *W, int *H, int mx, int my, int mw, int mh
) {
    Fl::screen_xywh(*X, *Y, *W, *H, mx, my, mw, mh);
}

void Fl_screen_xywh_mouse(int *X, int *Y, int *W, int *H) {
    Fl::screen_xywh(*X, *Y, *W, *H);
}

void Fl_screen_dpi(float *h, float *v, int n) {
    Fl::screen_dpi(*h, *v, n);
}

void Fl_screen_work_area(int *X, int *Y, int *W, int *H, int n) {
    Fl::screen_work_area(*X, *Y, *W, *H, n);
}

void Fl_screen_work_area_at(int *X, int *Y, int *W, int *H, int mx, int my) {
    Fl::screen_work_area(*X, *Y, *W, *H, mx, my);
}

void Fl_screen_work_area_mouse(int *X, int *Y, int *W, int *H) {
    Fl::screen_work_area(*X, *Y, *W, *H);
}

void Fl_keyboard_screen_scaling(int value) {
    Fl::keyboard_screen_scaling(value);
}

void *Fl_event_clipboard(void) {
    return Fl::event_clipboard();
}

const char *Fl_event_clipboard_type(void) {
    return Fl::event_clipboard_type();
}

int Fl_clipboard_contains(const char *type) {
    return Fl::clipboard_contains(type);
}

void Fl_event_dispatch(int (*cb)(int event, void *)) {
    Fl::event_dispatch((int (*)(int, Fl_Window *))cb);
}

int Fl_mac_os_version() {
#ifdef __APPLE__
    return fl_mac_os_version;
#endif
    return 0;
}

unsigned int Fl_inactive(unsigned int c) {
    return fl_inactive(c);
}

unsigned int Fl_lighter(unsigned int c) {
    return fl_lighter(c);
}

unsigned int Fl_darker(unsigned int c) {
    return fl_darker(c);
}

void Fl_set_box_type_cb(
    int box,
    void (*cb)(int, int, int, int, unsigned int),
    int x,
    int y,
    int w,
    int h
) {
    Fl::set_boxtype((Fl_Boxtype)box, cb, x, y, w, h);
}

int Fl_draw_box_active(void) {
    return Fl::draw_box_active();
}

unsigned int Fl_gray_ramp(int i) {
    return fl_gray_ramp(i);
}

unsigned int Fl_color_average(unsigned int c1, unsigned int c2, float weight) {
    return fl_color_average(c1, c2, weight);
}

unsigned int Fl_contrast(unsigned int c1, unsigned int c2) {
    return fl_contrast(c1, c2);
}

unsigned int Fl_rgb_color(unsigned char r, unsigned char g, unsigned char b) {
    return fl_rgb_color(r, g, b);
}

unsigned int Fl_rgb_color2(unsigned char g) {
    return fl_rgb_color(g);
}

extern unsigned fl_cmap[256];

unsigned int Fl_cmap(unsigned int c) {
    return fl_cmap[c];
}

unsigned int Fl_box_color(unsigned int c) {
    return (Fl_Color)Fl::box_color((Fl_Color)c);
}

void Fl_set_box_color(unsigned int c) {
    Fl::set_box_color((Fl_Color)c);
}

void Fl_add_system_handler(int (*cb)(void *, void *), void *data) {
    LOCK(Fl::add_system_handler(cb, data));
}

void Fl_remove_system_handler(int (*cb)(void *, void *)) {
    LOCK(Fl::remove_system_handler(cb));
}

void Fl_add_clipboard_notify(void (*cb)(int source, void *data), void *data) {
    LOCK(Fl::add_clipboard_notify(cb, data));
}

void Fl_remove_clipboard_notify(void (*cb)(int source, void *data)) {
    LOCK(Fl::remove_clipboard_notify(cb));
}

#ifdef CFLTK_USE_GL
int Fl_gl_visual(int mode) {
    return Fl::gl_visual(mode);
}
#endif

void Fl_open_callback(void (*cb)(const char *)) {
    fl_open_callback(cb);
}

void Fl_disable_wayland(void) {
    bool fl_disable_wayland = true;
}

Fl_Widget *Fl_Widget_Tracker_widget(Fl_Widget_Tracker *t) {
    return t->widget();
}

int Fl_Widget_Tracker_exists(Fl_Widget_Tracker *t) {
    return t->exists();
}

void Fl_get_color_rgb(
    unsigned int col, unsigned char *r, unsigned char *g, unsigned char *b
) {
    Fl::get_color((Fl_Color)col, *r, *g, *b);
}

int Fl_callback_reason(void) {
    return Fl::callback_reason();
}

void *Fl_get_fl_msg(void) {
#ifdef _WIN32
    return &fl_msg;
#else
    return NULL;
#endif
}

void *Fl_cairo_make_current(Fl_Widget *w) {
#ifdef FLTK_HAVE_CAIRO
    return Fl::cairo_make_current((Fl_Window *)w);
#endif
    return 0;
}

void Fl_set_cairo_autolink_context(int alink) {
#ifdef FLTK_HAVE_CAIRO
    Fl::cairo_autolink_context(alink);
#endif
}

int Fl_cairo_autolink_context() {
#ifdef FLTK_HAVE_CAIRO
    return Fl::cairo_autolink_context();
#endif
    return 0;
}

void *Fl_cairo_cc() {
#ifdef FLTK_HAVE_CAIRO
    return Fl::cairo_cc();
#endif
    return 0;
}

void Fl_set_cairo_cc(void *c, int own) {
#ifdef FLTK_HAVE_CAIRO
    Fl::cairo_cc((cairo_t *)c, own);
#endif
}

void Fl_cairo_flush(void *c) {
#ifdef FLTK_HAVE_CAIRO
    Fl::cairo_flush((cairo_t *)c);
#endif
}

int Fl_option(int opt) {
    return Fl::option((Fl::Fl_Option)opt);
}

void Fl_set_option(int opt, int val) {
    Fl::option((Fl::Fl_Option)opt, val);
}

void Fl_load_system_icons(void) {
    Fl_File_Icon::load_system_icons();
}

void Fl_set_contrast_level(int level) {
    fl_contrast_level(level);
}

int Fl_contrast_level() {
    return fl_contrast_level();
}

void Fl_set_contrast_mode(int mode) {
    fl_contrast_mode(mode);
}

int Fl_contrast_mode() {
    return fl_contrast_mode();
}

void Fl_set_contrast_function(unsigned int (*f)(unsigned int, unsigned int, int, int)) {
    fl_contrast_function(f);
}
