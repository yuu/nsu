#ifndef NSU_DEBUG_UTILS
#define NSU_DEBUG_UTILS

#include <stdarg.h>

#include <cstdio>

namespace nsu {

__attribute__((format(printf, 1, 2))) static void log(const char* fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);
}

}  // namespace nsu

#endif
