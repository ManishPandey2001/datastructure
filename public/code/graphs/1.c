//1. ENTER THE VERTICES AND EDGES AND REPRESENT IN ADJACENCY MATRIX AND PRINT IT.
#include< stdio.h >
#include< stdlib.h >

    void initMatrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = 0; 
        }
    }
    }
    void addEdge(int **matrix, int src, int dest) {
                 matrix[src][dest] = 1; 
                 matrix[dest][src] = 1; 
    }
    void printMatrix(int **matrix, int size) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
     }
     }
    int main() {
    int vertices, edges;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    int *matrix = (int *)malloc(vertices * sizeof(int *));
    for (int i = 0; i < vertices; i++) {
        matrix[i] = (int *)malloc(vertices * sizeof(int));
    }

    initMatrix(matrix, vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        int src, dest;
        printf("Enter edge (source destination): ");
        scanf("%d %d", &src, &dest);
        addEdge(matrix, src, dest);
    }

    printMatrix(matrix, vertices);

    for (int i = 0; i < vertices; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}



           





