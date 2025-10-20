#ifndef __CFL_BUTTON_H__
#define __CFL_BUTTON_H__

#include "cfl_macros.h"

#ifdef __cplusplus
extern "C" {
#endif

#define BUTTON_DECLARE(widget)                                                 \
    int widget##_shortcut(const widget *self);                                 \
    void widget##_set_shortcut(widget *self, int shortcut);                    \
    int widget##_clear(widget *self);                                          \
    int widget##_value(widget *self);                                          \
    void widget##_set_value(widget *self, int flag);                           \
    void widget##_set_down_box(widget *self, int);                             \
    int widget##_down_box(const widget *self);                                 \
    void widget##_set_compact(widget *self, unsigned char v);                  \
    unsigned char widget##_compact(widget *self);

WIDGET_DECLARE(Fl_Button)

BUTTON_DECLARE(Fl_Button)

WIDGET_DECLARE(Fl_Check_Button)

int Fl_Check_Button_is_checked(Fl_Check_Button *);

void Fl_Check_Button_set_checked(Fl_Check_Button *self, int checked);

BUTTON_DECLARE(Fl_Check_Button)

WIDGET_DECLARE(Fl_Radio_Button)

int Fl_Radio_Button_is_toggled(Fl_Radio_Button *);

void Fl_Radio_Button_toggle(Fl_Radio_Button *, int);

BUTTON_DECLARE(Fl_Radio_Button)

WIDGET_DECLARE(Fl_Toggle_Button)

int Fl_Toggle_Button_is_toggled(Fl_Toggle_Button *);

void Fl_Toggle_Button_toggle(Fl_Toggle_Button *, int);

BUTTON_DECLARE(Fl_Toggle_Button)

WIDGET_DECLARE(Fl_Round_Button)

int Fl_Round_Button_is_toggled(Fl_Round_Button *);

void Fl_Round_Button_toggle(Fl_Round_Button *, int);

BUTTON_DECLARE(Fl_Round_Button)

WIDGET_DECLARE(Fl_Radio_Round_Button)

int Fl_Radio_Round_Button_is_toggled(Fl_Radio_Round_Button *);

void Fl_Radio_Round_Button_toggle(Fl_Radio_Round_Button *, int);

BUTTON_DECLARE(Fl_Radio_Round_Button)

WIDGET_DECLARE(Fl_Radio_Light_Button)

int Fl_Radio_Light_Button_is_toggled(Fl_Radio_Light_Button *);

void Fl_Radio_Light_Button_toggle(Fl_Radio_Light_Button *, int);

BUTTON_DECLARE(Fl_Radio_Light_Button)

WIDGET_DECLARE(Fl_Light_Button)

int Fl_Light_Button_is_on(Fl_Light_Button *);

void Fl_Light_Button_turn_on(Fl_Light_Button *, int);

BUTTON_DECLARE(Fl_Light_Button)

WIDGET_DECLARE(Fl_Repeat_Button)

BUTTON_DECLARE(Fl_Repeat_Button)

WIDGET_DECLARE(Fl_Return_Button)

BUTTON_DECLARE(Fl_Return_Button)

WIDGET_DECLARE(Fl_Shortcut_Button)

int Fl_Shortcut_Button_default_value(Fl_Shortcut_Button *self);

void Fl_Shortcut_Button_set_default_value(Fl_Shortcut_Button *self, int flag);

void Fl_Shortcut_Button_default_clear(Fl_Shortcut_Button *self);

BUTTON_DECLARE(Fl_Shortcut_Button)

#ifdef __cplusplus
}
#endif
#endif
