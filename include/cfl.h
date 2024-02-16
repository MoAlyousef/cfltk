#ifndef __CFL_H__
#define __CFL_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Fl_Widget Fl_Widget;

typedef struct Fl_Widget_Tracker Fl_Widget_Tracker;

typedef void (*Fl_Awake_Handler)(void *data);

int Fl_run(void);

int Fl_check(void);

int Fl_ready(void);

void Fl_release(void);

int Fl_reload_scheme(void);

int Fl_menu_linespacing(void);

void Fl_set_menu_linespacing(int H);

int Fl_lock(void);

void Fl_unlock(void);

int Fl_awake_callback(Fl_Awake_Handler handler, void *data);

void Fl_awake(void);

void Fl_set_scrollbar_size(int);

int Fl_scrollbar_size(void);

int Fl_event(void);

int Fl_event_key(void);

int Fl_event_original_key(void);

int Fl_event_key_down(int);

const char *Fl_event_text(void);

int Fl_event_button(void);

int Fl_event_clicks(void);

int Fl_event_x(void);

int Fl_event_y(void);

int Fl_event_x_root(void);

int Fl_event_y_root(void);

int Fl_event_dx(void);

int Fl_event_dy(void);

void Fl_get_mouse(int *, int *);

int Fl_event_is_click(void);

int Fl_event_length(void);

int Fl_event_state(void);

int Fl_w(void);

int Fl_h(void);

int Fl_screen_x(void);

int Fl_screen_y(void);

int Fl_screen_h(void);

int Fl_screen_w(void);

int Fl_compose(int *del);

void Fl_compose_reset(void);

int Fl_compose_state(void);

void Fl_copy(const char *stuff, int len, int destination);

void Fl_paste_text(Fl_Widget *, int src);

void Fl_paste_image(Fl_Widget *widget, int src);

int Fl_set_scheme(const char *scheme);

int Fl_scheme(void);

const char *Fl_scheme_string(void);

int Fl_visible_focus(void);

void Fl_set_visible_focus(int);

void Fl_set_box_type(int, int);

int Fl_box_shadow_width(void);

void Fl_set_box_shadow_width(int W);

int Fl_box_border_radius_max(void);

void Fl_set_box_border_radius_max(int R);

unsigned int
Fl_get_rgb_color(unsigned char r, unsigned char g, unsigned char b);

void Fl_set_color(
    unsigned int c, unsigned char r, unsigned char g, unsigned char b
);

void Fl_set_color_with_alpha(
    unsigned int c,
    unsigned char r,
    unsigned char g,
    unsigned char b,
    unsigned char a
);

const char *Fl_get_font(int idx);

const char *Fl_get_font_name(int idx);

const char *Fl_get_font_name2(int idx, int *attributes);

int Fl_get_font_sizes(int font, int **sizep);

int Fl_set_fonts(const char *c);

void Fl_set_font(int, int);

void Fl_set_font2(int, const char *);

void Fl_set_font_size(int);

int Fl_font_size(void);

void Fl_add_handler(int (*ev_handler)(int ev));

void Fl_awake_msg(void *msg);

void *Fl_thread_msg(void);

int Fl_wait(void);

double Fl_wait_for(double);

void Fl_add_timeout(double t, void (*)(void *), void *);

void Fl_repeat_timeout(double t, void (*)(void *), void *);

void Fl_remove_timeout(void (*)(void *), void *);

int Fl_has_timeout(void (*)(void *), void *);

int Fl_dnd(void);

void *Fl_grab(void);

void Fl_set_grab(void *);

void *Fl_first_window(void);

void *Fl_next_window(const void *);

void *Fl_modal(void);

int Fl_should_program_quit(void);

void Fl_program_should_quit(int flag);

int Fl_event_inside(int, int, int, int);

Fl_Widget *Fl_belowmouse(void);

void Fl_set_belowmouse(Fl_Widget *w);

void Fl_delete_widget(Fl_Widget *w);

Fl_Widget_Tracker *Fl_Widget_Tracker_new(Fl_Widget *w);

int Fl_Widget_Tracker_deleted(Fl_Widget_Tracker *self);

void Fl_Widget_Tracker_delete(Fl_Widget_Tracker *self);

void Fl_init_all(void);

void Fl_redraw(void);

int Fl_event_shift(void);

int Fl_event_ctrl(void);

int Fl_event_command(void);

int Fl_event_alt(void);

void Fl_set_damage(int flag);

int Fl_damage(void);

int Fl_visual(int);

void Fl_own_colormap(void);

Fl_Widget *Fl_pushed(void);

Fl_Widget *Fl_focus(void);

void Fl_set_focus(void *);

double Fl_version(void);

int Fl_api_version(void);

int Fl_abi_version(void);

int Fl_load_font(const char *path);

void Fl_unload_font(const char *path);

void Fl_foreground(unsigned char r, unsigned char g, unsigned char b);

void Fl_background(unsigned char r, unsigned char g, unsigned char b);

void Fl_background2(unsigned char r, unsigned char g, unsigned char b);

void Fl_selection_color(unsigned char r, unsigned char g, unsigned char b);

void Fl_inactive_color(unsigned char r, unsigned char g, unsigned char b);

void Fl_get_system_colors(void);

int Fl_handle(int, void *);

int Fl_handle_(int, void *);

void Fl_add_idle(void (*)(void *), void *);

int Fl_has_idle(void (*)(void *), void *);

void Fl_remove_idle(void (*)(void *), void *);

void Fl_add_check(void (*)(void *), void *);

int Fl_has_check(void (*)(void *), void *);

void Fl_remove_check(void (*)(void *), void *);

void Fl_flush(void);

void Fl_set_screen_scale(int n, float val);

float Fl_screen_scale(int n);

int Fl_screen_scaling_supported(void);

int Fl_screen_count(void);

int Fl_screen_num(int x, int y);

int Fl_screen_num_inside(int x, int y, int w, int h);

void Fl_screen_xywh(int *X, int *Y, int *W, int *H, int n);

void Fl_screen_xywh_at(int *X, int *Y, int *W, int *H, int mx, int my);

void Fl_screen_xywh_inside(
    int *X, int *Y, int *W, int *H, int mx, int my, int mw, int mh
);

void Fl_screen_xywh_mouse(int *X, int *Y, int *W, int *H);

void Fl_screen_dpi(float *h, float *v, int n);

void Fl_screen_work_area(int *X, int *Y, int *W, int *H, int n);

void Fl_screen_work_area_at(int *X, int *Y, int *W, int *H, int mx, int my);

void Fl_screen_work_area_mouse(int *X, int *Y, int *W, int *H);

void Fl_keyboard_screen_scaling(int value);

void Fl_open_display(void);

void Fl_close_display(void);

int Fl_box_dx(int boxtype);

int Fl_box_dy(int boxtype);

int Fl_box_dw(int boxtype);

int Fl_box_dh(int boxtype);

int Fl_mac_os_version(void);

void *Fl_event_clipboard(void);

const char *Fl_event_clipboard_type(void);

int Fl_clipboard_contains(const char *type);

void Fl_event_dispatch(int (*cb)(int event, void *));

unsigned int Fl_inactive(unsigned int c);

unsigned int Fl_lighter(unsigned int c);

unsigned int Fl_darker(unsigned int c);

void Fl_set_box_type_cb(
    int, void (*cb)(int, int, int, int, unsigned int), int, int, int, int
);

int Fl_draw_box_active(void);

unsigned int Fl_gray_ramp(int i);

unsigned int Fl_color_average(unsigned int, unsigned int, float f);

unsigned int Fl_contrast(unsigned int c1, unsigned int c2);

unsigned int Fl_rgb_color(unsigned char r, unsigned char g, unsigned char b);

unsigned int Fl_rgb_color2(unsigned char g);

unsigned int Fl_cmap(unsigned int c);

unsigned int Fl_box_color(unsigned int c);

void Fl_set_box_color(unsigned int c);

void Fl_add_system_handler(int (*)(void *, void *), void *);

void Fl_remove_system_handler(int (*)(void *, void *));

int Fl_gl_visual(int mode);

void Fl_add_clipboard_notify(void (*cb)(int source, void *data), void *data);

void Fl_remove_clipboard_notify(void (*cb)(int source, void *data));

void Fl_open_callback(void (*cb)(const char *));

void Fl_disable_wayland(void);

Fl_Widget *Fl_Widget_Tracker_widget(Fl_Widget_Tracker *t);

int Fl_Widget_Tracker_exists(Fl_Widget_Tracker *t);

void Fl_get_color_rgb(
    unsigned int col, unsigned char *r, unsigned char *g, unsigned char *b
);

int Fl_callback_reason(void);

void *Fl_get_fl_msg(void);

void *Fl_cairo_make_current(Fl_Widget *w);

void Fl_set_cairo_autolink_context(int alink);

int Fl_cairo_autolink_context(void);

void *Fl_cairo_cc(void);

void Fl_set_cairo_cc(void *c, int own);

void Fl_cairo_flush(void *c);

int Fl_option(int opt);

void Fl_set_option(int opt, int val);

void Fl_load_system_icons(void);

void Fl_set_contrast_level(int level);

int Fl_contrast_level();

void Fl_set_contrast_mode(int mode);

int Fl_contrast_mode();

void Fl_set_contrast_function(unsigned int (*f)(unsigned int, unsigned int, int, int));

#ifdef __cplusplus
}
#endif
#endif
