#include "cfl_menu.h"
#include "cfl_lock.hpp"

#include "FL/Fl_Sys_Menu_Bar.H"
#include <FL/Fl.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Image.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Menu_Button.H>
#include <FL/Fl_Menu_Item.H>
#include <FL/platform.H>

#define MENU_DEFINE(widget)                                                                        \
    void widget##_add(widget *self, const char *name, int shortcut, Fl_Callback *cb, void *data,   \
                      int flag) {                                                                  \
        if (!cb)                                                                                   \
            return;                                                                                \
        LOCK(self->add(name, shortcut, cb, data, flag);)                                           \
    }                                                                                              \
    void widget##_insert(widget *self, int index, const char *name, int shortcut, Fl_Callback *cb, \
                         void *data, int flag) {                                                   \
        if (!cb)                                                                                   \
            return;                                                                                \
        LOCK(self->insert(index, name, shortcut, cb, data, flag);)                                 \
    }                                                                                              \
    Fl_Menu_Item *widget##_get_item(widget *self, const char *name) {                              \
        LOCK(auto ret = (Fl_Menu_Item *)self->find_item(name));                                    \
        return ret;                                                                                \
    }                                                                                              \
    int widget##_set_item(widget *self, Fl_Menu_Item *item) {                                      \
        LOCK(auto ret = self->value(item);)                                                        \
        return ret;                                                                                \
    }                                                                                              \
    int widget##_text_font(widget *self) {                                                         \
        LOCK(auto ret = self->textfont(););                                                        \
        return ret;                                                                                \
    }                                                                                              \
    void widget##_set_text_font(widget *self, int c) {                                             \
        LOCK(self->textfont(c);)                                                                   \
    }                                                                                              \
    int widget##_text_size(widget *self) {                                                         \
        LOCK(auto ret = self->textsize(););                                                        \
        return ret;                                                                                \
    }                                                                                              \
    void widget##_set_text_size(widget *self, int c) {                                             \
        LOCK(self->textsize(c);)                                                                   \
    }                                                                                              \
    unsigned int widget##_text_color(widget *self) {                                               \
        LOCK(auto ret = self->textcolor(););                                                       \
        return ret;                                                                                \
    }                                                                                              \
    void widget##_set_text_color(widget *self, unsigned int c) {                                   \
        LOCK(self->textcolor(c);)                                                                  \
    }                                                                                              \
    void widget##_add_choice(widget *self, const char *str) {                                      \
        LOCK(self->add(str);)                                                                      \
    }                                                                                              \
    const char *widget##_get_choice(widget *self) {                                                \
        LOCK(auto ret = self->text(););                                                            \
        return ret;                                                                                \
    }                                                                                              \
    int widget##_value(widget *self) {                                                             \
        LOCK(auto ret = self->value();)                                                            \
        return ret;                                                                                \
    }                                                                                              \
    int widget##_set_value(widget *self, int v) {                                                  \
        LOCK(auto ret = self->value(v);)                                                           \
        return ret;                                                                                \
    }                                                                                              \
    void widget##_clear(widget *self) {                                                            \
        LOCK(self->clear();)                                                                       \
    }                                                                                              \
    int widget##_clear_submenu(widget *self, int index) {                                          \
        LOCK(auto ret = self->clear_submenu(index));                                               \
        return ret;                                                                                \
    }                                                                                              \
    int widget##_size(const widget *self) {                                                        \
        LOCK(auto ret = self->size(););                                                            \
        return ret;                                                                                \
    }                                                                                              \
    const char *widget##_text(const widget *self, int idx) {                                       \
        LOCK(auto ret = self->text(idx););                                                         \
        return ret;                                                                                \
    }                                                                                              \
    const Fl_Menu_Item *widget##_at(const widget *self, int idx) {                                 \
        LOCK(auto ret = &self->menu()[idx];);                                                      \
        return ret;                                                                                \
    }                                                                                              \
    void widget##_set_mode(widget *self, int i, int fl) {                                          \
        LOCK(self->mode(fl);)                                                                      \
    }                                                                                              \
    int widget##_mode(const widget *self, int i) {                                                 \
        LOCK(auto ret = self->mode(i););                                                           \
        return ret;                                                                                \
    }                                                                                              \
    int widget##_find_index(const widget *self, const char *label) {                               \
        LOCK(auto ret = self->find_index(label););                                                 \
        return ret;                                                                                \
    }                                                                                              \
    const Fl_Menu_Item *widget##_menu(const widget *self) {                                        \
        LOCK(auto ret = self->menu(););                                                            \
        return ret;                                                                                \
    }                                                                                              \
    void widget##_remove(widget *self, int idx) {                                                  \
        LOCK(self->remove(idx);)                                                                   \
    }                                                                                              \
    void widget##_set_down_box(widget *self, int box) {                                            \
        LOCK(self->down_box(static_cast<Fl_Boxtype>(box)));                                        \
    }                                                                                              \
    int widget##_down_box(const widget *self) {                                                    \
        LOCK(auto ret = self->down_box(););                                                        \
        return ret;                                                                                \
    }                                                                                              \
    void widget##_global(widget *self) {                                                           \
        LOCK(self->global();)                                                                      \
    }

WIDGET_CLASS(Fl_Menu_Bar)

WIDGET_DEFINE(Fl_Menu_Bar)

MENU_DEFINE(Fl_Menu_Bar)

WIDGET_CLASS(Fl_Menu_Button)

WIDGET_DEFINE(Fl_Menu_Button)

const Fl_Menu_Item *Fl_Menu_Button_popup(Fl_Menu_Button *self) {
    LOCK(auto ret = self->popup()); return ret;
}

MENU_DEFINE(Fl_Menu_Button)

WIDGET_CLASS(Fl_Choice)

WIDGET_DEFINE(Fl_Choice)

MENU_DEFINE(Fl_Choice)

WIDGET_CLASS(Fl_Sys_Menu_Bar)

WIDGET_DEFINE(Fl_Sys_Menu_Bar)

MENU_DEFINE(Fl_Sys_Menu_Bar)

Fl_Menu_Item *Fl_Menu_Item_new(char **args, int sz) {
    LOCK(Fl_Menu_Item *items = new Fl_Menu_Item[sz + 1]; if (!items) return NULL;
         for (int i = 0; i < sz; i++) { items[i] = {args[i]}; } items[sz] = {NULL};)
    return items;
}

void Fl_Menu_Item_delete(Fl_Menu_Item *self) {
    delete[] self;
}

const Fl_Menu_Item *Fl_Menu_Item_popup(Fl_Menu_Item *self, int x, int y) {
    LOCK(auto ret = self->popup(x, y);) return ret;
}

const char *Fl_Menu_Item_label(Fl_Menu_Item *self) {
    LOCK(auto ret = self->label();) return ret;
}

void Fl_Menu_Item_set_label(Fl_Menu_Item *self, const char *a) {
    LOCK(self->label(a);)
}

int Fl_Menu_Item_label_type(Fl_Menu_Item *self) {
    LOCK(auto ret = self->labeltype();) return ret;
}

void Fl_Menu_Item_set_label_type(Fl_Menu_Item *self, int a) {
    LOCK(self->labeltype(static_cast<Fl_Labeltype>(a));)
}

unsigned int Fl_Menu_Item_label_color(Fl_Menu_Item *self) {
    LOCK(auto ret = self->labelcolor();) return ret;
}

void Fl_Menu_Item_set_label_color(Fl_Menu_Item *self, unsigned int a) {
    LOCK(self->labelcolor(a);)
}

int Fl_Menu_Item_label_font(Fl_Menu_Item *self) {
    LOCK(auto ret = self->labelfont();) return ret;
}

void Fl_Menu_Item_set_label_font(Fl_Menu_Item *self, int a) {
    LOCK(self->labelfont(a);)
}

int Fl_Menu_Item_label_size(Fl_Menu_Item *self) {
    LOCK(auto ret = self->labelsize();) return ret;
}

void Fl_Menu_Item_set_label_size(Fl_Menu_Item *self, int a) {
    LOCK(self->labelsize(a);)
}

int Fl_Menu_Item_value(Fl_Menu_Item *self) {
    LOCK(auto ret = self->value();) return ret;
}

void Fl_Menu_Item_set(Fl_Menu_Item *self) {
    LOCK(self->set();)
}

void Fl_Menu_Item_clear(Fl_Menu_Item *self) {
    LOCK(self->clear();)
}

int Fl_Menu_Item_visible(Fl_Menu_Item *self) {
    LOCK(auto ret = self->visible();) return ret;
}

void Fl_Menu_Item_show(Fl_Menu_Item *self) {
    LOCK(self->show();)
}

void Fl_Menu_Item_hide(Fl_Menu_Item *self) {
    LOCK(self->hide();)
}

int Fl_Menu_Item_active(Fl_Menu_Item *self) {
    LOCK(auto ret = self->active();) return ret;
}

void Fl_Menu_Item_activate(Fl_Menu_Item *self) {
    LOCK(self->activate();)
}

void Fl_Menu_Item_deactivate(Fl_Menu_Item *self) {
    LOCK(self->deactivate();)
}

int Fl_Menu_Item_submenu(const Fl_Menu_Item *self) {
    LOCK(auto ret = self->submenu();) return ret;
}

int Fl_Menu_Item_checkbox(const Fl_Menu_Item *self) {
    LOCK(auto ret = self->checkbox();) return ret;
}

int Fl_Menu_Item_radio(const Fl_Menu_Item *self) {
    LOCK(auto ret = self->radio();) return ret;
}

Fl_Menu_Item *Fl_Menu_Item_next(Fl_Menu_Item *self, int idx) {
    LOCK(auto ret = self->next(idx);) return ret;
}

void Fl_Menu_Item_set_callback(Fl_Menu_Item *self, Fl_Callback *c, void *p) {
    LOCK(self->callback(c, p);)
}

void *Fl_Menu_Item_user_data(const Fl_Menu_Item *self) {
    LOCK(auto ret = self->user_data();) return ret;
}

void Fl_Menu_Item_set_user_data(Fl_Menu_Item *self, void *data) {
    LOCK(self->user_data(data);)
}

void Fl_Menu_Item_draw(const Fl_Menu_Item *self, int x, int y, int w, int h, const void *m,
                       int selected) {
    fl_open_display();
    LOCK(self->draw(x, y, w, h, (const Fl_Menu_ *)m, selected);)
}

int Fl_Menu_Item_measure(const Fl_Menu_Item *self, int *hp, const void *m) {
    LOCK(auto ret = self->measure(hp, (const Fl_Menu_ *)m));
    return ret;
}

void Fl_Menu_Item_image(Fl_Menu_Item *self, void *image) {
    LOCK(self->image((Fl_Image *)image))
}
