/*
 * Copyright (c) 2016 yuu
 *
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */

#pragma onec

namespace neosuzu {

#define CPP03 199711
#define CPP11 201103
#define CPP14 201402
#define CPP1Z 201500

#define ISMIN11 __cplusplus < CPP11
#define ISOVER11 __cplusplus >= CPP11
#define ISOVER14 __cplusplus >= CPP14
#define ISOVER1Z __cplusplus >= CPP1Z

enum class CppVersion : uint32_t {
    cpp03 = 199711,
    cpp11 = 201103,
    cpp14 = 201402,
    cpp1z = 201500,
};

template <typename Enumeration>
auto as_integer(Enumeration value)
    -> typename std::underlying_type<Enumeration>::type {
    return static_cast<typename std::underlying_type<Enumeration>::type>(value);
}

constexpr CppVersion getCppVersion() noexcept {
    return static_cast<CppVersion>(__cplusplus);
}

} // neosuzu
