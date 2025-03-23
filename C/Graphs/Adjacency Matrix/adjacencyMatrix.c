#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct adj_Matrix
{
    int numOfVertices;
    int **matrix;

} adj_Matrix;

void freeGraphMatrix(adj_Matrix *graph)
{
    for (int i = 0; i < graph->numOfVertices; i++)
    {
        free(graph->matrix[i]);
    }

    free(graph->matrix);
}

adj_Matrix *initializeMatrix(int v)
{
    adj_Matrix *graph = malloc(sizeof(adj_Matrix));
    if (graph == NULL)
    {
        fprintf(stderr, "Memory allocation for adjacency matrix failed!\n");
        exit(EXIT_FAILURE);
    }

    graph->numOfVertices = v;
    graph->matrix = malloc(sizeof(int *) * v);

    if (graph->matrix == NULL)
    {
        fprintf(stderr, "Memory allocation for adjacency matrix array failed!\n");
        free(graph);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < graph->numOfVertices; i++)
    {
        graph->matrix[i] = calloc(graph->numOfVertices, sizeof(int));
        if (graph->matrix[i] == NULL)
        {
            fprintf(stderr, "Memory allocation for matrix row failed!\n");
            for (int j = 0; j < i; j++)
            {
                free(graph->matrix[j]);
            }
            freeGraphMatrix(graph);
            free(graph);
            exit(EXIT_FAILURE);
        }
    }

    return graph;
}

int checkForEdge(adj_Matrix *graph, int sourceVertex, int targetVertex)
{
    return graph->matrix[sourceVertex][targetVertex];
}
void addEdge(adj_Matrix *graph, int src, int dest, bool isDirected)
{
    if (src < 0 || src >= graph->numOfVertices || dest < 0 || dest >= graph->numOfVertices)
    {
        printf("Source (%d) or Destination (%d) out of bounds!\n", src, dest);
        return;
    }

    if (checkForEdge(graph, src, dest))
    {
        printf("Vertices %d and %d are already connected!", src, dest);
        return;
    }

    graph->matrix[src][dest] = 1;

    if (!isDirected)
    {
        graph->matrix[dest][src] = 1;
    }
}

void removeEdge(adj_Matrix *graph, int src, int dest, bool isDirected)
{
    if (src < 0 || src >= graph->numOfVertices || dest < 0 || dest >= graph->numOfVertices)
    {
        printf("Source (%d) or Destination (%d) out of bounds!\n", src, dest);
        return;
    }

    if (!checkForEdge(graph, src, dest))
    {
        printf("Vertices %d and %d are not connected in the first place! Bruhhh", src, dest);
        return;
    }

    graph->matrix[src][dest] = 0;

    if (!isDirected)
    {
        graph->matrix[dest][src] = 0;
    }
}

void printVertexConnections(adj_Matrix *graph)
{
    printf("Graph: {\n");
    for (int from = 0; from < graph->numOfVertices; from++)
    {
        for (int to = 0; to < graph->numOfVertices; to++)
        {
            if (graph->matrix[from][to] != 0)
            {
                printf("%d -> %d\n", from, to);
            }
        }
    }
    printf("}");
}

void printAdjMatrixGrid (adj_Matrix* graph)
{
    printf("Graph: {\n");
    for (int from = 0; from < graph->numOfVertices; from++)
    {
        for (int to = 0; to < graph->numOfVertices; to++)
        {
           printf("%d, ", graph->matrix[from][to]);
        }
        printf("\n");
    }
    printf("}");
}
