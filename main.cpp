#include <iostream>
#include "graph.h"
#include "load.h"

int main() {
    Graph g;
    Load l;
    l.loadBuses(g);
    g.fordFulkersonGroupSize(1, 4,8);
    g.printGraph(1);



    return 0;
}
