// 20. Rotten Oranges
#include < stdio.h >
#include < stdlib.h >

#define MAX 100

typedef struct {
    int x;
    int y;
} Point;

int isValid(int i, int j, int n, int m) {
    return (i >= 0 && i < n && j >= 0 && j < m);
}


int orangesRotting(int grid[MAX][MAX], int n, int m) {
    Point queue[MAX * MAX]; // Queue for BFS
    int front = 0, rear = 0;
    int time = 0, freshCount = 0;
    
   
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 2) {
                queue[rear++] = (Point){i, j}; 
            } else if (grid[i][j] == 1) {
                freshCount++; 
            }
        }
    }

    
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  
    while (front < rear) {
        int size = rear - front;
        for (int i = 0; i < size; i++) {
            Point current = queue[front++];
            for (int d = 0; d < 4; d++) {
                int newX = current.x + directions[d][0];
                int newY = current.y + directions[d][1];
                if (isValid(newX, newY, n, m) && grid[newX][newY] == 1) {
                    grid[newX][newY] = 2; 
                    queue[rear++] = (Point){newX, newY}; 
                    freshCount--; 
                }
            }
        }
        if (rear > front) { 
            time++;
        }
    }

    return freshCount == 0 ? time : -1; 
}


int main() {
    int grid1[MAX][MAX] = {{0, 1, 2}, {0, 1, 2}, {2, 1, 1}};
    int result1 = orangesRotting(grid1, 3, 3);
    printf("Output: %d\n", result1); 

    int grid2[MAX][MAX] = {{2, 2, 0, 1}};
    int result2 = orangesRotting(grid2, 1, 4);
    printf("Output: %d\n", result2); 

    return 0;
}
