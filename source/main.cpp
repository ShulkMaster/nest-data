#include "Menu.h"

int main() {
    bool isRunning = true;
    Menu main;
    main.addOption(new MenuOption("2", "mi option"));
    main.addOption(new MenuOption("2dd", "mi option 2"));
    main.addOption(new MenuOption("28", "mi option 3"));

    while (isRunning) {
        isRunning = main.render();
    }
    return 0;
}
