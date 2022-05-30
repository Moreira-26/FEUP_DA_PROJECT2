//
// Created by moreira on 25-05-2022.
//

#include "graph.h"

#include "graph.h"
#include <climits>
#include <queue>
#include <cmath>
#include <list>
#include <algorithm>
#define INF (INT_MAX/2)

// Constructor: nr nodes and direction (default: undirected)
Graph::Graph( bool dir, vector<Node> nodes){
    this->hasDir = dir;
    this->nodes= nodes;
    n = nodes.size();
}


// Add edge from source to destination with a certain weight
void Graph::addEdge(int src, int dest, int capacity, int duration) {
    if (src<0 || src>n || dest<0 || dest>n) return;
    Edge e;
    e.dest = dest -1;
    e.capacity = capacity;
    e.duration = duration;
    nodes[src - 1].adj.push_back(e);
}

vector<Node> &Graph::getNodes() {
    return nodes;
}

void Graph::setNumNodes(int numNodes){
    this->n =numNodes;
}
bool compareEdge(Edge e1, Edge e2){
    if(e1.capacity == e2.capacity){
        return true;
    }else{
        return e1.capacity > e2.capacity;
    }
}

void Graph::printGraph(int s) {
    for(int i = 0; i < nodes.size(); i++){
        for(Edge&e:nodes[i].adj){
            cout << i+1 << "->" << e.dest + 1 << " : " << e.reverseResidualCapacity << endl;
        }
    }

}

void Graph::dijkstraMaximumCapacity(int s, int final){
    s--; final--;
    MaxHeap<int, int> q(n, -1);
    for (int v=0; v<n; v++) {
        nodes[v].cap = 0;
        q.insert(v,0);
        nodes[v].visited =false;
    }

    nodes[s].cap = INF;
    q.increaseKey(s, INF);
    while(q.getSize() > 0){
        int v = q.removeMax();
        for (Edge w : nodes[v].adj){
            if(min(nodes[v].cap, w.capacity) > nodes[w.dest].cap){
                nodes[w.dest].cap = min(nodes[v].cap, w.capacity);
                nodes[w.dest].pred = v;
                q.increaseKey(w.dest, nodes[w.dest].cap);
            }
        }
    }
    int i = final;
    cout << final +1 << endl;
    while(i != 0){
        cout << nodes[i].pred +1 << endl;
        i = nodes[i].pred;
    }

    cout << nodes[final].cap << endl;
}


void Graph::dijkstraTranshipments(int s,  int final) {
    s--; final--;
    cout << s << " " << final << endl;
    MaxHeap<int, int> q(n, -1);
    for (int v=0; v<n; v++) {
        nodes[v].transhipment = INF;
        nodes[v].pred = 0;
        nodes[v].cap = 0;
        nodes[s].transhipment = 0;
        q.insert(v,0);
        nodes[v].visited =false;
    }

    nodes[s].cap = INF;
    q.increaseKey(s, INF);
    while(q.getSize() > 0){
        int v = q.removeMax();
        for (Edge w : nodes[v].adj){
            cout << v << " " << w.dest << endl;
            if(((nodes[v].transhipment +1) < nodes[w.dest].transhipment) /*&& (min(nodes[v].cap, w.capacity) > nodes[w.dest].cap)*/){
                nodes[w.dest].cap = min(nodes[v].cap, w.capacity);
                nodes[w.dest].pred = v;
                nodes[w.dest].transhipment = nodes[v].transhipment +1;
                q.increaseKey(w.dest, nodes[w.dest].cap);
            }
        }
    }
    int i = final;
    while(i != 0){
        cout << nodes[i].pred << endl;
        i = nodes[i].pred;
    }
    cout << nodes[final].cap << " "<< nodes[final].transhipment -1 << endl;
}



 bool Graph::bfs(int v, int final) {
    for (int i=0; i<n; i++) {
        nodes[i].visited = false;
        nodes[i].dist = INF;
    }
    queue<int> q; // queue of unvisited nodes
    q.push(v);
    nodes[v].dist = 0;
    nodes[v].visited = true;
    nodes[v].pred = -1;
    while (!q.empty()) {
        // while there are still unvisited nodes
        int u = q.front(); q.pop();
        // show node order
        if(u == final){
            return true;
        }
        for (auto &e : nodes[u].adj) {
            int w = e.dest;
            if (!nodes[w].visited && e.residualCapacity > 0 ) {
                q.push(w);
                nodes[w].visited = true;
                nodes[w].dist = nodes[u].dist + 1;
                nodes[w].pred = u;
            }
        }
    }

     return false;
}

void Graph::fordFulkerson(int s, int t) {
    s--;
    t--;
    for(int i = 0; i < n; i++){
        for(Edge &e:nodes[i].adj){
            e.residualCapacity = e.capacity;
        }
    }

    int max_flow = 0;

    while (bfs(s,t)){

        int pathFlow = INF;
        for(int v = t; v != s; v = nodes[v].pred){
            int u = nodes[v].pred;
            int rCapacity;
            for(Edge &e:nodes[u].adj){
                if(e.dest == v){
                    rCapacity = e.residualCapacity;
                    break;
                }
            }
            pathFlow = min(pathFlow, rCapacity);
        }

        for(int v = t; v != s; v = nodes[v].pred){
            int u = nodes[v].pred;
            for(Edge &e:nodes[u].adj){
                if(e.dest == v){
                    e.residualCapacity -= pathFlow;
                    e.reverseResidualCapacity += pathFlow;
                    break;
                }
            }
        }

        max_flow += pathFlow;

    }


    cout << max_flow << endl;
}



void Graph::fordFulkersonGroupSize(int s, int t, int groupSize) {
    s--;
    t--;
    for(int i = 0; i < n; i++){
        for(Edge &e:nodes[i].adj){
            e.residualCapacity = e.capacity;
            e.reverseResidualCapacity = 0;
        }
    }

    int size = groupSize;

    int max_flow = 0;

    while (bfs(s,t)){

        int pathFlow = INF;
        for(int v = t; v != s; v = nodes[v].pred){
            int u = nodes[v].pred;
            int rCapacity;
            for(Edge &e:nodes[u].adj){
                if(e.dest == v){
                    rCapacity = e.residualCapacity;
                    break;
                }
            }
            pathFlow = min(pathFlow, rCapacity);
            pathFlow = min(pathFlow,groupSize);

        }

        for(int v = t; v != s; v = nodes[v].pred){
            int u = nodes[v].pred;
            for(Edge &e:nodes[u].adj){
                if(e.dest == v){

                    if(max_flow >= size){
                        return;
                    }
                    e.residualCapacity -= pathFlow;
                    e.reverseResidualCapacity += pathFlow;
                    break;
                }
            }
        }

        groupSize-=pathFlow;
        max_flow += pathFlow;

    }
}
/*
void Graph::setDistances() {
    for(int i = 0; i < nodes.size(); i++){
        for(Edge& e:nodes[i].getAdj()){
            int d = e.dest;
            e.weight = haversine(nodes[i].getLati(), nodes[i].getLongi(), nodes[d].getLati(), nodes[d].getLongi());
        }
    }
}

void Graph::dijkstra_distance(int s) {
    MinHeap<int, int> q(n, -1);
    for (int v=0; v<n; v++) {
        nodes[v].setDist(INF);
        q.insert(v, INF);
        nodes[v].setVisited(false);
    }

    nodes[s].setDist(0);
    q.decreaseKey(s, 0);
    nodes[s].setPred(s);
    while (q.getSize()>0) {
        int u = q.removeMin();
        nodes[u].setVisited(true);
        for (Edge e : nodes[u].getAdj()) {
            int v = e.dest;
            double w = e.weight;
            if (!nodes[v].getVisited() && nodes[u].getDist() + w < nodes[v].getDist()) {
                nodes[v].setDist(nodes[u].getDist() + w);
                q.decreaseKey(v, nodes[v].getDist());
                nodes[v].setPred(u);
                nodes[v].setCurrentLine({e.lines});
            }
        }
    }
}

double Graph::dijkstra_getDistance(int a, int b) {
    dijkstra_distance(a);
    if (nodes[b].getDist() == INF) return -1;
    return nodes[b].getDist();
}

list<int> Graph::getPath(int a, int b) {
    list<int> path;
    if (nodes[b].getDist() == INF) return path;
    path.push_back(b);
    int v = b;
    while (v != a) {
        v = nodes[v].getPred();
        path.push_front(v);
    }
    return path;
}


void Graph::dijkstra_Lines(int s) {
    MinHeap<int, int> q(n, -1);
    for (int v=0; v<n; v++) {
        nodes[v].setDist(INF);
        q.insert(v, INF);
        nodes[v].setVisited(false);
    }

    nodes[s].setDist(0);
    q.decreaseKey(s, 0);
    nodes[s].setPred(s);
    while (q.getSize()>0) {
        int u = q.removeMin();
        nodes[u].setVisited(true);
        for (Edge e : nodes[u].getAdj()) {
            list<string> intersect = intersection(nodes[u].getCurrentLine(), e.lines);
            double w = 0;
            if(intersect.empty()){
                w = 1;
            }
            int v = e.dest;
            if (!nodes[v].getVisited() && nodes[u].getDist() + w < nodes[v].getDist()) {
                nodes[v].setDist(nodes[u].getDist() + w);
                q.decreaseKey(v, nodes[v].getDist());
                nodes[v].setPred(u);
                nodes[v].setCurrentLine(intersect);
                if(intersect.empty()){
                    nodes[v].setCurrentLine(e.lines);
                }
            }
        }
    }
}

list<pair<int, string>> Graph::dijkstra_path_Lines(int a, int b) {
    dijkstra_Lines(a);
    cout << nodes[b].getDist() << endl;
    list<pair<int, string>> path;
    if (nodes[b].getDist() == INF) return path;
    pair<int, string> aux1;
    aux1.first = b;
    aux1.second = nodes[b].getCurrentLine().front();
    path.push_back(aux1);
    int v = b;
    list<string> intersect= intersection(nodes[b].getCurrentLine(), nodes[v].getCurrentLine());
    while (nodes[v].getPred() != a) {
        pair<int, string> aux;
        int k = nodes[v].getPred();
        aux.first = k;
        intersect= intersection(nodes[k].getCurrentLine(), intersect);

        if(intersect.empty()){
            aux.second = nodes[k].getCurrentLine().front();
            intersect.push_back(aux.second);
        }else{
            aux.second = intersect.front();
        }
        path.push_front(aux);
        v = k;
    }
    return path;
}

double Graph::haversine(double lat1, double lon1, double lat2, double lon2) {
    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLon = (lon2 - lon1) * M_PI / 180.0;

    // convert to radians
    lat1 = (lat1) * M_PI / 180.0;
    lat2 = (lat2) * M_PI / 180.0;

    // apply formulae
    double a = pow(sin(dLat / 2), 2) + pow(sin(dLon / 2), 2) * cos(lat1) * cos(lat2);
    double rad = 6371;
    double c = 2 * asin(sqrt(a));
    double ret = rad * c;

    return  ret;
}


void Graph::addEdgesWalk(double distance) {
    for(node& n: nodes){
        for(node& n1:nodes){
            if(n.getCode().second == n1.getCode().second)
                continue;
            bool addEdgeBool = true;
            for(Edge e: n.getAdj()){
                if(e.dest == n1.getCode().second){
                    addEdgeBool = false;
                    break;
                }
            }
            if(haversine(n.getLati(),n.getLongi(),n1.getLati(),n1.getLongi()) < distance && addEdgeBool){
                addEdge(n.getCode().second,n1.getCode().second,1,"ANDAR");
            }
        }
    }
}*/
