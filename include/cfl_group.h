#ifndef __CFL_GROUP_H__
#define __CFL_GROUP_H__

#include "cfl_macros.h"

#ifdef __cplusplus
extern "C" {
#endif

WIDGET_DECLARE(Fl_Group)

Fl_Group *Fl_Group_current(void);

void Fl_Group_set_current(Fl_Group *grp);

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

WIDGET_DECLARE(Fl_Flex)

void Fl_Flex_set_size(Fl_Flex *self, Fl_Widget *w, int size);

void Fl_Flex_set_debug(int val);

void Fl_Flex_set_margin(Fl_Flex *self, int m);

int Fl_Flex_margin(const Fl_Flex *self);

void Fl_Flex_set_pad(Fl_Flex *self, int p);

int Fl_Flex_pad(const Fl_Flex *self);

GROUP_DECLARE(Fl_Flex)

#ifdef __cplusplus
}
#endif
#endif
