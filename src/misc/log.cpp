#include "log.h"

void error(std::string msg)
{
    std::cout << "\033[31;1;4m" << msg << "\033[0m" << "\n";
    exit(0);
}

void debug(std::string msg)
{
    std::cout << msg << "\n";
}