#include "cfl_button.h"
#include "cfl_lock.h"
#include "cfl_widget.hpp"

#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Image.H>
#include <FL/Fl_Light_Button.H>
#include <FL/Fl_Radio_Button.H>
#include <FL/Fl_Radio_Light_Button.H>
#include <FL/Fl_Radio_Round_Button.H>
#include <FL/Fl_Repeat_Button.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Round_Button.H>
#include <FL/Fl_Shortcut_Button.H>
#include <FL/Fl_Toggle_Button.H>

#define BUTTON_DEFINE(widget)                                                  \
    int widget##_shortcut(const widget *self) {                                \
        LOCK(auto ret = self->shortcut());                                     \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_shortcut(widget *self, int shortcut) {                   \
        LOCK(self->shortcut(shortcut));                                        \
    }                                                                          \
    int widget##_clear(widget *self) {                                         \
        LOCK(auto ret = self->clear());                                        \
        return ret;                                                            \
    }                                                                          \
    int widget##_value(widget *self) {                                         \
        LOCK(auto ret = self->value());                                        \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_value(widget *self, int flag) {                          \
        LOCK(self->value(flag));                                               \
    }                                                                          \
    void widget##_set_down_box(widget *self, int box) {                        \
        LOCK(self->down_box(static_cast<Fl_Boxtype>(box)));                    \
    }                                                                          \
    int widget##_down_box(const widget *self) {                                \
        LOCK(auto ret = self->down_box());                                     \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_compact(widget *self, unsigned char v) {                 \
        LOCK(self->compact(v));                                                \
    }                                                                          \
    unsigned char widget##_compact(widget *self) {                             \
        LOCK(auto ret = self->compact());                                      \
        return ret;                                                            \
    }

WIDGET_CLASS(Fl_Button)

WIDGET_DEFINE(Fl_Button)

BUTTON_DEFINE(Fl_Button)

WIDGET_CLASS(Fl_Check_Button)

WIDGET_DEFINE(Fl_Check_Button)

int Fl_Check_Button_is_checked(Fl_Check_Button *self) {
    LOCK(auto ret = self->value());
    return ret;
}

void Fl_Check_Button_set_checked(Fl_Check_Button *self, int checked) {
    LOCK(self->value(checked));
}

BUTTON_DEFINE(Fl_Check_Button)

WIDGET_CLASS(Fl_Radio_Button)

WIDGET_DEFINE(Fl_Radio_Button)

int Fl_Radio_Button_is_toggled(Fl_Radio_Button *self) {
    LOCK(auto ret = self->value());
    return ret;
}

void Fl_Radio_Button_toggle(Fl_Radio_Button *self, int boolean) {
    LOCK(self->value(boolean));
}

BUTTON_DEFINE(Fl_Radio_Button)

WIDGET_CLASS(Fl_Toggle_Button)

WIDGET_DEFINE(Fl_Toggle_Button)

int Fl_Toggle_Button_is_toggled(Fl_Toggle_Button *self) {
    LOCK(auto ret = self->value());
    return ret;
}

void Fl_Toggle_Button_toggle(Fl_Toggle_Button *self, int boolean) {
    LOCK(self->value(boolean));
}

BUTTON_DEFINE(Fl_Toggle_Button)

WIDGET_CLASS(Fl_Round_Button)

WIDGET_DEFINE(Fl_Round_Button)

int Fl_Round_Button_is_toggled(Fl_Round_Button *self) {
    LOCK(auto ret = self->value());
    return ret;
}

void Fl_Round_Button_toggle(Fl_Round_Button *self, int boolean) {
    LOCK(self->value(boolean));
}

BUTTON_DEFINE(Fl_Round_Button)

WIDGET_CLASS(Fl_Radio_Round_Button)

WIDGET_DEFINE(Fl_Radio_Round_Button)

int Fl_Radio_Round_Button_is_toggled(Fl_Radio_Round_Button *self) {
    LOCK(auto ret = self->value());
    return ret;
}

void Fl_Radio_Round_Button_toggle(Fl_Radio_Round_Button *self, int boolean) {
    LOCK(self->value(boolean));
}

BUTTON_DEFINE(Fl_Radio_Round_Button)

WIDGET_CLASS(Fl_Radio_Light_Button)

WIDGET_DEFINE(Fl_Radio_Light_Button)

int Fl_Radio_Light_Button_is_toggled(Fl_Radio_Light_Button *self) {
    LOCK(auto ret = self->value());
    return ret;
}

void Fl_Radio_Light_Button_toggle(Fl_Radio_Light_Button *self, int boolean) {
    LOCK(self->value(boolean));
}

BUTTON_DEFINE(Fl_Radio_Light_Button)

WIDGET_CLASS(Fl_Light_Button)

WIDGET_DEFINE(Fl_Light_Button)

int Fl_Light_Button_is_on(Fl_Light_Button *self) {
    LOCK(auto ret = self->value());
    return ret;
}

void Fl_Light_Button_turn_on(Fl_Light_Button *self, int boolean) {
    LOCK(self->value(boolean));
}

BUTTON_DEFINE(Fl_Light_Button)

WIDGET_CLASS(Fl_Repeat_Button)

WIDGET_DEFINE(Fl_Repeat_Button)

BUTTON_DEFINE(Fl_Repeat_Button)

WIDGET_CLASS(Fl_Return_Button)

WIDGET_DEFINE(Fl_Return_Button)

BUTTON_DEFINE(Fl_Return_Button)

WIDGET_CLASS(Fl_Shortcut_Button)

WIDGET_DEFINE(Fl_Shortcut_Button)

int Fl_Shortcut_Button_default_value(Fl_Shortcut_Button *self) {
    // LOCK(auto ret = self->default_value());
    return 0;
}

void Fl_Shortcut_Button_set_default_value(Fl_Shortcut_Button *self, int flag) {
    // LOCK(self->default_value(flag));
}

void Fl_Shortcut_Button_default_clear(Fl_Shortcut_Button *self) {
    // LOCK(self->default_clear());
}

BUTTON_DEFINE(Fl_Shortcut_Button)
