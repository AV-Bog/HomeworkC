#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

bool readFromFile(const char* filename, int graph[MAX_VERTICES][MAX_VERTICES], int* vertices) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return false;
    }
    fscanf(file, "%d", vertices);
    for (int i = 0; i < *vertices; ++i) {
        for (int j = 0; j < *vertices; ++j) {
            fscanf(file, "%d", &graph[i][j]);
        }
    }
    fclose(file);
    return true;
}

bool dfs(int graph[MAX_VERTICES][MAX_VERTICES], int vertex, int n) {
    bool reachable = true;

    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] != 1) {

            for (int j = 0; j < n; j++) {
                if (graph[vertex][j] == 1 && graph[j][i] == 1) {
                    reachable = true;
                }
                else {
                    reachable = false;
                }
            }
        }
    }
    return reachable;
}

int main() {
    if (!test()) {
        return -1;
    }
    int vertex; 
    int graph[MAX_VERTICES][MAX_VERTICES];
    readFromFile("file.txt", graph, &vertex);

    printf("numbers of the desired vertices:");
    for (int i = 0; i < vertex; i++) {
        if (dfs(graph, i, vertex)) {
            printf(" %d", i + 1);
        }
    }
    return 0;
}

bool test() {
    int vertexTest;
    int graphTest[MAX_VERTICES][MAX_VERTICES];
    if (!readFromFile("fileTest.txt", graphTest, &vertexTest)) {
        printf("reading from file failed");
        return false;
    }

    if (!dfs(graphTest, 2, vertexTest)) {
        printf("error: function does not work correctly for a string with zeros");
        return false;
    }
    return true;
}