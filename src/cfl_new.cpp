#include <stdlib.h>

#if defined(_MSC_VER) && _MSC_VER < 1900
#define noexcept
#endif

void *operator new(size_t size) {
    return malloc(size);
}

void *operator new[](size_t size) {
    return malloc(size);
}

void operator delete(void *val) noexcept {
    free(val);
}

void operator delete[](void *val) noexcept {
    free(val);
}
