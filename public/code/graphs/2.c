//2. CREATE THE GRAPH AS A ADJACENCY LIST WITH OPERATIONS SUCH AS INSERTION, DELETION
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

void deleteEdge(struct Graph* graph, int src, int dest) {
    struct Node* temp = graph->adjList[src];
    struct Node* prev = NULL;

    while (temp != NULL && temp->dest != dest) {
        prev = temp;
        temp = temp->next;
    }

    if (temp != NULL) {
        if (prev == NULL) {
            graph->adjList[src] = temp->next;
        } else {
            prev->next = temp->next;
        }
        free(temp);
    }
}

void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->vertices; i++) {
        struct Node* temp = graph->adjList[i];
        printf("Vertex %d: ", i);
        while (temp) {
            printf("%d -> ", temp->dest);
            temp = temp->next;
        }
        printf("NULL\n");
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
    }

    printf("\nAdjacency List Representation:\n");
    printGraph(graph);

    int srcDel, destDel;
    printf("Enter edge to delete (source destination): ");
    scanf("%d %d", &srcDel, &destDel);
    deleteEdge(graph, srcDel, destDel);
    
    printf("\nAdjacency List after deletion:\n");
    printGraph(graph);

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



