#include "cfl_tree.h"
#include "cfl_lock.h"
#include "cfl_widget.hpp"

#include <FL/Fl.H>
#include <FL/Fl_Image.H>
#include <FL/Fl_Tree.H>
#include <FL/Fl_Tree_Item.H>
#include <FL/Fl_Tree_Item_Array.H>
#include <FL/Fl_Widget.H>
#include <FL/platform.H>

#include <stdlib.h>

WIDGET_CLASS(Fl_Tree)

WIDGET_DEFINE(Fl_Tree)

void Fl_Tree_begin(Fl_Tree *self) {
    LOCK(self->begin());
}

void Fl_Tree_end(Fl_Tree *self) {
    LOCK(self->end());
}

void Fl_Tree_show_self(Fl_Tree *self) {
    LOCK(self->show_self());
}

void Fl_Tree_root_label(Fl_Tree *self, const char *new_label) {
    LOCK(self->root_label(new_label));
}

Fl_Tree_Item *Fl_Tree_root(Fl_Tree *self) {
    LOCK(auto ret = self->root());
    return ret;
}

void Fl_Tree_set_root(Fl_Tree *self, Fl_Tree_Item *newitem) {
    LOCK(self->root(newitem));
}

Fl_Tree_Item *Fl_Tree_add(Fl_Tree *self, const char *name) {
    LOCK(auto ret = self->add(name));
    return ret;
}

Fl_Tree_Item *
Fl_Tree_add_item(Fl_Tree *self, const char *name, Fl_Tree_Item *item) {
    LOCK(auto ret = self->add(name, item));
    return ret;
}

Fl_Tree_Item *
Fl_Tree_insert_above(Fl_Tree *self, Fl_Tree_Item *above, const char *name) {
    LOCK(auto ret = self->insert_above(above, name));
    return ret;
}

Fl_Tree_Item *
Fl_Tree_insert(Fl_Tree *self, Fl_Tree_Item *item, const char *name, int pos) {
    LOCK(auto ret = self->insert(item, name, pos));
    return ret;
}

const Fl_Tree_Item *Fl_Tree_find_item(const Fl_Tree *self, const char *path) {
    if (!path || strlen(path) == 0)
        return nullptr;
    LOCK(const Fl_Tree_Item *item = self->find_item(path));
    return item;
}

Fl_Tree_Item *Fl_Tree_find_item_mut(Fl_Tree *self, const char *path) {
    if (!path || strlen(path) == 0)
        return nullptr;
    LOCK(Fl_Tree_Item *item = self->find_item(path));
    return item;
}

int Fl_Tree_remove(Fl_Tree *self, Fl_Tree_Item *item) {
    LOCK(auto ret = self->remove(item));
    return ret;
}

void Fl_Tree_clear(Fl_Tree *self) {
    self->clear();
}

void Fl_Tree_clear_children(Fl_Tree *self, Fl_Tree_Item *item) {
    self->clear_children(item);
}

const Fl_Tree_Item *Fl_Tree_find_clicked(const Fl_Tree *self, int yonly) {
    LOCK(auto ret = self->find_clicked(yonly));
    return ret;
}

Fl_Tree_Item *Fl_Tree_item_clicked(Fl_Tree *self) {
    LOCK(auto ret = self->item_clicked());
    return ret;
}

Fl_Tree_Item *Fl_Tree_first(Fl_Tree *self) {
    LOCK(auto ret = self->first());
    return ret;
}

Fl_Tree_Item *Fl_Tree_first_visible_item(Fl_Tree *self) {
    LOCK(auto ret = self->first_visible_item());
    return ret;
}

Fl_Tree_Item *Fl_Tree_next(Fl_Tree *self, Fl_Tree_Item *item) {
    LOCK(auto ret = self->next(item));
    return ret;
}

Fl_Tree_Item *Fl_Tree_prev(Fl_Tree *self, Fl_Tree_Item *item) {
    LOCK(auto ret = self->prev(item));
    return ret;
}

Fl_Tree_Item *Fl_Tree_last(Fl_Tree *self) {
    LOCK(auto ret = self->last());
    return ret;
}

Fl_Tree_Item *Fl_Tree_last_visible_item(Fl_Tree *self) {
    LOCK(auto ret = self->last_visible_item());
    return ret;
}

Fl_Tree_Item *
Fl_Tree_next_visible_item(Fl_Tree *self, Fl_Tree_Item *start, int dir) {
    LOCK(auto ret = self->next_visible_item(start, dir));
    return ret;
}

Fl_Tree_Item *Fl_Tree_first_selected_item(Fl_Tree *self) {
    LOCK(auto ret = self->first_selected_item());
    return ret;
}

Fl_Tree_Item *Fl_Tree_last_selected_item(Fl_Tree *self) {
    LOCK(auto ret = self->last_selected_item());
    return ret;
}

Fl_Tree_Item *
Fl_Tree_next_item(Fl_Tree *self, Fl_Tree_Item *item, int dir, int visible) {
    LOCK(auto ret = self->next_item(item, dir, visible));
    return ret;
}

Fl_Tree_Item *
Fl_Tree_next_selected_item(Fl_Tree *self, Fl_Tree_Item *item, int dir) {
    LOCK(auto ret = self->next_selected_item(item, dir));
    return ret;
}

int Fl_Tree_get_selected_items(Fl_Tree *self, Fl_Tree_Item_Array **arr) {
    int c = 0;
    LOCK(for (Fl_Tree_Item *i = self->first_selected_item(); i;
              i               = self->next_selected_item(i)) c++;
         if (c == 0) return 0;
         *arr    = new Fl_Tree_Item_Array(c);
         int ret = self->get_selected_items(**arr));
    return ret;
}

int Fl_Tree_get_items(Fl_Tree *self, Fl_Tree_Item_Array **arr) {
    int c = 0;
    LOCK(for (Fl_Tree_Item *i = self->first(); i; i = self->next_item(i)) c++;
         if (c == 0) return 0;
         *arr = new Fl_Tree_Item_Array(c);
         for (Fl_Tree_Item *i = self->first(); i; i = self->next_item(i))(*arr)
             ->add(i));
    return c;
}

int Fl_Tree_open(Fl_Tree *self, const char *path, int docallback) {
    if (!path)
        return 0;
    LOCK(auto ret = self->open(path, docallback));
    return ret;
}

void Fl_Tree_open_toggle(Fl_Tree *self, Fl_Tree_Item *item, int docallback) {
    LOCK(self->open_toggle(item, docallback));
}

int Fl_Tree_close(Fl_Tree *self, const char *path, int docallback) {
    LOCK(auto ret = self->close(path, 1));
    return ret;
}

int Fl_Tree_is_open(const Fl_Tree *self, const char *path) {
    LOCK(auto ret = self->is_open(path));
    return ret;
}

int Fl_Tree_is_close(const Fl_Tree *self, const char *path) {
    LOCK(auto ret = self->is_close(path));
    return ret;
}

int Fl_Tree_select(Fl_Tree *self, const char *path, int docallback) {
    LOCK(auto ret = self->select(path, docallback));
    return ret;
}

void Fl_Tree_select_toggle(Fl_Tree *self, Fl_Tree_Item *item, int docallback) {
    LOCK(self->select_toggle(item, docallback));
}

int Fl_Tree_deselect(Fl_Tree *self, const char *path, int docallback) {
    LOCK(auto ret = self->deselect(path, docallback));
    return ret;
}

int Fl_Tree_deselect_all(Fl_Tree *self, Fl_Tree_Item *item, int docallback) {
    LOCK(auto ret = self->deselect_all(item, docallback));
    return ret;
}

int Fl_Tree_select_only(Fl_Tree *self, Fl_Tree_Item *selitem, int docallback) {
    LOCK(auto ret = self->select_only(selitem, docallback));
    return ret;
}

int Fl_Tree_select_all(Fl_Tree *self, Fl_Tree_Item *item, int docallback) {
    LOCK(auto ret = self->select_all(item, docallback));
    return ret;
}

int Fl_Tree_extend_selection_dir(
    Fl_Tree *self,
    Fl_Tree_Item *from,
    Fl_Tree_Item *to,
    int dir,
    int val,
    int visible
) {
    LOCK(auto ret = self->extend_selection_dir(from, to, dir, val, visible));
    return ret;
}

int Fl_Tree_extend_selection(
    Fl_Tree *self, Fl_Tree_Item *from, Fl_Tree_Item *to, int val, int visible
) {
    LOCK(auto ret = self->extend_selection(from, to, val, visible));
    return ret;
}

void Fl_Tree_set_item_focus(Fl_Tree *self, Fl_Tree_Item *item) {
    LOCK(self->set_item_focus(item));
}

Fl_Tree_Item *Fl_Tree_get_item_focus(const Fl_Tree *self) {
    LOCK(auto ret = self->get_item_focus());
    return ret;
}

int Fl_Tree_is_selected(Fl_Tree *self, const char *path) {
    LOCK(auto ret = self->is_selected(path));
    return ret;
}

int Fl_Tree_item_labelfont(const Fl_Tree *self) {
    LOCK(auto ret = self->item_labelfont());
    return ret;
}

void Fl_Tree_set_item_labelfont(Fl_Tree *self, int val) {
    LOCK(self->item_labelfont(val));
}

int Fl_Tree_item_labelsize(const Fl_Tree *self) {
    LOCK(auto ret = self->item_labelsize());
    return ret;
}

void Fl_Tree_set_item_labelsize(Fl_Tree *self, int val) {
    LOCK(self->item_labelsize(val));
}

unsigned int Fl_Tree_item_labelfgcolor(const Fl_Tree *self) {
    LOCK(auto ret = self->item_labelfgcolor());
    return ret;
}

void Fl_Tree_set_item_labelfgcolor(Fl_Tree *self, unsigned int val) {
    LOCK(self->item_labelfgcolor(val));
}

unsigned int Fl_Tree_item_labelbgcolor(const Fl_Tree *self) {
    LOCK(auto ret = self->item_labelbgcolor());
    return ret;
}

void Fl_Tree_set_item_labelbgcolor(Fl_Tree *self, unsigned int val) {
    LOCK(self->item_labelbgcolor(val));
}

unsigned int Fl_Tree_connectorcolor(const Fl_Tree *self) {
    LOCK(auto ret = self->connectorcolor());
    return ret;
}

void Fl_Tree_set_connectorcolor(Fl_Tree *self, unsigned int val) {
    LOCK(self->connectorcolor(val));
}

int Fl_Tree_marginleft(const Fl_Tree *self) {
    LOCK(auto ret = self->marginleft());
    return ret;
}

void Fl_Tree_set_marginleft(Fl_Tree *self, int val) {
    LOCK(self->marginleft(val));
}

int Fl_Tree_margintop(const Fl_Tree *self) {
    LOCK(auto ret = self->margintop());
    return ret;
}

void Fl_Tree_set_margintop(Fl_Tree *self, int val) {
    LOCK(self->margintop(val));
}

int Fl_Tree_marginbottom(const Fl_Tree *self) {
    LOCK(auto ret = self->marginbottom());
    return ret;
}

void Fl_Tree_set_marginbottom(Fl_Tree *self, int val) {
    LOCK(self->marginbottom(val));
}

int Fl_Tree_linespacing(const Fl_Tree *self) {
    LOCK(auto ret = self->linespacing());
    return ret;
}

void Fl_Tree_set_linespacing(Fl_Tree *self, int val) {
    LOCK(self->linespacing(val));
}

int Fl_Tree_openchild_marginbottom(const Fl_Tree *self) {
    LOCK(auto ret = self->openchild_marginbottom());
    return ret;
}

void Fl_Tree_set_openchild_marginbottom(Fl_Tree *self, int val) {
    LOCK(self->openchild_marginbottom(val));
}

int Fl_Tree_usericonmarginleft(const Fl_Tree *self) {
    LOCK(auto ret = self->usericonmarginleft());
    return ret;
}

void Fl_Tree_set_usericonmarginleft(Fl_Tree *self, int val) {
    LOCK(self->usericonmarginleft(val));
}

int Fl_Tree_labelmarginleft(const Fl_Tree *self) {
    LOCK(auto ret = self->labelmarginleft());
    return ret;
}

void Fl_Tree_set_labelmarginleft(Fl_Tree *self, int val) {
    LOCK(self->labelmarginleft(val));
}

int Fl_Tree_widgetmarginleft(const Fl_Tree *self) {
    LOCK(auto ret = self->widgetmarginleft());
    return ret;
}

void Fl_Tree_set_widgetmarginleft(Fl_Tree *self, int val) {
    LOCK(self->widgetmarginleft(val));
}

int Fl_Tree_connectorwidth(const Fl_Tree *self) {
    LOCK(auto ret = self->connectorwidth());
    return ret;
}

void Fl_Tree_set_connectorwidth(Fl_Tree *self, int val) {
    LOCK(self->connectorwidth(val));
}

void *Fl_Tree_usericon(const Fl_Tree *self) {
    LOCK(auto temp = self->usericon());
    if (!temp)
        return nullptr;
    LOCK(auto ret = ((Fl_Image *)temp)->copy());
    return ret;
}

void Fl_Tree_set_usericon(Fl_Tree *self, void *val) {
    LOCK(auto old = self->usericon(); if (!val) self->usericon(nullptr);
         else self->usericon(((Fl_Image *)val)->copy());
         delete old;)
}

void *Fl_Tree_openicon(const Fl_Tree *self) {
    LOCK(auto temp = self->openicon());
    if (!temp)
        return nullptr;
    LOCK(auto ret = ((Fl_Image *)temp)->copy());
    return ret;
}

void Fl_Tree_set_openicon(Fl_Tree *self, void *val) {
    LOCK(auto old = self->openicon(); if (!val) self->openicon(nullptr);
         else self->openicon(((Fl_Image *)val)->copy());
         delete old;)
}

void *Fl_Tree_closeicon(const Fl_Tree *self) {
    LOCK(auto temp = self->closeicon());
    if (!temp)
        return nullptr;
    LOCK(auto ret = ((Fl_Image *)temp)->copy());
    return ret;
}

void Fl_Tree_set_closeicon(Fl_Tree *self, void *val) {
    LOCK(auto old = self->closeicon(); if (!val) self->closeicon(nullptr);
         else self->closeicon(((Fl_Image *)val)->copy());
         delete old;)
}

int Fl_Tree_showcollapse(const Fl_Tree *self) {
    LOCK(auto ret = self->showcollapse());
    return ret;
}

void Fl_Tree_set_showcollapse(Fl_Tree *self, int val) {
    LOCK(self->showcollapse(val));
}

int Fl_Tree_showroot(const Fl_Tree *self) {
    LOCK(auto ret = self->showroot());
    return ret;
}

void Fl_Tree_set_showroot(Fl_Tree *self, int val) {
    LOCK(self->showroot(val));
}

int Fl_Tree_connectorstyle(const Fl_Tree *self) {
    LOCK(auto ret = self->connectorstyle());
    return ret;
}

void Fl_Tree_set_connectorstyle(Fl_Tree *self, int val) {
    LOCK(self->connectorstyle((Fl_Tree_Connector)val));
}

int Fl_Tree_sortorder(const Fl_Tree *self) {
    LOCK(auto ret = self->sortorder());
    return ret;
}

void Fl_Tree_set_sortorder(Fl_Tree *self, int val) {
    LOCK(self->sortorder((Fl_Tree_Sort)val));
}

int Fl_Tree_selectbox(const Fl_Tree *self) {
    LOCK(auto ret = self->selectbox());
    return ret;
}

void Fl_Tree_set_selectbox(Fl_Tree *self, int val) {
    LOCK(self->selectbox((Fl_Boxtype)val));
}

int Fl_Tree_selectmode(const Fl_Tree *self) {
    LOCK(auto ret = self->selectmode());
    return ret;
}

void Fl_Tree_set_selectmode(Fl_Tree *self, int val) {
    LOCK(self->selectmode((Fl_Tree_Select)val));
}

int Fl_Tree_item_reselect_mode(const Fl_Tree *self) {
    LOCK(auto ret = self->item_reselect_mode());
    return ret;
}

void Fl_Tree_set_item_reselect_mode(Fl_Tree *self, int mode) {
    LOCK(self->item_reselect_mode((Fl_Tree_Item_Reselect_Mode)mode));
}

int Fl_Tree_item_draw_mode(const Fl_Tree *self) {
    LOCK(auto ret = self->item_draw_mode());
    return ret;
}

void Fl_Tree_set_item_draw_mode(Fl_Tree *self, int mode) {
    LOCK(self->item_draw_mode(mode));
}

void Fl_Tree_calc_dimensions(Fl_Tree *self) {
    LOCK(self->calc_dimensions());
}

void Fl_Tree_calc_tree(Fl_Tree *self) {
    LOCK(self->calc_tree());
}

void Fl_Tree_recalc_tree(Fl_Tree *self) {
    LOCK(self->recalc_tree());
}

int Fl_Tree_displayed(Fl_Tree *self, Fl_Tree_Item *item) {
    LOCK(auto ret = self->displayed(item));
    return ret;
}

void Fl_Tree_show_item(Fl_Tree *self, Fl_Tree_Item *item, int yoff) {
    LOCK(self->show_item(item, yoff));
}

void Fl_Tree_show_item_top(Fl_Tree *self, Fl_Tree_Item *item) {
    LOCK(self->show_item_top(item));
}

void Fl_Tree_show_item_middle(Fl_Tree *self, Fl_Tree_Item *item) {
    LOCK(self->show_item_middle(item));
}

void Fl_Tree_show_item_bottom(Fl_Tree *self, Fl_Tree_Item *item) {
    LOCK(self->show_item_bottom(item));
}

void Fl_Tree_display(Fl_Tree *self, Fl_Tree_Item *item) {
    LOCK(self->display(item));
}

int Fl_Tree_vposition(const Fl_Tree *self) {
    LOCK(auto ret = self->vposition());
    return ret;
}

void Fl_Tree_set_vposition(Fl_Tree *self, int pos) {
    LOCK(self->vposition(pos));
}

int Fl_Tree_hposition(const Fl_Tree *self) {
    LOCK(auto ret = self->hposition());
    return ret;
}

void Fl_Tree_set_hposition(Fl_Tree *self, int pos) {
    LOCK(self->hposition(pos));
}

int Fl_Tree_is_scrollbar(Fl_Tree *self, Fl_Widget *w) {
    LOCK(auto ret = self->is_scrollbar(w));
    return ret;
}

int Fl_Tree_scrollbar_size(const Fl_Tree *self) {
    LOCK(auto ret = self->scrollbar_size());
    return ret;
}

void Fl_Tree_set_scrollbar_size(Fl_Tree *self, int size) {
    LOCK(self->scrollbar_size(size));
}

int Fl_Tree_is_vscroll_visible(const Fl_Tree *self) {
    LOCK(auto ret = self->is_vscroll_visible());
    return ret;
}

int Fl_Tree_is_hscroll_visible(const Fl_Tree *self) {
    LOCK(auto ret = self->is_hscroll_visible());
    return ret;
}

void Fl_Tree_set_callback_item(Fl_Tree *self, Fl_Tree_Item *item) {
    LOCK(self->callback_item(item));
}

Fl_Tree_Item *Fl_Tree_callback_item(Fl_Tree *self) {
    LOCK(auto ret = self->callback_item());
    return ret;
}

void Fl_Tree_set_callback_reason(Fl_Tree *self, int reason) {
    LOCK(self->callback_reason((Fl_Tree_Reason)reason));
}

int Fl_Tree_callback_reason(const Fl_Tree *self) {
    LOCK(auto ret = self->callback_reason());
    return ret;
}

int Fl_Tree_item_pathname(
    const Fl_Tree *self,
    char *pathname,
    int pathnamelen,
    const Fl_Tree_Item *item
) {
    char temp[256] = {0};
    LOCK(auto ret = self->item_pathname(temp, 256, item);
         if (ret == 0) strncpy(pathname, temp, strlen(temp)););
    return ret;
}

// TreeItems

class Fl_Tree_Item_Derived : public Fl_Tree_Item {
  public:
    void *draw_data = nullptr;
    using draw_cb   = int (*)(Fl_Tree_Item *, int, void *data);
    draw_cb cb      = nullptr;
    Fl_Tree_Item_Derived(Fl_Tree *tree, const char *txt) : Fl_Tree_Item(tree) {
        label(txt);
    }
    int draw_item_content(int render) override {
        fl_open_display();
        auto ret = Fl_Tree_Item::draw_item_content(render);
        if (cb) {
            ret = cb(this, render, draw_data);
        }
        return ret;
    }
};

Fl_Tree_Item *Fl_Tree_Item_new(Fl_Tree *tree, const char *label) {
    LOCK(auto ret = new Fl_Tree_Item_Derived(tree, label));
    return ret;
}

void Fl_Tree_Item_draw_item_content(
    Fl_Tree_Item *item, int (*cb)(Fl_Tree_Item *, int, void *), void *data
) {
    LOCK(((Fl_Tree_Item_Derived *)item)->cb        = cb;
         ((Fl_Tree_Item_Derived *)item)->draw_data = data;)
}

void Fl_Tree_Item_set_user_data(Fl_Tree_Item *item, void *data) {
    LOCK(item->user_data(data));
}

void *Fl_Tree_Item_user_data(const Fl_Tree_Item *item) {
    LOCK(auto ret = item->user_data());
    return ret;
}

int Fl_Tree_Item_x(const Fl_Tree_Item *self) {
    LOCK(auto ret = self->x());
    return ret;
}

int Fl_Tree_Item_y(const Fl_Tree_Item *self) {
    LOCK(auto ret = self->y());
    return ret;
}

int Fl_Tree_Item_w(const Fl_Tree_Item *self) {
    LOCK(auto ret = self->w());
    return ret;
}

int Fl_Tree_Item_h(const Fl_Tree_Item *self) {
    LOCK(auto ret = self->h());
    return ret;
}

int Fl_Tree_Item_label_x(const Fl_Tree_Item *self) {
    LOCK(auto ret = self->label_x());
    return ret;
}

int Fl_Tree_Item_label_y(const Fl_Tree_Item *self) {
    LOCK(auto ret = self->label_y());
    return ret;
}

int Fl_Tree_Item_label_w(const Fl_Tree_Item *self) {
    LOCK(auto ret = self->label_w());
    return ret;
}

int Fl_Tree_Item_label_h(const Fl_Tree_Item *self) {
    LOCK(auto ret = self->label_h());
    return ret;
}

void Fl_Tree_Item_show_self(const Fl_Tree_Item *self, const char *indent) {
    LOCK(self->show_self(indent));
}

void Fl_Tree_set_Item_label(Fl_Tree_Item *self, const char *val) {
    LOCK(self->label(val));
}

const char *Fl_Tree_Item_label(const Fl_Tree_Item *self) {
    LOCK(const char *label = self->label();
         auto *buf         = new char[strlen(label) + 1];
         memcpy(buf, label, strlen(label) + 1));
    return buf;
}

void Fl_Tree_Item_set_labelfont(Fl_Tree_Item *self, int val) {
    LOCK(self->labelfont(val));
}

int Fl_Tree_Item_labelfont(const Fl_Tree_Item *self) {
    LOCK(auto ret = self->labelfont());
    return ret;
}

void Fl_Tree_Item_set_labelsize(Fl_Tree_Item *self, int val) {
    LOCK(self->labelsize(val));
}

int Fl_Tree_Item_labelsize(const Fl_Tree_Item *self) {
    LOCK(auto ret = self->labelsize());
    return ret;
}

void Fl_Tree_Item_set_labelfgcolor(Fl_Tree_Item *self, unsigned int val) {
    LOCK(self->labelfgcolor(val));
}

unsigned int Fl_Tree_Item_labelfgcolor(const Fl_Tree_Item *self) {
    LOCK(auto ret = self->labelfgcolor());
    return ret;
}

void Fl_Tree_Item_set_labelcolor(Fl_Tree_Item *self, unsigned int val) {
    LOCK(self->labelcolor(val));
}

unsigned int Fl_Tree_Item_labelcolor(const Fl_Tree_Item *self) {
    LOCK(auto ret = self->labelcolor());
    return ret;
}

void Fl_Tree_Item_set_labelbgcolor(Fl_Tree_Item *self, unsigned int val) {
    LOCK(self->labelbgcolor(val));
}

unsigned int Fl_Tree_Item_labelbgcolor(const Fl_Tree_Item *self) {
    LOCK(auto ret = self->labelbgcolor());
    return ret;
}

void Fl_Tree_Item_set_widget(Fl_Tree_Item *self, Fl_Widget *val) {
    LOCK(self->widget(val));
}

Fl_Widget *Fl_Tree_Item_widget(const Fl_Tree_Item *self) {
    LOCK(auto ret = self->widget());
    return ret;
}

int Fl_Tree_Item_children(const Fl_Tree_Item *self) {
    LOCK(auto ret = self->children());
    return ret;
}

const Fl_Tree_Item *Fl_Tree_Item_child(const Fl_Tree_Item *self, int t) {
    LOCK(auto ret = self->child(t));
    return ret;
}

int Fl_Tree_Item_has_children(const Fl_Tree_Item *self) {
    LOCK(auto ret = self->has_children());
    return ret;
}

int Fl_Tree_Item_find_child(Fl_Tree_Item *self, const char *name) {
    LOCK(auto ret = self->find_child(name));
    return ret;
}

int Fl_Tree_Item_remove_child(Fl_Tree_Item *self, const char *new_label) {
    LOCK(auto ret = self->remove_child(new_label));
    return ret;
}

void Fl_Tree_Item_clear_children(Fl_Tree_Item *self) {
    LOCK(self->clear_children());
}

int Fl_Tree_Item_swap_children(
    Fl_Tree_Item *self, Fl_Tree_Item *a, Fl_Tree_Item *b
) {
    LOCK(auto ret = self->swap_children(a, b));
    return ret;
}

const Fl_Tree_Item *
Fl_Tree_Item_find_child_item(const Fl_Tree_Item *self, const char *name) {
    LOCK(auto ret = self->find_child_item(name));
    return ret;
}

Fl_Tree_Item *Fl_Tree_Item_replace(Fl_Tree_Item *self, Fl_Tree_Item *new_item) {
    LOCK(auto ret = self->replace(new_item));
    return ret;
}

Fl_Tree_Item *Fl_Tree_Item_replace_child(
    Fl_Tree_Item *self, Fl_Tree_Item *olditem, Fl_Tree_Item *newitem
) {
    LOCK(auto ret = self->replace_child(olditem, newitem));
    return ret;
}

Fl_Tree_Item *Fl_Tree_Item_deparent(Fl_Tree_Item *self, int index) {
    LOCK(auto ret = self->deparent(index));
    return ret;
}

int Fl_Tree_Item_reparent(
    Fl_Tree_Item *self, Fl_Tree_Item *newchild, int index
) {
    LOCK(auto ret = self->reparent(newchild, index));
    return ret;
}

int Fl_Tree_Item_move(Fl_Tree_Item *self, int to, int from) {
    LOCK(auto ret = self->move(to, from));
    return ret;
}

int Fl_Tree_Item_move_above(Fl_Tree_Item *self, Fl_Tree_Item *item) {
    LOCK(auto ret = self->move_above(item));
    return ret;
}

int Fl_Tree_Item_move_below(Fl_Tree_Item *self, Fl_Tree_Item *item) {
    LOCK(auto ret = self->move_below(item));
    return ret;
}

int Fl_Tree_Item_move_into(Fl_Tree_Item *self, Fl_Tree_Item *item, int pos) {
    LOCK(auto ret = self->move_into(item, pos));
    return ret;
}

int Fl_Tree_Item_depth(const Fl_Tree_Item *self) {
    LOCK(auto ret = self->depth());
    return ret;
}

Fl_Tree_Item *Fl_Tree_Item_prev(Fl_Tree_Item *self) {
    LOCK(auto ret = self->prev());
    return ret;
}

Fl_Tree_Item *Fl_Tree_Item_next(Fl_Tree_Item *self) {
    LOCK(auto ret = self->next());
    return ret;
}

Fl_Tree_Item *Fl_Tree_Item_next_sibling(Fl_Tree_Item *self) {
    LOCK(auto ret = self->next_sibling());
    return ret;
}

Fl_Tree_Item *Fl_Tree_Item_prev_sibling(Fl_Tree_Item *self) {
    LOCK(auto ret = self->prev_sibling());
    return ret;
}

void Fl_Tree_Item_update_prev_next(Fl_Tree_Item *self, int index) {
    LOCK(self->update_prev_next(index));
}

const Fl_Tree_Item *Fl_Tree_Item_parent(const Fl_Tree_Item *self) {
    LOCK(auto ret = self->parent());
    return ret;
}

void Fl_Tree_Item_set_parent(Fl_Tree_Item *self, Fl_Tree_Item *val) {
    LOCK(self->parent(val));
}

const Fl_Tree *Fl_Tree_Item_tree(const Fl_Tree_Item *self) {
    LOCK(auto ret = self->tree());
    return ret;
}

void Fl_Tree_Item_open(Fl_Tree_Item *self) {
    LOCK(self->open());
}

void Fl_Tree_Item_close(Fl_Tree_Item *self) {
    LOCK(self->close());
}

int Fl_Tree_Item_is_open(const Fl_Tree_Item *self) {
    LOCK(auto ret = self->is_open());
    return ret;
}

int Fl_Tree_Item_is_close(const Fl_Tree_Item *self) {
    LOCK(auto ret = self->is_close());
    return ret;
}

void Fl_Tree_Item_open_toggle(Fl_Tree_Item *self) {
    LOCK(self->open_toggle());
}

void Fl_Tree_Item_select(Fl_Tree_Item *self, int val) {
    LOCK(self->select(val));
}

void Fl_Tree_Item_select_toggle(Fl_Tree_Item *self) {
    LOCK(self->select_toggle());
}

int Fl_Tree_Item_select_all(Fl_Tree_Item *self) {
    LOCK(auto ret = self->select_all());
    return ret;
}

void Fl_Tree_Item_deselect(Fl_Tree_Item *self) {
    LOCK(self->deselect());
}

int Fl_Tree_Item_deselect_all(Fl_Tree_Item *self) {
    LOCK(auto ret = self->deselect_all());
    return ret;
}

int Fl_Tree_Item_is_root(const Fl_Tree_Item *self) {
    LOCK(auto ret = self->is_root());
    return ret;
}

int Fl_Tree_Item_is_visible(const Fl_Tree_Item *self) {
    LOCK(auto ret = self->is_visible());
    return ret;
}

char Fl_Tree_Item_is_active(const Fl_Tree_Item *self) {
    LOCK(auto ret = self->is_active());
    return ret;
}

char Fl_Tree_Item_is_activated(const Fl_Tree_Item *self) {
    LOCK(auto ret = self->is_activated());
    return ret;
}

void Fl_Tree_Item_deactivate(Fl_Tree_Item *self) {
    LOCK(self->deactivate());
}

void Fl_Tree_Item_activate(Fl_Tree_Item *self, int val) {
    LOCK(self->activate(val));
}

char Fl_Tree_Item_is_selected(const Fl_Tree_Item *self) {
    LOCK(auto ret = self->is_selected());
    return ret;
}

// TreeItemArray

int Fl_Tree_Item_Array_total(const Fl_Tree_Item_Array *self) {
    LOCK(auto ret = self->total());
    return ret;
}

void Fl_Tree_Item_Array_swap(Fl_Tree_Item_Array *self, int ax, int bx) {
    LOCK(self->swap(ax, bx));
}

int Fl_Tree_Item_Array_move(Fl_Tree_Item_Array *self, int to, int from) {
    LOCK(auto ret = self->move(to, from));
    return ret;
}

int Fl_Tree_Item_Array_deparent(Fl_Tree_Item_Array *self, int pos) {
    LOCK(auto ret = self->deparent(pos));
    return ret;
}

int Fl_Tree_Item_Array_reparent(
    Fl_Tree_Item_Array *self,
    Fl_Tree_Item *item,
    Fl_Tree_Item *newparent,
    int pos
) {
    LOCK(auto ret = self->reparent(item, newparent, pos));
    return ret;
}

void Fl_Tree_Item_Array_clear(Fl_Tree_Item_Array *self) {
    LOCK(self->clear());
}

void Fl_Tree_Item_Array_add(Fl_Tree_Item_Array *self, Fl_Tree_Item *val) {
    LOCK(self->add(val));
}

void Fl_Tree_Item_Array_insert(
    Fl_Tree_Item_Array *self, int pos, Fl_Tree_Item *new_item
) {
    LOCK(self->insert(pos, new_item));
}

void Fl_Tree_Item_Array_replace(
    Fl_Tree_Item_Array *self, int pos, Fl_Tree_Item *new_item
) {
    LOCK(self->replace(pos, new_item));
}

void Fl_Tree_Item_Array_remove(Fl_Tree_Item_Array *self, int index) {
    LOCK(self->remove(index));
}

int Fl_Tree_Item_Array_remove_item(
    Fl_Tree_Item_Array *self, Fl_Tree_Item *item
) {
    LOCK(auto ret = self->remove(item));
    return ret;
}

Fl_Tree_Item *Fl_Tree_Item_Array_at(Fl_Tree_Item_Array *self, int index) {
    LOCK(int total = self->total());
    if (index >= total)
        return nullptr;
    LOCK(auto ret = (*self)[index]);
    return ret;
}

void Fl_Tree_Item_Array_delete(Fl_Tree_Item_Array *self) {
    delete self;
}

void *Fl_Tree_Item_usericon(const Fl_Tree_Item *self) {
    LOCK(auto temp = self->usericon());
    if (!temp)
        return nullptr;
    LOCK(auto ret = ((Fl_Image *)temp)->copy());
    return ret;
}

void Fl_Tree_Item_set_usericon(Fl_Tree_Item *self, void *val) {
    LOCK(auto old = self->usericon(); if (!val) self->usericon(nullptr);
         else self->usericon(((Fl_Image *)val)->copy());
         delete old;)
}