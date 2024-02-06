#ifndef __CFL_BROWSER_H__
#define __CFL_BROWSER_H__

#include "cfl_macros.h"

#ifdef __cplusplus
extern "C" {
#endif

#define BROWSER_DECLARE(widget)                                                \
    int widget##_value(widget *);                                              \
    void widget##_remove(widget *, int line);                                  \
    void widget##_add(widget *, const char *newtext);                          \
    void widget##_insert(widget *, int line, const char *newtext);             \
    void widget##_move(widget *, int to, int from);                            \
    void widget##_swap(widget *, int a, int b);                                \
    void widget##_clear(widget *);                                             \
    int widget##_size(const widget *);                                         \
    int widget##_select(widget *, int line);                                   \
    int widget##_selected(const widget *, int line);                           \
    const char *widget##_text(const widget *, int line);                       \
    void widget##_set_text(widget *, int line, const char *newtext);           \
    void widget##_load_file(widget *, const char *file);                       \
    int widget##_text_size(widget *);                                          \
    void widget##_set_text_size(widget *, int s);                              \
    void widget##_set_icon(widget *, int line, void *icon);                    \
    void *widget##_icon(const widget *, int line);                             \
    void widget##_remove_icon(widget *, int line);                             \
    void widget##_topline(widget *self, int line);                             \
    int widget##_is_topline(widget *self);                                     \
    void widget##_bottomline(widget *self, int line);                          \
    void widget##_middleline(widget *self, int line);                          \
    char widget##_format_char(const widget *self);                             \
    void widget##_set_format_char(widget *self, char c);                       \
    char widget##_column_char(const widget *self);                             \
    void widget##_set_column_char(widget *self, char c);                       \
    const int *widget##_column_widths(const widget *self);                     \
    void widget##_set_column_widths(widget *self, const int *arr);             \
    int widget##_displayed(const widget *self, int line);                      \
    void widget##_make_visible(widget *self, int line);                        \
    int widget##_position(const widget *self);                                 \
    void widget##_set_position(widget *self, int pos);                         \
    int widget##_hposition(const widget *self);                                \
    void widget##_set_hposition(widget *self, int);                            \
    unsigned char widget##_has_scrollbar(const widget *self);                  \
    void widget##_set_has_scrollbar(widget *self, unsigned char mode);         \
    int widget##_scrollbar_size(const widget *self);                           \
    void widget##_set_scrollbar_size(widget *self, int newSize);               \
    void widget##_sort(widget *self);                                          \
    void *widget##_scrollbar(widget *self);                                    \
    void *widget##_hscrollbar(widget *self);                                   \
    void *widget##_data(const widget *self, int line);                         \
    void widget##_set_data(widget *self, int line, void *data);                \
    void widget##_hide_line(widget *self, int line);

WIDGET_DECLARE(Fl_Browser)

BROWSER_DECLARE(Fl_Browser)

WIDGET_DECLARE(Fl_Hold_Browser)

BROWSER_DECLARE(Fl_Hold_Browser)

WIDGET_DECLARE(Fl_Select_Browser)

BROWSER_DECLARE(Fl_Select_Browser)

WIDGET_DECLARE(Fl_Multi_Browser)

BROWSER_DECLARE(Fl_Multi_Browser)

WIDGET_DECLARE(Fl_File_Browser)

unsigned Fl_File_Browser_iconsize(const Fl_File_Browser *self);

void Fl_File_Browser_set_iconsize(Fl_File_Browser *self, unsigned s);

void Fl_File_Browser_set_filter(Fl_File_Browser *self, const char *pattern);

const char *Fl_File_Browser_filter(const Fl_File_Browser *self);

int Fl_File_Browser_filetype(const Fl_File_Browser *self);

void Fl_File_Browser_set_filetype(Fl_File_Browser *self, int t);

BROWSER_DECLARE(Fl_File_Browser)

WIDGET_DECLARE(Fl_Check_Browser)

int Fl_Check_Browser_add(Fl_Check_Browser *self, const char *s, int b);

int Fl_Check_Browser_remove(Fl_Check_Browser *self, int item);

void Fl_Check_Browser_clear(Fl_Check_Browser *self);

int Fl_Check_Browser_nitems(const Fl_Check_Browser *self);

int Fl_Check_Browser_nchecked(const Fl_Check_Browser *self);

int Fl_Check_Browser_checked(const Fl_Check_Browser *self, int item);

void Fl_Check_Browser_set_checked(Fl_Check_Browser *self, int item);

void Fl_Check_Browser_check_all(Fl_Check_Browser *self);

void Fl_Check_Browser_check_none(Fl_Check_Browser *self);

int Fl_Check_Browser_value(const Fl_Check_Browser *self);

const char *Fl_Check_Browser_text(const Fl_Check_Browser *self, int item);

int Fl_Check_Browser_position(const Fl_Check_Browser *self);

void Fl_Check_Browser_set_position(Fl_Check_Browser *self, int pos);

int Fl_Check_Browser_hposition(const Fl_Check_Browser *self);

void Fl_Check_Browser_set_hposition(Fl_Check_Browser *self, int);

unsigned char Fl_Check_Browser_has_scrollbar(const Fl_Check_Browser *self);

const void *Fl_Check_Browser_scrollbar(const Fl_Check_Browser *self);

const void *Fl_Check_Browser_hscrollbar(const Fl_Check_Browser *self);

void Fl_Check_Browser_set_has_scrollbar(
    Fl_Check_Browser *self, unsigned char mode
);

int Fl_Check_Browser_scrollbar_size(const Fl_Check_Browser *self);

void Fl_Check_Browser_set_scrollbar_size(Fl_Check_Browser *self, int newSize);

void Fl_Check_Browser_sort(Fl_Check_Browser *self);

void Fl_Check_Browser_set_text_color(Fl_Check_Browser *self, unsigned int c);

unsigned int Fl_Check_Browser_text_color(Fl_Check_Browser *self);

void Fl_Check_Browser_set_text_font(Fl_Check_Browser *self, int f);

int Fl_Check_Browser_text_font(Fl_Check_Browser *self);

void Fl_Check_Browser_set_text_size(Fl_Check_Browser *self, int s);

int Fl_Check_Browser_text_size(Fl_Check_Browser *self);

#ifdef __cplusplus
}
#endif
#endif
