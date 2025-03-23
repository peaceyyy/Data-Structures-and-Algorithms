#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node_t
{
    int val;
    struct node_t *next;
} node_t;

typedef struct
{
    node_t *head;
} List;

typedef struct
{
    int numOfVertices;
    List **nodeArr;
} AdjList;

node_t *createNode(int val)
{
    node_t *newNode = malloc(sizeof(node_t));
    if (newNode == NULL)
    {
        fprintf(stderr, "Memory allocation failed!");
        exit(1);
    }

    newNode->next = NULL;
    newNode->val = val;

    return newNode;
}

AdjList *initializeAdjList(int v)
{
    AdjList *g = malloc(sizeof(AdjList));
    g->numOfVertices = v;
    g->nodeArr = malloc(sizeof(List) * g->numOfVertices);

    for (int i = 0; i < v; i++)
    {
        g->nodeArr[i] = malloc(sizeof(List));
        g->nodeArr[i]->head = NULL;
    }

    return g;
}

int checkForEdge(AdjList *graph, int sourceVertex, int targetVertex)
{

    if (sourceVertex < 0 || sourceVertex >= graph->numOfVertices)
    {
        return 0;
    }

    node_t *trav = graph->nodeArr[sourceVertex]->head;

    while (trav != NULL)
    {
        if (trav->val == targetVertex)
        {
            return 1;
        }
        trav = trav->next;
    }

    return 0;
}
void addEdge(AdjList *graph, int src, int dest, bool isDirected)
{
    if (src < 0 || src >= graph->numOfVertices || dest < 0 || dest >= graph->numOfVertices)
    {
        printf("Source (%d) or Destination (%d) out of bounds!\n", src, dest);
        return;
    }

    if (checkForEdge(graph, src, dest))
    {
        printf("%d and %d are already connected\n", src, dest);
        return;
    }

    node_t *temp = createNode(dest);
    temp->next = graph->nodeArr[src]->head;
    graph->nodeArr[src]->head = temp;

    if (!isDirected)
    {
        node_t *temp2 = createNode(src);
        temp2->next = graph->nodeArr[dest]->head;
        graph->nodeArr[dest]->head = temp2;
    }
}

void removeEdge(AdjList *graph, int src, int dest, bool isDirected)
{
    
    if (src < 0 || src >= graph->numOfVertices || dest < 0 || dest >= graph->numOfVertices)
    {
        printf("Source (%d) or Destination (%d) out of bounds!\n", src, dest);
        return;
    }

    
    if (!checkForEdge(graph, src, dest))
    {
        printf("numOfVertices are not connected!\n");
        return;
    }

    
    node_t *trav1 = graph->nodeArr[src]->head;
    while (trav1 != NULL)
    {
        if (trav1->val == dest)
        {
            node_t *temp = trav1;
            trav1 = trav1->next;
            free(temp);
            break; 
        }
        trav1 = trav1->next;
    }

    
    if (!isDirected)
    {
        node_t *trav2 = graph->nodeArr[dest]->head;
        while (trav2 != NULL)
        {
            if ((trav2)->val == src)
            {
                node_t *temp = trav2;
                trav2 = trav2->next;
                free(temp);
                break; 
            }
            trav2 = trav2->next;
        }
    }
}

void printAdjList(AdjList *graph)

{
    if (graph == NULL)
    {
        printf("AdjList ain't here");
        return;
    }

    for (int i = 0; i < graph->numOfVertices; i++)
    {
        printf("Vertex %d: ", i);
        node_t *trav = graph->nodeArr[i]->head;
        while (trav != NULL)
        {
            printf("%d -> ", trav->val);
            trav = trav->next;
        }
        printf("NULL\n");
    }
}

void freeAdjList(AdjList *graph)
{
    if (graph == NULL) return; 

    for (int i = 0; i < graph->numOfVertices; i++)
    {
        if (graph->nodeArr[i] != NULL) 
        {
            node_t *trav = graph->nodeArr[i]->head;
            while (trav != NULL)
            {
                node_t *temp = trav;
                trav = trav->next;
                free(temp);
            }
            free(graph->nodeArr[i]);  
            graph->nodeArr[i] = NULL; // Prevent dangling pointer
        }
    }
    free(graph->nodeArr); 
    free(graph); 

}

void freeList (List* l)
{   
    if (l == NULL) return;

    node_t* trav = l->head;

    while (l != NULL)
    {
        node_t* temp = trav;
        trav = trav -> next;
        free(temp);
    }

    free(l);
}
List *getNodeNeighbors(AdjList *graph, int node)
{
    if (node < 0 || node >= graph->numOfVertices)
    {
        printf("Invalid node index!\n");
        return NULL;
    }
    List *neighborsList = malloc(sizeof(List));

    if (!neighborsList)
    {
        fprintf(stderr,"Memory allocation failed!\n");
        return NULL;
    }

    neighborsList->head = NULL;

    node_t *trav = graph->nodeArr[node]->head;
    while (trav != NULL)
    {
        node_t *newNode = createNode(trav->val);
        newNode->next = neighborsList->head;
        neighborsList->head = newNode;
        trav = trav->next;
    }

    return neighborsList;
}

int main()
{
    AdjList *graph = initializeAdjList(4);

    addEdge(graph, 0, 3, false);
    addEdge(graph, 2, 1, false);
    addEdge(graph, 1, 2, false);
    addEdge(graph, 0, 2, false);

    /////// Test get Node Neighbors

    printf("Neighbors of Node 0 are: ");
    List *nodeNeighbors = getNodeNeighbors(graph, 0);

    node_t *trav = nodeNeighbors->head;
    while (trav)
    {
        printf("%d -> ", trav->val);
        trav = trav->next;
    }
    printf("NULL\n");

    ///////

    printf("\n");
    printAdjList(graph);

    freeList(nodeNeighbors); 
    freeAdjList(graph);

    return 0;
}
