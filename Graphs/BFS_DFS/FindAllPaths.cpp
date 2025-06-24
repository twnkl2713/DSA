#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<int> &visited, vector<vector<int>> &graph, int node) {
    visited[node] = 1;
    for (int nbr : graph[node]) {
        if (!visited[nbr]) {
            dfs(visited, graph, nbr);
        }
    }
}

bool validPath(int n, vector<vector<int>> &edges, int source, int destination) {
    vector<int> visited(n, 0);
    vector<vector<int>> graph(n);

    for (int i = 0; i < edges.size(); i++) {
        int a = edges[i][0];
        int b = edges[i][1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(visited, graph, source);
    return visited[destination];
}

int main() {
    int n = 6;
    vector<vector<int>> edges = {
        {0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}
    };
    int source = 0;
    int destination = 5;

    if (validPath(n, edges, source, destination)) {
        cout << "Path exists between " << source << " and " << destination << endl;
    } else {
        cout << "No valid path between " << source << " and " << destination << endl;
    }
    return 0;
}
