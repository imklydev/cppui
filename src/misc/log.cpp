#include "log.h"

void error(std::string msg) {
    std::cout << msg << "\n";
    exit(0);
}

void log(std::string msg) {
    std::cout << msg << "\n";
}