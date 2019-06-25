#ifndef NSU_STRING
#define NSU_STRING

#include <sstream>
#include <string>
#include <vector>

namespace nsu {

std::vector<std::string> split(const std::string &str,
                               const std::string &delm) {
    auto offset = std::string::size_type(0);
    auto delm_length = delm.length();

    std::vector<std::string> fl;
    while (true) {
        auto pos = str.find(delm, offset);
        if (pos == std::string::npos) {
            const auto t = str.substr(offset);
            fl.emplace_back(t);
            break;
        }

        const auto t = str.substr(offset, pos - offset);
        fl.emplace_back(t);
        offset = pos + delm_length;
    }

    return fl;
}

std::vector<std::string> split(std::istringstream &in, char delm) {
    std::vector<std::string> ret;
    std::string s;
    while (std::getline(in, s, delm)) {
        ret.emplace_back(s);
    }

    return ret;
}

}  // namespace nsu

#endif
