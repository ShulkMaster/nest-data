#ifndef NEST_MENUOPTION_H
#define NEST_MENUOPTION_H
#include <string>

class MenuOption {
public:
    std::string name;
    std::string id;
    MenuOption(const char * id, const char * name);
};


#endif //NEST_MENUOPTION_H
