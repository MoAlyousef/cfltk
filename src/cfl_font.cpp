#include <FL/Fl.H> // Has to be the first include!

#include "cfl.h"

#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#ifdef _WIN32
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0501 /* need at least WinXP for this API, I think */
#endif
#define i_load_private_font(PATH) AddFontResourceEx((PATH), FR_PRIVATE, 0)
#define v_unload_private_font(PATH) RemoveFontResourceEx((PATH), FR_PRIVATE, 0)
#include <windows.h>
#elif __APPLE__
#include <ApplicationServices/ApplicationServices.h>
static int i_load_private_font(const char *pf) {
    int result = 0;
    CFErrorRef err;
    // Make a URL from the font name given
    CFURLRef fontURL = CFURLCreateFromFileSystemRepresentation(
        kCFAllocatorDefault, (const UInt8 *)pf, strlen(pf), false);
    // Try to load the font file
    if (CTFontManagerRegisterFontsForURL(fontURL, kCTFontManagerScopeProcess, &err)) {
        result = 1; // OK, we loaded the font, set this non-zero
    } else {
        printf("Failed loading font: %s\n", pf);
    }
    // discard the fontURL
    if (fontURL)
        CFRelease(fontURL);
    return result;
} // i_load_private_font

static void v_unload_private_font(const char *pf) {
    CFErrorRef err;
    // Make a URL from the font name given
    CFURLRef fontURL = CFURLCreateFromFileSystemRepresentation(
        kCFAllocatorDefault, (const UInt8 *)pf, strlen(pf), false);
    // Try to unregister the font
    CTFontManagerUnregisterFontsForURL(fontURL, kCTFontManagerScopeProcess, &err);
    if (fontURL)
        CFRelease(fontURL);
} // v_unload_private_font
#elif __ANDROID__
// Nothing!
#else /* Assume X11 with XFT/fontconfig - this will break on systems using legacy Xlib fonts */
#include <fontconfig/fontconfig.h>
#define USE_XFT 1
#define i_load_private_font(PATH) (int)FcConfigAppFontAddFile(NULL, (const FcChar8 *)(PATH))
#define v_unload_private_font(PATH) FcConfigAppFontClear(NULL)
#endif

#if !defined(__ANDROID__)
#define STB_TRUETYPE_IMPLEMENTATION
#include "stb_truetype.h"
#endif

#if defined(_MSC_VER) && _MSC_VER < 1900
#define snprintf _snprintf
#endif

const char *Fl_load_font(const char *path) {
#if !defined(__ANDROID__)
    stbtt_fontinfo font;
    FILE *fptr = fopen(path, "rb");
    if (!fptr)
        return nullptr;
    if (fseek(fptr, 0, SEEK_END)) {
        fclose(fptr);
        return nullptr;
    }
    size_t fsize = ftell(fptr);
    rewind(fptr);
    unsigned char *buffer = (unsigned char *)malloc(fsize);
    if (!buffer) {
        fclose(fptr);
        return nullptr;
    }
    size_t sz = fread(buffer, 1, fsize, fptr);
    fclose(fptr);
    if (sz != fsize) {
        free(buffer);
        return nullptr;
    }
    int init_ret = stbtt_InitFont(&font, buffer, stbtt_GetFontOffsetForIndex(buffer, 0));
    if (!init_ret) {
        free(buffer);
        return nullptr;
    }
    int length = 0;

    const char *info = stbtt_GetFontNameString(&font, &length, STBTT_PLATFORM_ID_MAC,
                                               STBTT_MAC_EID_ROMAN, STBTT_MAC_LANG_ENGLISH, 4);

    char *str = (char *)malloc(length + 1);
    snprintf(str, length + 1, "%s", info);
    auto ret = i_load_private_font(path);
    int f = 16;
    if (ret) {
        Fl::set_font(f, str);
    }
    free(buffer);
    return str;
#else
    return NULL;
#endif
}

void Fl_unload_font(const char *path) {
#if !defined(__ANDROID__)
    v_unload_private_font(path);
#endif
}
