#include "cfl_browser.h"
#include "cfl_lock.h"
#include "cfl_widget.hpp"

#include <FL/Fl.H>
#include <FL/Fl_Browser.H>
#include <FL/Fl_Check_Browser.H>
#include <FL/Fl_File_Browser.H>
#include <FL/Fl_Hold_Browser.H>
#include <FL/Fl_Image.H>
#include <FL/Fl_Multi_Browser.H>
#include <FL/Fl_Select_Browser.H>

#define BROWSER_DEFINE(widget)                                                 \
    int widget##_value(widget *self) {                                         \
        LOCK(int ret = self->value());                                         \
        return ret;                                                            \
    }                                                                          \
    void widget##_remove(widget *self, int line) {                             \
        LOCK(auto icon = self->icon(line); if (icon) delete icon;              \
             self->remove(line));                                              \
    }                                                                          \
    void widget##_add(widget *self, const char *newtext) {                     \
        LOCK(self->add(newtext));                                              \
    }                                                                          \
    void widget##_insert(widget *self, int line, const char *newtext) {        \
        LOCK(self->insert(line, newtext));                                     \
    }                                                                          \
    void widget##_move(widget *self, int to, int from) {                       \
        LOCK(self->move(to, from));                                            \
    }                                                                          \
    void widget##_swap(widget *self, int a, int b) {                           \
        LOCK(self->swap(a, b));                                                \
    }                                                                          \
    void widget##_clear(widget *self) {                                        \
        LOCK(for (int i = 0; i < self->size(); i++) {                          \
            auto icon = self->icon(i + 1);                                     \
            if (icon)                                                          \
                delete icon;                                                   \
        } self->clear());                                                      \
    }                                                                          \
    int widget##_size(const widget *self) {                                    \
        LOCK(auto ret = self->size());                                         \
        return ret;                                                            \
    }                                                                          \
    int widget##_select(widget *self, int line) {                              \
        LOCK(auto ret = self->select(line));                                   \
        return ret;                                                            \
    }                                                                          \
    int widget##_select_ext(widget *self, int line, int val) {                 \
        LOCK(auto ret = self->select(line, val));                              \
        return ret;                                                            \
    }                                                                          \
    int widget##_selected(const widget *self, int line) {                      \
        LOCK(auto ret = self->selected(line));                                 \
        return ret;                                                            \
    }                                                                          \
    const char *widget##_text(const widget *self, int line) {                  \
        LOCK(auto ret = self->text(line));                                     \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_text(widget *self, int line, const char *newtext) {      \
        LOCK(self->text(line, newtext));                                       \
    }                                                                          \
    void widget##_load_file(widget *self, const char *file) {                  \
        LOCK(self->load(file));                                                \
    }                                                                          \
    int widget##_text_size(widget *self) {                                     \
        LOCK(auto ret = self->textsize());                                     \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_text_size(widget *self, int s) {                         \
        LOCK(self->textsize(s));                                               \
    }                                                                          \
    void widget##_set_icon(widget *self, int line, void *icon) {               \
        LOCK(auto old = self->icon(line);                                      \
             if (!icon) self->icon(line, nullptr);                             \
             else {                                                            \
                 self->icon(line, ((Fl_Image *)icon)->copy());                 \
                 delete old;                                                   \
             })                                                                \
    }                                                                          \
    void *widget##_icon(const widget *self, int line) {                        \
        LOCK(auto temp = self->icon(line));                                    \
        if (!temp)                                                             \
            return nullptr;                                                    \
        LOCK(auto ret = ((Fl_Image *)temp)->copy());                           \
        return ret;                                                            \
    }                                                                          \
    void widget##_remove_icon(widget *self, int l) {                           \
        LOCK(self->remove_icon(l));                                            \
    }                                                                          \
    void widget##_topline(widget *self, int line) {                            \
        LOCK(self->topline(line));                                             \
    }                                                                          \
    int widget##_is_topline(widget *self) {                                    \
        LOCK(auto ret = self->topline());                                      \
        return ret;                                                            \
    }                                                                          \
    void widget##_bottomline(widget *self, int line) {                         \
        LOCK(self->bottomline(line));                                          \
    }                                                                          \
    void widget##_middleline(widget *self, int line) {                         \
        LOCK(self->middleline(line));                                          \
    }                                                                          \
    char widget##_format_char(const widget *self) {                            \
        LOCK(auto ret = self->format_char());                                  \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_format_char(widget *self, char c) {                      \
        LOCK(self->format_char(c));                                            \
    }                                                                          \
    char widget##_column_char(const widget *self) {                            \
        LOCK(auto ret = self->column_char());                                  \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_column_char(widget *self, char c) {                      \
        LOCK(self->column_char(c));                                            \
    }                                                                          \
    const int *widget##_column_widths(const widget *self) {                    \
        LOCK(auto ret = self->column_widths());                                \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_column_widths(widget *self, const int *arr) {            \
        LOCK(self->column_widths(arr));                                        \
    }                                                                          \
    int widget##_displayed(const widget *self, int line) {                     \
        LOCK(auto ret = self->displayed(line));                                \
        return ret;                                                            \
    }                                                                          \
    void widget##_make_visible(widget *self, int line) {                       \
        LOCK(self->make_visible(line));                                        \
    }                                                                          \
    int widget##_position(const widget *self) {                                \
        LOCK(auto ret = self->vposition());                                    \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_position(widget *self, int pos) {                        \
        LOCK(self->vposition(pos));                                            \
    }                                                                          \
    int widget##_hposition(const widget *self) {                               \
        LOCK(auto ret = self->hposition());                                    \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_hposition(widget *self, int pos) {                       \
        LOCK(self->hposition(pos));                                            \
    }                                                                          \
    unsigned char widget##_has_scrollbar(const widget *self) {                 \
        LOCK(auto ret = self->has_scrollbar());                                \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_has_scrollbar(widget *self, unsigned char mode) {        \
        LOCK(self->has_scrollbar(mode));                                       \
    }                                                                          \
    int widget##_scrollbar_size(const widget *self) {                          \
        LOCK(auto ret = self->scrollbar_size());                               \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_scrollbar_size(widget *self, int newSize) {              \
        LOCK(self->scrollbar_size(newSize));                                   \
    }                                                                          \
    void widget##_sort(widget *self) {                                         \
        LOCK(self->sort());                                                    \
    }                                                                          \
    void *widget##_scrollbar(widget *self) {                                   \
        LOCK(auto ret = &self->scrollbar);                                     \
        return ret;                                                            \
    }                                                                          \
    void *widget##_hscrollbar(widget *self) {                                  \
        LOCK(auto ret = &self->hscrollbar);                                    \
        return ret;                                                            \
    }                                                                          \
    void *widget##_data(const widget *self, int line) {                        \
        LOCK(auto ret = self->data(line));                                     \
        return ret;                                                            \
    }                                                                          \
    void widget##_set_data(widget *self, int line, void *data) {               \
        LOCK(self->data(line, data));                                          \
    }                                                                          \
    void widget##_hide_line(widget *self, int line) {                          \
        LOCK(self->hide(line));                                                \
    }

WIDGET_CLASS(Fl_Browser)

WIDGET_DEFINE(Fl_Browser)

BROWSER_DEFINE(Fl_Browser)

WIDGET_CLASS(Fl_Hold_Browser)

WIDGET_DEFINE(Fl_Hold_Browser)

BROWSER_DEFINE(Fl_Hold_Browser)

WIDGET_CLASS(Fl_Select_Browser)

WIDGET_DEFINE(Fl_Select_Browser)

BROWSER_DEFINE(Fl_Select_Browser)

WIDGET_CLASS(Fl_Multi_Browser)

WIDGET_DEFINE(Fl_Multi_Browser)

BROWSER_DEFINE(Fl_Multi_Browser)

WIDGET_CLASS(Fl_File_Browser)

WIDGET_DEFINE(Fl_File_Browser)

unsigned Fl_File_Browser_iconsize(const Fl_File_Browser *self) {
    LOCK(auto ret = self->iconsize());
    return ret;
}

void Fl_File_Browser_set_iconsize(Fl_File_Browser *self, unsigned s) {
    LOCK(self->iconsize(s));
}

void Fl_File_Browser_set_filter(Fl_File_Browser *self, const char *pattern) {
    LOCK(self->filter(pattern));
}

const char *Fl_File_Browser_filter(const Fl_File_Browser *self) {
    LOCK(auto ret = self->filter());
    return ret;
}

int Fl_File_Browser_filetype(const Fl_File_Browser *self) {
    LOCK(auto ret = self->filetype());
    return ret;
}

void Fl_File_Browser_set_filetype(Fl_File_Browser *self, int t) {
    LOCK(self->filetype(t));
}

BROWSER_DEFINE(Fl_File_Browser)

WIDGET_CLASS(Fl_Check_Browser)

WIDGET_DEFINE(Fl_Check_Browser)

int Fl_Check_Browser_add(Fl_Check_Browser *self, const char *s, int b) {
    LOCK(auto ret = self->add(s, b));
    return ret;
}

int Fl_Check_Browser_remove(Fl_Check_Browser *self, int item) {
    LOCK(auto ret = self->remove(item));
    return ret;
}

void Fl_Check_Browser_clear(Fl_Check_Browser *self) {
    LOCK(self->clear());
}

int Fl_Check_Browser_nitems(const Fl_Check_Browser *self) {
    LOCK(auto ret = self->nitems());
    return ret;
}

int Fl_Check_Browser_nchecked(const Fl_Check_Browser *self) {
    LOCK(auto ret = self->nchecked());
    return ret;
}

int Fl_Check_Browser_checked(const Fl_Check_Browser *self, int item) {
    LOCK(auto ret = self->checked(item));
    return ret;
}

void Fl_Check_Browser_set_checked(Fl_Check_Browser *self, int item) {
    LOCK(self->set_checked(item));
}

void Fl_Check_Browser_check_all(Fl_Check_Browser *self) {
    LOCK(self->check_all());
}

void Fl_Check_Browser_check_none(Fl_Check_Browser *self) {
    LOCK(self->check_none());
}

int Fl_Check_Browser_value(const Fl_Check_Browser *self) {
    LOCK(auto ret = self->value());
    return ret;
}

const char *Fl_Check_Browser_text(const Fl_Check_Browser *self, int item) {
    LOCK(auto ret = self->text(item));
    return ret;
}

void Fl_Check_Browser_set_text_color(Fl_Check_Browser *self, unsigned int c) {
    LOCK(self->textcolor(c));
}

unsigned int Fl_Check_Browser_text_color(Fl_Check_Browser *self) {
    LOCK(auto ret = self->textcolor());
    return ret;
}

void Fl_Check_Browser_set_text_font(Fl_Check_Browser *self, int f) {
    LOCK(self->textfont(f));
}

int Fl_Check_Browser_text_font(Fl_Check_Browser *self) {
    LOCK(auto ret = self->textfont());
    return ret;
}

void Fl_Check_Browser_set_text_size(Fl_Check_Browser *self, int s) {
    LOCK(self->textsize(s));
}

int Fl_Check_Browser_text_size(Fl_Check_Browser *self) {
    LOCK(auto ret = self->textsize());
    return ret;
}

int Fl_Check_Browser_position(const Fl_Check_Browser *self) {
    LOCK(auto ret = self->vposition());
    return ret;
}

void Fl_Check_Browser_set_position(Fl_Check_Browser *self, int pos) {
    LOCK(self->vposition(pos));
}

int Fl_Check_Browser_hposition(const Fl_Check_Browser *self) {
    LOCK(auto ret = self->hposition());
    return ret;
}

void Fl_Check_Browser_set_hposition(Fl_Check_Browser *self, int pos) {
    LOCK(self->hposition(pos));
}

unsigned char Fl_Check_Browser_has_scrollbar(const Fl_Check_Browser *self) {
    LOCK(auto ret = self->has_scrollbar());
    return ret;
}

void Fl_Check_Browser_set_has_scrollbar(
    Fl_Check_Browser *self, unsigned char mode
) {
    LOCK(self->has_scrollbar(mode));
}

int Fl_Check_Browser_scrollbar_size(const Fl_Check_Browser *self) {
    LOCK(auto ret = self->scrollbar_size());
    return ret;
}

void Fl_Check_Browser_set_scrollbar_size(Fl_Check_Browser *self, int newSize) {
    LOCK(self->scrollbar_size(newSize));
}

void Fl_Check_Browser_sort(Fl_Check_Browser *self) {
    LOCK(self->sort());
}

const void *Fl_Check_Browser_scrollbar(const Fl_Check_Browser *self) {
    LOCK(auto ret = &self->scrollbar);
    return ret;
}

const void *Fl_Check_Browser_hscrollbar(const Fl_Check_Browser *self) {
    LOCK(auto ret = &self->hscrollbar);
    return ret;
}
