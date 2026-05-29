#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

class Graph {

private:
    static const int SIZE = 5;
    int adjMatrix[SIZE][SIZE];

public:
    Graph();

    int getIndex(string location);
    int getDistance(int src, int dest);
};

#endif