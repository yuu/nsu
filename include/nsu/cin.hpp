#ifndef NSU_CIN
#define NSU_CIN

#include <fstream>

namespace nsu {

#ifndef SW_CIN_INPUT_FILE
#define SW_CIN_INPUT_FILE "input"
#endif

#define SW_CIN_INPUT                                        \
    std::ifstream CIN_INPUT_FILE_STREAM(SW_CIN_INPUT_FILE); \
    std::cin.rdbuf(CIN_INPUT_FILE_STREAM.rdbuf());

}  // namespace nsu

#endif
