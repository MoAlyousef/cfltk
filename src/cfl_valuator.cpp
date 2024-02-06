#include "cfl_valuator.h"
#include "cfl_lock.h"
#include "cfl_widget.hpp"

#include <FL/Fl.H>
#include <FL/Fl_Adjuster.H>
#include <FL/Fl_Counter.H>
#include <FL/Fl_Dial.H>
#include <FL/Fl_Fill_Dial.H>
#include <FL/Fl_Fill_Slider.H>
#include <FL/Fl_Hor_Fill_Slider.H>
#include <FL/Fl_Hor_Nice_Slider.H>
#include <FL/Fl_Hor_Slider.H>
#include <FL/Fl_Hor_Value_Slider.H>
#include <FL/Fl_Image.H>
#include <FL/Fl_Line_Dial.H>
#include <FL/Fl_Nice_Slider.H>
#include <FL/Fl_Roller.H>
#include <FL/Fl_Scrollbar.H>
#include <FL/Fl_Slider.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Value_Output.H>
#include <FL/Fl_Value_Slider.H>

#define VALUATOR_DEFINE(widget)                                                \
    void widget##_set_bounds(widget *self, double a, double b) {               \
        LOCK(self->bounds(a, b));                                              \
    }                                                                          \
    double widget##_minimum(widget *self) {                                    \
        LOCK(auto ret = self->minimum());                                      \
        ;                                                                      \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_minimum(widget *self, double a) {                        \
        LOCK(self->minimum(a));                                                \
    }                                                                          \
    double widget##_maximum(widget *self) {                                    \
        LOCK(auto ret = self->maximum());                                      \
        ;                                                                      \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_maximum(widget *self, double a) {                        \
        LOCK(self->maximum(a));                                                \
    }                                                                          \
    void widget##_set_range(widget *self, double a, double b) {                \
        LOCK(self->range(a, b));                                               \
    }                                                                          \
    void widget##_set_step(widget *self, double a, int b) {                    \
        LOCK(self->step(a, b));                                                \
    }                                                                          \
    double widget##_step(widget *self) {                                       \
        LOCK(auto ret = self->step());                                         \
        ;                                                                      \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_precision(widget *self, int digits) {                    \
        LOCK(self->precision(digits));                                         \
    }                                                                          \
    double widget##_value(widget *self) {                                      \
        LOCK(auto ret = self->value());                                        \
        ;                                                                      \
        return ret;                                                            \
    }                                                                          \
    int widget##_set_value(widget *self, double val) {                         \
        LOCK(auto ret = self->value(val));                                     \
        return ret;                                                            \
    }                                                                          \
    int widget##_format(widget *self, char *chr) {                             \
        LOCK(auto ret = self->format(chr));                                    \
        return ret;                                                            \
    }                                                                          \
    double widget##_round(widget *self, double val) {                          \
        LOCK(auto ret = self->round(val));                                     \
        return ret;                                                            \
    }                                                                          \
    double widget##_clamp(widget *self, double val) {                          \
        LOCK(auto ret = self->clamp(val));                                     \
        return ret;                                                            \
    }                                                                          \
    double widget##_increment(widget *self, double a, int b) {                 \
        LOCK(auto ret = self->increment(a, b));                                \
        return ret;                                                            \
    }

WIDGET_CLASS(Fl_Slider)

WIDGET_DEFINE(Fl_Slider)

float Fl_Slider_slider_size(const Fl_Slider *self) {
    LOCK(auto ret = self->slider_size());
    return ret;
}

void Fl_Slider_set_slider_size(Fl_Slider *self, float v) {
    LOCK(self->slider_size((double)v));
}

int Fl_Slider_slider_box(const Fl_Slider *self) {
    LOCK(auto ret = (int)self->slider());
    return ret;
}

void Fl_Slider_set_slider_box(Fl_Slider *self, int c) {
    LOCK(self->slider((Fl_Boxtype)c));
}

VALUATOR_DEFINE(Fl_Slider)

WIDGET_CLASS(Fl_Nice_Slider)

WIDGET_DEFINE(Fl_Nice_Slider)

VALUATOR_DEFINE(Fl_Nice_Slider)

WIDGET_CLASS(Fl_Counter)

WIDGET_DEFINE(Fl_Counter)

VALUATOR_DEFINE(Fl_Counter)

WIDGET_CLASS(Fl_Dial)

WIDGET_DEFINE(Fl_Dial)

short Fl_Dial_angle1(const Fl_Dial *self) {
    LOCK(auto ret = self->angle1());
    return ret;
}

short Fl_Dial_angle2(const Fl_Dial *self) {
    LOCK(auto ret = self->angle2());
    return ret;
}

void Fl_Dial_set_angle1(Fl_Dial *self, short val) {
    LOCK(self->angle1(val));
}

void Fl_Dial_set_angle2(Fl_Dial *self, short val) {
    LOCK(self->angle2(val));
}

VALUATOR_DEFINE(Fl_Dial)

WIDGET_CLASS(Fl_Line_Dial)

WIDGET_DEFINE(Fl_Line_Dial)

VALUATOR_DEFINE(Fl_Line_Dial)

WIDGET_CLASS(Fl_Roller)

WIDGET_DEFINE(Fl_Roller)

VALUATOR_DEFINE(Fl_Roller)

WIDGET_CLASS(Fl_Scrollbar)

WIDGET_DEFINE(Fl_Scrollbar)

VALUATOR_DEFINE(Fl_Scrollbar)

WIDGET_CLASS(Fl_Value_Slider)

WIDGET_DEFINE(Fl_Value_Slider)

void Fl_Value_Slider_set_text_color(Fl_Value_Slider *self, unsigned int c) {
    LOCK(self->textcolor(c));
}

unsigned int Fl_Value_Slider_text_color(Fl_Value_Slider *self) {
    LOCK(auto ret = self->textcolor());
    return ret;
}

void Fl_Value_Slider_set_text_font(Fl_Value_Slider *self, int f) {
    LOCK(self->textfont(f));
}

int Fl_Value_Slider_text_font(Fl_Value_Slider *self) {
    LOCK(auto ret = self->textfont());
    return ret;
}

void Fl_Value_Slider_set_text_size(Fl_Value_Slider *self, int s) {
    LOCK(self->textsize(s));
}

int Fl_Value_Slider_text_size(Fl_Value_Slider *self) {
    LOCK(auto ret = self->textsize());
    return ret;
}

VALUATOR_DEFINE(Fl_Value_Slider)

WIDGET_CLASS(Fl_Adjuster)

WIDGET_DEFINE(Fl_Adjuster)

VALUATOR_DEFINE(Fl_Adjuster)

WIDGET_CLASS(Fl_Value_Input)

WIDGET_DEFINE(Fl_Value_Input)

void Fl_Value_Input_set_text_color(Fl_Value_Input *self, unsigned int c) {
    LOCK(self->textcolor(c));
}

unsigned int Fl_Value_Input_text_color(Fl_Value_Input *self) {
    LOCK(auto ret = self->textcolor());
    return ret;
}

void Fl_Value_Input_set_text_font(Fl_Value_Input *self, int f) {
    LOCK(self->textfont(f));
}

int Fl_Value_Input_text_font(Fl_Value_Input *self) {
    LOCK(auto ret = self->textfont());
    return ret;
}

void Fl_Value_Input_set_text_size(Fl_Value_Input *self, int s) {
    LOCK(self->textsize(s));
}

int Fl_Value_Input_text_size(Fl_Value_Input *self) {
    LOCK(auto ret = self->textsize());
    return ret;
}

void Fl_Value_Input_set_soft(Fl_Value_Input *self, char val) {
    LOCK(self->soft(val));
}

char Fl_Value_Input_soft(const Fl_Value_Input *self) {
    LOCK(auto ret = self->soft());
    return ret;
}

VALUATOR_DEFINE(Fl_Value_Input)

WIDGET_CLASS(Fl_Value_Output)

WIDGET_DEFINE(Fl_Value_Output)

void Fl_Value_Output_set_text_color(Fl_Value_Output *self, unsigned int c) {
    LOCK(self->textcolor(c));
}

unsigned int Fl_Value_Output_text_color(Fl_Value_Output *self) {
    LOCK(auto ret = self->textcolor());
    return ret;
}

void Fl_Value_Output_set_text_font(Fl_Value_Output *self, int f) {
    LOCK(self->textfont(f));
}

int Fl_Value_Output_text_font(Fl_Value_Output *self) {
    LOCK(auto ret = self->textfont());
    return ret;
}

void Fl_Value_Output_set_text_size(Fl_Value_Output *self, int s) {
    LOCK(self->textsize(s));
}

int Fl_Value_Output_text_size(Fl_Value_Output *self) {
    LOCK(auto ret = self->textsize());
    return ret;
}

VALUATOR_DEFINE(Fl_Value_Output)

WIDGET_CLASS(Fl_Fill_Slider)

WIDGET_DEFINE(Fl_Fill_Slider)

VALUATOR_DEFINE(Fl_Fill_Slider)

WIDGET_CLASS(Fl_Fill_Dial)

WIDGET_DEFINE(Fl_Fill_Dial)

VALUATOR_DEFINE(Fl_Fill_Dial)

WIDGET_CLASS(Fl_Hor_Slider)

WIDGET_DEFINE(Fl_Hor_Slider)

VALUATOR_DEFINE(Fl_Hor_Slider)

WIDGET_CLASS(Fl_Hor_Fill_Slider)

WIDGET_DEFINE(Fl_Hor_Fill_Slider)

VALUATOR_DEFINE(Fl_Hor_Fill_Slider)

WIDGET_CLASS(Fl_Hor_Nice_Slider)

WIDGET_DEFINE(Fl_Hor_Nice_Slider)

VALUATOR_DEFINE(Fl_Hor_Nice_Slider)

WIDGET_CLASS(Fl_Hor_Value_Slider)

WIDGET_DEFINE(Fl_Hor_Value_Slider)

void Fl_Hor_Value_Slider_set_text_color(
    Fl_Hor_Value_Slider *self, unsigned int c
) {
    LOCK(self->textcolor(c));
}

unsigned int Fl_Hor_Value_Slider_text_color(Fl_Hor_Value_Slider *self) {
    LOCK(auto ret = self->textcolor());
    return ret;
}

void Fl_Hor_Value_Slider_set_text_font(Fl_Hor_Value_Slider *self, int f) {
    LOCK(self->textfont(f));
}

int Fl_Hor_Value_Slider_text_font(Fl_Hor_Value_Slider *self) {
    LOCK(auto ret = self->textfont());
    return ret;
}

void Fl_Hor_Value_Slider_set_text_size(Fl_Hor_Value_Slider *self, int s) {
    LOCK(self->textsize(s));
}

int Fl_Hor_Value_Slider_text_size(Fl_Hor_Value_Slider *self) {
    LOCK(auto ret = self->textsize());
    return ret;
}

VALUATOR_DEFINE(Fl_Hor_Value_Slider)
