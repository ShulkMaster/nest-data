#include "MenuOption.h"

MenuOption::MenuOption(const wchar_t *id, const wchar_t *name) {
    this->id = std::wstring(id);
    this->name = std::wstring(name);
}
