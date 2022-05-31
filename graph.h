//
// Created by moreira on 25-05-2022.
//

#ifndef DA_PROJECT2_GRAPH_H
#define DA_PROJECT2_GRAPH_H

#include "maxHeap.h"
#include <vector>
#include <list>
#include <iostream>

using namespace std;

struct Edge {
    int dest;   // Destination node
    int capacity;
    int duration;// An integer weight
    int residualCapacity  = 0;
    int reverseResidualCapacity = 0;
    int flow = 0;
};

struct Node {
    list<Edge> adj; // The list of outgoing edges (to adjacent nodes)
    int cap = 0;
    int pred = -1;
    bool visited = false;
    int transhipment = 0;
    int dist = 0;
};


class Graph {
    int n;              // Graph size (vertices are numbered from 1 to n)
    bool hasDir;        // false: undirect; true: directed
    vector<Node> nodes; // The list of nodes being represented


    /**
     * Este método executa o algortimo djikstra em que o peso da aresta aumenta em 1 se o utilizador for obrigado a mudar de linha
     * @param s id do nó de origem
     */
    void dijkstra_Lines(int s);

public:
    void addNode();

    void removeNode();

    void setNumNodes(int numNodes);

    void printGraph(int s);
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

    void dijkstraMaximumCapacity(int s, int final);

    void dijkstraTranshipments(int s,  int final);

    void fordFulkerson(int s, int t);

    void fordFulkersonGroupSize(int s, int t, int groupSize);

    void timeUntilReunite(int s, int t, int groupSize);

};


#endif //DA_PROJECT2_GRAPH_H
