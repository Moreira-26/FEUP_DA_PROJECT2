#include <iostream>
#include "graph.h"
#include "load.h"

int main() {
    Graph g;
    Load l;
    l.loadBuses(g);
    g.fordFulkerson(1, 4);
    g.printGraph(1);



    return 0;
}
