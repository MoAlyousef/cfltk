#include <cfl.h> // Fl_init_all, Fl_lock, Fl_run
#include <cfl_button.h>
#include <cfl_group.h>
#include <cfl_image.h> // Fl_register_images
#include <cfl_widget.h>
#include <cfl_window.h>
#include <stdio.h>
#include <stdlib.h>

void cb(Fl_Widget *w, void *data) {
    Fl_Group *parent = Fl_Widget_parent(w);
    Fl_Widget_delete(w);
    Fl_Group_redraw(parent);
}

void dcb(Fl_Widget *w, void *data) {
    puts("deleted");
}

int main(void) {
    Fl_init_all();        // init all styles
    Fl_register_images(); // necessary for image support
    Fl_lock();            // necessary for multithreaded support
    Fl_Window *w = Fl_Window_new(100, 100, 400, 300, NULL);
    Fl_Button *b = Fl_Button_new(160, 210, 80, 40, "Click me");
    Fl_Button_set_deletion_callback(b, dcb, b);
    Fl_Window_end(w);
    Fl_Window_show(w);
    Fl_Button_set_callback(b, cb, NULL);
    return Fl_run();
}