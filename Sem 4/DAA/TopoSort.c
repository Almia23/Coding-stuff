// TOPO SORT
#include <stdio.h>

int visited[20], adj[50][50], stack[50], k[50], i, j, top = 0;

void dfs(int v, int vn)
{
    visited[v] = 1;
    for (j = 0; j < vn; j++)
    {
        if (!visited[adj[i][j]])
            dfs(adj[i][j], k[adj[i][j]]);
    }
    stack[top++] = v;
}
int main()
{
    printf("Enter number of nodes: \n");
    int n;
    scanf("%d", &n);
    printf("Enter adjacency list\n");
    for (i = 0; i < n; i++)
    {
        printf("Enter num of adjacent nodes for node %d\n", i);
        scanf("%d", &k[i]);
        if (k[i] != 0)
        {
            for (j = 0; j < k[i]; j++)
            {
                scanf("%d", &adj[i][j]);
            }
        }
        visited[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, k[i]);
        }
    }
    printf("topological sort: \n");
    for (i = n - 1; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }
}
