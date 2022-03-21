#ifndef NEST_MENU_H
#define NEST_MENU_H

#include <iostream>
#include <codecvt>
#include <locale>
#include "Console.h"
#include "MenuOption.h"


class InvalidMenuOptionException : std::exception {
private:
    const char *meg;
public:
    InvalidMenuOptionException(const wchar_t* reason, MenuOption *option);

    const char *what() const noexcept override;

    virtual ~InvalidMenuOptionException() override;
};

/**
 * @brief Main object to handle menu functionality
 */
class Menu {
private:
    /**
    * Number of milliseconds need it to provide a frame rate, current
    * values ensures 59FPS, close enough
    */
    const static int FRAME_TIME = 17;
    /**
     * Keeps track of the current frame number drawing 1 to 60
     */
    unsigned short int frame = 1;
    /**
     * Holds a pointer to the array of options to display, this does not include the exit option
     */
    MenuOption **options = nullptr;
    unsigned short int optionSize = 0;
    unsigned short int selectedIndex = 0;
    MenuOption* selected;
    Console *console;
    std::wstring controlMsg = std::wstring(L"Use ↑ ↓ to navigate    	⏎ to select");
public:
    constexpr static const wchar_t *EXIT_ID = L"exit";
    // var x = "exit";
    constexpr static const wchar_t *EXIT_ID2 = L"0";

    Menu();

    /**
     * Adds a new @MenuOption to be display in the list
     * The exit option is added automatically and always has IDs 'exit' and '0', adding a new option
     * with any of this ID's will result in exception
     * @remarks There is a limit to the options amount, it supports up to 65,535 @ max range
     * @remarks The supplied options are automatically dispose please do not delete the options anywhere else
     * @throws InvalidMenuOptionException
     * @param option The new option to be added
     */
    void addOption(MenuOption *option) noexcept(false);

    /**
     * Displays all the @MenuOption that have been added and invokes the if the
     * user preses or selects its corresponding ID
     * @return true as long as the user does not select the option exit
     */
    bool render() const;

    virtual ~Menu();
};


#endif //NEST_MENU_H
