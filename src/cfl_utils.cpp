#include "cfl_utils.h"

#include <FL/Fl_Widget.H>
#include <FL/filename.H>
#include <typeinfo>

int Fl_filename_expand(char *out, int len, const char *in) {
    return fl_filename_expand(out, len, in);
}

const char *Fl_type_name(void *w) {
    return typeid(*(Fl_Widget *)w).name();
}