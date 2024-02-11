#include <cfl.h> // Fl_init_all, Fl_lock, Fl_run
#include <cfl_box.h>
#include <cfl_button.h>
#include <cfl_draw.h>
#include <cfl_enums.h>
#include <cfl_group.h>
#include <cfl_image.h> // Fl_register_images
#include <cfl_widget.h>
#include <cfl_window.h>
#include <stdio.h>
#include <stdlib.h>

#define BLUE 0x42A5F500
#define SEL_BLUE 0x3f51b500
#define GRAY 0x75757500
#define WIDTH 600
#define HEIGHT 400

// the button's callback
void cb(Fl_Widget *w, void *data) {
    Fl_Box *count = (Fl_Box *)data;
    int val       = atoi(Fl_Box_label(count));
    val++;
    char temp[12];
    snprintf(temp, sizeof(temp), "%d", val);
    Fl_Box_set_label(count, temp);
}

// the bar's custom drawn shadow
void draw(Fl_Widget *w, void *data) {
    Fl_set_color_rgb(211, 211, 211);
    Fl_rectf(0, Fl_Widget_height(w), Fl_Widget_width(w), 3);
}

int main(void) {
    Fl_init_all(); // init all styles
    Fl_Window *w = Fl_Window_new(100, 100, WIDTH, HEIGHT, "Flutter-like");
    Fl_Flex *col = Fl_Flex_new(0, 0, WIDTH, HEIGHT, NULL);
    Fl_Box *bar  = Fl_Box_new(0, 0, 0, 0, "  FLTK App!");
    Fl_Flex_set_size(col, (Fl_Widget *)bar, 60);
    Fl_Box_set_align(bar, Fl_Align_Left | Fl_Align_Inside);
    Fl_Box *text =
        Fl_Box_new(0, 0, 0, 0, "You have pushed the button this many times:");
    Fl_Box_set_align(text, Fl_Align_Bottom | Fl_Align_Inside);
    Fl_Box *count = Fl_Box_new(0, 0, 0, 0, "0");
    Fl_Box_set_align(count, Fl_Align_Top | Fl_Align_Inside);
    Fl_Flex *row = Fl_Flex_new(0, 0, 0, 0, NULL);
    Fl_Flex_set_type(row, 1); // row
    Fl_Flex_set_size(col, (Fl_Widget *)row, 60);
    Fl_Box_new(0, 0, 0, 0, NULL);
    Fl_Button *but =
        Fl_Button_new(WIDTH - 100, HEIGHT - 100, 60, 60, "@+6plus");
    Fl_Flex_set_size(row, (Fl_Widget *)but, 60);
    Fl_Box *spacing1 = Fl_Box_new(0, 0, 0, 0, NULL);
    Fl_Flex_set_size(row, (Fl_Widget *)spacing1, 20);
    Fl_Flex_end(row);
    Fl_Box *spacing2 = Fl_Box_new(0, 0, 0, 0, NULL);
    Fl_Flex_set_size(col, (Fl_Widget *)spacing2, 20);
    Fl_Flex_end(col);
    Fl_Window_end(w);
    Fl_Window_resizable(w, w);
    Fl_Window_show(w);

    Fl_background(255, 255, 255);
    Fl_set_visible_focus(0);

    Fl_Box_set_box(bar, Fl_BoxType_FlatBox);
    Fl_Box_set_label_size(bar, 22);
    Fl_Box_set_label_color(bar, Fl_Color_White);
    Fl_Box_set_color(bar, BLUE);
    Fl_Box_draw(bar, draw, NULL);

    Fl_Box_set_label_size(text, 18);
    Fl_Box_set_label_font(text, Fl_Font_Times);

    Fl_Box_set_label_size(count, 36);
    Fl_Box_set_label_color(count, GRAY);

    Fl_Button_set_color(but, BLUE);
    Fl_Button_set_selection_color(but, SEL_BLUE);
    Fl_Button_set_label_color(but, Fl_Color_White);
    Fl_Button_set_box(but, Fl_BoxType_OFlatBox);
    Fl_Button_set_callback(but, cb, count);
    return Fl_run();
}