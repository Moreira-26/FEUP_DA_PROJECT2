//
// Created by moreira on 25-05-2022.
//

#include "graph.h"

#include <climits>
#include <queue>
#include <algorithm>


// Constructor: nr nodes and direction (default: undirected)
Graph::Graph(bool dir, vector<Node> nodes) {
    this->hasDir = dir;
    this->nodes = nodes;
    n = nodes.size();
}


int Graph::getNumberNodes() {
    return n;
}


void Graph::removeNode(int numNode) {
    nodes.erase(nodes.begin() + numNode);
}


void Graph::addNode() {
    Node node;
    nodes.push_back(node);
}


void Graph::addEdge(int src, int dest, int capacity, int duration) {
    if (src < 0 || src > n || dest < 0 || dest > n) return;
    Edge e;
    e.dest = dest - 1;
    e.capacity = capacity;
    e.duration = duration;
    nodes[src - 1].adj.push_back(e);
}


vector<Node> &Graph::getNodes() {
    return nodes;
}


void Graph::setNumNodes(int numNodes) {
    this->n = numNodes;
}




void Graph::printGraph() {
    for (int i = 0; i < nodes.size(); i++) {
        for (Edge &e: nodes[i].adj) {
            cout << i + 1 << "->" << e.dest + 1 << " : " << e.reverseResidualCapacity << endl;
        }
    }

}

//1.1
pair<int, list<int>> Graph::dijkstraMaximumCapacity(int s, int final) {
    s--;
    final--;
    int transhipments = 0;
    MaxHeap<int, int> q(n, -1);
    for (int v = 0; v < n; v++) {
        nodes[v].cap = 0;
        q.insert(v, 0);
        nodes[v].visited = false;
    }

    nodes[s].cap = INF;
    q.increaseKey(s, INF);
    while (q.getSize() > 0) {
        int v = q.removeMax();
        for (Edge w: nodes[v].adj) {
            if (min(nodes[v].cap, w.capacity) > nodes[w.dest].cap) {
                nodes[w.dest].cap = min(nodes[v].cap, w.capacity);
                nodes[w.dest].pred = v;
                q.increaseKey(w.dest, nodes[w.dest].cap);
            }
        }
    }
    list<int> path;
    int i = final;
    while (i != s) {
        path.push_front(i);
        i = nodes[i].pred;
    }
    path.push_front(s);

    pair<int, list<int>> result;
    result.first = nodes[final].cap;
    result.second = path;
    return result;
}

//1.2
pair<int, list<int>> Graph::dijkstraTranshipments(int s, int final) {
    s--;
    final--;
    MaxHeap<int, int> q(n, -1);
    for (int v = 0; v < n; v++) {
        nodes[v].transhipment = INF;
        nodes[v].pred = 0;
        nodes[v].cap = 0;
        nodes[s].transhipment = 0;
        nodes[v].used = false;
        q.insert(v, 0);
        nodes[v].visited = false;
    }

    nodes[s].cap = INF;
    q.increaseKey(s, INF);
    while (q.getSize() > 0) {
        int v = q.removeMax();
        for (Edge w: nodes[v].adj) {
            if ((nodes[v].transhipment + 1) < nodes[w.dest].transhipment) {
                nodes[w.dest].cap = min(nodes[v].cap, w.capacity);
                nodes[w.dest].pred = v;
                nodes[w.dest].transhipment = nodes[v].transhipment + 1;
                q.increaseKey(w.dest, nodes[w.dest].cap);
            }
        }
    }
    list<int> path;
    int i = final;
    while (i != s) {
        path.push_front(i);
        i = nodes[i].pred;
    }
    path.push_front(s);

    pair<int, list<int>> result;
    result.first = nodes[final].cap;
    result.second = path;
    return result;
}

//1.2
pair<int, list<int>> Graph::dijkstraMaximumCapacityPath(int v, int final) {
    int transhipments = 0;
    MaxHeap<int, int> q(n, -1);
    for (int v = 0; v < n; v++) {
        nodes[v].cap = 0;
        q.insert(v, 0);
    }

    nodes[v].cap = INF;
    q.increaseKey(v, INF);
    while (q.getSize() > 0) {
        int v = q.removeMax();
        for (Edge w: nodes[v].adj) {
            if ((min(nodes[v].cap, w.capacity) > nodes[w.dest].cap) && nodes[v].used) {
                nodes[w.dest].cap = min(nodes[v].cap, w.capacity);
                nodes[w.dest].pred = v;
                q.increaseKey(w.dest, nodes[w.dest].cap);
            }
        }
    }
    list<int> path;
    int i = final;
    while (i != v) {
        path.push_front(i);
        transhipments++;
        i = nodes[i].pred;
    }
    path.push_front(v);

    pair<int, list<int>> result;
    result.first = nodes[final].cap;
    result.second = path;
    return result;
}

//1.2
void Graph::testPaths(int s, int t) {
    s--;
    t--;
    list<pair<int,list<int>>> paths;
    paths.push_back(dijkstraMaximumCapacity(s + 1, t + 1));//pareto-otimo prioridade capacidade
    paths.push_back(dijkstraTranshipments(s + 1, t + 1));//pareto-otimo prioridade transbordos


    int aux = nodes[t].pred;
    nodes[t].used = true;
    while (aux != s) {
        nodes[aux].used = true;
        aux = nodes[aux].pred;
    }
    nodes[s].used = true;

    for (int i = 0; i < n; i++) {
        nodes[i].used = true;
        paths.push_back(dijkstraMaximumCapacityPath(s, t));
    }

    list<pair<int,list<int>>> ::iterator it1;
    list<pair<int,list<int>>>::iterator it2;

    for(int i = 0 ;i < paths.size(); i++){
        it1 = paths.begin();
        advance(it1,i);
        for(it2 = paths.begin();it2 != paths.end(); it2++){
            int aux = 0;
            if(paths.size() == 1){
                break;
            }
            if(it2 == it1){
                continue;
            }
            if((it2->first <= it1->first) && (it2->second.size() == it1->second.size())){
                if(aux < i){
                    i = 0;
                }
                it2 = paths.erase(it2);

            }
            if((it2->first == it1->first) && (it2->second.size() >= it1->second.size())){
                if(aux < i){
                    i = 0;
                }
                it2 = paths.erase(it2);
            }
            aux++;
        }
    }

    cout << endl;
    int path = 0;

    for (auto &n: paths) {
        path++;
        cout  << "Capacity: " << n.first << " Transhipments: " <<n.second.size() - 1 << " Path: " << path;
        for (auto &s: n.second) {
            cout << s + 1 << " ";
        }
        cout << endl;
    }
}

//2.1, 2.2 and 2.3
void Graph::fordFulkerson(int s, int t) {
    s--;
    t--;
    for (int i = 0; i < n; i++) {
        for (Edge &e: nodes[i].adj) {
            e.residualCapacity = e.capacity;
        }
    }
    int max_flow = 0;

    while (bfs(s, t)) {
        int pathFlow = INF;

        for (int v = t; v != s; v = nodes[v].pred) {
            int u = nodes[v].pred;
            int rCapacity;
            for (Edge &e: nodes[u].adj) {
                if (e.dest == v) {
                    rCapacity = e.residualCapacity;
                    break;
                }
            }
            pathFlow = min(pathFlow, rCapacity);
        }

        for (int v = t; v != s; v = nodes[v].pred) {
            int u = nodes[v].pred;
            for (Edge &e: nodes[u].adj) {
                if (e.dest == v) {
                    e.residualCapacity -= pathFlow;
                    e.reverseResidualCapacity += pathFlow;
                    break;
                }
            }
        }
        max_flow += pathFlow;
    }
}

//2.1 and 2.2
void Graph::fordFulkersonGroupSize(int s, int t, int groupSize) {
    setNumNodes(n + 1);
    addNode();
    addEdge(n, s, groupSize, 24);
    fordFulkerson(n, t);
    removeNode(nodes.size() - 1);

}

//2.4
bool Graph::bfs(int v, int final) {
    for (int i = 0; i < n; i++) {
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
        int u = q.front();
        q.pop();
        if (u == final) {
            return true;
        }
        for (auto &e: nodes[u].adj) {
            int w = e.dest;
            if (!nodes[w].visited && e.residualCapacity >0) {
                q.push(w);
                nodes[w].visited = true;
                nodes[w].dist = nodes[u].dist + 1;
                nodes[w].pred = u;
            }
        }
    }
    return false;
}

//2.4
void Graph::fordFulkersonTime(int s, int t) {
    s--;
    t--;
    for (int i = 0; i < n; i++) {
        nodes[i].time = 0;
        for (Edge &e: nodes[i].adj) {
            e.residualCapacity = e.capacity;
        }
    }

    int max_flow = 0;


    while (bfs(s, t)) {

        int pathFlow = INF;
        for (int v = t; v != s; v = nodes[v].pred) {
            int u = nodes[v].pred;
            int rCapacity;
            for (Edge &e: nodes[u].adj) {
                if (e.dest == v) {
                    rCapacity = e.residualCapacity;
                    break;
                }
            }
            pathFlow = min(pathFlow, rCapacity);
        }

        for (int v = t; v != s; v = nodes[v].pred) {
            int u = nodes[v].pred;
            for (Edge &e: nodes[u].adj) {
                if (e.dest == v) {
                    e.residualCapacity -= pathFlow;
                    e.reverseResidualCapacity += pathFlow;
                    if (nodes[u].time < (nodes[e.dest].time + e.duration)) {
                        nodes[u].time = nodes[e.dest].time + e.duration;
                    }
                    break;
                }
            }
        }
        max_flow += pathFlow;
    }

    cout <<"Time needed: " << nodes[s].time << endl;
    cout << endl;
}

//2.5
void Graph::earliestStart(int s, int t) {
    s--;
    t--;

    for (Node &v: nodes) {
        v.time = 0;
        v.pred = -1;
        v.degree = 0;
        v.used = false;
        v.waitingTime = 0;
    }
    queue<int> q1;
    nodes[s].used = true;
    q1.push(s);
    while(!q1.empty()){
        int i = q1.front();
        if(i == t){
            break;
        }
        q1.pop();
        for(Edge &e: nodes[i].adj){
            nodes[e.dest].used = true;
            q1.push(e.dest);
        }
    }

    for (Node &v: nodes) {
        if(!v.used){
            continue;
        }
        for (Edge &e: v.adj) {
            nodes[e.dest].degree++;
        }
    }

    queue<int> q;
    q.push(s);

    int minDur = -1;
    int vf = -1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if(v == t){
            break;
        }
        if (minDur < nodes[v].time) {
            minDur = nodes[v].time;
            vf = v;
        }
        for (Edge &e: nodes[v].adj) {
            if (nodes[e.dest].time < (nodes[v].time + e.duration)) {
                nodes[e.dest].time = nodes[v].time + e.duration;
                nodes[e.dest].pred = v;
            }
            nodes[e.dest].degree--;
            if (nodes[e.dest].degree == 0) {
                q.push(e.dest);
            }
        }
    }
    for(Node &v: nodes){
        for(Edge &e: v.adj){
            if(v.used) {
                nodes[e.dest].waitingTime = max((nodes[e.dest].time - (v.time + e.duration)), nodes[e.dest].waitingTime);
            }
        }
    }
    for(int i = 0; i< n; i++){
        if(nodes[i].used){
            cout << i +1 << ": " << nodes[i].waitingTime << endl;
        }
    }

}










