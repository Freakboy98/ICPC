#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int N, M, i, j;
int map[MAX][MAX];
int visited[MAX][MAX];
int parent[MAX][MAX][2];

// Directions for moving in the matrix (right, down, left, up)
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

// Function to check if the next move is valid
int is_valid(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < M && map[x][y] == 0 && !visited[x][y]);
}

// BFS function to find the shortest path
typedef struct {
    int x, y, dist;
} Node;

int bfs(int sx, int sy, int ex, int ey) {
    Node queue[MAX * MAX];
    int front = 0, rear = 0;

    queue[rear++] = (Node){sx, sy, 0};
    visited[sx][sy] = 1;
    parent[sx][sy][0] = -1; // To mark the starting node
    parent[sx][sy][1] = -1; // To mark the starting node

    while (front < rear) {
        Node current = queue[front++];
        int x = current.x;
        int y = current.y;
        int dist = current.dist;

        if (x == ex && y == ey) {
            return dist;
        }

        for (i = 0; i < 4; i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];

            if (is_valid(nx, ny)) {
                visited[nx][ny] = 1;
                parent[nx][ny][0] = x;
                parent[nx][ny][1] = y;
                queue[rear++] = (Node){nx, ny, dist + 1};
            }
        }
    }

    return -1; // If there is no path
}

// Function to print the path using arrows
void print_path_with_arrows(int ex, int ey) {
    int x = ex;
    int y = ey;

    while (parent[x][y][0] != -1 && parent[x][y][1] != -1) {
        int px = parent[x][y][0];
        int py = parent[x][y][1];

        if (px == x - 1 && py == y) {
            map[x][y] = 2; // Down arrow
        } else if (px == x + 1 && py == y) {
            map[x][y] = 3; // Up arrow
        } else if (px == x && py == y - 1) {
            map[x][y] = 4; // Right arrow
        } else if (px == x && py == y + 1) {
            map[x][y] = 5; // Left arrow
        }

        x = px;
        y = py;
    }

    // Mark the starting point with S and the ending point with E
    map[0][0] = 6; 
    map[ex][ey] = 7;

    // Print the map with arrows
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            if (map[i][j] == 2) {
                printf("ก้ ");
            } else if (map[i][j] == 3) {
                printf("ก่ ");
            } else if (map[i][j] == 4) {
                printf("กๆ ");
            } else if (map[i][j] == 5) {
                printf("ก็ ");
            } else if (map[i][j] == 6) {
                printf("Me ");
            } else if (map[i][j] == 7) {
                printf("EXist ");
            } else {
                printf("%d ", map[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    N = 6;
    M = 6;

    // Example map (0: normal, 1: abnormal)
    int example_map[6][6] = {
        {0, 0, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 1, 0},
        {1, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 0}
    };

    // Copy example_map to global map
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            map[i][j] = example_map[i][j];
            visited[i][j] = 0;
        }
    }

    int ex = N - 1;
    int ey = M - 1;

    printf("Finding shortest path using BFS...\n");
    int distance = bfs(0, 0, ex, ey);
    if (distance == -1) {
        printf("No path found.\n");
    } else {
        printf("Shortest path distance: %d\n", distance);
        print_path_with_arrows(ex, ey);
    }

    return 0;
}

