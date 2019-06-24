#ifndef NSU_CIN
#define NSU_CIN

#include <fstream>

namespace nsu {

#ifndef SW_CIN_INPUT_FILE
#define SW_CIN_INPUT_FILE "input"
#endif

#define SW_CIN_INPUT                     \
    std::ifstream in(SW_CIN_INPUT_FILE); \
    std::cin.rdbuf(in.rdbuf());

}  // namespace nsu

#endif
