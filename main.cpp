#include <iostream>
#include "graph.h"
#include "load.h"
#include "menus.h"
string FILE_NAME = "in01.txt";
int main() {
    Graph g;
    Load l;
    l.loadBuses(g);
    Menus menu(g);
    menu.mainMenu();

    return 0;
}
