#include <FL/Fl.H> // Has to be the first include!

#include "cfl.h"

#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
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
        kCFAllocatorDefault, (const UInt8 *)pf, strlen(pf), false
    );
    // Try to load the font file
    if (CTFontManagerRegisterFontsForURL(
            fontURL, kCTFontManagerScopeProcess, &err
        )) {
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
        kCFAllocatorDefault, (const UInt8 *)pf, strlen(pf), false
    );
    // Try to unregister the font
    CTFontManagerUnregisterFontsForURL(
        fontURL, kCTFontManagerScopeProcess, &err
    );
    if (fontURL)
        CFRelease(fontURL);
} // v_unload_private_font
#elif __ANDROID__
// Nothing!
#else /* Assume X11 with XFT/fontconfig - this will break on systems using     \
         legacy Xlib fonts */
#include <fontconfig/fontconfig.h>
#define USE_XFT 1
#define i_load_private_font(PATH)                                              \
    (int)FcConfigAppFontAddFile(nullptr, (const FcChar8 *)(PATH))
#define v_unload_private_font(PATH) FcConfigAppFontClear(nullptr)
#endif

#if defined(_MSC_VER) && _MSC_VER < 1900
#define snprintf _snprintf
#endif

int Fl_load_font(const char *path) {
#ifndef __ANDROID__
    return i_load_private_font(path);
#else
    return 0;
#endif
}

void Fl_unload_font(const char *path) {
#ifndef __ANDROID__
    v_unload_private_font(path);
#endif
}
