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

int Fl_screen_x(void);

int Fl_screen_y(void);

int Fl_screen_h(void);

int Fl_screen_w(void);

void Fl_paste_text(Fl_Widget *, int src);

void Fl_paste_image(Fl_Widget *widget, int src);

void Fl_set_scheme(const char *scheme);

int Fl_scheme(void);

const char *Fl_scheme_string(void);

int Fl_visible_focus(void);

void Fl_set_visible_focus(int);

void Fl_set_box_type(int, int);

unsigned int Fl_get_rgb_color(unsigned char r, unsigned char g, unsigned char b);

void Fl_set_color(unsigned int c, unsigned char r, unsigned char g, unsigned char b);

const char *Fl_get_font(int idx);

unsigned char Fl_set_fonts(const char *c);

void Fl_set_font(int, int);

void Fl_set_font2(int, const char *);

void Fl_set_font_size(int);

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

int Fl_should_program_quit(void);

void Fl_program_should_quit(int flag);

int Fl_event_inside(int, int, int, int);

Fl_Widget *Fl_belowmouse(void);

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

const char *Fl_load_font(const char *path);

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

void Fl_flush(void);

void Fl_set_screen_scale(int n, float val);

float Fl_screen_scale(int n);

int Fl_screen_scaling_supported(void);

int Fl_screen_count(void);

int Fl_screen_num(int x, int y);

void Fl_screen_xywh(int *X, int *Y, int *W, int *H, int n);

void Fl_screen_dpi(float *h, float *v, int n);

void Fl_screen_work_area(int *X, int *Y, int *W, int *H, int n);

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

#ifdef __cplusplus
}
#endif
#endif
