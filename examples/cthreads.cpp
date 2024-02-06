#include "cfl.h"
#include "cfl_box.h"
#include "cfl_button.h"
#include "cfl_window.h"
#include <cstdio>
#include <stdexcept>
#include <string>
#include <thread>

using namespace std::chrono_literals;

void cb(Fl_Widget *w, void *data) {
    auto box = (Fl_Box *)data;
    std::thread writer([=] {
        for (int i = 0; i != 1000; i++) {
            std::this_thread::sleep_for(10ms);
            char buf[100];
            snprintf(buf, 100, "Hello %d", i);
            Fl_lock();
            Fl_Box_set_label(box, buf);
            Fl_awake();
            Fl_unlock();
        }
    });
    writer.detach();
    std::thread reader([=] {
        while (true) {
            std::this_thread::sleep_for(1000ms);
            Fl_lock();
            printf("%s\n", Fl_Box_label(box));
            fflush(stdout);
            Fl_awake();
            Fl_unlock();
        }
    });
    reader.detach();
}

int main() {
    Fl_lock();
    auto win = Fl_Window_new(100, 100, 400, 300, "");
    auto box = Fl_Box_new(0, 0, 400, 200, "Hello");
    auto but = Fl_Button_new(160, 210, 80, 40, "Click");
    Fl_Window_end(win);
    Fl_Window_show(win);
    Fl_Button_set_callback(but, cb, box);

    return Fl_run();
}