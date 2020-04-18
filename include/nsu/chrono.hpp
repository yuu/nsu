#ifndef NSU_CHRONO
#define NSU_CHRONO

#include <chrono>
#include <iostream>

namespace nsu {

template <typename Clock, typename Duration>
std::ostream &operator<<(
    std::ostream &stream,
    const std::chrono::time_point<Clock, Duration> &time_point) {
    const time_t time = Clock::to_time_t(time_point);
#if __GNUC__ > 4 || \
    ((__GNUC__ == 4) && __GNUC_MINOR__ > 8 && __GNUC_REVISION__ > 1)
    // Maybe the put_time will be implemented later?
    struct tm tm;
    localtime_r(&time, &tm);
    return stream << std::put_time(&tm, "%c");  // Print standard date&time
#else
    char buffer[26];
    ctime_r(&time, buffer);
    buffer[24] = '\0';  // Removes the newline that is added
    return stream << buffer;
#endif
}

}  // namespace nsu

#endif
