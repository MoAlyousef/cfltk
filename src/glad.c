// Modified from https://github.com/maeln/gl_loader
/*
 * This file his an extract from glad: https://glad.dav1d.de/
 */

#include <stdlib.h>

#if defined(_WIN32) && !defined(APIENTRY) && !defined(__CYGWIN__) &&           \
    !defined(__SCITECH_SNAP__)
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN 1
#endif
#ifndef NOMINMAX
#define NOMINMAX 1
#endif
#endif

void *get_proc(const char *namez);

#if defined(_WIN32) || defined(__CYGWIN__)
#include <windows.h>
static HMODULE libGL;

typedef void *(*PFNWGLGETPROCADDRESSPROC_PRIVATE)(const char *);
static PFNWGLGETPROCADDRESSPROC_PRIVATE gladGetProcAddressPtr;

#ifdef _MSC_VER
#ifdef __has_include
#if __has_include(<winapifamily.h>)
#define HAVE_WINAPIFAMILY 1
#endif
#elif _MSC_VER >= 1700 && !_USING_V110_SDK71_
#define HAVE_WINAPIFAMILY 1
#endif
#endif

#ifdef HAVE_WINAPIFAMILY
#include <winapifamily.h>
#if !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) &&                      \
    WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)
#define IS_UWP 1
#endif
#endif

int open_gl(void) {
#ifndef IS_UWP
    libGL = LoadLibraryW(L"opengl32.dll");
    if (libGL != NULL) {
        void (*tmp)(void);
        tmp = (void (*)(void))GetProcAddress(libGL, "wglGetProcAddress");
        gladGetProcAddressPtr = (PFNWGLGETPROCADDRESSPROC_PRIVATE)tmp;
        return gladGetProcAddressPtr != NULL;
    }
#endif

    return 0;
}

void close_gl(void) {
    if (libGL != NULL) {
        FreeLibrary((HMODULE)libGL);
        libGL = NULL;
    }
}
#else
#include <dlfcn.h>
static void *libGL;

#if !defined(__APPLE__) && !defined(__HAIKU__)
typedef void *(*PFNGLXGETPROCADDRESSPROC_PRIVATE)(const char *);
static PFNGLXGETPROCADDRESSPROC_PRIVATE gladGetProcAddressPtr;
#endif

int open_gl(void) {
#ifdef __APPLE__
    static const char *NAMES[] = {
        "../Frameworks/OpenGL.framework/OpenGL",
        "/Library/Frameworks/OpenGL.framework/OpenGL",
        "/System/Library/Frameworks/OpenGL.framework/OpenGL",
        "/System/Library/Frameworks/OpenGL.framework/Versions/Current/OpenGL"
    };
#else
    static const char *NAMES[] = {"libGL.so.1", "libGL.so"};
#endif

    unsigned int index = 0;
    for (index = 0; index < (sizeof(NAMES) / sizeof(NAMES[0])); index++) {
        libGL = dlopen(NAMES[index], RTLD_NOW | RTLD_GLOBAL);

        if (libGL != NULL) {
#if defined(__APPLE__) || defined(__HAIKU__)
            return 1;
#else
            gladGetProcAddressPtr = (PFNGLXGETPROCADDRESSPROC_PRIVATE
            )dlsym(libGL, "glXGetProcAddressARB");
            return gladGetProcAddressPtr != NULL;
#endif
        }
    }

    return 0;
}

void close_gl(void) {
    if (libGL != NULL) {
        dlclose(libGL);
        libGL = NULL;
    }
}
#endif

void *get_proc(const char *namez) {
    void *result = NULL;
    if (libGL == NULL)
        return NULL;

#if !defined(__APPLE__) && !defined(__HAIKU__)
    if (gladGetProcAddressPtr != NULL) {
        result = gladGetProcAddressPtr(namez);
    }
#endif
    if (result == NULL) {
#if defined(_WIN32) || defined(__CYGWIN__)
        result = (void *)GetProcAddress((HMODULE)libGL, namez);
#else
        result = dlsym(libGL, namez);
#endif
    }

    return result;
}
