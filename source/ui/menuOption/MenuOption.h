#ifndef NEST_MENUOPTION_H
#define NEST_MENUOPTION_H
#include <string>

class MenuOption {
public:
    std::wstring name;
    std::wstring id;
    MenuOption(const wchar_t* id, const wchar_t* name);
};


#endif //NEST_MENUOPTION_H
