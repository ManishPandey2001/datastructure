//4. TRAVERSE THE ADJACENT LIST WITH DEPTH FIRST SEARCH

#include< stdio.h >
#include< stdlib.h >

struct Node {
    int dest;
    struct Node* next;
};

struct Graph {
    int vertices;
    struct Node** adjList;
};

struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->adjList = malloc(vertices * sizeof(struct Node*));

    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

struct Node* createNode(int dest) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

void insertEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

void dfs(struct Graph* graph, int visited[], int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    struct Node* temp = graph->adjList[vertex];
    while (temp) {
        if (!visited[temp->dest]) {
            dfs(graph, visited, temp->dest);
        }
        temp = temp->next;
    }
}

int main() {
    int vertices, edges;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    struct Graph* graph = createGraph(vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        int src, dest;
        printf("Enter edge (source destination): ");
        scanf("%d %d", &src, &dest);
        insertEdge(graph, src, dest);
        insertEdge(graph, dest, src); 
    }

    int visited[vertices];
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
    }

    printf("DFS starting from vertex 0:\n");
    dfs(graph, visited, 0);

    printf("\n");

    for (int i = 0; i < vertices; i++) {
        struct Node* temp = graph->adjList[i];
        while (temp) {
            struct Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->adjList);
    free(graph);

    return 0;
}


