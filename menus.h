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
    /**
     * Constructor of the Menus class
     * @param g // graph with the first data set already read
     */

    Menus(Graph& g);

    /**
     * This method is responsible to draw the main menu and handle if the inputs
     */
    void mainMenu();

    /**
     * This method is responsible to draw the scenario one menu and handle with the inputs
     */
    void scenarioOneMenu();

    /**
     * This method is responsible to draw the scenario two menu and handle with the inputs
     */
    void scenarioTwoMenu();

    /**
     * This method is responsible to draw the data set menu and handle with the inputs
     */
    void dataSet();

};



#endif //DA_PROJECT2_MENUS_H
