#include "Menu.h"

/**
 * Contains a beautiful ASCII representation of a unicorn
 * Art by -Tua Xiong from https://www.asciiart.eu/mythology/unicorns
 */
const wchar_t*UNICORN_BANNER = L"              ,,))))))));,\n"
                             "            __)))))))))))))),\n"
                             "\\|/       -\\(((((''''((((((((.\n"
                             "-*-==//////((''  .     `)))))),\n"
                             "/|\\      ))| o    ;-.    '(((((                                  ,(,\n"
                             "         ( `|    /  )    ;))))'                               ,_))^;(~\n"
                             "            |   |   |   ,))((((_     _____------~~~-.        %,;(;(>';'~\n"
                             "            o_);   ;    )))(((` ~---~  `::           \\      %%~~)(v;(`('~\n"
                             "                  ;    ''''````         `:       `:::|\\,__,%%    );`'; ~\n"
                             "                 |   _                )     /      `:|`----'     `-'\n"
                             "           ______/\\/~    |                 /        /\n"
                             "         /~;;.____/;;'  /          ___--,-(   `;;;/\n"
                             "        / //  _;______;'------~~~~~    /;;/\\    /\n"
                             "       //  | |                        / ;   \\;;,\\\n"
                             "      (<_  | ;                      /',/-----'  _>\n"
                             "       \\_| ||_                     //~;~~~~~~~~~\n"
                             "           `\\_|                   (,~~\n"
                             "                                   \\~\\\n"
                             "                                    ~~";


InvalidMenuOptionException::InvalidMenuOptionException(const wchar_t* reason, MenuOption* option) {
    std::wstring newMessage = (L"Option [" + std::wstring(option->id) + L"]: " + reason);
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> strconverter;
    meg = strconverter.to_bytes(newMessage).c_str();
}

const char *InvalidMenuOptionException::what() const noexcept {
    return meg;
}


InvalidMenuOptionException::~InvalidMenuOptionException() noexcept {
    delete meg;
}

Menu::Menu() {
    console = new Console();
}

void Menu::addOption(MenuOption *option) noexcept(false) {
    if (EXIT_ID == option->id || EXIT_ID2 == option->id) {
        throw InvalidMenuOptionException(L"Exit options already exist", option);
    }

    if (optionSize == 0) {
        selected = option;
    }

    auto newOptions = new MenuOption *[optionSize + 1];
    for (int i = 0; i < optionSize; ++i) {
        newOptions[i] = options[i];
    }
    newOptions[optionSize] = option;
    optionSize++;
    options = newOptions;
}

bool Menu::render() const {
    for (int i = 0; i < optionSize; ++i) {
        if (selected == options[i]) {
            (*console | L"=>" | L"[" | options[i]->id | L"] " | options[i]->name) << Console::end;
            continue;
        }
        
        *console << options[i]->id << " " << options[i]->name << Console::end;
    }
    
    *console << controlMsg << Console::end;
    return false;
}

Menu::~Menu() {
    delete[] options;
    delete console;
}
