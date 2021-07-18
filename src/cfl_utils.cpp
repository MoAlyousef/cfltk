#include "cfl_utils.h"

#include <FL/filename.H>

int Fl_filename_expand(char *out, int len, const char *in) {
    return fl_filename_expand(out, len, in);
}