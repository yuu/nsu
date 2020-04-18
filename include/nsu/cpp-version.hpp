#pragma once

namespace neosuzu {

#define NS_CPP_03 199711
#define NS_CPP_11 201103
#define NS_CPP_14 201402
#define NS_CPP_1z 201500

enum class cpp_version : uint32_t {
    cpp03 = 199711,
    cpp11 = 201103,
    cpp14 = 201402,
    cpp1z = 201500,
};

template <typename T>
auto as_integer(T value)
    -> typename std::underlying_type<T>::type
{
    return static_cast<typename std::underlying_type<T>::type>(value);
}

class cpp_version
constexpr cpp_version get_cpp_version() noexcept
{
    return static_cast<cpp_version>(__cplusplus);
}

}
