#include "cfl_dialog.h"
#include "cfl_lock.h"
#include "cfl_widget.hpp"

#include <FL/Fl.H>
#include <FL/Fl_Color_Chooser.H>
#include <FL/Fl_File_Chooser.H>
#include <FL/Fl_Help_Dialog.H>
#include <FL/Fl_Image.H>
#include <FL/Fl_Native_File_Chooser.H>
#include <FL/fl_ask.H>
#include <FL/platform.H>
#include <string.h>

Fl_Native_File_Chooser *Fl_Native_File_Chooser_new(int val) {
#ifndef __ANDROID__
    LOCK(auto ret = new Fl_Native_File_Chooser(val));
    return ret;
#else
    return nullptr;
#endif
}

void Fl_Native_File_Chooser_delete(Fl_Native_File_Chooser *self) {
    delete self;
}

const char *Fl_Native_File_Chooser_filename(Fl_Native_File_Chooser *self) {
    LOCK(const char *x = self->filename());
    if (!strcmp(x, ""))
        return nullptr;
    else
        return x;
}

const char *
Fl_Native_File_Chooser_filenames(Fl_Native_File_Chooser *self, int cnt) {
    LOCK(const char *x = self->filename(cnt));
    if (!strcmp(x, ""))
        return nullptr;
    else
        return x;
}

int Fl_Native_File_Chooser_count(Fl_Native_File_Chooser *self) {
    LOCK(auto ret = self->count());
    return ret;
}

void Fl_Native_File_Chooser_set_directory(
    Fl_Native_File_Chooser *self, const char *val
) {
    LOCK(self->directory(val));
}

const char *Fl_Native_File_Chooser_directory(Fl_Native_File_Chooser *self) {
    LOCK(auto ret = self->directory());
    return ret;
}

int Fl_Native_File_Chooser_show(Fl_Native_File_Chooser *self) {
    fl_open_display();
    LOCK(auto ret = self->show());
    return ret;
}

void Fl_Native_File_Chooser_set_option(Fl_Native_File_Chooser *self, int opt) {
    LOCK(self->options(opt));
}

void Fl_Native_File_Chooser_set_type(Fl_Native_File_Chooser *self, int typ) {
    LOCK(self->type(typ));
}

void Fl_Native_File_Chooser_set_title(
    Fl_Native_File_Chooser *self, const char *title
) {
    LOCK(self->title(title));
}

void Fl_Native_File_Chooser_set_filter(
    Fl_Native_File_Chooser *self, const char *f
) {
    LOCK(self->filter(f));
}

void Fl_Native_File_Chooser_set_preset_file(
    Fl_Native_File_Chooser *self, const char *f
) {
    LOCK(self->preset_file(f));
}

const char *Fl_Native_File_Chooser_errmsg(Fl_Native_File_Chooser *self) {
    LOCK(auto ret = self->errmsg());
    return ret;
}

void Fl_message(int x, int y, const char *txt) {
    LOCK(fl_message_position(x, y, 0); fl_message("%s", txt));
}

void Fl_message2(const char *txt) {
    LOCK(fl_message("%s", txt));
}

void Fl_alert(int x, int y, const char *txt) {
    LOCK(fl_message_position(x, y, 0); fl_alert("%s", txt));
}

void Fl_alert2(const char *txt) {
    LOCK(fl_alert("%s", txt));
}

int Fl_choice(
    int x,
    int y,
    const char *txt,
    const char *b0,
    const char *b1,
    const char *b2
) {
    LOCK(fl_message_position(x, y, 0); if (strlen(b2) == 0) b2 = nullptr;
         auto ret = fl_choice("%s", b0, b1, b2, txt));
    return ret;
}

int Fl_choice_n(
    int x,
    int y,
    const char *txt,
    const char *b0,
    const char *b1,
    const char *b2
) {
    LOCK(fl_message_position(x, y, 0); if (strlen(b2) == 0) b2 = nullptr;
         auto ret = fl_choice_n("%s", b0, b1, b2, txt));
    return ret;
}

int Fl_choice2(
    const char *txt, const char *b0, const char *b1, const char *b2
) {
    if (strlen(b2) == 0)
        b2 = nullptr;
    LOCK(auto ret = fl_choice("%s", b0, b1, b2, txt));
    return ret;
}

int Fl_choice2_n(
    const char *txt, const char *b0, const char *b1, const char *b2
) {
    if (strlen(b2) == 0)
        b2 = nullptr;
    LOCK(auto ret = fl_choice_n("%s", b0, b1, b2, txt));
    return ret;
}

const char *Fl_input(int x, int y, const char *txt, const char *deflt) {
    fl_message_position(x, y, 0);
    LOCK(auto ret = fl_input("%s", deflt, txt));
    return ret;
}

const char *Fl_input2(const char *txt, const char *deflt) {
    LOCK(auto ret = fl_input("%s", deflt, txt));
    return ret;
}

const char *Fl_password(int x, int y, const char *txt, const char *deflt) {
    fl_message_position(x, y, 0);
    LOCK(auto ret = fl_password("%s", deflt, txt));
    return ret;
}

const char *Fl_password2(const char *txt, const char *deflt) {
    LOCK(auto ret = fl_password("%s", deflt, txt));
    return ret;
}

Fl_Help_Dialog *Fl_Help_Dialog_new(void) {
    LOCK(auto ret = new Fl_Help_Dialog());
    return ret;
}

void Fl_Help_Dialog_delete(Fl_Help_Dialog *self) {
    delete self;
}

int Fl_Help_Dialog_h(Fl_Help_Dialog *self) {
    LOCK(auto ret = self->h());
    return ret;
}

void Fl_Help_Dialog_hide(Fl_Help_Dialog *self) {
    LOCK(self->hide());
}

int Fl_Help_Dialog_load(Fl_Help_Dialog *self, const char *f) {
    LOCK(auto ret = self->load(f));
    return ret;
}

void Fl_Help_Dialog_position(Fl_Help_Dialog *self, int xx, int yy) {
    LOCK(self->position(xx, yy));
}

void Fl_Help_Dialog_resize(
    Fl_Help_Dialog *self, int xx, int yy, int ww, int hh
) {
    LOCK(self->resize(xx, yy, ww, hh));
}

void Fl_Help_Dialog_show(Fl_Help_Dialog *self) {
    LOCK(self->show());
}

void Fl_Help_Dialog_set_text_size(Fl_Help_Dialog *self, int s) {
    LOCK(self->textsize(s));
}

int Fl_Help_Dialog_text_size(Fl_Help_Dialog *self) {
    LOCK(auto ret = self->textsize());
    return ret;
}

void Fl_Help_Dialog_set_value(Fl_Help_Dialog *self, const char *f) {
    LOCK(self->value(f));
}

const char *Fl_Help_Dialog_value(const Fl_Help_Dialog *self) {
    LOCK(auto ret = self->value());
    return ret;
}

int Fl_Help_Dialog_visible(Fl_Help_Dialog *self) {
    LOCK(auto ret = self->visible());
    return ret;
}

int Fl_Help_Dialog_w(Fl_Help_Dialog *self) {
    LOCK(auto ret = self->w());
    return ret;
}

int Fl_Help_Dialog_x(Fl_Help_Dialog *self) {
    LOCK(auto ret = self->x());
    return ret;
}

int Fl_Help_Dialog_y(Fl_Help_Dialog *self) {
    LOCK(auto ret = self->y());
    return ret;
}

void Fl_beep(int type) {
    LOCK(fl_beep(type));
}

Fl_File_Chooser *
Fl_File_Chooser_new(const char *d, const char *p, int t, const char *title) {
    LOCK(auto ret = new Fl_File_Chooser(d, p, t, title));
    return ret;
}

void Fl_File_Chooser_delete(Fl_File_Chooser *self) {
    delete self;
}

void *Fl_File_Chooser_newButton(Fl_File_Chooser *self) {
    LOCK(auto ret = self->newButton);
    return ret;
}

void *Fl_File_Chooser_previewButton(Fl_File_Chooser *self) {
    LOCK(auto ret = self->previewButton);
    return ret;
}

void *Fl_File_Chooser_showHiddenButton(Fl_File_Chooser *self) {
    LOCK(auto ret = self->showHiddenButton);
    return ret;
}

void Fl_File_Chooser_set_callback(
    Fl_File_Chooser *self, void (*cb)(Fl_File_Chooser *, void *), void *d
) {
    LOCK(self->callback(cb, d));
}

void Fl_File_Chooser_set_color(Fl_File_Chooser *self, unsigned int c) {
    LOCK(self->color(c));
}

unsigned int Fl_File_Chooser_color(Fl_File_Chooser *self) {
    LOCK(auto ret = self->color());
    return ret;
}

int Fl_File_Chooser_count(Fl_File_Chooser *self) {
    LOCK(auto ret = self->count());
    return ret;
}

void Fl_File_Chooser_set_directory(Fl_File_Chooser *self, const char *d) {
    LOCK(self->directory(d));
}

char *Fl_File_Chooser_directory(Fl_File_Chooser *self) {
    LOCK(auto ret = self->directory());
    return ret;
}

void Fl_File_Chooser_set_filter(Fl_File_Chooser *self, const char *p) {
    LOCK(self->filter(p));
}

const char *Fl_File_Chooser_filter(Fl_File_Chooser *self) {
    LOCK(auto ret = self->filter());
    return ret;
}

int Fl_File_Chooser_filter_value(Fl_File_Chooser *self) {
    LOCK(auto ret = self->filter_value());
    return ret;
}

void Fl_File_Chooser_set_filter_value(Fl_File_Chooser *self, int f) {
    LOCK(self->filter_value(f));
}

void Fl_File_Chooser_hide(Fl_File_Chooser *self) {
    LOCK(self->hide());
}

void Fl_File_Chooser_set_iconsize(Fl_File_Chooser *self, unsigned char s) {
    LOCK(self->iconsize(s));
}

unsigned char Fl_File_Chooser_iconsize(Fl_File_Chooser *self) {
    LOCK(auto ret = self->iconsize());
    return ret;
}

void Fl_File_Chooser_set_label(Fl_File_Chooser *self, const char *l) {
    LOCK(self->label(l));
}

const char *Fl_File_Chooser_label(Fl_File_Chooser *self) {
    LOCK(auto ret = self->label());
    return ret;
}

void Fl_File_Chooser_set_ok_label(Fl_File_Chooser *self, const char *l) {
    LOCK(self->ok_label(l));
}

const char *Fl_File_Chooser_ok_label(Fl_File_Chooser *self) {
    LOCK(auto ret = self->ok_label());
    return ret;
}

void Fl_File_Chooser_set_preview(Fl_File_Chooser *self, int e) {
    LOCK(self->preview(e));
}

int Fl_File_Chooser_preview(const Fl_File_Chooser *self) {
    LOCK(auto ret = self->preview());
    return ret;
}

void Fl_File_Chooser_rescan(Fl_File_Chooser *self) {
    LOCK(self->rescan());
}

void Fl_File_Chooser_rescan_keep_filename(Fl_File_Chooser *self) {
    LOCK(self->rescan_keep_filename());
}

void Fl_File_Chooser_show(Fl_File_Chooser *self) {
    LOCK(self->show());
}

int Fl_File_Chooser_shown(Fl_File_Chooser *self) {
    LOCK(auto ret = self->shown());
    return ret;
}

void Fl_File_Chooser_set_text_color(Fl_File_Chooser *self, unsigned int c) {
    LOCK(self->textcolor(c));
}

unsigned int Fl_File_Chooser_text_color(Fl_File_Chooser *self) {
    LOCK(auto ret = self->textcolor());
    return ret;
}

void Fl_File_Chooser_set_text_font(Fl_File_Chooser *self, int f) {
    LOCK(self->textfont(f));
}

int Fl_File_Chooser_text_font(Fl_File_Chooser *self) {
    LOCK(auto ret = self->textfont());
    return ret;
}

void Fl_File_Chooser_set_text_size(Fl_File_Chooser *self, int s) {
    LOCK(self->textsize(s));
}

int Fl_File_Chooser_text_size(Fl_File_Chooser *self) {
    LOCK(auto ret = self->textsize());
    return ret;
}

void Fl_File_Chooser_set_type(Fl_File_Chooser *self, int t) {
    LOCK(self->type(t));
}

int Fl_File_Chooser_type(Fl_File_Chooser *self) {
    LOCK(auto ret = self->type());
    return ret;
}

void *Fl_File_Chooser_user_data(const Fl_File_Chooser *self) {
    LOCK(auto ret = self->user_data());
    return ret;
}

void Fl_File_Chooser_set_user_data(Fl_File_Chooser *self, void *d) {
    LOCK(self->user_data(d));
}

const char *Fl_File_Chooser_value(Fl_File_Chooser *self, int f) {
    LOCK(auto ret = self->value(f));
    return ret;
}

void Fl_File_Chooser_set_value(Fl_File_Chooser *self, const char *filename) {
    LOCK(self->value(filename));
}

int Fl_File_Chooser_visible(Fl_File_Chooser *self) {
    LOCK(auto ret = self->visible());
    return ret;
}

void Fl_File_Chooser_set_add_favorites_label(const char *msg) {
    LOCK(Fl_File_Chooser::add_favorites_label = msg)
}

void Fl_File_Chooser_set_all_files_label(const char *msg) {
    LOCK(Fl_File_Chooser::all_files_label = msg)
}

void Fl_File_Chooser_set_custom_filter_label(const char *msg) {
    LOCK(Fl_File_Chooser::custom_filter_label = msg)
}

void Fl_File_Chooser_set_existing_file_label(const char *msg) {
    LOCK(Fl_File_Chooser::existing_file_label = msg)
}

void Fl_File_Chooser_set_favorites_label(const char *msg) {
    LOCK(Fl_File_Chooser::favorites_label = msg)
}

void Fl_File_Chooser_set_filename_label(const char *msg) {
    LOCK(Fl_File_Chooser::filename_label = msg)
}

void Fl_File_Chooser_set_filesystems_label(const char *msg) {
    LOCK(Fl_File_Chooser::filesystems_label = msg)
}

void Fl_File_Chooser_set_manage_favorites_label(const char *msg) {
    LOCK(Fl_File_Chooser::manage_favorites_label = msg)
}

void Fl_File_Chooser_set_new_directory_label(const char *msg) {
    LOCK(Fl_File_Chooser::new_directory_label = msg)
}

void Fl_File_Chooser_set_new_directory_tooltip(const char *msg) {
    LOCK(Fl_File_Chooser::new_directory_tooltip = msg)
}

void Fl_File_Chooser_set_preview_label(const char *msg) {
    LOCK(Fl_File_Chooser::preview_label = msg)
}

void Fl_File_Chooser_set_save_label(const char *msg) {
    LOCK(Fl_File_Chooser::save_label = msg)
}

void Fl_File_Chooser_set_show_label(const char *msg) {
    LOCK(Fl_File_Chooser::show_label = msg)
}

void Fl_File_Chooser_set_hidden_label(const char *msg) {
    LOCK(Fl_File_Chooser::hidden_label = msg)
}

void Fl_File_Chooser_set_position(Fl_File_Chooser *self, int x, int y) {
    LOCK(self->position(x, y));
}

void Fl_File_Chooser_set_size(Fl_File_Chooser *self, int w, int h) {
    LOCK(self->size(w, h));
}

int Fl_File_Chooser_x(const Fl_File_Chooser *self) {
    LOCK(auto ret = self->x());
    return ret;
}

int Fl_File_Chooser_y(const Fl_File_Chooser *self) {
    LOCK(auto ret = self->y());
    return ret;
}

int Fl_File_Chooser_w(const Fl_File_Chooser *self) {
    LOCK(auto ret = self->w());
    return ret;
}

int Fl_File_Chooser_h(const Fl_File_Chooser *self) {
    LOCK(auto ret = self->h());
    return ret;
}

char *Fl_dir_chooser(const char *message, const char *fname, int relative) {
    LOCK(auto ret = fl_dir_chooser(message, fname, relative));
    return ret;
}

char *Fl_file_chooser(
    const char *message, const char *pat, const char *fname, int relative
) {
    LOCK(auto ret = fl_file_chooser(message, pat, fname, relative));
    return ret;
}

int Fl_color_chooser(
    const char *name,
    unsigned char *r,
    unsigned char *g,
    unsigned char *b,
    int cmode
) {
    LOCK(auto ret = fl_color_chooser(name, *r, *g, *b, cmode));
    return ret;
}

void Fl_message_title(const char *title) {
    LOCK(fl_message_title(title));
}

void Fl_message_title_default(const char *title) {
    LOCK(fl_message_title_default(title));
}

void *Fl_message_icon(void) {
    LOCK(auto ret = fl_message_icon());
    return ret;
}

void Fl_message_set_hotspot(int enable) {
    LOCK(fl_message_hotspot(enable));
}

int Fl_message_hotspot(void) {
    LOCK(auto ret = fl_message_hotspot());
    return ret;
}

void Fl_message_set_font(int f, int s) {
    LOCK(fl_message_font((Fl_Font)f, (Fl_Fontsize)s));
}

void Fl_message_icon_label(const char *label) {
    LOCK(fl_message_icon_label(label));
}

#undef LOCK
