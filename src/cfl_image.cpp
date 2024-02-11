#include "cfl_image.h"
#include "cfl_lock.h"
#include "cfl_widget.hpp"

#include <FL/Fl.H>
#include <FL/Fl_Anim_GIF_Image.H>
#include <FL/Fl_BMP_Image.H>
#include <FL/Fl_GIF_Image.H>
#include <FL/Fl_ICO_Image.H>
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

#define IMAGE_DEFINE(image)                                                    \
    void image##_draw(image *self, int X, int Y, int W, int H) {               \
        LOCK(self->draw(X, Y, W, H));                                          \
    }                                                                          \
    void image##_draw_ext(                                                     \
        image *self, int X, int Y, int W, int H, int cx, int cy                \
    ) {                                                                        \
        LOCK(self->draw(X, Y, W, H, cx, cy));                                  \
    }                                                                          \
    int image##_width(image *self) {                                           \
        LOCK(auto ret = self->w());                                            \
        return ret;                                                            \
    }                                                                          \
    int image##_height(image *self) {                                          \
        LOCK(auto ret = self->h());                                            \
        return ret;                                                            \
    }                                                                          \
    int image##_count(image *self) {                                           \
        LOCK(auto ret = self->count());                                        \
        return ret;                                                            \
    }                                                                          \
    const char *const *image##_data(image *self) {                             \
        LOCK(auto ret = self->data());                                         \
        return ret;                                                            \
    }                                                                          \
    image *image##_copy(image *self) {                                         \
        return (image *)self->copy();                                          \
    }                                                                          \
    image *image##_copy_sized(image *self, int W, int H) {                     \
        return (image *)self->copy(W, H);                                      \
    }                                                                          \
    void image##_scale(                                                        \
        image *self, int width, int height, int proportional, int can_expand   \
    ) {                                                                        \
        LOCK(self->scale(width, height, proportional, can_expand));            \
    }                                                                          \
    int image##_fail(image *self) {                                            \
        LOCK(auto ret = self->fail());                                         \
        return ret;                                                            \
    }                                                                          \
    int image##_data_w(const image *self) {                                    \
        LOCK(auto ret = self->data_w());                                       \
        return ret;                                                            \
    }                                                                          \
    int image##_data_h(const image *self) {                                    \
        LOCK(auto ret = self->data_h());                                       \
        return ret;                                                            \
    }                                                                          \
    int image##_d(const image *self) {                                         \
        LOCK(auto ret = self->d());                                            \
        return ret;                                                            \
    }                                                                          \
    int image##_ld(const image *self) {                                        \
        LOCK(auto ret = self->ld());                                           \
        return ret;                                                            \
    }                                                                          \
    void image##_inactive(image *self) {                                       \
        LOCK(self->inactive());                                                \
    }                                                                          \
    image *image##_from_dyn_ptr(Fl_Image *other) {                             \
        return dynamic_cast<image *>(other);                                   \
    }                                                                          \
    void image##_delete(image *self) {                                         \
        self->release();                                                       \
    }

void Fl_Image_set_scaling_algorithm(int algorithm) {
    LOCK(Fl_Image::scaling_algorithm((Fl_RGB_Scaling)algorithm));
}

int Fl_Image_scaling_algorithm(void) {
    LOCK(auto ret = Fl_Image::scaling_algorithm());
    return (int)ret;
}

void Fl_RGB_Image_set_scaling_algorithm(int algorithm) {
    LOCK(Fl_Image::RGB_scaling((Fl_RGB_Scaling)algorithm));
}

int Fl_RGB_Image_scaling_algorithm(void) {
    LOCK(auto ret = Fl_Image::RGB_scaling());
    return (int)ret;
}

IMAGE_DEFINE(Fl_JPEG_Image)

Fl_JPEG_Image *Fl_JPEG_Image_new(const char *filename) {
    LOCK(auto ret = new Fl_JPEG_Image(filename));
    return ret;
}

Fl_JPEG_Image *Fl_JPEG_Image_from(const unsigned char *data) {
    LOCK(auto ret = new Fl_JPEG_Image(nullptr, data));
    return ret;
}

IMAGE_DEFINE(Fl_Image)

IMAGE_DEFINE(Fl_PNG_Image)

Fl_PNG_Image *Fl_PNG_Image_new(const char *filename) {
    LOCK(auto ret = new Fl_PNG_Image(filename));
    return ret;
}

Fl_PNG_Image *Fl_PNG_Image_from(const unsigned char *data, int size) {
    LOCK(auto ret = new Fl_PNG_Image(nullptr, data, size));
    return ret;
}

IMAGE_DEFINE(Fl_SVG_Image)

Fl_SVG_Image *Fl_SVG_Image_new(const char *filename) {
    LOCK(auto ret = new Fl_SVG_Image(filename));
    return ret;
}

Fl_SVG_Image *Fl_SVG_Image_from(const char *data) {
    LOCK(auto ret = new Fl_SVG_Image(nullptr, data));
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

Fl_BMP_Image *Fl_BMP_Image_from(const unsigned char *data, long len) {
    LOCK(auto ret = new Fl_BMP_Image(nullptr, data, len));
    return ret;
}

IMAGE_DEFINE(Fl_GIF_Image)

Fl_GIF_Image *Fl_GIF_Image_new(const char *filename) {
    LOCK(auto ret = new Fl_GIF_Image(filename));
    return ret;
}

Fl_GIF_Image *Fl_GIF_Image_from(const unsigned char *data, unsigned long len) {
    LOCK(auto ret = new Fl_GIF_Image(nullptr, data, len));
    return ret;
}

IMAGE_DEFINE(Fl_Anim_GIF_Image)

Fl_Anim_GIF_Image *Fl_Anim_GIF_Image_new(
    const char *filename, void *canvas, unsigned short flags
) {
    LOCK(
        auto ret = new Fl_Anim_GIF_Image(filename, (Fl_Widget *)canvas, flags)
    );
    return ret;
}

Fl_Anim_GIF_Image *Fl_Anim_GIF_Image_from(
    const char *imagename,
    const unsigned char *data,
    const unsigned long length,
    void *canvas,
    unsigned short flags
) {
    LOCK(
        auto ret = new Fl_Anim_GIF_Image(
            imagename, data, length, (Fl_Widget *)canvas, flags
        )
    );
    return ret;
}

double Fl_Anim_GIF_Image_delay(const Fl_Anim_GIF_Image *self, int frame_) {
    LOCK(auto ret = self->delay(frame_));
    return ret;
}

void Fl_Anim_GIF_Image_set_delay(
    Fl_Anim_GIF_Image *self, int frame, double delay
) {
    LOCK(self->delay(frame, delay));
}

int Fl_Anim_GIF_Image_is_animated(const Fl_Anim_GIF_Image *self) {
    LOCK(auto ret = self->is_animated());
    return ret;
}

void Fl_Anim_GIF_Image_set_speed(Fl_Anim_GIF_Image *self, double speed) {
    LOCK(self->speed(speed));
}

double Fl_Anim_GIF_Image_speed(Fl_Anim_GIF_Image *self) {
    LOCK(auto ret = self->speed());
    return ret;
}

int Fl_Anim_GIF_Image_start(Fl_Anim_GIF_Image *self) {
    LOCK(auto ret = self->start());
    return ret;
}

int Fl_Anim_GIF_Image_stop(Fl_Anim_GIF_Image *self) {
    LOCK(auto ret = self->stop());
    return ret;
}

int Fl_Anim_GIF_Image_next(Fl_Anim_GIF_Image *self) {
    LOCK(auto ret = self->next());
    return ret;
}

int Fl_Anim_GIF_Image_playing(const Fl_Anim_GIF_Image *self) {
    LOCK(auto ret = self->playing());
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
    LOCK(auto ret = new Fl_Tiled_Image(i->copy(), w, h));
    return ret;
}

IMAGE_DEFINE(Fl_RGB_Image)

Fl_RGB_Image *
Fl_RGB_Image_new(const unsigned char *bits, int W, int H, int depth, int ld) {
    int temp = 0;
    if (ld == 0) {
        temp = abs(W * depth);
    } else {
        temp = abs(ld);
    }
    auto sz   = abs(temp * H);
    auto *arr = new unsigned char[sz];
    if (!arr)
        return nullptr;
    memset(arr, 0, sz);
    memcpy(arr, bits, sz);
    LOCK(auto *img = new Fl_RGB_Image(arr, W, H, depth, ld);
         if (!img) return nullptr;
         img->alloc_array = 1);
    return img;
}

Fl_RGB_Image *Fl_RGB_Image_from_data(
    const unsigned char *bits, int W, int H, int depth, int ld
) {
    LOCK(auto *img = new Fl_RGB_Image(bits, W, H, depth, ld);
         if (!img) return nullptr;
         img->alloc_array = 0);
    return img;
}

extern int fl_convert_pixmap(
    const char *const *cdata, unsigned char *out, unsigned int bg
);

Fl_RGB_Image *Fl_RGB_Image_from_pixmap(const Fl_Pixmap *pxm) {
    auto rgb = new Fl_RGB_Image(nullptr, pxm->data_w(), pxm->data_h(), 4);
    if (pxm && pxm->data_w() > 0 && pxm->data_h() > 0) {
        rgb->array       = new uchar[pxm->data_w() * pxm->data_h() * rgb->d()];
        rgb->alloc_array = 1;
        fl_convert_pixmap(pxm->data(), (uchar *)rgb->array, 49);
    }
    rgb->scale(pxm->w(), pxm->h(), 0, 1);
    return rgb;
}

IMAGE_DEFINE(Fl_Shared_Image)

Fl_Shared_Image *Fl_Shared_Image_get(const char *name, int W, int H) {
    LOCK(auto ret = Fl_Shared_Image::get(name, W, H));
    return ret;
}

Fl_Shared_Image *Fl_Shared_Image_from_rgb(Fl_RGB_Image *rgb, int own_it) {
    LOCK(auto ret = Fl_Shared_Image::get((Fl_RGB_Image *)rgb->copy(), own_it));
    return ret;
}

IMAGE_DEFINE(Fl_ICO_Image)

Fl_ICO_Image *Fl_ICO_Image_new(const char *filename, int id) {
    LOCK(auto ret = new Fl_ICO_Image(filename, id));
    return ret;
}

Fl_ICO_Image *
Fl_ICO_Image_from_data(const unsigned char *bits, unsigned long len, int id) {
    LOCK(auto ret = new Fl_ICO_Image(nullptr, id, bits, len));
    return ret;
}

void *const
Fl_ICO_Image_icondirentry(const Fl_ICO_Image *self, unsigned long *size) {
    LOCK(auto ret = self->icondirentry(); *size = self->idcount(););
    auto temp = new Fl_ICO_Image::IconDirEntry[*size];
    memcpy(temp, ret, *size);
    return temp;
}

void Fl_register_images(void) {
    LOCK(fl_register_images());
}
