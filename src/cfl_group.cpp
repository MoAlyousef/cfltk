#include "cfl_group.h"
#include "cfl_lock.hpp"

#include <FL/Fl.H>
#include <FL/Fl_Color_Chooser.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Image.H>
#include <FL/Fl_Pack.H>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Tile.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Wizard.H>
#include <FL/fl_draw.H>
#include <FL_Flex.H>

WIDGET_CLASS(Fl_Group)

WIDGET_DEFINE(Fl_Group)

Fl_Group *Fl_Group_current(void) {
    LOCK(auto ret = Fl_Group::current());
    return ret;
}

void Fl_Group_set_current(Fl_Group *grp) {
    LOCK(Fl_Group::current(grp));
}

GROUP_DEFINE(Fl_Group)

WIDGET_CLASS(Fl_Pack)

WIDGET_DEFINE(Fl_Pack)

int Fl_Pack_spacing(Fl_Pack *self) {
    LOCK(auto ret = self->spacing());
    return ret;
}
void Fl_Pack_set_spacing(Fl_Pack *self, int spacing) {
    LOCK(self->spacing(spacing));
}

GROUP_DEFINE(Fl_Pack)

WIDGET_CLASS(Fl_Scroll)

WIDGET_DEFINE(Fl_Scroll)

void *Fl_Scroll_scrollbar(Fl_Scroll *self) {
    LOCK(auto ret = &self->scrollbar);
    return ret;
}

void *Fl_Scroll_hscrollbar(Fl_Scroll *self) {
    LOCK(auto ret = &self->hscrollbar);
    return ret;
}

void *Fl_Scroll_hscrollbar(const Fl_Scroll *self);

int Fl_Scroll_xposition(const Fl_Scroll *self) {
    LOCK(auto ret = self->xposition());
    return ret;
}

int Fl_Scroll_yposition(const Fl_Scroll *self) {
    LOCK(auto ret = self->yposition());
    return ret;
}

void Fl_Scroll_scroll_to(Fl_Scroll *self, int x, int y) {
    LOCK(self->scroll_to(x, y));
}

int Fl_Scroll_scrollbar_size(const Fl_Scroll *self) {
    LOCK(auto ret = self->scrollbar_size());
    return ret;
}

void Fl_Scroll_set_scrollbar_size(Fl_Scroll *self, int newSize) {
    LOCK(self->scrollbar_size(newSize));
}

GROUP_DEFINE(Fl_Scroll)

WIDGET_CLASS(Fl_Tabs)

WIDGET_DEFINE(Fl_Tabs)

Fl_Widget *Fl_Tabs_value(Fl_Tabs *self) {
    LOCK(auto ret = self->value());
    return ret;
}

int Fl_Tabs_set_value(Fl_Tabs *self, Fl_Widget *w) {

    LOCK(auto ret = self->value(w));
    return ret;
}

Fl_Widget *Fl_Tabs_push(const Fl_Tabs *self) {
    LOCK(auto ret = self->push());
    return ret;
}

int Fl_Tabs_set_push(Fl_Tabs *self, Fl_Widget *w) {

    LOCK(auto ret = self->push(w));
    return ret;
}

void Fl_Tabs_client_area(Fl_Tabs *self, int *rx, int *ry, int *rw, int *rh) {
    LOCK(self->client_area(*rx, *ry, *rw, *rh));
}

void Fl_Tabs_set_tab_align(Fl_Tabs *self, int a) {
    LOCK(self->tab_align(a));
}

int Fl_Tabs_tab_align(const Fl_Tabs *self) {
    LOCK(auto ret = self->tab_align());
    return ret;
}

GROUP_DEFINE(Fl_Tabs)

WIDGET_CLASS(Fl_Tile)

WIDGET_DEFINE(Fl_Tile)

GROUP_DEFINE(Fl_Tile)

WIDGET_CLASS(Fl_Wizard)

WIDGET_DEFINE(Fl_Wizard)

void Fl_Wizard_next(Fl_Wizard *self) {
    LOCK(self->next());
}

void Fl_Wizard_prev(Fl_Wizard *self) {
    LOCK(self->prev());
}

Fl_Widget *Fl_Wizard_value(Fl_Wizard *self) {
    LOCK(auto ret = (Fl_Widget *)self->value());
    return ret;
}

void Fl_Wizard_set_value(Fl_Wizard *self, Fl_Widget *wid) {
    LOCK(self->value(wid));
}

GROUP_DEFINE(Fl_Wizard)

WIDGET_CLASS(Fl_Color_Chooser)

WIDGET_DEFINE(Fl_Color_Chooser)

double Fl_Color_Chooser_r(Fl_Color_Chooser *self) {
    LOCK(auto ret = self->r());
    return ret;
}
double Fl_Color_Chooser_g(Fl_Color_Chooser *self) {
    LOCK(auto ret = self->g());
    return ret;
}
double Fl_Color_Chooser_b(Fl_Color_Chooser *self) {
    LOCK(auto ret = self->b());
    return ret;
}

GROUP_DEFINE(Fl_Color_Chooser)

WIDGET_CLASS(Fl_Flex)

WIDGET_DEFINE(Fl_Flex)

void Fl_Flex_set_size(Fl_Flex *self, Fl_Widget* w, int size) {
    LOCK(self->setSize(w, size));
}

void Fl_Flex_set_debug(Fl_Flex *self, int val) {
    LOCK(self->setDebug(val));
}

GROUP_DEFINE(Fl_Flex)