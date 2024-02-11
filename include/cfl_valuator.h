#ifndef __CFL_VALUATOR_H__
#define __CFL_VALUATOR_H__

#include "cfl_macros.h"

#ifdef __cplusplus
extern "C" {
#endif

#define VALUATOR_DECLARE(widget)                                               \
    void widget##_set_bounds(widget *, double a, double b);                    \
    double widget##_minimum(widget *);                                         \
    void widget##_set_minimum(widget *, double a);                             \
    double widget##_maximum(widget *);                                         \
    void widget##_set_maximum(widget *, double a);                             \
    void widget##_set_range(widget *, double a, double b);                     \
    void widget##_set_step(widget *, double a, int b);                         \
    double widget##_step(widget *);                                            \
    void widget##_set_precision(widget *, int digits);                         \
    double widget##_value(widget *);                                           \
    int widget##_set_value(widget *, double);                                  \
    int widget##_format(widget *, char *);                                     \
    double widget##_round(widget *, double);                                   \
    double widget##_clamp(widget *, double);                                   \
    double widget##_increment(widget *, double, int);

WIDGET_DECLARE(Fl_Slider)

float Fl_Slider_slider_size(const Fl_Slider *self);

void Fl_Slider_set_slider_size(Fl_Slider *self, float v);

int Fl_Slider_slider_box(const Fl_Slider *self);

void Fl_Slider_set_slider_box(Fl_Slider *self, int c);

VALUATOR_DECLARE(Fl_Slider)

WIDGET_DECLARE(Fl_Nice_Slider)

VALUATOR_DECLARE(Fl_Nice_Slider)

WIDGET_DECLARE(Fl_Counter)

VALUATOR_DECLARE(Fl_Counter)

WIDGET_DECLARE(Fl_Dial)

short Fl_Dial_angle1(const Fl_Dial *self);

short Fl_Dial_angle2(const Fl_Dial *self);

void Fl_Dial_set_angle1(Fl_Dial *self, short val);

void Fl_Dial_set_angle2(Fl_Dial *self, short val);

VALUATOR_DECLARE(Fl_Dial)

WIDGET_DECLARE(Fl_Line_Dial)

VALUATOR_DECLARE(Fl_Line_Dial)

WIDGET_DECLARE(Fl_Roller)

VALUATOR_DECLARE(Fl_Roller)

WIDGET_DECLARE(Fl_Scrollbar)

VALUATOR_DECLARE(Fl_Scrollbar)

WIDGET_DECLARE(Fl_Value_Slider)

void Fl_Value_Slider_set_text_color(Fl_Value_Slider *self, unsigned int c);

unsigned int Fl_Value_Slider_text_color(Fl_Value_Slider *self);

void Fl_Value_Slider_set_text_font(Fl_Value_Slider *self, int f);

int Fl_Value_Slider_text_font(Fl_Value_Slider *self);

void Fl_Value_Slider_set_text_size(Fl_Value_Slider *self, int s);

int Fl_Value_Slider_text_size(Fl_Value_Slider *self);

VALUATOR_DECLARE(Fl_Value_Slider)

WIDGET_DECLARE(Fl_Adjuster)

VALUATOR_DECLARE(Fl_Adjuster)

WIDGET_DECLARE(Fl_Value_Input)

void Fl_Value_Input_set_text_color(Fl_Value_Input *self, unsigned int c);

unsigned int Fl_Value_Input_text_color(Fl_Value_Input *self);

void Fl_Value_Input_set_text_font(Fl_Value_Input *self, int f);

int Fl_Value_Input_text_font(Fl_Value_Input *self);

void Fl_Value_Input_set_text_size(Fl_Value_Input *self, int s);

int Fl_Value_Input_text_size(Fl_Value_Input *self);

void Fl_Value_Input_set_soft(Fl_Value_Input *self, char val);

char Fl_Value_Input_soft(const Fl_Value_Input *self);

VALUATOR_DECLARE(Fl_Value_Input)

WIDGET_DECLARE(Fl_Value_Output)

void Fl_Value_Output_set_text_color(Fl_Value_Output *self, unsigned int c);

unsigned int Fl_Value_Output_text_color(Fl_Value_Output *self);

void Fl_Value_Output_set_text_font(Fl_Value_Output *self, int f);

int Fl_Value_Output_text_font(Fl_Value_Output *self);

void Fl_Value_Output_set_text_size(Fl_Value_Output *self, int s);

int Fl_Value_Output_text_size(Fl_Value_Output *self);

VALUATOR_DECLARE(Fl_Value_Output)

WIDGET_DECLARE(Fl_Fill_Slider)

VALUATOR_DECLARE(Fl_Fill_Slider)

WIDGET_DECLARE(Fl_Fill_Dial)

VALUATOR_DECLARE(Fl_Fill_Dial)

WIDGET_DECLARE(Fl_Hor_Slider)

VALUATOR_DECLARE(Fl_Hor_Slider)

WIDGET_DECLARE(Fl_Hor_Fill_Slider)

VALUATOR_DECLARE(Fl_Hor_Fill_Slider)

WIDGET_DECLARE(Fl_Hor_Nice_Slider)

VALUATOR_DECLARE(Fl_Hor_Nice_Slider)

WIDGET_DECLARE(Fl_Hor_Value_Slider)

void Fl_Hor_Value_Slider_set_text_color(
    Fl_Hor_Value_Slider *self, unsigned int c
);

unsigned int Fl_Hor_Value_Slider_text_color(Fl_Hor_Value_Slider *self);

void Fl_Hor_Value_Slider_set_text_font(Fl_Hor_Value_Slider *self, int f);

int Fl_Hor_Value_Slider_text_font(Fl_Hor_Value_Slider *self);

void Fl_Hor_Value_Slider_set_text_size(Fl_Hor_Value_Slider *self, int s);

int Fl_Hor_Value_Slider_text_size(Fl_Hor_Value_Slider *self);

VALUATOR_DECLARE(Fl_Hor_Value_Slider)

#ifdef __cplusplus
}
#endif
#endif
