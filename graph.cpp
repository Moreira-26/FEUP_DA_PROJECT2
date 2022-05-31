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

void Graph::removeNode(){
    nodes.pop_back();
}

void Graph::addNode(){
    Node node;
    nodes.push_back(node);
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
}

void Graph::fordFulkersonGroupSize(int s, int t, int groupSize) {
    setNumNodes(n+1);
    addNode();
    addEdge(n,s,groupSize, 24);
    fordFulkerson(n, t);
    removeNode();

}

void Graph::timeUntilReunite(int s, int t, int groupSize) {

}
