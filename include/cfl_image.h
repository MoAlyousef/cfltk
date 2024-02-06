#ifndef __CFL_IMAGE_H__
#define __CFL_IMAGE_H__

#ifdef __cplusplus
extern "C" {
#endif

#define IMAGE_DECLARE(image)                                                   \
    typedef struct image image;                                                \
    void image##_draw(image *, int X, int Y, int W, int H);                    \
    void image##_draw_ext(                                                     \
        image *, int X, int Y, int W, int H, int cx, int cy                    \
    );                                                                         \
    int image##_width(image *);                                                \
    int image##_height(image *);                                               \
    void image##_delete(image *);                                              \
    int image##_count(image *self);                                            \
    const char *const *image##_data(image *self);                              \
    image *image##_copy(image *self);                                          \
    image *image##_copy_sized(image *self, int W, int H);                      \
    void image##_scale(                                                        \
        image *self, int width, int height, int proportional, int can_expand   \
    );                                                                         \
    int image##_fail(image *self);                                             \
    int image##_data_w(const image *self);                                     \
    int image##_data_h(const image *self);                                     \
    int image##_d(const image *self);                                          \
    int image##_ld(const image *self);                                         \
    void image##_inactive(image *self);                                        \
    image *image##_from_dyn_ptr(Fl_Image *other);

IMAGE_DECLARE(Fl_Image)

void Fl_Image_set_scaling_algorithm(int algorithm);

int Fl_Image_scaling_algorithm(void);

void Fl_RGB_Image_set_scaling_algorithm(int algorithm);

int Fl_RGB_Image_scaling_algorithm(void);

IMAGE_DECLARE(Fl_JPEG_Image)

Fl_JPEG_Image *Fl_JPEG_Image_new(const char *filename);

Fl_JPEG_Image *Fl_JPEG_Image_from(const unsigned char *data);

IMAGE_DECLARE(Fl_PNG_Image)

Fl_PNG_Image *Fl_PNG_Image_new(const char *filename);

Fl_PNG_Image *Fl_PNG_Image_from(const unsigned char *data, int size);

IMAGE_DECLARE(Fl_SVG_Image)

Fl_SVG_Image *Fl_SVG_Image_new(const char *filename);

Fl_SVG_Image *Fl_SVG_Image_from(const char *data);

void Fl_SVG_Image_normalize(Fl_SVG_Image *self);

IMAGE_DECLARE(Fl_BMP_Image)

Fl_BMP_Image *Fl_BMP_Image_new(const char *filename);

Fl_BMP_Image *Fl_BMP_Image_from(const unsigned char *data, long len);

IMAGE_DECLARE(Fl_GIF_Image)

Fl_GIF_Image *Fl_GIF_Image_new(const char *filename);

Fl_GIF_Image *Fl_GIF_Image_from(const unsigned char *data, unsigned long len);

IMAGE_DECLARE(Fl_Anim_GIF_Image)

Fl_Anim_GIF_Image *
Fl_Anim_GIF_Image_new(const char *filename, void *canvas, unsigned short flags);

Fl_Anim_GIF_Image *Fl_Anim_GIF_Image_from(
    const char *imagename,
    const unsigned char *data,
    const unsigned long length,
    void *canvas,
    unsigned short flags
);

double Fl_Anim_GIF_Image_delay(const Fl_Anim_GIF_Image *self, int frame_);

void Fl_Anim_GIF_Image_set_delay(
    Fl_Anim_GIF_Image *self, int frame, double delay
);

int Fl_Anim_GIF_Image_is_animated(const Fl_Anim_GIF_Image *self);

void Fl_Anim_GIF_Image_set_speed(Fl_Anim_GIF_Image *self, double speed);

double Fl_Anim_GIF_Image_speed(Fl_Anim_GIF_Image *self);

int Fl_Anim_GIF_Image_start(Fl_Anim_GIF_Image *self);

int Fl_Anim_GIF_Image_stop(Fl_Anim_GIF_Image *self);

int Fl_Anim_GIF_Image_next(Fl_Anim_GIF_Image *self);

int Fl_Anim_GIF_Image_playing(const Fl_Anim_GIF_Image *self);

IMAGE_DECLARE(Fl_Pixmap)

Fl_Pixmap *Fl_Pixmap_new(const char *const *D);

IMAGE_DECLARE(Fl_XPM_Image)

Fl_XPM_Image *Fl_XPM_Image_new(const char *filename);

IMAGE_DECLARE(Fl_XBM_Image)

Fl_XBM_Image *Fl_XBM_Image_new(const char *filename);

IMAGE_DECLARE(Fl_PNM_Image)

Fl_PNM_Image *Fl_PNM_Image_new(const char *filename);

IMAGE_DECLARE(Fl_Tiled_Image)

Fl_Tiled_Image *Fl_Tiled_Image_new(Fl_Image *i, int w, int h);

IMAGE_DECLARE(Fl_RGB_Image)

Fl_RGB_Image *
Fl_RGB_Image_new(const unsigned char *bits, int W, int H, int depth, int ld);

Fl_RGB_Image *Fl_RGB_Image_from_data(
    const unsigned char *bits, int W, int H, int depth, int ld
);

Fl_RGB_Image *Fl_RGB_Image_from_pixmap(const Fl_Pixmap *image);

IMAGE_DECLARE(Fl_Shared_Image)

Fl_Shared_Image *Fl_Shared_Image_get(const char *name, int W, int H);

Fl_Shared_Image *Fl_Shared_Image_from_rgb(Fl_RGB_Image *rgb, int own_it);

IMAGE_DECLARE(Fl_ICO_Image)

Fl_ICO_Image *Fl_ICO_Image_new(const char *filename, int id);

Fl_ICO_Image *
Fl_ICO_Image_from_data(const unsigned char *bits, unsigned long len, int id);

void *const
Fl_ICO_Image_icondirentry(const Fl_ICO_Image *self, unsigned long *size);

void Fl_register_images(void);

#ifdef __cplusplus
}
#endif
#endif
