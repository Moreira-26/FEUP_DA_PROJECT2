//
// Created by moreira on 25-05-2022.
//

#include "graph.h"

#include <climits>
#include <queue>
#include <algorithm>
#define INF (INT_MAX/2)

// Constructor: nr nodes and direction (default: undirected)
Graph::Graph( bool dir, vector<Node> nodes){
    this->hasDir = dir;
    this->nodes= nodes;
    n = nodes.size();
}


void Graph::removeNode(int numNode){
    nodes.erase(nodes.begin() + numNode);
}


void Graph::addNode(){
    Node node;
    nodes.push_back(node);
}


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


void Graph::printGraph() {
    for(int i = 0; i < nodes.size(); i++){
        for(Edge&e:nodes[i].adj){
            cout << i+1 << "->" << e.dest + 1 << " : " << e.reverseResidualCapacity << endl;
        }
    }

}


pair<int, int> Graph::dijkstraMaximumCapacity(int s, int final){
    s--; final--;
    int transhipments = 0;
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
    while(i != s){
        transhipments++;
        i = nodes[i].pred;
    }

    pair<int, int> result;
    result.first =  nodes[final].cap;
    result.second = transhipments;
    return  result;
}


pair<int, int> Graph::dijkstraTranshipments(int s,  int final) {
    s--; final--;
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
            if((nodes[v].transhipment +1) < nodes[w.dest].transhipment){
                nodes[w.dest].cap = min(nodes[v].cap, w.capacity);
                nodes[w.dest].pred = v;
                nodes[w.dest].transhipment = nodes[v].transhipment +1;
                q.increaseKey(w.dest, nodes[w.dest].cap);
            }
        }
    }
    pair<int, int> result(nodes[final].cap, nodes[final].transhipment);
    return result;
}


bool Graph::bfs(int v, int final) {
    for (int i=0; i<n; i++) {
        nodes[i].visited = false;
        nodes[i].dist = INF;
        nodes[i].used = false;
    }
    queue<int> q;
    q.push(v);
    nodes[v].dist = 0;
    nodes[v].visited = true;
    nodes[v].pred = -1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if(u == final){
            return true;
        }
        for (auto &e : nodes[u].adj) {
            int w = e.dest;
            if (!nodes[w].visited) {
                q.push(w);
                nodes[w].visited = true;
                nodes[w].dist = nodes[u].dist + 1;
                nodes[w].pred = u;
            }
        }
    }
     return false;
}


list<int> Graph::bfs_path(int v, int final) {
    for (int i=0; i<n; i++) {
        nodes[i].visited = false;
        nodes[i].dist = INF;
    }
    queue<int> q;
    q.push(v);
    nodes[v].dist = 0;
    nodes[v].visited = true;
    nodes[v].pred = -1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if(u == final){
            break;
        }
        for (auto &e : nodes[u].adj) {
            int w = e.dest;
            if (!nodes[w].visited && nodes[w].used) {
                q.push(w);
                nodes[w].visited = true;
                nodes[w].dist = nodes[u].dist + 1;
                nodes[w].pred = u;
            }
        }
    }
    list<int> result;
    int i = final;
    while(i != v){
        result.push_front(i);
        i = nodes[i].pred;
    }
    //push front in order to keep the order from the beginning to the end
    result.push_front(i);
    return result;
}


void Graph::fordFulkerson(int s, int t) {
    s--; t--;
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
    removeNode(nodes.size() - 1);

}


void Graph::timeUntilReunite(int s, int t) {
    s--;
    t--;
    removeNode(0);

    for(Node &v : nodes){
        v.time = 0;
        v.pred = -1;
        v.degree = 0;
    }
    for(Node &v : nodes){
        for(Edge &e : v.adj){
            nodes[e.dest].degree++;
        }
    }

    queue<int> q;
    for(int i = 0; i < nodes.size(); i++){
        if(nodes[i].degree == 0){
            q.push(i);
        }
    }

    int minDur = -1;
    int vf = -1;
    while(!q.empty()){
        int v = q.front(); q.pop();

        if(minDur < nodes[v].time){
            minDur = nodes[v].time;
            cout << nodes[v].time << endl;
            vf = v;
        }
        for(Edge &e: nodes[v].adj){
            if(nodes[e.dest].time < (nodes[v].time + e.duration)){
                nodes[e.dest].time = nodes[v].time + e.duration;
                nodes[e.dest].pred = v;
            }
            nodes[e.dest].degree--;
            if(nodes[e.dest].degree == 0){
                q.push(e.dest);
            }
        }
    }
}


void Graph::fordFulkersonTime(int s, int t) {
    s--;
    t--;
    for(int i = 0; i < n; i++){
        nodes[i].time = 0;
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
                    if(nodes[u].time < (nodes[e.dest].time + e.duration)){
                        nodes[u].time = nodes[e.dest].time + e.duration;
                    }
                    break;
                }
            }
        }
        max_flow += pathFlow;
    }
    cout << max_flow << endl;
    cout << nodes[s].time << endl;
}

void Graph::testPaths(int s, int t) {
    s--;t--;
    dijkstraTranshipments(s+1,t+1);
    int aux = nodes[t].pred;
    nodes[t].used = true;
    while(aux != s){
        nodes[aux].used = true;
        aux = nodes[aux].pred;
    }
    nodes[s].used = true;
    list<list<int>> paths;
    for(int i = 0; i < n; i++){
        nodes[i].used = true;
        paths.push_back(bfs_path(s,t));
    }

    int path = 0;
    for(auto &n: paths){
        path++;
        cout << path << ": ";
        for(auto &s : n){
            cout << s+1 << " ";
        }
        cout << endl;
    }
}

