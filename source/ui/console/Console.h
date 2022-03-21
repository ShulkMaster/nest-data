#ifndef NEST_CONSOLE_H
#define NEST_CONSOLE_H
#include <iostream>

class Console {
public:
    static char const end = L'\n';
    std::wostream& print = std::wcout;
    Console operator<<(const char msg);

    Console operator<<(const char* msg);
    Console operator<<(std::wstring msg);
    Console operator<<(int number);

    Console operator|(const char& msg);
    Console operator|(std::wstring msg);
    Console operator|(int number);
};

#endif //NEST_CONSOLE_H
