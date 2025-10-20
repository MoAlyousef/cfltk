#ifndef __CFL_UTILS_H__
#define __CFL_UTILS_H__

#ifdef __cplusplus
extern "C" {
#endif

int Fl_filename_expand(char *out, int len, const char *in);

const char *Fl_type_name(void *w);

int Fl_open_uri(const char *uri, char *msg, int msglen);

void Fl_decode_uri(char *uri);

#ifdef __cplusplus
}
#endif
#endif
