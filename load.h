//
// Created by moreira on 25-05-2022.
//

#ifndef DA_PROJECT2_LOAD_H
#define DA_PROJECT2_LOAD_H

#include <string>
#include "graph.h"
extern string FILE_NAME;
using namespace  std;


class Load {

public:
    /**
     * Constructor of the class Load
     */
    Load();
    /**
     * Method responsible for reading all buses from buse's file and creating nodes and edges
     * @param g Graph where nodes and edges will be added
     */
    void loadBuses(Graph &g);

};


#endif //DA_PROJECT2_LOAD_H
