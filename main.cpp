#include <iostream>
#include "graph.h"
#include "load.h"

int main() {
    Graph g;
    Load l;
    l.loadBuses(g);
    g.printGraph();

    return 0;
}
