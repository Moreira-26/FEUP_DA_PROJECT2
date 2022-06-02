#include <iostream>
#include "graph.h"
#include "load.h"

int main() {
    Graph g;
    Load l;
    l.loadBuses(g);
    //g.fordFulkerson(1, 6);
    //g.fordFulkersonGroupSize(1, 6,4);
    //g.timeUntilReunite(2,6);
    //g.fordFulkersonTime(1,6);
    //g.printGraph();
    g.testPaths(1,210);

    return 0;
}
