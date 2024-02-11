#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Window.H>
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
            Fl::lock();
            box->copy_label(buf);
            Fl::awake();
            Fl::unlock();
        }
    });
    writer.detach();
    std::thread reader([=] {
        while (true) {
            std::this_thread::sleep_for(1000ms);
            Fl::lock();
            printf("%s\n", box->label());
            fflush(stdout);
            Fl::awake();
            Fl::unlock();
        }
    });
    reader.detach();
}

int main() {
    Fl::lock();
    auto win = new Fl_Window(400, 300);
    auto box = new Fl_Box(0, 0, 400, 200, "Hello");
    auto but = new Fl_Button(160, 210, 80, 40, "Click");
    win->end();
    win->show();
    but->callback(cb, box);

    return Fl::run();
}