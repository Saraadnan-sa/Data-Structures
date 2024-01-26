#include <iostream>
#include <stack>

using namespace std;

// Assuming a maximum number of vertices
const int MAX_VERTICES = 5;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void dfs(int v, int graph[MAX_VERTICES][MAX_VERTICES], bool visited[MAX_VERTICES], stack<int>& order, int V) {
    visited[v] = true;
    for (int u = 0; u < V; ++u) {
        if (graph[v][u] && !visited[u]) {
            dfs(u, graph, visited, order, V);
        }
    }
    order.push(v);
}

void dfsTranspose(int v, Node* transposeGraph[MAX_VERTICES], bool visited[MAX_VERTICES]) {
    visited[v] = true;
    cout << v << " ";
    Node* current = transposeGraph[v];
    while (current != nullptr) {
        if (!visited[current->data]) {
            dfsTranspose(current->data, transposeGraph, visited);
        }

        current = current->next;
    }
}

void Kosarajus_algo(int graph[MAX_VERTICES][MAX_VERTICES], int V) {
    
    bool visited[MAX_VERTICES] = {false};
    stack<int> order;

    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            dfs(i, graph, visited, order, V); 
        }
    }

    // Transpose the graph
    Node* transposeGraph[MAX_VERTICES] = {nullptr};
    for (int i = 0; i < V; ++i) {
        for (int u = 0; u < V; ++u) {
            if (graph[i][u]) {
                Node* newNode = new Node(i);
                newNode->next = transposeGraph[u];
                transposeGraph[u] = newNode;
            }
        }
    }

    bool visited2[MAX_VERTICES] = {false};

    // Print strongly connected components
    while (!order.empty()) {
        int v = order.top();
        order.pop();

        if (!visited2[v]) {
            dfsTranspose(v, transposeGraph, visited2);
            cout << endl;
        }
    }
}

int main() {
    int V = 5;
    int graph[MAX_VERTICES][MAX_VERTICES] = {0};

    // Adding edges to the graph
    graph[0][1] = 1;
    graph[1][2] = 1;
    graph[2][0] = 1;
    graph[1][3] = 1;
    graph[3][4] = 1;

    cout << "Strongly Connected Components:\n";
    Kosarajus_algo(graph, V);

    return 0;
}