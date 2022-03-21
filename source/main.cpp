#include "Menu.h"
#include "graph.h"
#include <fcntl.h>


class App {
private:
    bool isRunning = true;
    Menu main;
    DataStrut::Graph graph;

public:
    App(): graph(DataStrut::Graph(new DataStrut::Node())) {
        main.addOption(new MenuOption(L"1", L"Ver informacion"));
        main.addOption(new MenuOption(L"2", L"Agregar informacion"));
        main.addOption(new MenuOption(L"3", L"Modificar informacion"));
        main.addOption(new MenuOption(L"4", L"Remover informacion"));
    }
    void run() {
        while (isRunning) {
            isRunning = main.render();
        }
    }
};

int main() {
    std::locale old_locale;
    setlocale(LC_ALL, "en_US.UTF-8");
    App app;
    app.run();
    setlocale(LC_ALL, old_locale.name().c_str());
    return 0;
}
