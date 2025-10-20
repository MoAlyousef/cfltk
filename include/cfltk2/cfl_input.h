#ifndef __CFL_INPUT_H__
#define __CFL_INPUT_H__

#include "cfl_macros.h"

#ifdef __cplusplus
extern "C" {
#endif

#define INPUT_DECLARE(widget)                                                  \
    int widget##_set_value(widget *, const char *);                            \
    const char *widget##_value(widget *);                                      \
    int widget##_maximum_size(widget *);                                       \
    void widget##_set_maximum_size(widget *, int m);                           \
    int widget##_position(widget *);                                           \
    int widget##_set_position(widget *, int p);                                \
    int widget##_set_mark(widget *, int m);                                    \
    int widget##_mark(widget *);                                               \
    int widget##_replace(widget *, int b, int e, const char *text, int ilen);  \
    int widget##_insert(widget *, const char *t, int l);                       \
    int widget##_append(widget *, const char *t, int l, char keep_selection);  \
    int widget##_copy(widget *, int clipboard);                                \
    int widget##_undo(widget *);                                               \
    int widget##_copy_cuts(widget *);                                          \
    unsigned int widget##_cursor_color(const widget *);                        \
    void widget##_set_cursor_color(widget *, unsigned int s);                  \
    int widget##_text_font(widget *);                                          \
    void widget##_set_text_font(widget *, int s);                              \
    unsigned int widget##_text_color(widget *);                                \
    void widget##_set_text_color(widget *, unsigned int s);                    \
    int widget##_text_size(widget *);                                          \
    void widget##_set_text_size(widget *, int s);                              \
    int widget##_readonly(widget *);                                           \
    void widget##_set_readonly(widget *, int boolean);                         \
    int widget##_wrap(widget *);                                               \
    void widget##_set_wrap(widget *, int boolean);                             \
    void widget##_set_tab_nav(widget *, int flag);                             \
    int widget##_tab_nav(const widget *);

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

WIDGET_DECLARE(Fl_Output)

INPUT_DECLARE(Fl_Output)

WIDGET_DECLARE(Fl_Multiline_Output)

INPUT_DECLARE(Fl_Multiline_Output)

#ifdef __cplusplus
}
#endif
#endif
