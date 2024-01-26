#include <iostream>
using namespace std;

const int MAX_NODES = 100;  // Maximum number of nodes, adjust as needed

class Graph {
private:
    int nodes[MAX_NODES];
    bool edges[MAX_NODES][MAX_NODES];

public:
    Graph() {
        // Initialize nodes and edges
        for (int i = 0; i < MAX_NODES; ++i) {
            nodes[i] = 0;
            for (int j = 0; j < MAX_NODES; ++j) {
                edges[i][j] = false;
            }
        }
    }

    void addNode(int node) {
        // Add a new node to the graph
        if (nodes[node] == 0) {
            nodes[node] = 1;
        }
    }

    void displayGraph() {
        // Display the graph in adjacency matrix format
        for (int i = 0; i < MAX_NODES; ++i) {
            if (nodes[i] == 1) {
                cout << i << ": ";
                for (int j = 0; j < MAX_NODES; ++j) {
                    if (edges[i][j]) {
                        cout << j << " ";
                    }
                }
                cout  << endl;
            }
        }
    }

    void addEdge(int node1, int node2) {
        // Add an undirected edge between node1 and node2
        if (nodes[node1] == 1 && nodes[node2] == 1) {
            edges[node1][node2] = true;
            edges[node2][node1] = true;
        }
        else if (nodes[node1]==0){
            cout<<"Node "<<node1<<" do not exists"<<endl;
        }
        else if (nodes[node2]==0){
            cout<<"Node "<<node2<<" do not exists"<<endl;
        }
    }
};

int main() {
    Graph graph;

    // Adding nodes
    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(3);

    // Adding edges
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(4,3);

    // Display the graph
    graph.displayGraph();

    return 0;
}
