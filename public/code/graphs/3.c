//3. TRAVERSE THE ADJACENT MATRIX WITH DEPTH FIRST SEARCH
 #include< stdio.h >
#include< stdlib.h >
    void dfs(int graph[][10], int visited[], int v, int n) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            dfs(graph, visited, i, n);
        }
    }
}
int main() {
    int n, e;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[10][10] = {0};
    printf("Enter number of edges: ");
    scanf("%d", &e);

    for (int i = 0; i < e; i++) {
        int src, dest;
        printf("Enter edge (source destination): ");
        scanf("%d %d", &src, &dest);
        graph[src][dest] = 1;
        graph[dest][src] = 1;
    }

    int visited[10] = {0};
    
    printf("DFS starting from vertex 0:\n");
    dfs(graph, visited, 0, n);

    printf("\n");
    return 0;
}

    

 