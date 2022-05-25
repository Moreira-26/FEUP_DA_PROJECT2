//
// Created by moreira on 25-05-2022.
//

#include "load.h"
#include <fstream>
#include <sstream>
#include <iostream>


void Load::loadBuses(Graph& g) {
    ifstream fileStream;
    string firstLine, line;
    string numNodes, numEdges, src, dest, cap, dur ;

    fileStream.open(FILE_NAME);

    getline(fileStream,firstLine);
    istringstream lineStream(firstLine);
    getline(lineStream,numNodes,' ');
    getline(lineStream,numEdges,' ');

    g.setNumNodes(stoi(numNodes));

    for(int i = 0; i < stoi(numNodes);i++){
        Node n;
        g.getNodes().push_back(n);
    }

    while(getline(fileStream,line)){
        istringstream lineBus(line);
        getline(lineBus,src,' ');
        getline(lineBus,dest,' ');
        getline(lineBus,cap,' ');
        getline(lineBus,dur,' ');
        g.addEdge(stoi(src), stoi(dest), stoi(cap), stoi(dur));
    }

}

Load::Load() {

}
