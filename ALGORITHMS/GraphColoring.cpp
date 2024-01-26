#include <iostream>
using namespace std;

#define V 4

void GraphColoring(int G[V][V], int numberOfColors);
bool GraphColoringUtil(int G[V][V], int numberOfColors, int Result[], int vertex);
bool isSafe(int G[V][V], int Result[], int vertex, int c);
void printSolution(int Color[]);
int max(int Array[], int n);

void GraphColoring(int G[V][V], int numberOfColors)
{
    int Result[V] = {0};
    if (GraphColoringUtil(G, numberOfColors, Result, 0))
    {
        printSolution(Result);
        cout << "Minimum Number of Colors: " << max(Result, V) << endl;
    }
    else
    {
        cout << "Solution Not Possible" << endl;
    }
}
bool GraphColoringUtil(int G[V][V], int numberOfColors, int Result[], int vertex)
{
    if (vertex == V)
    {
        return true;
    }
    for (int c = 1; c <= numberOfColors; c++)
    {
        if (isSafe(G, Result, vertex, c))
        {
            Result[vertex] = c;
            if (GraphColoringUtil(G, numberOfColors, Result, vertex + 1))
            {
                return true;
            }
            Result[vertex] = 0;
        }
    }
    return false;
}
bool isSafe(int G[V][V], int Result[], int vertex, int c)
{

    for (int i = 0; i < V; i++)
    {
        if (G[vertex][i] && c == Result[i])
        {
            return false;
        }
    }
    return true;
}
void printSolution(int Color[])
{
    cout << "Vertex\tColor\n";
    for (int i = 0; i < V; i++)
    {
        cout << i << "\t" << Color[i] << endl;
    }
}

int max(int Array[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (Array[i] > res)
        {
            res = Array[i];
        }
    }
    return res;
}

int main()
{
    // int Graph[V][V] = {{0, 1, 0, 1, 1, 0, 1},
    //                    {1, 0, 1, 0, 0, 0, 0},
    //                    {0, 1, 0, 1, 0, 0, 0},
    //                    {1, 0, 1, 0, 1, 0, 0},
    //                    {1, 0, 0, 1, 0, 1, 0},
    //                    {0, 0, 0, 0, 1, 0, 1},
    //                    {1, 0, 0, 0, 0, 1, 0}};

    int Graph[V][V] = {{0, 1, 1, 1},
                       {1, 0, 1, 0},
                       {1, 1, 0, 1},
                       {1, 0, 1, 0}};

    GraphColoring(Graph, 6);
    return 0;
}