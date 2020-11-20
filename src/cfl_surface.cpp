#include "cfl_surface.h"
#include "cfl_global.hpp"

#include "FL/Fl.H"
#include <FL/Fl_Image_Surface.H>
#include <FL/Fl_SVG_File_Surface.H>
#include <stdio.h>

void Fl_Surface_Device_set_current(Fl_Surface_Device *self) {
    LOCK(self->set_current())
}

int Fl_Surface_Device_is_current(Fl_Surface_Device *self) {
    return self->is_current();
}

Fl_Surface_Device *Fl_Surface_Device_surface(void) {
    return Fl_Surface_Device::surface();
}

void Fl_Surface_Device_push_current(Fl_Surface_Device *new_current){
    LOCK(Fl_Surface_Device::push_current(new_current))}

Fl_Surface_Device *Fl_Surface_Device_pop_current(void) {
    Fl_Surface_Device *ret = 0;
    LOCK(Fl_Surface_Device::pop_current());
    return ret;
}

Fl_Image_Surface *Fl_Image_Surface_new(int w, int h, int high_res) {
    return new Fl_Image_Surface(w, h, high_res);
}

void Fl_Image_Surface_delete(Fl_Image_Surface *s) {
    delete s;
}

void Fl_Image_Surface_set_current(Fl_Image_Surface *self) {
    LOCK(self->set_current())
}

int Fl_Image_Surface_is_current(Fl_Image_Surface *self) {
    return self->is_current();
}

void *Fl_Image_Surface_image(Fl_Image_Surface *self) {
    return self->image();
}

void *Fl_Image_Surface_highres_image(Fl_Image_Surface *self) {
    return self->highres_image();
}

void Fl_Image_Surface_origin(Fl_Image_Surface *self, int *x, int *y) {
    self->origin(x, y);
}

void Fl_Image_Surface_set_origin(Fl_Image_Surface *self, int x, int y) {
    LOCK(self->origin(x, y))
}

void Fl_Image_Surface_rescale(Fl_Image_Surface *self) {
    LOCK(self->rescale())
}

void Fl_Image_Surface_draw(Fl_Image_Surface *self, void *widget, int delta_x, int delta_y) {
    LOCK(self->draw((Fl_Widget *)widget, delta_x, delta_y))
}

void Fl_Image_Surface_draw_decorated_window(Fl_Image_Surface *self, void *widget, int delta_x,
                                            int delta_y){
    LOCK(self->draw_decorated_window((Fl_Window *)widget, delta_x, delta_y))}

Fl_SVG_File_Surface *Fl_SVG_File_Surface_new(int width, int height, const char *file) {
    FILE *f = fopen(file, "w");
    return new Fl_SVG_File_Surface(width, height, f);
}

void Fl_SVG_File_Surface_delete(Fl_SVG_File_Surface *self) {
    FILE *f = self->file();
    delete self;
    fclose(f);
}

void Fl_SVG_File_Surface_origin(Fl_SVG_File_Surface *self, int x, int y) {
    LOCK(self->origin(x, y))
}

int Fl_SVG_File_Surface_printable_rect(Fl_SVG_File_Surface *self, int *w, int *h) {
    return self->printable_rect(w, h);
}

void Fl_SVG_File_Surface_draw(Fl_SVG_File_Surface *self, void *widget, int delta_x, int delta_y) {
    LOCK(self->draw((Fl_Widget *)widget, delta_x, delta_y))
}

void Fl_SVG_File_Surface_draw_decorated_window(Fl_SVG_File_Surface *self, void *widget, int delta_x,
                                               int delta_y) {
    LOCK(self->draw_decorated_window((Fl_Window *)widget, delta_x, delta_y))
}