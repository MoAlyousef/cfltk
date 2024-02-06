#include <cfl.h> // Fl_init_all, Fl_lock, Fl_run
#include <cfl_box.h>
#include <cfl_enums.h>
#include <cfl_image.h> // Fl_register_images
#include <cfl_window.h>

#define TRUE 1
#define FALSE 0
#define NULL (void *)0

int main(void) {
    Fl_register_images();
    Fl_Window *w = Fl_Window_new(100, 100, 400, 300, NULL);
    Fl_Box *b    = Fl_Box_new(0, 0, 400, 300, NULL);
    Fl_Window_end(w);
    Fl_Window_show(w);
    Fl_Window_set_color(w, Fl_Color_White);
    Fl_PNG_Image *i = Fl_PNG_Image_new("img.png");
    Fl_PNG_Image_scale(i, 400, 300, TRUE, FALSE);
    Fl_Box_set_image(b, i);
    return Fl_run();
}