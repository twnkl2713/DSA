#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int parent, vector<int>& vis, vector<int> adj[]) {
    vis[node] = 1;

    for (auto adjacentNode : adj[node]) {
        if (!vis[adjacentNode]) {
            if (dfs(adjacentNode, node, vis, adj)) {
                return true; // Cycle found in DFS subtree
            }
        } else if (adjacentNode != parent) {
            return true; // Visited node that isn't the parent ⇒ cycle
        }
    }
    return false;
}

bool isCycle(int V, vector<vector<int>>& edges) {
    vector<int> adj[V];
    for (auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u); // Because the graph is undirected
    }

    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (dfs(i, -1, vis, adj)) return true;
        }
    }

    return false;
}

int main() {
    int V = 5;
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 0}, // forms a cycle
        {3, 4}
    };
    if (isCycle(V, edges)) {
        cout << "Cycle Detected!" << endl;
    } else {
        cout << "No Cycle Found." << endl;
    }
    return 0;
}
