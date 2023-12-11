#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the adjacency list
struct Node
{
    int vertex;
    int weight;
    struct Node *next;
};

// Structure to represent the graph
struct Graph
{
    int numVertices;
    struct Node **adjList;
};

// Function to create a new node
struct Node *createNode(int vertex, int weight)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices
struct Graph *createGraph(int numVertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    // Allocate memory for an array of adjacency lists
    graph->adjList = (struct Node **)malloc(numVertices * sizeof(struct Node *));

    // Initialize each adjacency list as empty
    for (int i = 0; i < numVertices; ++i)
    {
        graph->adjList[i] = NULL;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph *graph, int src, int dest, int weight)
{
    // Add an edge from src to dest
    struct Node *newNode = createNode(dest, weight);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // If the graph is undirected, add an edge from dest to src as well
    /*
    newNode = createNode(src, weight);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
    */
}

// Function to print the adjacency list representation of the graph
void printGraph(struct Graph *graph)
{
    for (int i = 0; i < graph->numVertices; ++i)
    {
        struct Node *temp = graph->adjList[i];
        printf("Adjacency list of vertex %d:\n", i);
        while (temp != NULL)
        {
            printf("-> %d (Weight: %d) ", temp->vertex, temp->weight);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    int numVertices = 5;
    struct Graph *graph = createGraph(numVertices);

    // Example: Adding edges to the graph
    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 3, 1);
    addEdge(graph, 1, 2, 4);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 3, 4, 3);

    // Print the adjacency list representation of the graph
    printGraph(graph);

    return 0;
}
