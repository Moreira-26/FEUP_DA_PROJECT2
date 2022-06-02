//
// Created by moreira on 25-05-2022.
//

#ifndef DA_PROJECT2_GRAPH_H
#define DA_PROJECT2_GRAPH_H

#include "maxHeap.h"
#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#include <sstream>

#define INF (INT_MAX/2)

extern string FILE_NAME;

using namespace std;

struct Edge {
    int dest;   // Destination node
    int capacity;
    int duration;// An integer weight
    int residualCapacity  = 0;
    int reverseResidualCapacity = 0;
};

struct Node {
    list<Edge> adj; // The list of outgoing edges (to adjacent nodes)
    int cap = 0;
    int pred = -1;
    bool visited = false;
    int transhipment = 0;
    int dist = 0;
    int time = 0;
    int waitingTime = 0;
    int degree = 0;
    bool used = false;
};


class Graph {
    int n;              // Graph size (vertices are numbered from 1 to n)
    bool hasDir = false;
    vector<Node> nodes; // The list of nodes being represented



public:
    void addNode();

    void removeNode(int numNode);

    void setNumNodes(int numNodes);

    void printGraph();
    /**
     * Construtor da classe graph
     * @param dir grafo dirigido ou nao
     * @param nodes vetor de nós
     */
    Graph( bool dir = true, vector<Node> nodes = {});

    /**
     * Este método adiciona uma aresta ao grafo
     * @param src origem
     * @param dest destino
     * @param weight peso
     * @param lineCode codigo da linha
     */
    void addEdge(int src, int dest, int capacity, int duration);

    /**
     * Este método executa o algoritmo bfs
     * @param v id do nó de origem
     * @param final id do nó de destino
     */
    bool bfs (int v, int final);

    /**
     * método responsável por retornar o vetor com todos os nós do grafo
     * @return vetor com todos os nós do grafo
     */
    vector<Node>& getNodes();

    int getNumberNodes();

    pair<int, list<int>> dijkstraMaximumCapacity(int s, int final);

    pair<int, list<int>> dijkstraTranshipments(int s,  int final);

    void fordFulkerson(int s, int t);

    void fordFulkersonGroupSize(int s, int t, int groupSize);

    void earliestStart(int s, int t);

    void fordFulkersonTime(int s, int t);

    void testPaths (int s, int t);

    pair<int,list<int>> dijkstraMaximumCapacityPath(int v, int final);
};


#endif //DA_PROJECT2_GRAPH_H
