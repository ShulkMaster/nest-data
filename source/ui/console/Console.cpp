#include "Console.h"

//Operator overload does not work well with templating

Console Console::operator<<(const char msg) {
    print << msg;
    return *this;
}

Console Console::operator<<(const char* msg) {
    print << msg;
    return *this;
}

Console Console::operator<<(std::wstring msg) {
    print << msg;
    return *this;
}

Console Console::operator<<(int number) {
    print << number;
    return *this;
}

Console Console::operator|(const char& msg) {
    print << "\033[1;31m" << msg << "\033[0m";
    return *this;
}

Console Console::operator|(std::wstring msg) {
    print << "\033[1;31m" << msg << "\033[0m";
    return *this;
}

Console Console::operator|(int number) {
    print << "\033[1;31m" << number << "\033[0m";
    return *this;
}