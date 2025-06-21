#include <iostream>
#include <vector>
using namespace std;

class Edge {
public:
    int src;
    int dest;
    int wt;
    Edge(int s, int d, int w) {
        src = s;
        dest = d;
        wt = w;
    }
};

void printAllPaths(vector<Edge> graph[], int src, int tar, string path, vector<bool>& vis) {
    if (src == tar) {
        cout << path << endl;
        return;
    }

    for (Edge e : graph[src]) {
        if (!vis[e.dest]) {
            vis[e.dest] = true;
            printAllPaths(graph, e.dest, tar, path + "->" + to_string(e.dest), vis);
            vis[e.dest] = false;
        }
    }
}

void createGraph(vector<Edge> graph[], int V) {
    for (int i = 0; i < V; i++) {
        graph[i] = vector<Edge>();
    }

    graph[0].push_back(Edge(0, 1, 1));
    graph[0].push_back(Edge(0, 2, 1));

    graph[1].push_back(Edge(1, 0, 1));
    graph[1].push_back(Edge(1, 3, 1));

    graph[2].push_back(Edge(2, 0, 1));
    graph[2].push_back(Edge(2, 4, 1));

    graph[3].push_back(Edge(3, 1, 1));
    graph[3].push_back(Edge(3, 4, 1));
    graph[3].push_back(Edge(3, 5, 1));

    graph[4].push_back(Edge(4, 2, 1));
    graph[4].push_back(Edge(4, 3, 1));
    graph[4].push_back(Edge(4, 5, 1));

    graph[5].push_back(Edge(5, 3, 1));
    graph[5].push_back(Edge(5, 4, 1));
    graph[5].push_back(Edge(5, 6, 1));

    graph[6].push_back(Edge(6, 5, 1));
}

int main() {
    int V = 7;
    vector<Edge> graph[V];
    createGraph(graph, V);

    int src = 0;
    int tar = 5;

    vector<bool> vis(V, false);
    vis[src] = true;
    printAllPaths(graph, src, tar, to_string(src), vis);

    return 0;
}
