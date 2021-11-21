#include "cfl_image.h"
#include "cfl_lock.h"

#include <FL/Fl.H>
#include <FL/Fl_BMP_Image.H>
#include <FL/Fl_GIF_Image.H>
#include <FL/Fl_Image.H>
#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_PNM_Image.H>
#include <FL/Fl_Pixmap.H>
#include <FL/Fl_RGB_Image.H>
#include <FL/Fl_SVG_Image.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_Tiled_Image.H>
#include <FL/Fl_XBM_Image.H>
#include <FL/Fl_XPM_Image.H>
#include <stdlib.h>

#define IMAGE_DEFINE(image)                                                                        \
    void image##_draw(image *self, int X, int Y, int W, int H) {                                   \
        LOCK(self->draw(X, Y, W, H));                                                              \
    }                                                                                              \
    void image##_draw_ext(image *self, int X, int Y, int W, int H, int cx, int cy) {               \
        LOCK(self->draw(X, Y, W, H, cx, cy));                                                      \
    }                                                                                              \
    int image##_width(image *self) {                                                               \
        LOCK(auto ret = self->w());                                                                \
        return ret;                                                                                \
    }                                                                                              \
    int image##_height(image *self) {                                                              \
        LOCK(auto ret = self->h());                                                                \
        return ret;                                                                                \
    }                                                                                              \
    void image##_delete(image *self) {                                                             \
        delete self;                                                                               \
    }                                                                                              \
    int image##_count(image *self) {                                                               \
        LOCK(auto ret = self->count());                                                            \
        return ret;                                                                                \
    }                                                                                              \
    const char *const *image##_data(image *self) {                                                 \
        LOCK(auto ret = self->data());                                                             \
        return ret;                                                                                \
    }                                                                                              \
    image *image##_copy(image *self) {                                                             \
        return (image *)self->copy();                                                              \
    }                                                                                              \
    void image##_scale(image *self, int width, int height, int proportional, int can_expand) {     \
        LOCK(self->scale(width, height, proportional, can_expand));                                \
    }                                                                                              \
    int image##_fail(image *self) {                                                                \
        LOCK(auto ret = self->fail());                                                             \
        return ret;                                                                                \
    }                                                                                              \
    int image##_data_w(const image *self) {                                                        \
        LOCK(auto ret = self->data_w());                                                           \
        return ret;                                                                                \
    }                                                                                              \
    int image##_data_h(const image *self) {                                                        \
        LOCK(auto ret = self->data_h());                                                           \
        return ret;                                                                                \
    }                                                                                              \
    int image##_d(const image *self) {                                                             \
        LOCK(auto ret = self->d());                                                                \
        return ret;                                                                                \
    }                                                                                              \
    int image##_ld(const image *self) {                                                            \
        LOCK(auto ret = self->ld());                                                               \
        return ret;                                                                                \
    }                                                                                              \
    void image##_inactive(image *self) {                                                           \
        LOCK(self->inactive());                                                                    \
    }

void Fl_Image_set_scaling_algorithm(int algorithm) {
    LOCK(Fl_Image::scaling_algorithm((Fl_RGB_Scaling)algorithm));
}

int Fl_Image_scaling_algorithm(void) {
    LOCK(auto ret = Fl_Image::scaling_algorithm());
    return (int)ret;
}

IMAGE_DEFINE(Fl_JPEG_Image)

Fl_JPEG_Image *Fl_JPEG_Image_new(const char *filename) {
    LOCK(auto ret = new Fl_JPEG_Image(filename));
    return ret;
}

Fl_JPEG_Image *Fl_JPEG_Image_from(const unsigned char *data) {
    LOCK(auto ret = new Fl_JPEG_Image(NULL, data));
    return ret;
}

IMAGE_DEFINE(Fl_Image)

IMAGE_DEFINE(Fl_PNG_Image)

Fl_PNG_Image *Fl_PNG_Image_new(const char *filename) {
    LOCK(auto ret = new Fl_PNG_Image(filename));
    return ret;
}

Fl_PNG_Image *Fl_PNG_Image_from(const unsigned char *data, int size) {
    LOCK(auto ret = new Fl_PNG_Image(NULL, data, size));
    return ret;
}

IMAGE_DEFINE(Fl_SVG_Image)

Fl_SVG_Image *Fl_SVG_Image_new(const char *filename) {
    LOCK(auto ret = new Fl_SVG_Image(filename));
    return ret;
}

Fl_SVG_Image *Fl_SVG_Image_from(const char *data) {
    LOCK(auto ret = new Fl_SVG_Image(NULL, data));
    return ret;
}

void Fl_SVG_Image_normalize(Fl_SVG_Image *self) {
    LOCK(self->normalize());
}

IMAGE_DEFINE(Fl_BMP_Image)

Fl_BMP_Image *Fl_BMP_Image_new(const char *filename) {
    LOCK(auto ret = new Fl_BMP_Image(filename));
    return ret;
}

Fl_BMP_Image *Fl_BMP_Image_from(const unsigned char *data) {
    LOCK(auto ret = new Fl_BMP_Image(NULL, data));
    return ret;
}

IMAGE_DEFINE(Fl_GIF_Image)

Fl_GIF_Image *Fl_GIF_Image_new(const char *filename) {
    LOCK(auto ret = new Fl_GIF_Image(filename));
    return ret;
}

Fl_GIF_Image *Fl_GIF_Image_from(const unsigned char *data) {
    LOCK(auto ret = new Fl_GIF_Image(NULL, data));
    return ret;
}

IMAGE_DEFINE(Fl_Pixmap)

Fl_Pixmap *Fl_Pixmap_new(const char *const *D) {
    LOCK(auto ret = new Fl_Pixmap(D));
    return ret;
}

IMAGE_DEFINE(Fl_XPM_Image)

Fl_XPM_Image *Fl_XPM_Image_new(const char *filename) {
    LOCK(auto ret = new Fl_XPM_Image(filename));
    return ret;
}

IMAGE_DEFINE(Fl_XBM_Image)

Fl_XBM_Image *Fl_XBM_Image_new(const char *filename) {
    LOCK(auto ret = new Fl_XBM_Image(filename));
    return ret;
}

IMAGE_DEFINE(Fl_PNM_Image)

Fl_PNM_Image *Fl_PNM_Image_new(const char *filename) {
    LOCK(auto ret = new Fl_PNM_Image(filename));
    return ret;
}

IMAGE_DEFINE(Fl_Tiled_Image)

Fl_Tiled_Image *Fl_Tiled_Image_new(Fl_Image *i, int w, int h) {
    LOCK(auto ret = new Fl_Tiled_Image(i, w, h));
    return ret;
}

IMAGE_DEFINE(Fl_RGB_Image)

Fl_RGB_Image *Fl_RGB_Image_new(const unsigned char *bits, int W, int H, int depth, int ld) {
    int temp = 0;
    if (ld == 0) {
        temp = abs(W * depth);
    } else {
        temp = abs(ld);
    }
    auto sz = abs(temp * H);
    unsigned char *arr = new unsigned char[sz];
    if (!arr)
        return NULL;
    memset(arr, 0, sz);
    memcpy(arr, bits, sz);
    LOCK(Fl_RGB_Image *img = new Fl_RGB_Image(arr, W, H, depth, ld); if (!img) return NULL;
         img->alloc_array = 1);
    return img;
}

Fl_RGB_Image *Fl_RGB_Image_from_data(const unsigned char *bits, int W, int H, int depth, int ld) {
    LOCK(Fl_RGB_Image *img = new Fl_RGB_Image(bits, W, H, depth, ld); if (!img) return NULL;
         img->alloc_array = 0);
    return img;
}

extern int fl_convert_pixmap(const char *const *cdata, unsigned char *out, unsigned int bg);

Fl_RGB_Image *Fl_RGB_Image_from_pixmap(const Fl_Pixmap *pxm) {
    auto rgb = new Fl_RGB_Image(0, pxm->data_w(), pxm->data_h(), 4);
    if (pxm && pxm->data_w() > 0 && pxm->data_h() > 0) {
        rgb->array = new uchar[pxm->data_w() * pxm->data_h() * rgb->d()];
        rgb->alloc_array = 1;
        fl_convert_pixmap(pxm->data(), (uchar *)rgb->array, 49);
    }
    rgb->scale(pxm->w(), pxm->h(), 0, 1);
    return rgb;
}

void Fl_Shared_Image_draw(Fl_Shared_Image *self, int X, int Y, int W, int H) {
    LOCK(self->draw(X, Y, W, H));
}

void Fl_Shared_Image_draw_ext(Fl_Shared_Image *self, int X, int Y, int W, int H, int cx, int cy) {
    LOCK(self->draw(X, Y, W, H, cx, cy));
}

int Fl_Shared_Image_width(Fl_Shared_Image *self) {
    LOCK(auto ret = self->w());
    return ret;
}

int Fl_Shared_Image_height(Fl_Shared_Image *self) {
    LOCK(auto ret = self->h());
    return ret;
}

void Fl_Shared_Image_delete(Fl_Shared_Image *self) {
    LOCK(self->release());
}

int Fl_Shared_Image_count(Fl_Shared_Image *self) {
    LOCK(auto ret = self->count());
    return ret;
}

const char *const *Fl_Shared_Image_data(Fl_Shared_Image *self) {
    LOCK(auto ret = self->data());
    return ret;
}

Fl_Shared_Image *Fl_Shared_Image_copy(Fl_Shared_Image *self) {
    LOCK(auto ret = (Fl_Shared_Image *)self->copy());
    return ret;
}

void Fl_Shared_Image_scale(Fl_Shared_Image *self, int width, int height, int proportional,
                           int can_expand) {
    LOCK(self->scale(width, height, proportional, can_expand));
}

Fl_Shared_Image *Fl_Shared_Image_get(const char *name, int W, int H) {
    LOCK(auto ret = Fl_Shared_Image::get(name, W, H));
    return ret;
}

Fl_Shared_Image *Fl_Shared_Image_from_rgb(Fl_RGB_Image *rgb, int own_it) {
    LOCK(auto ret = Fl_Shared_Image::get(rgb, own_it));
    return ret;
}

int Fl_Shared_Image_fail(Fl_Shared_Image *self) {
    LOCK(auto ret = self->fail());
    return ret;
}

int Fl_Shared_Image_data_w(const Fl_Shared_Image *self) {
    LOCK(auto ret = self->data_w());
    return ret;
}

int Fl_Shared_Image_data_h(const Fl_Shared_Image *self) {
    LOCK(auto ret = self->data_h());
    return ret;
}

int Fl_Shared_Image_d(const Fl_Shared_Image *self) {
    LOCK(auto ret = self->d());
    return ret;
}

int Fl_Shared_Image_ld(const Fl_Shared_Image *self) {
    LOCK(auto ret = self->ld());
    return ret;
}

void Fl_Shared_Image_inactive(Fl_Shared_Image *self) {
    LOCK(self->inactive());
}

void Fl_register_images(void) {
    LOCK(fl_register_images());
}
