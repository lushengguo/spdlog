//
// Copyright(c) 2015 Gabi Melman.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)
//

#pragma once

#include <iomanip>
#include <locale>
#include <sstream>

namespace utils {

template <typename T>
inline std::string format(const T &value) {
    static std::locale location("");
    std::stringstream ss;
    ss.imbue(location);
    ss << value;
    return ss.str();
}

template <>
inline std::string format(const double &value) {
    static std::locale location("");
    std::stringstream ss;
    ss.imbue(location);
    ss << std::fixed << std::setprecision(1) << value;
    return ss.str();
}

}  // namespace utils
