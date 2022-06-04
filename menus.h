//
// Created by Hugo Miguel Fernandes Gomes on 02/06/2022.
//

#ifndef DA_PROJECT2_MENUS_H
#define DA_PROJECT2_MENUS_H


#include <string>
#include "graph.h"
#include <map>
#include "load.h"
#include <iomanip>

using namespace  std;
class Menus {
    Graph g1;
    Load l;

public:

    Menus(Graph& g);

    void mainMenu();

    void scenarioOneMenu();

    void scenarioTwoMenu();

    void dataSet();

};



#endif //DA_PROJECT2_MENUS_H
