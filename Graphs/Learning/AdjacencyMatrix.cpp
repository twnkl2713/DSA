#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

void printGraph(const vector<vector<int>>& adjacencyMatrix) {
    int n = adjacencyMatrix.size();
    for (int i = 1; i < n; i++) {
        cout << "Node: " << i << ", Neighbors: ";
        for (int j = 1; j < n; j++) {
            if (adjacencyMatrix[i][j] == 1) {
                cout << j << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    vector<pair<int, int>> edgeList = {
        {11, 5}, {6, 3}, {3, 4}, {4, 2}, {1, 3}
    };

    // Find the maximum node value to size the adjacency matrix correctly
    int maxNode = 0;
    for (auto edge : edgeList) {
        maxNode = max({maxNode, edge.first, edge.second});
    }

    // Create adjacency matrix of size (maxNode+1) x (maxNode+1)
    vector<vector<int>> adjacencyMatrix(maxNode + 1, vector<int>(maxNode + 1, 0));

    for (auto edge : edgeList) {
        int a = edge.first;
        int b = edge.second;
        adjacencyMatrix[a][b] = 1;
        adjacencyMatrix[b][a] = 1; // Since the graph is undirected
    }
    printGraph(adjacencyMatrix);
    return 0;
}
