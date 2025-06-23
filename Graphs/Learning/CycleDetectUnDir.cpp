#include <iostream>
#include <vector>
using namespace std;

class Edge {
public:
    int src, dest;
    Edge(int s, int d) {
        src = s;
        dest = d;
    }
};

void createGraph(vector<Edge> graph[], int V) {
    for (int i = 0; i < V; i++) {
        graph[i] = vector<Edge>();
    }
    graph[0].push_back(Edge(0, 1));
    graph[0].push_back(Edge(0, 2));
    graph[0].push_back(Edge(0, 3));
    graph[1].push_back(Edge(1, 0));
    graph[1].push_back(Edge(1, 2));
    graph[2].push_back(Edge(2, 0));
    graph[2].push_back(Edge(2, 1));
    graph[3].push_back(Edge(3, 0));
    graph[3].push_back(Edge(3, 4));
    graph[4].push_back(Edge(4, 3));
}

bool isCyclicUtil(vector<Edge> graph[], vector<bool>& vis, int curr, int par) {
    vis[curr] = true;

    for (Edge e : graph[curr]) {
        if (vis[e.dest] && e.dest != par) {
            // Case 1: visited & not parent → cycle
            return true;
        } else if (!vis[e.dest]) {
            // Case 2: not visited → DFS
            if (isCyclicUtil(graph, vis, e.dest, curr)) {
                return true;
            }
        }
        // Case 3: visited & is parent → do nothing (continue)
    }

    return false;
}

bool isCyclic(vector<Edge> graph[], int V) {
    vector<bool> vis(V, false);
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (isCyclicUtil(graph, vis, i, -1)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int V = 5;
    vector<Edge> graph[V];
    createGraph(graph, V);

    if (isCyclic(graph, V)) {
        cout << "Cycle detected" << endl;
    } else {
        cout << "No cycle detected" << endl;
    }
    return 0;
}
