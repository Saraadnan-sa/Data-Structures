#include <iostream>
#include <climits>
#define v 7
using namespace std;

// Printing the solution
void printArr(int arr[], int size)
{
    cout << "Shortest distances from source:\n";
    for (int i = 0; i < size; i++)
    {
        cout << i << ": " << arr[i] << "\n";
    }
}

void BellmanFord(int graph[v][v], int V, int src)
{
    int dist[V];

    // Step 1: Initialize distances from the source to all other vertices as INFINITY
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    // Distance from the source to itself is 0
    dist[src] = 0;

    // Step 2: Relax all edges |V| - 1 times
    for (int k = 1; k <= V - 1; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (graph[i][j] != 0 &&
                    dist[i] != INT_MAX &&
                    dist[i] + graph[i][j] < dist[j])
                {
                    dist[j] = dist[i] + graph[i][j];
                }
            }
        }
    }

    // Step 3: Detect negative weight cycle
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (graph[i][j] != 0 && 
                dist[i] != INT_MAX && 
                dist[i] + graph[i][j] < dist[j])
            {
                cout << "Graph contains negative weight cycle\n";
                return;
            }
        }
    }

    // Print the distances
    printArr(dist, V);
}

int main()
{

    int graph[v][v] = {
        {0, 6, 5, 5, 0, 0, 0},
        {0, 0, 0, 0, -1, 0, 0},
        {0, -2, 0, 0, 1, 0, 0},
        {0, 0, -2, 0, 0, -1, 0},
        {0, 0, 0, 0, 0, 0, 3},
        {0, 0, 0, 0, 0, 0, 3},
        {0, 0, 0, 0, 0, 0, 0}};

    int sourceVertex = 0;
    BellmanFord(graph, v, sourceVertex);

    return 0;
}