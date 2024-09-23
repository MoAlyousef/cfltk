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

int Fl_open_uri(const char *uri, char *msg, int msglen) {
    return fl_open_uri(uri, msg, msglen);
}

void Fl_decode_uri(char *uri) {
    fl_decode_uri(uri);
}