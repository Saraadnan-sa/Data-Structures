#include <iostream>
#include <climits>
using namespace std;

#define V 4

int minDistance(int dist[], bool visited[])
{
    int min = INT_MAX;
    int min_index;
    for (int v = 0; v < V; v++)
        if (visited[v] == false && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    return min_index;
}
void printSolution(int dist[])
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t\t\t" << dist[i] << endl;
}
void dijkstra(int graph[V][V], int src)
{
    // step 1
    int dist[V];
    bool visited[V];

    // step 2
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    // step 3
    dist[src] = 0;

    // step 4
    for (int count = 0; count < V - 1; count++)
    {
        // step 5
        int u = minDistance(dist, visited);

        // step 6
        visited[u] = true;

        // step 7
        for (int v = 0; v < V; v++)
        {
            // step 8 -- 4 conditions
            if (!visited[v]                         // condition 1
                && graph[u][v]                      // condition 2
                && dist[u] != INT_MAX               // condition 3
                && dist[u] + graph[u][v] < dist[v]) // condition 4

                dist[v] = dist[u] + graph[u][v]; // function
        }
    }

    printSolution(dist);
}

int main()
{
    // int graph[V][V] = {
    //   // 0  1  2  3  4  5  6  7  8
    //     {0, 4, 0, 0, 0, 0, 0, 8, 0},   // 0
    //     {4, 0, 8, 0, 0, 0, 0, 11, 0},  // 1
    //     {0, 8, 0, 7, 0, 4, 0, 0, 2},   // 2
    //     {0, 0, 7, 0, 9, 14, 0, 0, 0},  // 3
    //     {0, 0, 0, 9, 0, 10, 0, 0, 0},  // 4
    //     {0, 0, 4, 14, 10, 0, 2, 0, 0}, // 5
    //     {0, 0, 0, 0, 0, 2, 0, 1, 6},   // 6
    //     {8, 11, 0, 0, 0, 0, 1, 0, 7},  // 7
    //     {0, 0, 2, 0, 0, 0, 6, 7, 0}};  // 8

    int graph[V][V] = {
        {0, 3, 1, 0},
        {3, 0, 0, 3},
        {1, 0, 0, 6},
        {0, 3, 6, 0}

    };

    // int graph[V][V] = {
    //     {0,10,5},
    //     {0,0,-8},
    //     {0,0,0}

    // };
    dijkstra(graph, 0);
    return 0;
}