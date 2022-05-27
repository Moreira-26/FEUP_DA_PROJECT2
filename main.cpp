#include <iostream>
#include "graph.h"
#include "load.h"

int main() {
    Graph g;
    Load l;
    l.loadBuses(g);
    //g.printGraph();
    g.dijkstraMaximumCapacity(1, 4);

    return 0;
}
