#include "../include/Graph.h"

Graph::Graph() {

    int temp[5][5] = {

        // S    I8   H8   M    IIUI
        {0,    4,   7,   3,   6},  // Saddar
        {4,    0,   2,   5,   4},  // I8
        {7,    2,   0,   6,   3},  // H8
        {3,    5,   6,   0,   4},  // Markaz
        {6,    4,   3,   4,   0}   // IIUI
    };

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            adjMatrix[i][j] = temp[i][j];
        }
    }
}

// convert location string → index
int Graph::getIndex(string location) {

    if (location == "saddar") return 0;
    if (location == "i8") return 1;
    if (location == "h8") return 2;
    if (location == "markaz") return 3;
    if (location == "iiui") return 4;

    return -1;
}

// get distance
int Graph::getDistance(int src, int dest) {
    return adjMatrix[src][dest];
}