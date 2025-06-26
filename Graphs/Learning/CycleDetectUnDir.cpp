#include <bits/stdc++.h>
using namespace std;

// Function to detect cycle using BFS
bool detectCycle(int src, vector<int> adj[], vector<int>& vis) {
    vis[src] = 1;
    queue<pair<int, int>> q;
    q.push({src, -1}); // node, parent

    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto neighbor : adj[node]) {
            if (!vis[neighbor]) {
                vis[neighbor] = 1;
                q.push({neighbor, node});
            } else if (neighbor != parent) {
                return true; // Found a cycle
            }
        }
    }
    return false;
}

// Function to check for cycle in any component
bool isCycle(int V, vector<vector<int>>& edges) {
    vector<int> adj[V];
    for (auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }

    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (detectCycle(i, adj, vis)) return true;
        }
    }
    return false;
}

int main() {
    int V = 5; // Number of vertices
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 0}, // This forms a cycle
        {3, 4}
    };

    if (isCycle(V, edges)) {
        cout << "Cycle Detected!" << endl;
    } else {
        cout << "No Cycle Found." << endl;
    }
    return 0;
}
