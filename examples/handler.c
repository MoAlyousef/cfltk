#include <cfl.h> // Fl_init_all
#include <cfl_box.h>
#include <cfl_button.h>
#include <cfl_enums.h> // EventNames, Event_PUSH
#include <cfl_window.h>
#include <stdio.h>
#include <stdlib.h>

int cb(Fl_Widget *w, int e, void *data) {
    switch (e) {
    case Fl_Event_Push:
        Fl_Box_set_label((Fl_Box *)data, "Hello");
        // return 1 when handled, 0 otherwise
        return 1;
    default:
        return 0;
    }
}

int main() {
    Fl_Window *w = Fl_Window_new(100, 100, 400, 300, NULL);
    Fl_Box *f    = Fl_Box_new(0, 0, 400, 200, NULL);
    Fl_Button *b = Fl_Button_new(160, 210, 80, 40, "Click me");
    Fl_Window_end(w);
    Fl_Window_show(w);
    Fl_Button_handle(b, cb, f);
    return Fl_run();
}
