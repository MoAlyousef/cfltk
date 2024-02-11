
// Example for android themed app

#include <cfl.h> // Fl_init_all, Fl_lock, Fl_run
#include <cfl_button.h>
#include <cfl_enums.h>
#include <cfl_widget.h>
#include <cfl_window.h>
#include <stdlib.h>

void cb(Fl_Widget *w, void *data) {
    char buf[8];
    int v = atoi(Fl_Widget_label(w));
    v++;
    snprintf(buf, 8, "%d", v);
    Fl_Widget_set_label(w, buf);
}

int main(void) {
    Fl_init_all();
    Fl_Window *w = Fl_Window_new(0, 40, 600, 800 - 80, NULL);
    Fl_Button *b = Fl_Button_new(220, 500, 160, 80, "0");
    Fl_Window_end(w);
    Fl_Window_show(w);
    Fl_Window_set_color(w, Fl_Color_White);
    Fl_Button_set_color(b, Fl_Color_Magenta);
    Fl_Button_set_label_color(b, Fl_Color_White);
    Fl_Button_clear_visible_focus(b);
    Fl_Button_set_selection_color(b, Fl_Color_DarkMagenta);
    Fl_Button_set_box(b, Fl_BoxType_RFlatBox);
    Fl_Button_set_label_size(b, 36);
    Fl_Button_set_callback(b, cb, NULL);
    return Fl_run();
}
