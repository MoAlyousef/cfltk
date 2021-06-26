#ifndef __CFL_INPUT_H__
#define __CFL_INPUT_H__

#include "cfl_widget.h"

#ifdef __cplusplus
extern "C" {
#endif

#define INPUT_DECLARE(widget)                                                                      \
    int widget##_set_value(widget *, const char *);                                                \
    const char *widget##_value(widget *);                                                          \
    int widget##_maximum_size(widget *);                                                           \
    void widget##_set_maximum_size(widget *, int m);                                               \
    int widget##_position(widget *);                                                               \
    int widget##_set_position(widget *, int p);                                                    \
    int widget##_set_mark(widget *, int m);                                                        \
    int widget##_mark(widget *);                                                                   \
    int widget##_replace(widget *, int b, int e, const char *text, int ilen);                      \
    int widget##_insert(widget *, const char *t, int l);                                           \
    int widget##_append(widget *, const char *t, int l, char keep_selection);                      \
    int widget##_copy(widget *, int clipboard);                                                    \
    int widget##_undo(widget *);                                                                   \
    int widget##_copy_cuts(widget *);                                                              \
    int widget##_text_font(widget *);                                                              \
    void widget##_set_text_font(widget *, int s);                                                  \
    unsigned int widget##_text_color(widget *);                                                    \
    void widget##_set_text_color(widget *, unsigned int s);                                        \
    int widget##_text_size(widget *);                                                              \
    void widget##_set_text_size(widget *, int s);                                                  \
    int widget##_readonly(widget *);                                                               \
    void widget##_set_readonly(widget *, int boolean);                                             \
    int widget##_wrap(widget *);                                                                   \
    void widget##_set_wrap(widget *, int boolean);

#define INPUT_DEFINE(widget)                                                                       \
    int widget##_set_value(widget *self, const char *t) {                                          \
        LOCK(auto ret = self->value(t));                                                           \
        return ret;                                                                                \
    }                                                                                              \
    const char *widget##_value(widget *self) {                                                     \
        LOCK(auto ret = self->value());                                                            \
        return ret;                                                                                \
    }                                                                                              \
    int widget##_maximum_size(widget *self) {                                                      \
        LOCK(auto ret = self->maximum_size());                                                     \
        return ret;                                                                                \
    }                                                                                              \
    void widget##_set_maximum_size(widget *self, int m) {                                          \
        LOCK(self->maximum_size(m);)                                                               \
    }                                                                                              \
    int widget##_position(widget *self) {                                                          \
        LOCK(auto ret = self->position());                                                         \
        return ret;                                                                                \
    }                                                                                              \
    int widget##_set_position(widget *self, int p) {                                               \
        LOCK(auto ret = self->position(p));                                                        \
        return ret;                                                                                \
    }                                                                                              \
    int widget##_set_mark(widget *self, int m) {                                                   \
        LOCK(auto ret = self->mark(m));                                                            \
        return ret;                                                                                \
    }                                                                                              \
    int widget##_mark(widget *self) {                                                              \
        LOCK(auto ret = self->mark());                                                             \
        return ret;                                                                                \
    }                                                                                              \
    int widget##_replace(widget *self, int b, int e, const char *text, int ilen) {                 \
        LOCK(auto ret = self->replace(b, e, text, ilen));                                          \
        return ret;                                                                                \
    }                                                                                              \
    int widget##_insert(widget *self, const char *t, int l) {                                      \
        LOCK(auto ret = self->insert(t, l));                                                       \
        return ret;                                                                                \
    }                                                                                              \
    int widget##_append(widget *self, const char *t, int l, char keep_selection) {                 \
        LOCK(auto ret = self->append(t, l, keep_selection));                                       \
        return ret;                                                                                \
    }                                                                                              \
    int widget##_copy(widget *self, int clipboard) {                                               \
        LOCK(auto ret = self->copy(clipboard));                                                    \
        return ret;                                                                                \
    }                                                                                              \
    int widget##_undo(widget *self) {                                                              \
        LOCK(auto ret = self->undo());                                                             \
        return ret;                                                                                \
    }                                                                                              \
    int widget##_copy_cuts(widget *self) {                                                         \
        LOCK(auto ret = self->cut());                                                              \
        return ret;                                                                                \
    }                                                                                              \
    int widget##_text_font(widget *self) {                                                         \
        LOCK(auto ret = self->textfont());                                                         \
        return ret;                                                                                \
    }                                                                                              \
    void widget##_set_text_font(widget *self, int s) {                                             \
        LOCK(self->textfont(s);)                                                                   \
    }                                                                                              \
    unsigned int widget##_text_color(widget *self) {                                               \
        LOCK(auto ret = self->textcolor());                                                        \
        return ret;                                                                                \
    }                                                                                              \
    void widget##_set_text_color(widget *self, unsigned int s) {                                   \
        LOCK(self->textcolor(s);)                                                                  \
    }                                                                                              \
    int widget##_text_size(widget *self) {                                                         \
        LOCK(auto ret = self->textsize());                                                         \
        return ret;                                                                                \
    }                                                                                              \
    void widget##_set_text_size(widget *self, int s) {                                             \
        LOCK(self->textsize(s);)                                                                   \
    }                                                                                              \
    int widget##_readonly(widget *self) {                                                          \
        LOCK(auto ret = self->readonly());                                                         \
        return ret;                                                                                \
    }                                                                                              \
    void widget##_set_readonly(widget *self, int boolean) {                                        \
        LOCK(self->readonly(boolean);)                                                             \
    }                                                                                              \
    int widget##_wrap(widget *self) {                                                              \
        LOCK(auto ret = self->wrap());                                                             \
        return ret;                                                                                \
    }                                                                                              \
    void widget##_set_wrap(widget *self, int boolean) {                                            \
        LOCK(self->wrap(boolean);)                                                                 \
    }

WIDGET_DECLARE(Fl_Input)

INPUT_DECLARE(Fl_Input)

WIDGET_DECLARE(Fl_Int_Input)

INPUT_DECLARE(Fl_Int_Input)

WIDGET_DECLARE(Fl_Float_Input)

INPUT_DECLARE(Fl_Float_Input)

WIDGET_DECLARE(Fl_Multiline_Input)

INPUT_DECLARE(Fl_Multiline_Input)

WIDGET_DECLARE(Fl_Secret_Input)

INPUT_DECLARE(Fl_Secret_Input)

WIDGET_DECLARE(Fl_File_Input)

void Fl_File_Input_set_down_box(Fl_File_Input *self, int box);

int Fl_File_Input_down_box(const Fl_File_Input *self);

INPUT_DECLARE(Fl_File_Input)

#ifdef __cplusplus
}
#endif
#endif
