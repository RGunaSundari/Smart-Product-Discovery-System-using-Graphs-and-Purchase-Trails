#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "graph.h"


// Initialize graph
void initializeGraph(Graph *graph, int vertices)
{
    graph->vertices = vertices;

    for (int i = 0; i < vertices; i++)
    {
        graph->head[i] = NULL;
    }
}

// Insert or update an edge
void insertNode(Graph *graph, int source,
                int destination, int weight)
{
    Node *current = graph->head[source];

    while (current != NULL)
    {
        if (current->destination == destination)
        {
            current->weight += weight;
            return;
        }

        current = current->next;
    }

    Node *newNode = malloc(sizeof(Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    newNode->destination = destination;
    newNode->weight = weight;
    newNode->next = graph->head[source];

    graph->head[source] = newNode;
}

// Add an undirected edge
void addEdge(Graph *graph, int source,
             int destination, int weight)
{
    if (source < 0 || destination < 0 ||
        source >= graph->vertices ||
        destination >= graph->vertices ||
        source == destination || weight <= 0)
    {
        return;
    }

    insertNode(graph, source, destination, weight);
    insertNode(graph, destination, source, weight);
}

// Display graph
void displayGraph(const Graph *graph,
                  const Product products[])
{
    printf("\n========== PRODUCT GRAPH ==========\n");

    for (int i = 0; i < graph->vertices; i++)
    {
        printf("%s -> ", products[i].name);

        Node *current = graph->head[i];

        while (current != NULL)
        {
            printf("%s (Weight: %d) -> ",
                   products[current->destination].name,
                   current->weight);

            current = current->next;
        }

        printf("NULL\n");
    }

    printf("===================================\n");
}

// Free allocated memory
void freeGraph(Graph *graph)
{
    for (int i = 0; i < graph->vertices; i++)
    {
        Node *current = graph->head[i];

        while (current != NULL)
        {
            Node *temp = current;
            current = current->next;
            free(temp);
        }

        graph->head[i] = NULL;
    }
}

// Breadth First Search
void BFS(const Graph *graph, int start)
{
    int visited[MAX_PRODUCTS] = {0};
    int queue[MAX_PRODUCTS];

    int front = 0;
    int rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("\nBFS Traversal: ");

    while (front < rear)
    {
        int current = queue[front++];

        printf("%d ", current);

        Node *temp = graph->head[current];

        while (temp != NULL)
        {
            int next = temp->destination;

            if (!visited[next])
            {
                visited[next] = 1;
                queue[rear++] = next;
            }

            temp = temp->next;
        }
    }

    printf("\n");
}

// DFS helper function
void DFSUtil(const Graph *graph, int vertex, int visited[])
{
    visited[vertex] = 1;

    printf("%d ", vertex);

    Node *temp = graph->head[vertex];

    while (temp != NULL)
    {
        int next = temp->destination;

        if (!visited[next])
        {
            DFSUtil(graph, next, visited);
        }

        temp = temp->next;
    }
}

// Depth First Search
void DFS(const Graph *graph, int start)
{
    int visited[MAX_PRODUCTS] = {0};

    printf("\nDFS Traversal: ");

    DFSUtil(graph, start, visited);

    printf("\n");
}
// Load purchase transactions from CSV
int loadTransactionsFromCSV(
    Graph *graph,
    const Product products[],
    int count,
    const char *filename)
{
    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Unable to open CSV file!\n");
        return -1;
    }

    char line[256];
    int transactionCount = 0;

    while (fgets(line, sizeof(line), file) != NULL)
    {
        // Read customer ID
        char *customer = strtok(line, ",");

        // Read transaction ID
        char *transaction = strtok(NULL, ",");

        // Read product IDs
        char *productList = strtok(NULL, ",");
        // Skip CSV header
        if (strncmp(line, "CustomerID", 10) == 0 ||strncmp(line, "customerID", 10) == 0)
        {
            continue;
        }

        if (customer == NULL ||
            transaction == NULL ||
            productList == NULL)
        {
            continue;
        }

        int basket[MAX_PRODUCTS];
        int basketCount = 0;

        char *ptr = productList;

        // Extract product IDs
        while (*ptr != '\0')
        {
            while (isspace((unsigned char)*ptr))
                ptr++;

            if (*ptr == '\0')
                break;

            char *end;
            long productID = strtol(ptr, &end, 10);

            if (ptr == end)
            {
                break;
            }

            int index = findProductByID(
                products, count, (int)productID
            );

            if (index != -1 && basketCount < MAX_PRODUCTS)
            {
                int duplicate = 0;

                for (int i = 0; i < basketCount; i++)
                {
                    if (basket[i] == index)
                    {
                        duplicate = 1;
                        break;
                    }
                }

                if (!duplicate)
                {
                    basket[basketCount++] = index;
                }
            }

            ptr = end;
        }

        // Connect every pair of products
        for (int i = 0; i < basketCount; i++)
        {
            for (int j = i + 1; j < basketCount; j++)
            {
                addEdge(
                    graph,
                    basket[i],
                    basket[j],
                    1
                );
            }
        }

        transactionCount++;
    }

    fclose(file);

    return transactionCount;
}