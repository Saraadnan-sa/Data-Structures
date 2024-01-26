#include <iostream>
#include <algorithm>
using namespace std;

class Graph {
    int **edgelist;
    int V;
    int edgeCount;

public:
    Graph(int V, int E)
    {
        this->V = V;
        this->edgeCount = 0;

        edgelist = new int *[E];
        for (int i = 0; i < E; i++)
        {
            edgelist[i] = new int[3]; // Assuming each edge has 3 elements (weight, vertex1, vertex2)
        }
    }

    // Function to add an edge in a graph
    void addEdge(int x, int y, int w)
    {
        edgelist[edgeCount][0] = w;
        edgelist[edgeCount][1] = x;
        edgelist[edgeCount][2] = y;
        edgeCount++;
    }

    // Find function with path compression
    int find(int i, int parent[])
    {
        if (parent[i] == -1)
            return i;

        return parent[i] = find(parent[i], parent);
    }

    // Union function with rank by union
    void unite(int x, int y, int parent[], int rank[])
    {
        int s1 = find(x, parent);
        int s2 = find(y, parent);

        if (s1 != s2)
        {
            if (rank[s1] < rank[s2])
            {
                parent[s1] = s2;
            }
            else if (rank[s1] > rank[s2])
            {
                parent[s2] = s1;
            }
            else
            {
                parent[s2] = s1;
                rank[s1] += 1;
            }
        }
    }

    void kruskals_mst()
    {
        // Sort all edges
        sort(edgelist, edgelist + edgeCount, [](const int *a, const int *b) {
            return a[0] < b[0];
        });

        // Initialize parent and rank arrays
        int *parent = new int[V];
        int *rank = new int[V];
        for (int i = 0; i < V; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }

        int ans = 0;
        cout << "Following are the edges in the "
                "constructed MST"
             << endl;
        for (int i = 0; i < edgeCount; i++)
        {
            int w = edgelist[i][0];
            int x = edgelist[i][1];
            int y = edgelist[i][2];

            // Take this edge in MST if it does
            // not form a cycle
            if (find(x, parent) != find(y, parent))
            {
                unite(x, y, parent, rank);
                ans += w;
                cout << x << " -- " << y << " == " << w << endl;
            }
        }
        cout << "Minimum Cost Spanning Tree: " << ans;

        // Deallocate memory
        delete[] parent;
        delete[] rank;
    }

    // Destructor to deallocate memory
    ~Graph()
    {
        for (int i = 0; i < edgeCount; i++)
        {
            delete[] edgelist[i];
        }
        delete[] edgelist;
    }
};

// Driver code
int main()
{
    int V = 4, E = 5;
    Graph g(V, E);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);
    g.addEdge(2, 0, 6);
    g.addEdge(0, 3, 5);

    // Function call
    g.kruskals_mst();

    return 0;
}
