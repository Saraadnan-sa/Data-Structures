#include <iostream>
#include <vector>
# include <queue>
using namespace std;

class Graph
{
private:
    int vertices;
    int **adjacencyMatrix;
    vector<vector<int>> adjacencyList;

public:
    Graph(int v) : vertices(v)
    {
        // Dynamically allocate memory for the adjacency matrix
        adjacencyMatrix = new int *[vertices];
        for (int i = 0; i < vertices; ++i)
        {
            adjacencyMatrix[i] = new int[vertices];
            // Initialize the adjacency matrix with zeros
            for (int j = 0; j < vertices; ++j)
            {
                adjacencyMatrix[i][j] = 0;
            }
        }

        // Resize the adjacency list to the number of vertices
        adjacencyList.resize(vertices);
    }

    void addEdge(int src, int dest)
    {
        // Assuming the graph is undirected
        adjacencyMatrix[src][dest] = 1;
        adjacencyMatrix[dest][src] = 1;

        // Update the adjacency list
        adjacencyList[src].push_back(dest);
        adjacencyList[dest].push_back(src);
    }

    // void printAdjacencyMatrix()
    // {
    //     cout << "Adjacency Matrix:\n";
    //     for (int i = 0; i < vertices; ++i)
    //     {
    //         for (int j = 0; j < vertices; ++j)
    //         {
    //             cout << adjacencyMatrix[i][j] << " ";
    //         }
    //         cout << endl;
    //     }
    // }

    // void printAdjacencyList()
    // {
    //     cout << "Adjacency List:\n";
    //     for (int i = 0; i < vertices; ++i)
    //     {
    //         cout << i << ": ";
    //         for (int j : adjacencyList[i])
    //         {
    //             cout << j << " ";
    //         }
    //         cout << endl;
    //     }
        
        
    // }

    void bfs(int startVertex)
    {
        // Array to keep track of visited vertices
        bool visited[vertices]={};
        

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
            for (int i = 0; i < vertices; ++i)
            {
                if (adjacencyMatrix[currentVertex][i] == 1 && !visited[i])
                {
                    bfsQueue.push(i);
                    visited[i] = true;
                }
            }
        }

        cout << endl;
    }



    ~Graph()
    {
        // Deallocate memory for the adjacency matrix
        for (int i = 0; i < vertices; ++i)
        {
            delete[] adjacencyMatrix[i];
        }
        delete[] adjacencyMatrix;
    }
};

int main()
{
    // Create a graph with 5 vertices
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

    // // Print adjacency matrix
    // graph.printAdjacencyMatrix();

    // // Print adjacency list
    // graph.printAdjacencyList();
graph.bfs(2);
    return 0;
}
