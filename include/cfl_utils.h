#ifndef __CFL_UTILS_H__
#define __CFL_UTILS_H__

#ifdef __cplusplus
extern "C" {
#endif

int Fl_filename_expand(char *out, int len, const char *in);

const char *Fl_type_name(void *w);

#ifdef __cplusplus
}
#endif
#endif
