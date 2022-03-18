#include "Menu.h"

/**
 * Contains a beautiful ASCII representation of a unicorn
 * Art by -Tua Xiong from https://www.asciiart.eu/mythology/unicorns
 */
const char *UNICORN_BANNER = "              ,,))))))));,\n"
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


InvalidMenuOptionException::InvalidMenuOptionException(const char *reason, MenuOption *option) {
    meg = ("Option [" + std::string(option->id) + "]: " + reason).data();
}

const char *InvalidMenuOptionException::what() const noexcept {
    return meg;
}


InvalidMenuOptionException::~InvalidMenuOptionException() noexcept {
    delete meg;
}

void Menu::addOption(MenuOption *option) noexcept(false) {
    if (EXIT_ID == option->id || EXIT_ID2 == option->id) {
        throw InvalidMenuOptionException("Exit options already exist", option);
    }

    auto newOptions = new MenuOption *[optionSize + 1];
    for (int i = 0; i < optionSize; ++i) {
        newOptions[i] = options[i];
    }
    newOptions[optionSize] = option;
    optionSize++;
    options = newOptions;
}

bool Menu::render() {
    for (int i = 0; i < optionSize; ++i) {
        std::cout << options[i]->name << options[i]->id << std::endl;
    }
    return false;
}

Menu::~Menu() {
    delete[] options;
}
