#include <stdio.h>

#define MAX_SIZE 100 

void initAdjMatrix(int graph[MAX_SIZE][MAX_SIZE], int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            graph[i][j] = 0;
        }
    }
}

void addEdge(int graph[MAX_SIZE][MAX_SIZE], int start, int end) {
    graph[start][end] = 1;
    graph[end][start] = 1;
}
