#ifndef __CFL_GROUP_H__
#define __CFL_GROUP_H__

#include "cfl_widget.h"

#ifdef __cplusplus
extern "C" {
#endif

#define GROUP_DECLARE(widget)                                                                      \
    void widget##_begin(widget *self);                                                             \
    void widget##_end(widget *self);                                                               \
    int widget##_find(widget *self, const void *);                                                 \
    void widget##_add(widget *self, void *);                                                       \
    void widget##_insert(widget *self, void *, int pos);                                           \
    void widget##_remove(widget *self, void *wid);                                                 \
    void widget##_remove_by_index(widget *self, int idx);                                          \
    void widget##_clear(widget *self);                                                             \
    int widget##_children(widget *self);                                                           \
    Fl_Widget *widget##_child(widget *, int index);                                                \
    void widget##_resizable(widget *self, void *);                                                 \
    void widget##_set_clip_children(widget *self, int c);                                          \
    int widget##_clip_children(widget *self);                                                      \
    void widget##_init_sizes(widget *self);

#define GROUP_DEFINE(widget)                                                                       \
    void widget##_begin(widget *self) {                                                            \
        LOCK(self->begin();)                                                                       \
    }                                                                                              \
    void widget##_end(widget *self) {                                                              \
        LOCK(self->end();)                                                                         \
    }                                                                                              \
    int widget##_find(widget *self, const void *wid) {                                             \
        LOCK(auto ret = self->find((const Fl_Widget *)wid));                                       \
        return ret;                                                                                \
    }                                                                                              \
    void widget##_add(widget *self, void *wid) {                                                   \
        LOCK(self->add((Fl_Widget *)wid);)                                                         \
    }                                                                                              \
    void widget##_insert(widget *self, void *wid, int pos) {                                       \
        LOCK(self->insert(*(Fl_Widget *)wid, pos);)                                                \
    }                                                                                              \
    void widget##_remove(widget *self, void *wid) {                                                \
        LOCK(self->remove(*(Fl_Widget *)wid);)                                                     \
    }                                                                                              \
    void widget##_remove_by_index(widget *self, int idx) {                                         \
        LOCK(((Fl_Group *)self)->remove(idx);)                                                     \
    }                                                                                              \
    void widget##_clear(widget *self) {                                                            \
        LOCK(self->clear();)                                                                       \
    }                                                                                              \
    int widget##_children(widget *self) {                                                          \
        LOCK(auto ret = self->children());                                                         \
        return ret;                                                                                \
    }                                                                                              \
    Fl_Widget *widget##_child(widget *self, int index) {                                           \
        LOCK(auto ret = self->child(index));                                                       \
        return ret;                                                                                \
    }                                                                                              \
    void widget##_resizable(widget *self, void *wid) {                                             \
        LOCK(self->resizable((Fl_Widget *)wid);)                                                   \
    }                                                                                              \
    void widget##_set_clip_children(widget *self, int c) {                                         \
        LOCK(self->clip_children(c);)                                                              \
    }                                                                                              \
    int widget##_clip_children(widget *self) {                                                     \
        LOCK(auto ret = self->clip_children());                                                    \
        return ret;                                                                                \
    }                                                                                              \
    void widget##_init_sizes(widget *self) {                                                       \
        LOCK(self->init_sizes();)                                                                  \
    }

WIDGET_DECLARE(Fl_Group)

Fl_Group *Fl_Group_current(void);

void Fl_Group_set_current(Fl_Group *grp);

void Fl_Group_draw_child(const Fl_Group *self, Fl_Widget *w);

void Fl_Group_update_child(const Fl_Group *self, Fl_Widget *w);

void Fl_Group_draw_outside_label(const Fl_Group *self, const Fl_Widget *widget);

void Fl_Group_draw_children(Fl_Group *self);

GROUP_DECLARE(Fl_Group)

WIDGET_DECLARE(Fl_Pack)

int Fl_Pack_spacing(Fl_Pack *self);

void Fl_Pack_set_spacing(Fl_Pack *self, int spacing);

GROUP_DECLARE(Fl_Pack)

WIDGET_DECLARE(Fl_Scroll)

void *Fl_Scroll_scrollbar(Fl_Scroll *self);

void *Fl_Scroll_hscrollbar(Fl_Scroll *self);

int Fl_Scroll_xposition(const Fl_Scroll *self);

int Fl_Scroll_yposition(const Fl_Scroll *self);

void Fl_Scroll_scroll_to(Fl_Scroll *self, int, int);

int Fl_Scroll_scrollbar_size(const Fl_Scroll *self);

void Fl_Scroll_set_scrollbar_size(Fl_Scroll *self, int newSize);

GROUP_DECLARE(Fl_Scroll)

WIDGET_DECLARE(Fl_Tabs)

Fl_Widget *Fl_Tabs_value(Fl_Tabs *self);

int Fl_Tabs_set_value(Fl_Tabs *self, Fl_Widget *w);

Fl_Widget *Fl_Tabs_push(const Fl_Tabs *self);

int Fl_Tabs_set_push(Fl_Tabs *self, Fl_Widget *w);

void Fl_Tabs_client_area(Fl_Tabs *self, int *rx, int *ry, int *rw, int *rh);

void Fl_Tabs_set_tab_align(Fl_Tabs *self, int a);

int Fl_Tabs_tab_align(const Fl_Tabs *self);

GROUP_DECLARE(Fl_Tabs)

WIDGET_DECLARE(Fl_Tile)

GROUP_DECLARE(Fl_Tile)

WIDGET_DECLARE(Fl_Wizard)

void Fl_Wizard_next(Fl_Wizard *);

void Fl_Wizard_prev(Fl_Wizard *);

Fl_Widget *Fl_Wizard_value(Fl_Wizard *);

void Fl_Wizard_set_value(Fl_Wizard *, Fl_Widget *);

GROUP_DECLARE(Fl_Wizard)

WIDGET_DECLARE(Fl_Color_Chooser)

double Fl_Color_Chooser_r(Fl_Color_Chooser *self);

double Fl_Color_Chooser_g(Fl_Color_Chooser *self);

double Fl_Color_Chooser_b(Fl_Color_Chooser *self);

GROUP_DECLARE(Fl_Color_Chooser)

#ifdef __cplusplus
}
#endif
#endif
