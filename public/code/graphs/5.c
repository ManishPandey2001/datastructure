//5. TRAVERSE THE ADJACENT MATRIX WITH BREADTH FIRST SEARCH.
#include< stdio.h >
#include< stdlib.h >

#define MAX_VERTICES 10

void bfs(int g[MAX_VERTICES][MAX_VERTICES], int vis[], int start, int n) {
    int queue[MAX_VERTICES], front = 0, rear = 0;
    vis[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int curr = queue[front++];
        printf("%d ", curr);

        for (int i = 0; i < n; i++) {
            if (g[curr][i] == 1 && !vis[i]) {
                vis[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}
    int main() {
    int n, e;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[MAX_VERTICES][MAX_VERTICES] = {0};
    printf("Enter number of edges: ");
    scanf("%d", &e);
    for (int i = 0; i < e; i++) {
        int src, dest;
        printf("Enter edge (source destination): ");
        scanf("%d %d", &src, &dest);
        graph[src][dest] = 1;
        graph[dest][src] = 1; 
    }

    int visited[MAX_VERTICES] = {0};
    printf("BFS starting from vertex 0:\n");
    bfs(graph, visited, 0, n);
    printf("\n");
    return 0;
}





