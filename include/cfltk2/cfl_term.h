#ifndef __CFL_TERM_H__
#define __CFL_TERM_H__

#include "cfl_macros.h"

#ifdef __cplusplus
extern "C" {
#endif

WIDGET_DECLARE(Fl_Terminal)

int Fl_Terminal_ansi(Fl_Terminal const *self);

void Fl_Terminal_set_ansi(Fl_Terminal *self, int boolean);

void Fl_Terminal_append(Fl_Terminal *self, const char *txt);

void Fl_Terminal_append_u8(Fl_Terminal *self, const char *txt, int len);

void Fl_Terminal_append_ascii(Fl_Terminal *self, const char *txt);

void Fl_Terminal_append_utf8(Fl_Terminal *self, const char *txt);

void Fl_Terminal_append_utf8_u8(Fl_Terminal *self, const char *txt, int len);

void Fl_Terminal_clear_mouse_selection(Fl_Terminal *self);

void Fl_Terminal_clear_to_color(Fl_Terminal *self, unsigned set);

void Fl_Terminal_clear_history(Fl_Terminal *self);

void Fl_Terminal_clear_screen(Fl_Terminal *self, int boolean);

void Fl_Terminal_clear_screen_home(Fl_Terminal *self, int boolean);

int Fl_Terminal_cursor_col(Fl_Terminal const *self);

void Fl_Terminal_set_cursor_col(Fl_Terminal *self, int val);

void Fl_Terminal_cursor_home(Fl_Terminal *self);

int Fl_Terminal_cursor_row(Fl_Terminal const *self);

void Fl_Terminal_set_cursor_row(Fl_Terminal *self, int val);

void Fl_Terminal_cursor_up(Fl_Terminal *self, int count, int do_scroll);

void Fl_Terminal_cursor_down(Fl_Terminal *self, int count, int do_scroll);

void Fl_Terminal_cursor_left(Fl_Terminal *self, int count);

void Fl_Terminal_cursor_right(Fl_Terminal *self, int count, int do_scroll);

void Fl_Terminal_scroll(Fl_Terminal *self, int count);

void Fl_Terminal_clear_eod(Fl_Terminal *self);

void Fl_Terminal_clear_eol(Fl_Terminal *self);

void Fl_Terminal_clear_cur_line(Fl_Terminal *self);

void Fl_Terminal_clear_line(Fl_Terminal *self, int drow);

void Fl_Terminal_clear_sod(Fl_Terminal *self);

void Fl_Terminal_clear_sol(Fl_Terminal *self);

void Fl_Terminal_insert_char(Fl_Terminal *self, char c, int rep);

void Fl_Terminal_insert_char_eol(Fl_Terminal *self, char c, int drow, int dcol, int rep);

void Fl_Terminal_insert_rows(Fl_Terminal *self, int count);

void Fl_Terminal_delete_chars(Fl_Terminal *self, int drow, int dcol, int count);

void Fl_Terminal_delete_cur_chars(Fl_Terminal *self, int count);

void Fl_Terminal_delete_rows(Fl_Terminal *self, int count);


unsigned Fl_Terminal_cursor_bg_color(Fl_Terminal const *self
); // Actually Fl_Color

void Fl_Terminal_set_cursor_bg_color(Fl_Terminal *self, unsigned set);

unsigned Fl_Terminal_cursor_fg_color(Fl_Terminal const *self
); // Actually Fl_Color

void Fl_Terminal_set_cursor_fg_color(Fl_Terminal *self, unsigned set);

int Fl_Terminal_display_columns(Fl_Terminal const *self);

void Fl_Terminal_set_display_columns(Fl_Terminal *self, int set);

int Fl_Terminal_display_rows(Fl_Terminal const *self);

int Fl_Terminal_history_rows(Fl_Terminal const *self);

void Fl_Terminal_set_history_rows(Fl_Terminal *self, int set);

int Fl_Terminal_get_selection(Fl_Terminal const *self, int *retval);

int Fl_Terminal_history_use(Fl_Terminal const *self);

int Fl_Terminal_margin_bottom(Fl_Terminal const *self);

void Fl_Terminal_set_margin_bottom(Fl_Terminal *self, int set);

int Fl_Terminal_margin_left(Fl_Terminal const *self);

void Fl_Terminal_set_margin_left(Fl_Terminal *self, int set);

int Fl_Terminal_margin_right(Fl_Terminal const *self);

void Fl_Terminal_set_margin_right(Fl_Terminal *self, int set);

int Fl_Terminal_margin_top(Fl_Terminal const *self);

void Fl_Terminal_set_margin_top(Fl_Terminal *self, int set);

unsigned Fl_Terminal_output_translate(Fl_Terminal const *self
); // Returns OutFlags

void Fl_Terminal_set_output_translate(Fl_Terminal *self, unsigned set);

void Fl_Terminal_print_char(Fl_Terminal *self, char c);

void Fl_Terminal_print_char_utf8(Fl_Terminal *self, const char *txt, int len);

// Note: Fl_Terminal_printf not supported for Rust
void Fl_Terminal_printf(Fl_Terminal *self, const char *fmt, ...);

void Fl_Terminal_plot_char(Fl_Terminal *self, char c, int row, int col);

void Fl_Terminal_plot_char_utf8(
    Fl_Terminal *self, const char *txt, int len, int row, int col
);

float Fl_Terminal_redraw_rate(Fl_Terminal const *self);

void Fl_Terminal_set_redraw_rate(Fl_Terminal *self, float set);

int Fl_Terminal_redraw_style(Fl_Terminal const *self
); // Actually enum RedrawStyle

void Fl_Terminal_set_redraw_style(Fl_Terminal *self, int set);

void Fl_Terminal_reset_terminal(Fl_Terminal *self);

int Fl_Terminal_scrollbar_actual_size(Fl_Terminal const *self);

int Fl_Terminal_scrollbar_size(Fl_Terminal const *self);

void Fl_Terminal_set_scrollbar_size(Fl_Terminal *self, int set);

// int Fl_Terminal_hscrollbar_actual_size(Fl_Terminal const *self);

// int Fl_Terminal_hscrollbar_size(Fl_Terminal const *self);

// void Fl_Terminal_set_hscrollbar_size(Fl_Terminal *self, int set);

// int Fl_Terminal_hscroll_col(Fl_Terminal const *self);

// void Fl_Terminal_set_hscroll_col(Fl_Terminal *self, int set);

int Fl_Terminal_hscrollbar_style(Fl_Terminal const *self);   // Actually returns enum HScrollbarStyle

void Fl_Terminal_set_hscrollbar_style(Fl_Terminal *self, int set);

unsigned Fl_Terminal_selection_bg_color(Fl_Terminal const *self
); // Actually Fl_Color

void Fl_Terminal_set_selection_bg_color(Fl_Terminal *self, unsigned set);

unsigned Fl_Terminal_selection_fg_color(Fl_Terminal const *self
); // Actually Fl_Color

void Fl_Terminal_set_selection_fg_color(Fl_Terminal *self, unsigned set);

int Fl_Terminal_show_unknown(Fl_Terminal const *self);

void Fl_Terminal_set_show_unknown(Fl_Terminal *self, int boolean);

unsigned char Fl_Terminal_text_attrib(Fl_Terminal const *self); // Actually returns Attrib

void Fl_Terminal_set_text_attrib(
    Fl_Terminal *self,
    unsigned char set
); // Actually Attrib

unsigned Fl_Terminal_text_bg_color(Fl_Terminal const *self
); // Actually Fl_Color

void Fl_Terminal_set_text_bg_color(Fl_Terminal *self, unsigned set);

unsigned Fl_Terminal_text_bg_color_default(Fl_Terminal const *self
); // Actually Fl_Color

void Fl_Terminal_set_text_bg_color_default(Fl_Terminal *self, unsigned set);

void Fl_Terminal_set_text_bg_color_xterm(Fl_Terminal *self, unsigned char set);

void Fl_Terminal_set_text_color(Fl_Terminal *self, unsigned set);

unsigned Fl_Terminal_text_fg_color(Fl_Terminal const *self
); // Actually Fl_Color

void Fl_Terminal_set_text_fg_color(Fl_Terminal *self, unsigned set);

unsigned Fl_Terminal_text_fg_color_default(Fl_Terminal const *self
); // Actually Fl_Color

void Fl_Terminal_set_text_fg_color_default(Fl_Terminal *self, unsigned set);

void Fl_Terminal_set_text_fg_color_xterm(Fl_Terminal *self, unsigned char set);

int Fl_Terminal_text_font(Fl_Terminal const *self); // Actually Fl_Font

void Fl_Terminal_set_text_font(Fl_Terminal *self, int set);

int Fl_Terminal_text_size(Fl_Terminal const *self);

void Fl_Terminal_set_text_size(Fl_Terminal *self, int set);

const char* Fl_Terminal_text(Fl_Terminal const *self, int lines_below_cursor);       // Argument is bool

const char *Fl_Terminal_selection_text(Fl_Terminal const *self);
int Fl_Terminal_selection_text_len(Fl_Terminal const *self);

//----------------------------------------------------------------------
/// Access to terminal widget's vertical and horizontal scrollbar
typedef void Fl_Terminal_Scrollbar;
Fl_Terminal_Scrollbar * Fl_Terminal_scrollbar(Fl_Terminal *self);
Fl_Terminal_Scrollbar * Fl_Terminal_hscrollbar(Fl_Terminal *self);

//----------------------------------------------------------------------
/// Utf8Char class, used to describe characters in the terminal ring buffer
typedef void Fl_Terminal_Utf8Char;

unsigned Fl_Terminal_Utf8Char_attr_bgcolor(
    Fl_Terminal_Utf8Char const *self, const Fl_Terminal *grp); // Actually returns Fl_Color

unsigned Fl_Terminal_Utf8Char_attr_fgcolor(
    Fl_Terminal_Utf8Char const *self, const Fl_Terminal *grp); // Actually returns Fl_Color

unsigned char Fl_Terminal_Utf8Char_attrib(Fl_Terminal_Utf8Char const *self);

unsigned Fl_Terminal_Utf8Char_bgcolor(Fl_Terminal_Utf8Char const *self
); // Actually returns Fl_Color

unsigned Fl_Terminal_Utf8Char_fgcolor(Fl_Terminal_Utf8Char const *self
); // Actually returns Fl_Color

int Fl_Terminal_Utf8Char_is_char(Fl_Terminal_Utf8Char const *self,
                                 char c); // boolean

int Fl_Terminal_Utf8Char_length(Fl_Terminal_Utf8Char const *self);

int Fl_Terminal_Utf8Char_max_utf8(Fl_Terminal_Utf8Char const *self);

double Fl_Terminal_Utf8Char_pwidth(Fl_Terminal_Utf8Char const *self);

int Fl_Terminal_Utf8Char_pwidth_int(Fl_Terminal_Utf8Char const *self);

const unsigned char *
Fl_Terminal_Utf8Char_text_utf8(Fl_Terminal_Utf8Char const *self);

unsigned char Fl_Terminal_Utf8Char_charflags(Fl_Terminal_Utf8Char const *self);

int Fl_Terminal_Utf8Char_length(Fl_Terminal_Utf8Char const *self);

// Construct a new Utf8Char, useful for testing
Fl_Terminal_Utf8Char *Fl_Terminal_Utf8Char_new_obj(unsigned char c);

//----------------------------------------------------------------------
// The following are protected functions used to access ring buffer text:

int Fl_Terminal_disp_erow(Fl_Terminal const *self);

int Fl_Terminal_disp_srow(Fl_Terminal const *self);

int Fl_Terminal_hist_erow(Fl_Terminal const *self);

int Fl_Terminal_hist_srow(Fl_Terminal const *self);

int Fl_Terminal_hist_use(Fl_Terminal const *self);

int Fl_Terminal_hist_use_srow(Fl_Terminal const *self);

int Fl_Terminal_h_to_row(Fl_Terminal const *self, int H);

int Fl_Terminal_w_to_col(Fl_Terminal const *self, int W);

int Fl_Terminal_is_inside_selection(
    Fl_Terminal const *self, int row, int col
); // Actual return type is bool

int Fl_Terminal_is_selection(Fl_Terminal const *self
); // Actual return type is bool

int Fl_Terminal_offset(Fl_Terminal const *self);

int Fl_Terminal_ring_erow(Fl_Terminal const *self);

int Fl_Terminal_ring_srow(Fl_Terminal const *self);

int Fl_Terminal_ring_rows(Fl_Terminal const *self);

const Fl_Terminal_Utf8Char *
Fl_Terminal_u8c_cursor(Fl_Terminal const *self);

const Fl_Terminal_Utf8Char *
Fl_Terminal_u8c_disp_row(Fl_Terminal const *self, int drow);

const Fl_Terminal_Utf8Char *
Fl_Terminal_u8c_hist_row(Fl_Terminal const *self, int hrow);

const Fl_Terminal_Utf8Char *
Fl_Terminal_u8c_hist_use_row(Fl_Terminal const *self, int hurow);

const Fl_Terminal_Utf8Char *
Fl_Terminal_u8c_ring_row(Fl_Terminal const *self, int grow);

const unsigned Fl_Terminal_Utf8Char_size(void);

void Fl_free_str(const char *str);

// todo: Protected methods still unimplemented here:
//   current_style, h_to_row, selection_extend, w_to_col, walk_selection, vscroll_width

GROUP_DECLARE(Fl_Terminal)


#ifdef __cplusplus
}
#endif
#endif
