#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph
{
private:
    int vertices;
    list<int> *adjacencyList; // Array of linked lists

public:
    Graph(int v) : vertices(v)
    {
        adjacencyList = new list<int>[vertices];
    }

    void addEdge(int src, int dest)
    {
        // Assuming the graph is undirected
        adjacencyList[src].push_back(dest);
        adjacencyList[dest].push_back(src);
    }

    void printAdjacencyList()
    {
        cout << "Adjacency List:\n";
        for (int i = 0; i < vertices; ++i)
        {
            cout << i << ": ";
            for (int j : adjacencyList[i])
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    void bfs(int startVertex)
    {
        // Array to keep track of visited vertices
        bool *visited = new bool[vertices];
        for (int i = 0; i < vertices; ++i)
        {
            visited[i] = false;
        }

        // Queue for BFS traversal
        queue<int> bfsQueue;

        // Start with the given vertex
        bfsQueue.push(startVertex);
        visited[startVertex] = true;

        cout << "BFS starting from vertex " << startVertex << ": ";

        while (!bfsQueue.empty())
        {
            int currentVertex = bfsQueue.front();
            cout << currentVertex << " ";
            bfsQueue.pop();

            // Enqueue adjacent vertices that haven't been visited
            for (int neighbor : adjacencyList[currentVertex])
            {
                if (!visited[neighbor])
                {
                    bfsQueue.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }

        cout << endl;

        delete[] visited;
    }

    ~Graph()
    {
        delete[] adjacencyList;
    }
};

int main()
{
    // Create a graph with 9 vertices
    Graph graph(9);

    // Add edges
    graph.addEdge(1, 2);
    graph.addEdge(1, 5);
    graph.addEdge(2, 6);
    graph.addEdge(3, 6);
    graph.addEdge(3, 7);
    graph.addEdge(3, 4);
    graph.addEdge(4, 8);
    graph.addEdge(4, 7);
    graph.addEdge(6, 7);
    graph.addEdge(7, 8);

    // Print adjacency list
    graph.printAdjacencyList();

    // Perform BFS starting from vertex 2
    graph.bfs(2);

    return 0;
}
