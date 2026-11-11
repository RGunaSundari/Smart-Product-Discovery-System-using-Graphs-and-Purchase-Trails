#ifndef GRAPH_H
#define GRAPH_H

#include "product.h"

typedef struct Node
{
    int destination;
    int weight;
    struct Node *next;

} Node;

typedef struct
{
    Node *head[MAX_PRODUCTS];
    int vertices;

} Graph;

void initializeGraph(Graph *graph, int vertices);

void addEdge(Graph *graph, int source, int destination, int weight);

void displayGraph(const Graph *graph,
                  const Product products[]);

void freeGraph(Graph *graph);

void BFS(const Graph *graph, int start);

void DFS(const Graph *graph, int start);

int loadTransactionsFromCSV(
    Graph *graph,
    const Product products[],
    int count,
    const char *filename
);

#endif