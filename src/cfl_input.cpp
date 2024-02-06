#include "cfl_input.h"
#include "cfl_lock.h"
#include "cfl_widget.hpp"

#include <FL/Fl.H>
#include <FL/Fl_File_Input.H>
#include <FL/Fl_Float_Input.H>
#include <FL/Fl_Image.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Multiline_Output.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Secret_Input.H>
#include <FL/Fl_Value_Output.H>

#define INPUT_DEFINE(widget)                                                   \
    int widget##_set_value(widget *self, const char *t) {                      \
        LOCK(auto ret = self->value(t));                                       \
        return ret;                                                            \
    }                                                                          \
    const char *widget##_value(widget *self) {                                 \
        LOCK(auto ret = self->value());                                        \
        return ret;                                                            \
    }                                                                          \
    int widget##_maximum_size(widget *self) {                                  \
        LOCK(auto ret = self->maximum_size());                                 \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_maximum_size(widget *self, int m) {                      \
        LOCK(self->maximum_size(m));                                           \
    }                                                                          \
    int widget##_position(widget *self) {                                      \
        LOCK(auto ret = self->insert_position());                              \
        return ret;                                                            \
    }                                                                          \
    int widget##_set_position(widget *self, int p) {                           \
        LOCK(auto ret = self->insert_position(p));                             \
        return ret;                                                            \
    }                                                                          \
    int widget##_set_mark(widget *self, int m) {                               \
        LOCK(auto ret = self->mark(m));                                        \
        return ret;                                                            \
    }                                                                          \
    int widget##_mark(widget *self) {                                          \
        LOCK(auto ret = self->mark());                                         \
        return ret;                                                            \
    }                                                                          \
    int widget##_replace(                                                      \
        widget *self, int b, int e, const char *text, int ilen                 \
    ) {                                                                        \
        LOCK(auto ret = self->replace(b, e, text, ilen));                      \
        return ret;                                                            \
    }                                                                          \
    int widget##_insert(widget *self, const char *t, int l) {                  \
        LOCK(auto ret = self->insert(t, l));                                   \
        return ret;                                                            \
    }                                                                          \
    int widget##_append(                                                       \
        widget *self, const char *t, int l, char keep_selection                \
    ) {                                                                        \
        LOCK(auto ret = self->append(t, l, keep_selection));                   \
        return ret;                                                            \
    }                                                                          \
    int widget##_copy(widget *self, int clipboard) {                           \
        LOCK(auto ret = self->copy(clipboard));                                \
        return ret;                                                            \
    }                                                                          \
    int widget##_undo(widget *self) {                                          \
        LOCK(auto ret = self->undo());                                         \
        return ret;                                                            \
    }                                                                          \
    int widget##_copy_cuts(widget *self) {                                     \
        LOCK(auto ret = self->cut());                                          \
        return ret;                                                            \
    }                                                                          \
    unsigned int widget##_cursor_color(const widget *self) {                   \
        LOCK(auto ret = self->cursor_color());                                 \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_cursor_color(widget *self, unsigned int s) {             \
        LOCK(self->cursor_color(s));                                           \
    }                                                                          \
    int widget##_text_font(widget *self) {                                     \
        LOCK(auto ret = self->textfont());                                     \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_text_font(widget *self, int s) {                         \
        LOCK(self->textfont(s));                                               \
    }                                                                          \
    unsigned int widget##_text_color(widget *self) {                           \
        LOCK(auto ret = self->textcolor());                                    \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_text_color(widget *self, unsigned int s) {               \
        LOCK(self->textcolor(s));                                              \
    }                                                                          \
    int widget##_text_size(widget *self) {                                     \
        LOCK(auto ret = self->textsize());                                     \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_text_size(widget *self, int s) {                         \
        LOCK(self->textsize(s));                                               \
    }                                                                          \
    int widget##_readonly(widget *self) {                                      \
        LOCK(auto ret = self->readonly());                                     \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_readonly(widget *self, int boolean) {                    \
        LOCK(self->readonly(boolean));                                         \
    }                                                                          \
    int widget##_wrap(widget *self) {                                          \
        LOCK(auto ret = self->wrap());                                         \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_wrap(widget *self, int boolean) {                        \
        LOCK(self->wrap(boolean));                                             \
    };                                                                         \
    void widget##_set_tab_nav(widget *self, int flag) {                        \
        LOCK(self->tab_nav(flag));                                             \
    }                                                                          \
    int widget##_tab_nav(const widget *self) {                                 \
        LOCK(auto ret = self->tab_nav());                                      \
        return ret;                                                            \
    }

WIDGET_CLASS(Fl_Input)

WIDGET_DEFINE(Fl_Input)

INPUT_DEFINE(Fl_Input)

WIDGET_CLASS(Fl_Int_Input)

WIDGET_DEFINE(Fl_Int_Input)

INPUT_DEFINE(Fl_Int_Input)

WIDGET_CLASS(Fl_Float_Input)

WIDGET_DEFINE(Fl_Float_Input)

INPUT_DEFINE(Fl_Float_Input)

WIDGET_CLASS(Fl_Multiline_Input)

WIDGET_DEFINE(Fl_Multiline_Input)

INPUT_DEFINE(Fl_Multiline_Input)

WIDGET_CLASS(Fl_Secret_Input)

WIDGET_DEFINE(Fl_Secret_Input)

INPUT_DEFINE(Fl_Secret_Input)

WIDGET_CLASS(Fl_File_Input)

WIDGET_DEFINE(Fl_File_Input)

void Fl_File_Input_set_down_box(Fl_File_Input *self, int box) {
    LOCK(self->down_box(static_cast<Fl_Boxtype>(box)));
}
int Fl_File_Input_down_box(const Fl_File_Input *self) {
    LOCK(auto ret = self->down_box());
    return ret;
}

INPUT_DEFINE(Fl_File_Input)

WIDGET_CLASS(Fl_Output)

WIDGET_DEFINE(Fl_Output)

INPUT_DEFINE(Fl_Output)

WIDGET_CLASS(Fl_Multiline_Output)

WIDGET_DEFINE(Fl_Multiline_Output)

INPUT_DEFINE(Fl_Multiline_Output)