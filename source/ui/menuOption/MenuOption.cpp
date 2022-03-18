#include "MenuOption.h"

MenuOption::MenuOption(const char *id, const char *name) {
    this->id = std::string(id);
    this->name = std::string(name);
}
