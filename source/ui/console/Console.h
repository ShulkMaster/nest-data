#ifndef NEST_CONSOLE_H
#define NEST_CONSOLE_H
#include <iostream>

class Console {
public:
    static char const end = '\n';
    std::ostream& print = std::cout;
    Console operator<<(const char msg);

    Console operator<<(const char* msg);
    Console operator<<(std::string msg);
    Console operator<<(int number);

    Console operator|(const char& msg);
    Console operator|(std::string msg);
    Console operator|(int number);
};

#endif //NEST_CONSOLE_H
