#include "cfl_misc.h"
#include "cfl_lock.h"
#include "cfl_widget.hpp"

#include <FL/Fl.H>
#include <FL/Fl_Chart.H>
#include <FL/Fl_Clock.H>
#include <FL/Fl_Help_View.H>
#include <FL/Fl_Image.H>
#include <FL/Fl_Input_Choice.H>
#include <FL/Fl_Progress.H>
#include <FL/Fl_Spinner.H>
#include <FL/Fl_Tooltip.H>

WIDGET_CLASS(Fl_Spinner)

WIDGET_DEFINE(Fl_Spinner)

double Fl_Spinner_minimum(Fl_Spinner *self) {
    LOCK(auto ret = self->minimum());
    return ret;
}

void Fl_Spinner_set_minimum(Fl_Spinner *self, double a) {
    LOCK(self->minimum(a));
}

double Fl_Spinner_maximum(Fl_Spinner *self) {
    LOCK(auto ret = self->maximum());
    return ret;
}

void Fl_Spinner_set_maximum(Fl_Spinner *self, double a) {
    LOCK(self->maximum(a));
}

void Fl_Spinner_set_range(Fl_Spinner *self, double a, double b) {
    LOCK(self->range(a, b));
}

void Fl_Spinner_set_step(Fl_Spinner *self, double a) {
    LOCK(self->step(a));
}

double Fl_Spinner_step(Fl_Spinner *self) {
    LOCK(auto ret = self->step());
    return ret;
}

int Fl_Spinner_maxsize(const Fl_Spinner *self) {
    LOCK(auto ret = self->maximum_size());
    return ret;
}

void Fl_Spinner_set_maxsize(Fl_Spinner *self, int m) {
    LOCK(self->maximum_size(m));
}

int Fl_Spinner_text_font(const Fl_Spinner *self) {
    LOCK(auto ret = self->textfont());
    return ret;
}

void Fl_Spinner_set_text_font(Fl_Spinner *self, int s) {
    LOCK(self->textfont(s));
}

int Fl_Spinner_text_size(const Fl_Spinner *self) {
    LOCK(auto ret = self->textsize());
    return ret;
}

void Fl_Spinner_set_text_size(Fl_Spinner *self, int s) {
    LOCK(self->textsize(s));
}

unsigned int Fl_Spinner_text_color(const Fl_Spinner *self) {
    LOCK(auto ret = self->textcolor());
    return ret;
}

void Fl_Spinner_set_text_color(Fl_Spinner *self, unsigned int n) {
    LOCK(self->textcolor(n));
}

double Fl_Spinner_value(const Fl_Spinner *self) {
    LOCK(auto ret = self->value());
    return ret;
}

void Fl_Spinner_set_value(Fl_Spinner *self, double val) {
    LOCK(self->value(val));
}

void Fl_Spinner_set_wrap(Fl_Spinner *self, int flag) {
    LOCK(self->wrap(flag));
}

int Fl_Spinner_wrap(const Fl_Spinner *self) {
    LOCK(auto ret = self->wrap());
    return ret;
}

WIDGET_CLASS(Fl_Clock)

WIDGET_DEFINE(Fl_Clock)

WIDGET_CLASS(Fl_Chart)

WIDGET_DEFINE(Fl_Chart)

void Fl_Chart_clear(Fl_Chart *self) {
    LOCK(self->clear());
}

void Fl_Chart_add(Fl_Chart *self, double val, const char *str, unsigned col) {
    LOCK(self->add(val, str, col));
}

void Fl_Chart_insert(
    Fl_Chart *self, int ind, double val, const char *str, unsigned col
) {
    LOCK(self->insert(ind, val, str, col));
}

void Fl_Chart_replace(
    Fl_Chart *self, int ind, double val, const char *str, unsigned col
) {
    LOCK(self->replace(ind, val, str, col));
}

void Fl_Chart_set_bounds(Fl_Chart *self, double a, double b) {
    LOCK(self->bounds(a, b));
}

int Fl_Chart_size(const Fl_Chart *self) {
    LOCK(auto ret = self->size());
    return ret;
}

int Fl_Chart_maxsize(const Fl_Chart *self) {
    LOCK(auto ret = self->maxsize());
    return ret;
}

void Fl_Chart_set_maxsize(Fl_Chart *self, int m) {
    LOCK(self->maxsize(m));
}

int Fl_Chart_text_font(const Fl_Chart *self) {
    LOCK(auto ret = self->textfont());
    return ret;
}

void Fl_Chart_set_text_font(Fl_Chart *self, int s) {
    LOCK(self->textfont(s));
}

int Fl_Chart_text_size(const Fl_Chart *self) {
    LOCK(auto ret = self->textsize());
    return ret;
}

void Fl_Chart_set_text_size(Fl_Chart *self, int s) {
    LOCK(self->textsize(s));
}

unsigned int Fl_Chart_text_color(const Fl_Chart *self) {
    LOCK(auto ret = self->textcolor());
    return ret;
}

void Fl_Chart_set_text_color(Fl_Chart *self, unsigned int n) {
    LOCK(self->textcolor(n));
}

int Fl_Chart_is_autosize(const Fl_Chart *self) {
    LOCK(auto ret = self->autosize());
    return ret;
}

void Fl_Chart_make_autosize(Fl_Chart *self, int n) {
    LOCK(self->autosize(n));
}

void Fl_Chart_bounds(Fl_Chart *self, double *a, double *b) {
    LOCK(self->bounds(a, b));
}

WIDGET_CLASS(Fl_Progress)

WIDGET_DEFINE(Fl_Progress)

double Fl_Progress_minimum(Fl_Progress *self) {
    LOCK(auto ret = self->minimum());
    return ret;
}

void Fl_Progress_set_minimum(Fl_Progress *self, double a) {
    LOCK(self->minimum(a));
}

double Fl_Progress_maximum(Fl_Progress *self) {
    LOCK(auto ret = self->maximum());
    return ret;
}

void Fl_Progress_set_maximum(Fl_Progress *self, double a) {
    LOCK(self->maximum(a));
}

double Fl_Progress_value(Fl_Progress *self) {
    LOCK(auto ret = self->value());
    return ret;
}

void Fl_Progress_set_value(Fl_Progress *self, double val) {
    LOCK(self->value(val));
}

float Fl_Tooltip_delay(void) {
    LOCK(auto ret = Fl_Tooltip::delay());
    return ret;
}

void Fl_Tooltip_set_delay(float f) {
    LOCK(Fl_Tooltip::delay(f));
}

float Fl_Tooltip_hidedelay(void) {
    LOCK(auto ret = Fl_Tooltip::hidedelay());
    return ret;
}

void Fl_Tooltip_set_hidedelay(float f) {
    LOCK(Fl_Tooltip::hidedelay(f));
}

float Fl_Tooltip_hoverdelay(void) {
    LOCK(auto ret = Fl_Tooltip::hoverdelay());
    return ret;
}

void Fl_Tooltip_set_hoverdelay(float f) {
    LOCK(Fl_Tooltip::hoverdelay(f));
}

int Fl_Tooltip_enabled(void) {
    LOCK(auto ret = Fl_Tooltip::enabled());
    return ret;
}

void Fl_Tooltip_enable(int b) {
    LOCK(Fl_Tooltip::enable(b));
}

void Fl_Tooltip_disable(void) {
    LOCK(Fl_Tooltip::disable());
}

void Fl_Tooltip_enter_area(
    Fl_Widget *w, int X, int Y, int W, int H, const char *tip
) {
    LOCK(Fl_Tooltip::enter_area(w, X, Y, W, H, tip));
}

void *Fl_Tooltip_current_widget(void) {
    LOCK(auto ret = Fl_Tooltip::current());
    return ret;
}

void Fl_Tooltip_current(Fl_Widget *w) {
    LOCK(Fl_Tooltip::current(w));
}

int Fl_Tooltip_font(void) {
    LOCK(auto ret = Fl_Tooltip::font());
    return ret;
}

void Fl_Tooltip_set_font(int i) {
    LOCK(Fl_Tooltip::font(i));
}

int Fl_Tooltip_font_size(void) {
    LOCK(auto ret = Fl_Tooltip::size());
    return ret;
}

void Fl_Tooltip_set_font_size(int s) {
    LOCK(Fl_Tooltip::size(s));
}

int Fl_Tooltip_color(void) {
    LOCK(auto ret = Fl_Tooltip::color());
    return ret;
}

void Fl_Tooltip_set_color(unsigned int c) {
    LOCK(Fl_Tooltip::color(c));
}

int Fl_Tooltip_text_color(void) {
    LOCK(auto ret = Fl_Tooltip::textcolor());
    return ret;
}

void Fl_Tooltip_set_text_color(unsigned int c) {
    LOCK(Fl_Tooltip::textcolor(c));
}

int Fl_Tooltip_margin_width(void) {
    LOCK(auto ret = Fl_Tooltip::margin_width());
    return ret;
}

void Fl_Tooltip_set_margin_width(int v) {
    LOCK(Fl_Tooltip::margin_width(v));
}

int Fl_Tooltip_margin_height(void) {
    LOCK(auto ret = Fl_Tooltip::margin_height());
    return ret;
}

void Fl_Tooltip_set_margin_height(int v) {
    LOCK(Fl_Tooltip::margin_height(v));
}

int Fl_Tooltip_wrap_width(void) {
    LOCK(auto ret = Fl_Tooltip::wrap_width());
    return ret;
}

void Fl_Tooltip_set_wrap_width(int v) {
    LOCK(Fl_Tooltip::wrap_width(v));
}

void *Fl_Tooltip_current_window(void) {
    LOCK(auto ret = (void *)Fl_Tooltip::current_window());
    return ret;
}

WIDGET_CLASS(Fl_Help_View)

WIDGET_DEFINE(Fl_Help_View)

const char *Fl_Help_View_directory(const Fl_Help_View *self) {
    LOCK(auto ret = self->directory());
    return ret;
}

const char *Fl_Help_View_filename(const Fl_Help_View *self) {
    LOCK(auto ret = self->filename());
    return ret;
}

int Fl_Help_View_find(Fl_Help_View *self, const char *s, int p) {
    LOCK(auto ret = self->find(s, p));
    return ret;
}

const char *Fl_Help_View_value(const Fl_Help_View *self) {
    LOCK(auto ret = self->value());
    return ret;
}

void Fl_Help_View_set_value(Fl_Help_View *self, const char *val) {
    LOCK(self->value(val));
}

void Fl_Help_View_clear_selection(Fl_Help_View *self) {
    LOCK(self->clear_selection());
}

void Fl_Help_View_select_all(Fl_Help_View *self) {
    LOCK(self->select_all());
}

void Fl_Help_View_set_topline(Fl_Help_View *self, const char *n) {
    LOCK(self->topline(n));
}

void Fl_Help_View_set_topline2(Fl_Help_View *self, int v) {
    LOCK(self->topline(v));
}

int Fl_Help_View_topline(const Fl_Help_View *self) {
    LOCK(auto ret = self->topline());
    return ret;
}

void Fl_Help_View_set_leftline(Fl_Help_View *self, int v) {
    LOCK(self->leftline(v));
}

int Fl_Help_View_leftline(const Fl_Help_View *self) {
    LOCK(auto ret = self->leftline());
    return ret;
}

void Fl_Help_View_set_text_color(Fl_Help_View *self, unsigned int c) {
    LOCK(self->textcolor(c));
}

unsigned int Fl_Help_View_text_color(Fl_Help_View *self) {
    LOCK(auto ret = self->textcolor());
    return ret;
}

void Fl_Help_View_set_text_font(Fl_Help_View *self, int f) {
    LOCK(self->textfont(f));
}

int Fl_Help_View_text_font(Fl_Help_View *self) {
    LOCK(auto ret = self->textfont());
    return ret;
}

void Fl_Help_View_set_text_size(Fl_Help_View *self, int s) {
    LOCK(self->textsize(s));
}

int Fl_Help_View_text_size(Fl_Help_View *self) {
    LOCK(auto ret = self->textsize());
    return ret;
}

int Fl_Help_View_scrollbar_size(const Fl_Help_View *self) {
    LOCK(auto ret = self->scrollbar_size());
    return ret;
}

void Fl_Help_View_set_scrollbar_size(Fl_Help_View *self, int newSize) {
    LOCK(self->scrollbar_size(newSize));
}

int Fl_Help_View_load(Fl_Help_View *self, const char *f) {
    LOCK(auto ret = self->load(f));
    return ret;
}

WIDGET_CLASS(Fl_Input_Choice)

WIDGET_DEFINE(Fl_Input_Choice)

void Fl_Input_Choice_set_down_box(Fl_Input_Choice *self, int box) {
    LOCK(self->down_box(static_cast<Fl_Boxtype>(box)));
}

int Fl_Input_Choice_down_box(const Fl_Input_Choice *self) {
    LOCK(auto ret = self->down_box());
    return ret;
}

void Fl_Input_Choice_add(Fl_Input_Choice *self, const char *s) {
    LOCK(self->add(s));
}

void Fl_Input_Choice_clear(Fl_Input_Choice *self) {
    LOCK(self->clear());
}

const char *Fl_Input_Choice_value(const Fl_Input_Choice *self) {
    LOCK(auto ret = self->value());
    return ret;
}

int Fl_Input_Choice_value2(Fl_Input_Choice *self) {
    LOCK(auto ret = self->menu()->value());
    return ret;
}

void Fl_Input_Choice_set_value(Fl_Input_Choice *self, const char *val) {
    LOCK(self->value(val));
}

void Fl_Input_Choice_set_value2(Fl_Input_Choice *self, int val) {
    LOCK(self->value(val));
}

void *Fl_Input_Choice_input(Fl_Input_Choice *self) {
    LOCK(auto ret = self->input());
    return ret;
}

void *Fl_Input_Choice_menu_button(Fl_Input_Choice *self) {
    LOCK(auto ret = self->menubutton());
    return ret;
}

void Fl_Input_Choice_set_text_color(Fl_Input_Choice *self, unsigned int c) {
    LOCK(self->textcolor(c));
}

unsigned int Fl_Input_Choice_text_color(Fl_Input_Choice *self) {
    LOCK(auto ret = self->textcolor());
    return ret;
}

void Fl_Input_Choice_set_text_font(Fl_Input_Choice *self, int f) {
    LOCK(self->textfont(f));
}

int Fl_Input_Choice_text_font(Fl_Input_Choice *self) {
    LOCK(auto ret = self->textfont());
    return ret;
}

void Fl_Input_Choice_set_text_size(Fl_Input_Choice *self, int s) {
    LOCK(self->textsize(s));
}

int Fl_Input_Choice_text_size(Fl_Input_Choice *self) {
    LOCK(auto ret = self->textsize());
    return ret;
}
