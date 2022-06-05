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
    int n;              // Graph size
    bool hasDir = false;
    vector<Node> nodes; // The list of nodes being represented



public:
    /**
     * Method responsible for creating a Node and inserting it in the graph
     */
    void addNode();

    /**
     * Method responsible for removing a Node
     * @param numNode index of the node in the vector nodes
     */
    void removeNode(int numNode);

    /**
     * Method responsible for updating the size variable of the vector nodes (n)
     * @param numNodes new size
     */
    void setNumNodes(int numNodes);

    /**
     * Method responsible for displaying the graph
     */
    void printGraph();

    /**
     * Constructor of class graph
     * @param dir graph is directed or not
     * @param nodes vector of nodes
     */
    Graph( bool dir = true, vector<Node> nodes = {});

    /**
     * This method adds an edge to the graph
     * @param src
     * @param dest
     * @param capacity
     * @param duration
     */
    void addEdge(int src, int dest, int capacity, int duration);

    /**
        This method executes bfs algorithm
     * @param v index of source node
     * @param final index of final node
     */
    bool bfs (int v, int final);

    /**
     * Method responsible to return the vector with all the nodes of the graph
     * @return vector with all the nodes of the graph
     */
    vector<Node>& getNodes();

    /**
     * This method returns the size of vector nodes
     * @return size of vector nodes
     */
    int getNumberNodes();

    /**
     * This method executes the Dijkstra algorithm in order to determine the maximum capacity
     * @param s source node
     * @param final destination node
     * @return pair with the capacity and the path used
     */
    pair<int, list<int>> dijkstraMaximumCapacity(int s, int final);

    /**
     * This method executes the Dijkstra algorithm in order to determine the minimum number of transhipments
     * @param s source node
     * @param final destination node
     * @return pair with the capacity and the path used
     */
    pair<int, list<int>>  dijkstraTranshipments(int s,  int final);

    /**
     * This method executes the FordFulkerson algorithm in order to determine the max flow
     * @param s source node
     * @param t destination node
     * @return max flow
     */
    int fordFulkerson(int s, int t);

    /**
     * This method executes the FordFulkerson algorithm in order to determine a path that can handles the group size
     * @param s source node
     * @param t destination node
     * @param groupSize group size
     */
    void fordFulkersonGroupSize(int s, int t, int groupSize);
    /**
     * This method executes the earliest start algorithm in order to determine how much time is waited in which node
     * @param s source node
     * @param t destination node
     */
    void earliestStart(int s, int t);

    /**
     * This method executes the FordFulkerson algorithm in order to determine the minimum time needed to reunite in the destination node
     * @param s source node
     * @param t destination node
     */
    void fordFulkersonTime(int s, int t);

    /**
     * Compares and filters all pareto optimal solutions
     * @param s source node
     * @param t destination node
     */
    void testPaths (int s, int t);

    /**
     * This method executes the Dijkstra algorithm in order to determine the maximum capacity with the available nodes only
     * @param v source node
     * @param final destination node
     * @return pair with the capacity and the path used
     */
    pair<int,list<int>> dijkstraMaximumCapacityPath(int v, int final);
};


#endif //DA_PROJECT2_GRAPH_H
