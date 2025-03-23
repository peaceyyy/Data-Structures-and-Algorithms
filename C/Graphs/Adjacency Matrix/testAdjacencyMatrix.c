#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Include the header file for the adjacency matrix implementation
#include "adjacencyMatrix.c"

int main() {
    // Initialize a graph with 5 vertices
    int numVertices = 5;
    adj_Matrix* graph = initializeMatrix(numVertices);

    // Add some edges
    addEdge(graph, 0, 1, false);
    addEdge(graph, 0, 2, false);
    addEdge(graph, 1, 3, false);
    addEdge(graph, 3, 4, false);

    // Print the adjacency matrix
    printf("Adjacency Matrix after adding edges:\n");
    printAdjMatrixGrid(graph);

    // Remove an edge
    removeEdge(graph, 0, 2, false);

    // Print the adjacency matrix again
    printf("\n\nAdjacency Matrix after removing an edge:\n\n");
    printAdjMatrixGrid(graph);

    // Free allocated memory
    freeGraphMatrix(graph);
    free(graph);

    return 0;
}