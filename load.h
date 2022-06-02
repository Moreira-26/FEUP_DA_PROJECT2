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

    int numNodes;
    int numEdges;
public:
    Load();
    void loadBuses(Graph &g);

};


#endif //DA_PROJECT2_LOAD_H
