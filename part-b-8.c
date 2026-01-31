/* Graph Traversal Techniques: DFS and BFS */

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int adj[MAX][MAX], visited[MAX];
int n;

/* DFS using recursion */
void dfs(int v)
{
    int i;
    visited[v] = 1;
    printf("%d ", v);

    for(i = 0; i < n; i++)
    {
        if(adj[v][i] == 1 && !visited[i])
            dfs(i);
    }
}

/* BFS using queue */
void bfs(int start)
{
    int queue[MAX], front = 0, rear = 0;
    int i, v;

    for(i = 0; i < n; i++)
        visited[i] = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while(front < rear)
    {
        v = queue[front++];
        printf("%d ", v);

        for(i = 0; i < n; i++)
        {
            if(adj[v][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main()
{
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    for(i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS traversal: ");
    dfs(start);

    printf("\nBFS traversal: ");
    bfs(start);

    return 0;
}
