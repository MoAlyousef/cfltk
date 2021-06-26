#include "cfl_group.h"

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

WIDGET_CLASS(Fl_Group)

WIDGET_DEFINE(Fl_Group)

Fl_Group *Fl_Group_current(void) {
    LOCK(auto ret = Fl_Group::current());
    return ret;
}

void Fl_Group_set_current(Fl_Group *grp) {
    LOCK(Fl_Group::current(grp));
}

void Fl_Group_draw_child(const Fl_Group *self, Fl_Widget *widget) {
    if (widget->visible() && widget->type() < 0xF0 &&
        fl_not_clipped(widget->x(), widget->y(), widget->w(), widget->h())) {
        LOCK(widget->clear_damage(FL_DAMAGE_ALL); widget->draw(); widget->clear_damage();)
    }
}

void Fl_Group_update_child(const Fl_Group *self, Fl_Widget *widget) {
    if (widget->damage() && widget->visible() && widget->type() < 0xF0 &&
        fl_not_clipped(widget->x(), widget->y(), widget->w(), widget->h())) {
        LOCK(widget->draw(); widget->clear_damage();)
    }
}

void Fl_Group_draw_outside_label(const Fl_Group *self, const Fl_Widget *widget) {
    if (!widget->visible())
        return;
    // skip any labels that are inside the widget:
    if (!(widget->align() & 15) || (widget->align() & FL_ALIGN_INSIDE))
        return;
    // invent a box that is outside the widget:
    Fl_Align a = widget->align();
    int X = widget->x();
    int Y = widget->y();
    int W = widget->w();
    int H = widget->h();
    int wx, wy;
    if (const_cast<Fl_Group *>(self)->as_window()) {
        wx = wy = 0;
    } else {
        wx = self->x();
        wy = self->y();
    }
    if ((a & FL_ALIGN_POSITION_MASK) == FL_ALIGN_LEFT_TOP) {
        a = (a & (~FL_ALIGN_POSITION_MASK)) | FL_ALIGN_TOP_RIGHT;
        X = wx;
        W = widget->x() - X - 3;
    } else if ((a & FL_ALIGN_POSITION_MASK) == FL_ALIGN_LEFT_BOTTOM) {
        a = (a & (~FL_ALIGN_POSITION_MASK)) | FL_ALIGN_BOTTOM_RIGHT;
        X = wx;
        W = widget->x() - X - 3;
    } else if ((a & FL_ALIGN_POSITION_MASK) == FL_ALIGN_RIGHT_TOP) {
        a = (a & (~FL_ALIGN_POSITION_MASK)) | FL_ALIGN_TOP_LEFT;
        X = X + W + 3;
        W = wx + self->w() - X;
    } else if ((a & FL_ALIGN_POSITION_MASK) == FL_ALIGN_RIGHT_BOTTOM) {
        a = (a & (~FL_ALIGN_POSITION_MASK)) | FL_ALIGN_BOTTOM_LEFT;
        X = X + W + 3;
        W = wx + self->w() - X;
    } else if (a & FL_ALIGN_TOP) {
        a ^= FL_ALIGN_TOP;
        a |= FL_ALIGN_BOTTOM;
        Y = wy;
        H = widget->y() - Y;
    } else if (a & FL_ALIGN_BOTTOM) {
        a ^= FL_ALIGN_BOTTOM;
        a |= FL_ALIGN_TOP;
        Y = Y + H;
        H = wy + self->h() - Y;
    } else if (a & FL_ALIGN_LEFT) {
        a ^= FL_ALIGN_LEFT;
        a |= FL_ALIGN_RIGHT;
        X = wx;
        W = widget->x() - X - 3;
    } else if (a & FL_ALIGN_RIGHT) {
        a ^= FL_ALIGN_RIGHT;
        a |= FL_ALIGN_LEFT;
        X = X + W + 3;
        W = wx + self->w() - X;
    }
    LOCK(widget->draw_label(X, Y, W, H, (Fl_Align)a);)
}

void Fl_Group_draw_children(Fl_Group *self) {
    LOCK(
        Fl_Widget *const *a = self->array(); if (self->clip_children()) {
            fl_push_clip(self->x() + Fl::box_dx(self->box()), self->y() + Fl::box_dy(self->box()),
                         self->w() - Fl::box_dw(self->box()), self->h() - Fl::box_dh(self->box()));
        } if (self->damage() & ~0x01) {
            for (int i = self->children(); i--;) {
                Fl_Widget &o = **a++;
                Fl_Group_draw_child(self, &o);
                Fl_Group_draw_outside_label(self, &o);
            }
        } else {
            for (int i = self->children(); i--;)
                Fl_Group_update_child(self, *a++);
        } if (self->clip_children()) fl_pop_clip();)
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
    LOCK(self->scroll_to(x, y);)
}

int Fl_Scroll_scrollbar_size(const Fl_Scroll *self) {
    LOCK(auto ret = self->scrollbar_size());
    return ret;
}

void Fl_Scroll_set_scrollbar_size(Fl_Scroll *self, int newSize) {
    LOCK(self->scrollbar_size(newSize);)
}

GROUP_DEFINE(Fl_Scroll)

WIDGET_CLASS(Fl_Tabs)

WIDGET_DEFINE(Fl_Tabs)

Fl_Widget *Fl_Tabs_value(Fl_Tabs *self) {
    LOCK(auto ret = self->value());
    return ret;
}

int Fl_Tabs_set_value(Fl_Tabs *self, Fl_Widget *w) {

    LOCK(auto ret =self->value(w));
    return ret;
}

Fl_Widget *Fl_Tabs_push(const Fl_Tabs *self) {
    LOCK(auto ret = self->push());
    return ret;
}

int Fl_Tabs_set_push(Fl_Tabs *self, Fl_Widget *w) {

    LOCK(auto ret =self->push(w));
    return ret;
}

void Fl_Tabs_client_area(Fl_Tabs *self, int *rx, int *ry, int *rw, int *rh) {
    LOCK(self->client_area(*rx, *ry, *rw, *rh));
}

void Fl_Tabs_set_tab_align(Fl_Tabs *self, int a) {
    LOCK(self->tab_align(a);)
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
    LOCK(self->next();)
}

void Fl_Wizard_prev(Fl_Wizard *self) {
    LOCK(self->prev();)
}

Fl_Widget *Fl_Wizard_value(Fl_Wizard *self) {
    LOCK(auto ret = (Fl_Widget *)self->value());
    return ret;
}

void Fl_Wizard_set_value(Fl_Wizard *self, Fl_Widget *wid) {
    LOCK(self->value(wid);)
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
