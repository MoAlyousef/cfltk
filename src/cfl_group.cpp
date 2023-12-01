#include "cfl_group.h"
#include "cfl_lock.h"
#include "cfl_widget.hpp"

#include <FL/Fl.H>
#include <FL/Fl_Color_Chooser.H>
#include <FL/Fl_Flex.H>
#include <FL/Fl_Grid.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Image.H>
#include <FL/Fl_Pack.H>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Terminal.H>
#include <FL/Fl_Tile.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Wizard.H>
#include <FL/fl_draw.H>

WIDGET_CLASS(Fl_Group)

WIDGET_DEFINE(Fl_Group)

Fl_Group *Fl_Group_current(void) {
    LOCK(auto ret = Fl_Group::current());
    return ret;
}

void Fl_Group_set_current(Fl_Group *grp) {
    LOCK(Fl_Group::current(grp));
}

GROUP_DEFINE(Fl_Group)

WIDGET_CLASS(Fl_Pack)

WIDGET_DEFINE(Fl_Pack)

int Fl_Pack_spacing(Fl_Pack *self) {
    LOCK(auto ret = self->spacing());
    return ret;
}
void Fl_Pack_set_spacing(Fl_Pack *self, int spacing) {
    LOCK(self->spacing(spacing));
}

GROUP_DEFINE(Fl_Pack)

WIDGET_CLASS(Fl_Scroll)

WIDGET_DEFINE(Fl_Scroll)

void *Fl_Scroll_scrollbar(Fl_Scroll *self) {
    LOCK(auto ret = &self->scrollbar);
    return ret;
}

void *Fl_Scroll_hscrollbar(Fl_Scroll *self) {
    LOCK(auto ret = &self->hscrollbar);
    return ret;
}

void *Fl_Scroll_hscrollbar(const Fl_Scroll *self);

int Fl_Scroll_xposition(const Fl_Scroll *self) {
    LOCK(auto ret = self->xposition());
    return ret;
}

int Fl_Scroll_yposition(const Fl_Scroll *self) {
    LOCK(auto ret = self->yposition());
    return ret;
}

void Fl_Scroll_scroll_to(Fl_Scroll *self, int x, int y) {
    LOCK(self->scroll_to(x, y));
}

int Fl_Scroll_scrollbar_size(const Fl_Scroll *self) {
    LOCK(auto ret = self->scrollbar_size());
    return ret;
}

void Fl_Scroll_set_scrollbar_size(Fl_Scroll *self, int newSize) {
    LOCK(self->scrollbar_size(newSize));
}

GROUP_DEFINE(Fl_Scroll)

WIDGET_CLASS(Fl_Tabs)

WIDGET_DEFINE(Fl_Tabs)

Fl_Widget *Fl_Tabs_value(Fl_Tabs *self) {
    LOCK(auto ret = self->value());
    return ret;
}

int Fl_Tabs_set_value(Fl_Tabs *self, Fl_Widget *w) {
    LOCK(auto ret = self->value(w));
    return ret;
}

Fl_Widget *Fl_Tabs_push(const Fl_Tabs *self) {
    LOCK(auto ret = self->push());
    return ret;
}

int Fl_Tabs_set_push(Fl_Tabs *self, Fl_Widget *w) {
    LOCK(auto ret = self->push(w));
    return ret;
}

void Fl_Tabs_client_area(Fl_Tabs *self, int *rx, int *ry, int *rw, int *rh) {
    LOCK(self->client_area(*rx, *ry, *rw, *rh));
}

void Fl_Tabs_set_tab_align(Fl_Tabs *self, int a) {
    LOCK(self->tab_align(a));
}

int Fl_Tabs_tab_align(const Fl_Tabs *self) {
    LOCK(auto ret = self->tab_align());
    return ret;
}

void Fl_Tabs_handle_overflow(Fl_Tabs *self, int ov) {
    LOCK(self->handle_overflow(ov));
}

GROUP_DEFINE(Fl_Tabs)

WIDGET_CLASS(Fl_Tile)

WIDGET_DEFINE(Fl_Tile)

GROUP_DEFINE(Fl_Tile)

WIDGET_CLASS(Fl_Wizard)

WIDGET_DEFINE(Fl_Wizard)

void Fl_Wizard_next(Fl_Wizard *self) {
    LOCK(self->next());
}

void Fl_Wizard_prev(Fl_Wizard *self) {
    LOCK(self->prev());
}

Fl_Widget *Fl_Wizard_value(Fl_Wizard *self) {
    LOCK(auto ret = (Fl_Widget *)self->value());
    return ret;
}

void Fl_Wizard_set_value(Fl_Wizard *self, Fl_Widget *wid) {
    LOCK(self->value(wid));
}

GROUP_DEFINE(Fl_Wizard)

WIDGET_CLASS(Fl_Color_Chooser)

WIDGET_DEFINE(Fl_Color_Chooser)

double Fl_Color_Chooser_r(Fl_Color_Chooser *self) {
    LOCK(auto ret = self->r());
    return ret;
}
double Fl_Color_Chooser_g(Fl_Color_Chooser *self) {
    LOCK(auto ret = self->g());
    return ret;
}
double Fl_Color_Chooser_b(Fl_Color_Chooser *self) {
    LOCK(auto ret = self->b());
    return ret;
}

int Fl_Color_Chooser_set_rgb(Fl_Color_Chooser *self, double r, double g,
                             double b) {
    LOCK(auto ret = self->rgb(r, g, b));
    return ret;
}

GROUP_DEFINE(Fl_Color_Chooser)

WIDGET_CLASS(Fl_Flex)

WIDGET_DEFINE(Fl_Flex)

void Fl_Flex_set_size(Fl_Flex *self, Fl_Widget *w, int size) {
    LOCK(self->fixed(w, size));
}

void Fl_Flex_set_margin(Fl_Flex *self, int m) {
    LOCK(self->margin(m));
}

int Fl_Flex_margin(const Fl_Flex *self) {
    LOCK(auto ret = self->margin());
    return ret;
}

void Fl_Flex_set_pad(Fl_Flex *self, int p) {
    LOCK(self->gap(p));
}

int Fl_Flex_pad(const Fl_Flex *self) {
    LOCK(auto ret = self->gap());
    return ret;
}

void Fl_Flex_set_margins(Fl_Flex *self, int x1, int y1, int x2, int y2) {
    LOCK(self->margin(x1, y1, x2, y2));
}

int Fl_Flex_margins(const Fl_Flex *self, int *x1, int *y1, int *x2, int *y2) {
    LOCK(auto ret = self->margin(x1, y1, x2, y2));
    return ret;
}

GROUP_DEFINE(Fl_Flex)

WIDGET_CLASS(Fl_Grid)

WIDGET_DEFINE(Fl_Grid)

void Fl_Grid_set_layout(Fl_Grid *self, int rows, int cols, int margin,
                        int gap) {
    LOCK(self->layout(rows, cols, margin, gap));
}

void Fl_Grid_layout(Fl_Grid *self) {
    LOCK(self->layout());
}

void Fl_Grid_clear_layout(Fl_Grid *self) {
    LOCK(self->clear_layout());
}

void Fl_Grid_set_need_layout(Fl_Grid *self, int set) {
    LOCK(self->need_layout(set));
}

int Fl_Grid_need_layout(const Fl_Grid *self) {
    LOCK(auto ret = self->need_layout());
    return ret;
}

void Fl_Grid_set_margin(Fl_Grid *self, int left, int top, int right,
                        int bottom) {
    LOCK(self->margin(left, top, right, bottom));
}

void Fl_Grid_set_gap(Fl_Grid *self, int row_gap, int col_gap) {
    LOCK(self->gap(row_gap, col_gap));
}

void *Fl_Grid_set_widget(Fl_Grid *self, Fl_Widget *wi, int row, int col,
                         unsigned short align) {
    LOCK(auto ret = self->widget(wi, row, col, align));
    return ret;
}

void *Fl_Grid_set_widget_ext(Fl_Grid *self, Fl_Widget *wi, int row, int col,
                             int rowspan, int colspan, unsigned short align) {
    LOCK(auto ret = self->widget(wi, row, col, rowspan, colspan, align));
    return ret;
}

void Fl_Grid_set_col_width(Fl_Grid *self, int col, int value) {
    LOCK(self->col_width(col, value));
}

void Fl_Grid_set_col_weight(Fl_Grid *self, int col, int value) {
    LOCK(self->col_weight(col, value));
}

void Fl_Grid_set_col_gap(Fl_Grid *self, int col, int value) {
    LOCK(self->col_gap(col, value));
}

void Fl_Grid_set_row_height(Fl_Grid *self, int row, int value) {
    LOCK(self->row_height(row, value));
}

void Fl_Grid_set_row_weight(Fl_Grid *self, int row, int value) {
    LOCK(self->row_weight(row, value));
}

void Fl_Grid_set_row_gap(Fl_Grid *self, int row, int value) {
    LOCK(self->row_gap(row, value));
}

void Fl_Grid_show_grid(Fl_Grid *self, int set) {
    LOCK(self->show_grid(set));
}

void Fl_Grid_show_grid_with_color(Fl_Grid *self, int set, unsigned int col) {
    LOCK(self->show_grid(set, (Fl_Color)col));
}

void Fl_Grid_debug(Fl_Grid *self, int level) {
    LOCK(self->debug(level));
}

GROUP_DEFINE(Fl_Grid)

WIDGET_CLASS(Fl_Terminal)

WIDGET_DEFINE(Fl_Terminal)

void Fl_Terminal_set_ansi(Fl_Terminal *self, int boolean) {
    LOCK(self->ansi(boolean));
}

int Fl_Terminal_ansi(Fl_Terminal *self) {
    LOCK(auto ret = self->ansi());
    return ret;
}

void Fl_Terminal_append(Fl_Terminal *self, const char *txt) {
    LOCK(self->append(txt));
}

void Fl_Terminal_append_u8(Fl_Terminal *self, const char *txt, int len) {
    LOCK(self->append(txt, len));
}

void Fl_Terminal_append_ascii(Fl_Terminal *self, const char *txt) {
    LOCK(self->append_ascii(txt));
}

void Fl_Terminal_append_utf8(Fl_Terminal *self, const char *txt) {
    LOCK(self->append_utf8(txt));
}

void Fl_Terminal_append_utf8_u8(Fl_Terminal *self, const char *txt, int len) {
    LOCK(self->append_utf8(txt, len));
}

void Fl_Terminal_clear_history(Fl_Terminal *self) {
    LOCK(self->clear_history());
}

int Fl_Terminal_cursor_col(Fl_Terminal *self) {
    LOCK(auto ret = self->cursor_col());
    return ret;
}

int Fl_Terminal_cursor_row(Fl_Terminal *self) {
    LOCK(auto ret = self->cursor_row());
    return ret;
}

unsigned Fl_Terminal_cursor_bg_color(Fl_Terminal *self) {
    LOCK(auto ret = self->cursorbgcolor());
    return ret;
}

void Fl_Terminal_set_cursor_bg_color(Fl_Terminal *self, unsigned set) {
    LOCK(self->cursorbgcolor((Fl_Color)set));
}

unsigned Fl_Terminal_cursor_fg_color(Fl_Terminal *self) {
    LOCK(auto ret = self->cursorfgcolor());
    return ret;
}

void Fl_Terminal_set_cursor_fg_color(Fl_Terminal *self, unsigned set) {
    LOCK(self->cursorfgcolor((Fl_Color)set));
}

int Fl_Terminal_display_columns(Fl_Terminal *self) {
    LOCK(auto ret = self->display_columns());
    return ret;
}

void Fl_Terminal_set_display_columns(Fl_Terminal *self, int set) {
    LOCK(self->display_columns(set));
}

int Fl_Terminal_display_rows(Fl_Terminal *self) {
    LOCK(auto ret = self->display_rows());
    return ret;
}

void Fl_Terminal_set_display_rows(Fl_Terminal *self, int set) {
    LOCK(self->display_rows(set));
}

int Fl_Terminal_history_lines(Fl_Terminal *self) {
    LOCK(auto ret = self->history_lines());
    return ret;
}

void Fl_Terminal_set_history_lines(Fl_Terminal *self, int set) {
    LOCK(self->history_lines(set));
}

int Fl_Terminal_history_rows(Fl_Terminal *self) {
    LOCK(auto ret = self->history_rows());
    return ret;
}

void Fl_Terminal_set_history_rows(Fl_Terminal *self, int set) {
    LOCK(self->history_rows(set));
}

int Fl_Terminal_history_use(Fl_Terminal *self) {
    LOCK(auto ret = self->history_use());
    return ret;
}

int Fl_Terminal_margin_bottom(Fl_Terminal *self) {
    LOCK(auto ret = self->margin_bottom());
    return ret;
}

void Fl_Terminal_set_margin_bottom(Fl_Terminal *self, int set) {
    LOCK(self->margin_bottom(set));
}

int Fl_Terminal_margin_left(Fl_Terminal *self) {
    LOCK(auto ret = self->margin_left());
    return ret;
}

void Fl_Terminal_set_margin_left(Fl_Terminal *self, int set) {
    LOCK(self->margin_left(set));
}

int Fl_Terminal_margin_right(Fl_Terminal *self) {
    LOCK(auto ret = self->margin_right());
    return ret;
}

void Fl_Terminal_set_margin_right(Fl_Terminal *self, int set) {
    LOCK(self->margin_right(set));
}

int Fl_Terminal_margin_top(Fl_Terminal *self) {
    LOCK(auto ret = self->margin_top());
    return ret;
}

void Fl_Terminal_set_margin_top(Fl_Terminal *self, int set) {
    LOCK(self->margin_top(set));
}

void Fl_Terminal_print_char(Fl_Terminal *self, char c) {
    LOCK(self->print_char(c));
}

void Fl_Terminal_print_char_utf8(Fl_Terminal *self, const char *txt, int len) {
    LOCK(self->print_char(txt, len));
}

void Fl_Terminal_put_char(Fl_Terminal *self, char c, int row, int col) {
    LOCK(self->putchar(c, row, col));
}

void Fl_Terminal_put_char_utf8(Fl_Terminal *self, const char *txt, int len, int drow,
                           int dcol) {
    LOCK(self->putchar(txt, len, drow, dcol));
}

float Fl_Terminal_redraw_rate(Fl_Terminal *self) {
    LOCK(auto ret = self->redraw_rate());
    return ret;
}

void Fl_Terminal_set_redraw_rate(Fl_Terminal *self, float set) {
    LOCK(self->redraw_rate(set));
}

int Fl_Terminal_redraw_style(
    Fl_Terminal *self) { // Actually returns enum RedrawStyle
    LOCK(auto ret = self->redraw_style());
    return ret;
}

void Fl_Terminal_set_redraw_style(Fl_Terminal *self, int set) {
    LOCK(self->redraw_style((Fl_Terminal::RedrawStyle)set));
}

void Fl_Terminal_reset_terminal(Fl_Terminal *self) {
    LOCK(self->reset_terminal());
}

int Fl_Terminal_scrollbar_actual_size(Fl_Terminal *self) {
    LOCK(auto ret = self->scrollbar_actual_size());
    return ret;
}

int Fl_Terminal_scrollbar_size(Fl_Terminal *self) {
    LOCK(auto ret = self->scrollbar_size());
    return ret;
}

void Fl_Terminal_set_scrollbar_size(Fl_Terminal *self, int set) {
    LOCK(self->scrollbar_size(set));
}

unsigned
Fl_Terminal_selection_bg_color(Fl_Terminal *self) { // Actually returns Fl_Color
    LOCK(auto ret = self->selectionbgcolor());
    return ret;
}

void Fl_Terminal_set_selection_bg_color(Fl_Terminal *self, unsigned set) {
    LOCK(self->selectionbgcolor(set));
}

unsigned
Fl_Terminal_selection_fg_color(Fl_Terminal *self) { // Actually returns Fl_Color
    LOCK(auto ret = self->selectionfgcolor());
    return ret;
}

void Fl_Terminal_set_selection_fg_color(Fl_Terminal *self, unsigned set) {
    LOCK(self->selectionfgcolor(set));
}

int Fl_Terminal_show_unknown(Fl_Terminal *self) {
    LOCK(auto ret = self->show_unknown());
    return ret;
}

void Fl_Terminal_set_show_unknown(Fl_Terminal *self, int boolean) {
    LOCK(self->show_unknown(boolean));
}

void Fl_Terminal_text_attrib(Fl_Terminal *self, unsigned set) {
    LOCK(self->textattrib(set));
}

unsigned
Fl_Terminal_text_bg_color(Fl_Terminal *self) { // Actually returns Fl_Color
    LOCK(auto ret = self->textbgcolor());
    return ret;
}

void Fl_Terminal_set_text_bg_color(Fl_Terminal *self, unsigned set) {
    LOCK(self->textbgcolor(set));
}

unsigned Fl_Terminal_text_bg_color_default(
    Fl_Terminal *self) { // Actually returns Fl_Color
    LOCK(auto ret = self->textbgcolor_default());
    return ret;
}

void Fl_Terminal_set_text_bg_color_default(Fl_Terminal *self, unsigned set) {
    LOCK(self->textbgcolor_default(set));
}

void Fl_Terminal_set_text_bg_color_xterm(Fl_Terminal *self, unsigned char set) {
    LOCK(self->textbgcolor_xterm(set));
}

unsigned
Fl_Terminal_text_fg_color(Fl_Terminal *self) { // Actually returns Fl_Color
    LOCK(auto ret = self->textfgcolor());
    return ret;
}

void Fl_Terminal_set_text_fg_color(Fl_Terminal *self, unsigned set) {
    LOCK(self->textfgcolor(set));
}

unsigned Fl_Terminal_text_fg_color_default(
    Fl_Terminal *self) { // Actually returns Fl_Color
    LOCK(auto ret = self->textfgcolor_default());
    return ret;
}

void Fl_Terminal_set_text_fg_color_default(Fl_Terminal *self, unsigned set) {
    LOCK(self->textfgcolor_default(set));
}

void Fl_Terminal_set_text_fg_color_xterm(Fl_Terminal *self, unsigned char set) {
    LOCK(self->textfgcolor_xterm(set));
}

int Fl_Terminal_text_font(Fl_Terminal *self) { // Actually Fl_Font
    LOCK(auto ret = self->textfont());
    return ret;
}

void Fl_Terminal_set_text_font(Fl_Terminal *self, int set) {
    LOCK(self->textfont(set));
}

int Fl_Terminal_text_size(Fl_Terminal *self) {
    LOCK(auto ret = self->textsize());
    return ret;
}

void Fl_Terminal_set_text_size(Fl_Terminal *self, int set) {
    LOCK(self->textsize(set));
}

GROUP_DEFINE(Fl_Terminal)
