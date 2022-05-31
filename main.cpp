#include <iostream>
#include "graph.h"
#include "load.h"

int main() {
    Graph g;
    Load l;
    l.loadBuses(g);
    //g.fordFulkerson(1, 6);
    g.fordFulkersonGroupSize(1, 6,4);
    g.printGraph(1);

    return 0;
}
