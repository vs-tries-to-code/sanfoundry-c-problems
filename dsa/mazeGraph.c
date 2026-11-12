
#include <stdio.h>
#include <limits.h>

#define MAX 100

// globally declaring matrices - visited for dfs, dist for bfs
int maze[MAX][MAX];
int visited[MAX][MAX];
int dist[MAX][MAX];

int n;

// Queue
struct Queue {
    int a[MAX * MAX][2];
    int front, rear;
};

typedef struct Queue q;

//q initialisation globally
q Q = {.front = 0, .rear = -1};


int dir[5] = {-1, 0, 1, 0, -1};

//queue ops
void enqueue(int r, int c) {
    //overflow
    if(Q.rear == MAX * MAX - 1) {
        printf("Queue overflow\n");
        return;
    }

    Q.rear++;

    Q.a[Q.rear][0] = r;
    Q.a[Q.rear][1] = c;
}

int isEmpty() {
    return Q.front > Q.rear;
}

void dequeue(int cell[2]) {
    if(!isEmpty()){
        cell[0] = Q.a[Q.front][0];
        cell[1] = Q.a[Q.front][1];
    }

    Q.front++;
}


int dfs(int r, int c, int endX, int endY) {

    //boundary check
    if(r < 0 || r >= n || c < 0 || c >= n)
        return 0;

    //check obstacle or visited
    if(maze[r][c] == 1 || visited[r][c])
        return 0;

    //dest reached!
    if(r == endX && c == endY)
        return 1;

    visited[r][c] = 1;

    //explore all four directions
    for(int i = 0; i < 4; i++) {

        int nr = r + dir[i];
        int nc = c + dir[i+1];

        if(dfs(nr, nc, endX, endY))
            return 1;
    }

    return 0;
}

int bfs(int startX, int startY, int endX, int endY) {

    //important, reset queue! 
    Q.front = 0;
    Q.rear = -1;

    //initialise distance matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            dist[i][j] = INT_MAX;
        }
    }

    //starting position
    dist[startX][startY] = 0;
    enqueue(startX, startY);

    while(!isEmpty()) {

        int cell[2];
        dequeue(cell);

        int r = cell[0];
        int c = cell[1];

        //destination reached
        if(r == endX && c == endY)
            return dist[r][c];

        //explore neighbours
        for(int i = 0; i < 4; i++) {

            int nr = r + dir[i];
            int nc = c + dir[i+1];

            if(nr >= 0 && nr < n &&
               nc >= 0 && nc < n &&
               maze[nr][nc] == 0 &&
               dist[nr][nc] == INT_MAX) {

                dist[nr][nc] = dist[r][c] + 1;

                enqueue(nr, nc);
            }
        }
    }

    return -1;
}

int main() {

    printf("Enter dimension of grid (n x n):\n");
    scanf("%d", &n);

    if(n <= 0 || n > MAX) {
        printf("Invalid dimension\n");
        return 0;
    }

    printf("Enter maze (1: obstacle, 0: path):\n");

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &maze[i][j]);
        }
    }

    int startX, startY, endX, endY;

    printf("Enter starting position:\n");
    scanf("%d %d", &startX, &startY);

    printf("Enter destination:\n");
    scanf("%d %d", &endX, &endY);

    //validate positions
    if(startX < 0 || startX >= n ||
       startY < 0 || startY >= n ||
       endX < 0 || endX >= n ||
       endY < 0 || endY >= n ||
       maze[startX][startY] == 1 ||
       maze[endX][endY] == 1) {

        printf("Invalid starting or destination cell\n");
        return 0;
    }

    //initialise visited matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            visited[i][j] = 0;
        }
    }

    // DFS
    if(dfs(startX, startY, endX, endY))
        printf("\nDFS: Path exists\n");
    else
        printf("\nDFS: No path exists\n");

    // BFS
    int shortest = bfs(startX, startY, endX, endY);

    if(shortest != -1)
        printf("BFS: Shortest distance = %d\n", shortest);
    else
        printf("BFS: No path exists\n");

    return 0;
}