#include <cfltk2/cfl.h> // Fl_init_all, Fl_lock, Fl_run
#include <cfltk2/cfl_button.h>
#include <cfltk2/cfl_image.h> // Fl_register_images
#include <cfltk2/cfl_widget.h>
#include <cfltk2/cfl_window.h>
#include <stdlib.h>

void cb(Fl_Widget *w, void *data) {
    Fl_Widget_set_label(w, "Works!");
}

int main(void) {
    Fl_init_all();        // init all styles
    Fl_register_images(); // necessary for image support
    Fl_lock();            // necessary for multithreaded support
    Fl_Window *w = Fl_Window_new(100, 100, 400, 300, NULL);
    Fl_Button *b = Fl_Button_new(160, 210, 80, 40, "Click me");
    Fl_Window_end(w);
    Fl_Window_show(w);
    Fl_Button_set_callback(b, cb, NULL);
    return Fl_run();
}