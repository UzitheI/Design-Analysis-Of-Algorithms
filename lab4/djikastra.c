#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define V 9

int minDistance(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void printPath(int parent[], int j)
{
    if (parent[j] == -1)
        return;
    printPath(parent, parent[j]);
    printf("%d ", j);
}

void printSolution(int dist[], int parent[], int src)
{
    printf("Vertex\t Distance\tPath");
    for (int i = 0; i < V; i++)
    {
        printf("\n%d -> %d \t\t %d\t\t%d ", src, i, dist[i], src);
        printPath(parent, i);
    }
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V];
    bool sptSet[V];
    int parent[V];

    for (int i = 0; i < V; i++)
    {
        parent[src] = -1;
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (!sptSet[v] && graph[u][v] &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v])
            {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist, parent, src);
}

int main()
{
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    printf("Dijkstra's Shortest Path Algorithm\n\n");
    dijkstra(graph, 0);

    return 0;
}