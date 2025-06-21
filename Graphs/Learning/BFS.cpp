#include <iostream>
#include <vector>
#include <queue>
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

void createGraph(vector<Edge> graph[], int V) {
    for(int i = 0; i < V; i++) {
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

void bfs(vector<Edge> graph[], int V) {
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(0); // Start from source node 0

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        if(!visited[curr]) {
            cout << curr << " ";
            visited[curr] = true;
            for(Edge e : graph[curr]) {
                q.push(e.dest);
            }
        }
    }
    cout << endl;
}

int main() {
    int V = 7;
    vector<Edge> graph[V];
    createGraph(graph, V);
    bfs(graph, V);

    return 0;
}
