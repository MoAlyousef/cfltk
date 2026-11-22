#include <cfltk/cfl_browser.h>
#include <cfltk/cfl_image.h>

#include <FL/Fl_Hold_Browser.H>
#include <FL/Fl_RGB_Image.H>
#include <FL/Fl_Shared_Image.H>

#include <cstdio>
#include <cstdlib>

static void check(bool condition, const char *message) {
    if (!condition) {
        std::fprintf(stderr, "%s\n", message);
        std::abort();
    }
}

int main() {
    const unsigned char pixel[] = {255, 0, 0};
    Fl_RGB_Image rgb(pixel, 1, 1, 3);
    auto shared = Fl_Shared_Image_from_rgb(&rgb, 1);
    Fl_Hold_Browser browser(0, 0, 100, 100);

    // Copies of a shared image retain the same object, unlike ordinary images.
    for (int iteration = 0; iteration < 10; iteration++) {
        Fl_Hold_Browser_add(&browser, "first");
        Fl_Hold_Browser_add(&browser, "second");
        Fl_Hold_Browser_set_icon(&browser, 1, shared);
        Fl_Hold_Browser_set_icon(&browser, 2, shared);
        check(shared->refcount() == 3, "each row must retain the shared image");
        Fl_Hold_Browser_clear(&browser);
        check(
            shared->refcount() == 1,
            "clear must release only the row references"
        );
    }

    Fl_Hold_Browser_add(&browser, "icon");
    Fl_Hold_Browser_set_icon(&browser, 1, shared);
    Fl_Hold_Browser_set_icon(&browser, 1, shared);
    check(
        shared->refcount() == 2,
        "replacing an icon must release its old reference"
    );

    Fl_Hold_Browser_set_icon(&browser, 1, nullptr);
    check(
        shared->refcount() == 1,
        "setting a null icon must release its reference"
    );
    check(browser.icon(1) == nullptr, "setting a null icon must detach it");

    Fl_Hold_Browser_set_icon(&browser, 1, shared);
    Fl_Hold_Browser_remove_icon(&browser, 1);
    check(
        shared->refcount() == 1, "removing an icon must release its reference"
    );
    check(browser.icon(1) == nullptr, "removing an icon must detach it");
    Fl_Hold_Browser_remove_icon(&browser, 1);

    Fl_Hold_Browser_set_icon(&browser, 1, shared);
    Fl_Hold_Browser_remove(&browser, 1);
    check(
        shared->refcount() == 1,
        "removing a row must release its icon reference"
    );
    shared->release();

    // The browser can also own the last reference when a row is removed.
    shared = Fl_Shared_Image_from_rgb(&rgb, 1);
    Fl_Hold_Browser_add(&browser, "last reference");
    Fl_Hold_Browser_set_icon(&browser, 1, shared);
    shared->release();
    Fl_Hold_Browser_remove(&browser, 1);

    // Ordinary images must still be copied and freed by the same operations.
    Fl_Hold_Browser_add(&browser, "rgb");
    Fl_Hold_Browser_set_icon(&browser, 1, &rgb);
    check(browser.icon(1) != &rgb, "ordinary icons must be copied");
    Fl_Hold_Browser_set_icon(&browser, 1, &rgb);
    Fl_Hold_Browser_remove_icon(&browser, 1);
    Fl_Hold_Browser_set_icon(&browser, 1, &rgb);
    Fl_Hold_Browser_set_icon(&browser, 1, nullptr);
    Fl_Hold_Browser_set_icon(&browser, 1, &rgb);
    Fl_Hold_Browser_remove(&browser, 1);
    Fl_Hold_Browser_add(&browser, "rgb");
    Fl_Hold_Browser_set_icon(&browser, 1, &rgb);
    Fl_Hold_Browser_clear(&browser);
}
