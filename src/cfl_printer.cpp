#include "cfl_printer.h"
#include "cfl_lock.h"
#include "cfl_widget.hpp"

#include "FL/Fl_Widget.H"
#include "FL/Fl_Window.H"
#include <FL/Fl_Printer.H>

Fl_Printer *Fl_Printer_new(void) {
    LOCK(auto ret = new Fl_Printer);
    return ret;
}

void Fl_Printer_delete(Fl_Printer *self) {
    delete self;
}

int Fl_Printer_begin_job(
    Fl_Printer *self,
    int pagecount,
    int *frompage,
    int *topage,
    char **perr_message
) {
    LOCK(auto ret = self->begin_job(pagecount, frompage, topage, perr_message));
    return ret;
}

int Fl_Printer_begin_page(Fl_Printer *self) {
    LOCK(auto ret = self->begin_page());
    return ret;
}

int Fl_Printer_printable_rect(Fl_Printer *self, int *w, int *h) {
    LOCK(auto ret = self->printable_rect(w, h));
    return ret;
}

void Fl_Printer_margins(
    Fl_Printer *self, int *left, int *top, int *right, int *bottom
) {
    LOCK(self->margins(left, top, right, bottom));
}

void Fl_Printer_origin(Fl_Printer *self, int *x, int *y) {
    LOCK(self->origin(x, y));
}

void Fl_Printer_set_origin(Fl_Printer *self, int x, int y) {
    LOCK(self->origin(x, y));
}

void Fl_Printer_scale(Fl_Printer *self, float scale_x, float scale_y) {
    LOCK(self->scale(scale_x, scale_y));
}

void Fl_Printer_rotate(Fl_Printer *self, float angle) {
    LOCK(self->rotate(angle));
}

void Fl_Printer_translate(Fl_Printer *self, int x, int y) {
    LOCK(self->translate(x, y));
}

void Fl_Printer_untranslate(Fl_Printer *self) {
    LOCK(self->untranslate());
}

int Fl_Printer_end_page(Fl_Printer *self) {
    LOCK(auto ret = self->end_page());
    return ret;
}

void Fl_Printer_end_job(Fl_Printer *self) {
    LOCK(self->end_job());
}

void Fl_Printer_set_current(Fl_Printer *self) {
    LOCK(self->set_current());
}

int Fl_Printer_is_current(Fl_Printer *self) {
    LOCK(auto ret = self->is_current());
    return ret;
}

void Fl_Printer_print_widget(
    Fl_Printer *self, void *widget, int delta_x, int delta_y
) {
    LOCK(self->print_widget((Fl_Widget *)widget, delta_x, delta_y));
}

void Fl_Printer_print_window(
    Fl_Printer *self, void *win, int x_offset, int y_offset
) {
    LOCK(self->print_window((Fl_Window *)win, x_offset, y_offset));
}

void Fl_Printer_set_dialog_title(const char *msg) {
    LOCK(Fl_Printer::dialog_title = msg)
}

void Fl_Printer_set_dialog_printer(const char *msg) {
    LOCK(Fl_Printer::dialog_printer = msg)
}

void Fl_Printer_set_dialog_range(const char *msg) {
    LOCK(Fl_Printer::dialog_range = msg)
}

void Fl_Printer_set_dialog_copies(const char *msg) {
    LOCK(Fl_Printer::dialog_copies = msg)
}

void Fl_Printer_set_dialog_all(const char *msg) {
    LOCK(Fl_Printer::dialog_all = msg)
}

void Fl_Printer_set_dialog_pages(const char *msg) {
    LOCK(Fl_Printer::dialog_pages = msg)
}

void Fl_Printer_set_dialog_from(const char *msg) {
    LOCK(Fl_Printer::dialog_from = msg)
}

void Fl_Printer_set_dialog_to(const char *msg) {
    LOCK(Fl_Printer::dialog_to = msg)
}

void Fl_Printer_set_dialog_properties(const char *msg) {
    LOCK(Fl_Printer::dialog_properties = msg)
}

void Fl_Printer_set_dialog_copyNo(const char *msg) {
    LOCK(Fl_Printer::dialog_copyNo = msg)
}

void Fl_Printer_set_dialog_print_button(const char *msg) {
    LOCK(Fl_Printer::dialog_print_button = msg)
}

void Fl_Printer_set_dialog_cancel_button(const char *msg) {
    LOCK(Fl_Printer::dialog_cancel_button = msg)
}

void Fl_Printer_set_dialog_print_to_file(const char *msg) {
    LOCK(Fl_Printer::dialog_print_to_file = msg)
}

void Fl_Printer_set_property_title(const char *msg) {
    LOCK(Fl_Printer::property_title = msg)
}

void Fl_Printer_set_property_pagesize(const char *msg) {
    LOCK(Fl_Printer::property_pagesize = msg)
}

void Fl_Printer_set_property_mode(const char *msg) {
    LOCK(Fl_Printer::property_mode = msg)
}

void Fl_Printer_set_property_use(const char *msg) {
    LOCK(Fl_Printer::property_use = msg)
}

void Fl_Printer_set_property_save(const char *msg) {
    LOCK(Fl_Printer::property_save = msg)
}

void Fl_Printer_set_property_cancel(const char *msg) {
    LOCK(Fl_Printer::property_cancel = msg)
}
