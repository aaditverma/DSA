#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

bool bfs(vector<vector<int>>& graph, int source, int sink, vector<int>& parent) {
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(source);
    visited[source] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 0; v < n; ++v) {
            if (!visited[v] && graph[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return visited[sink];
}

int edmonds_karp(vector<vector<int>>& graph, int source, int sink) {
    int n = graph.size();
    vector<int> parent(n, -1);
    int max_flow = 0;

    while (bfs(graph, source, sink, parent)) {
        int path_flow = INT_MAX;
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            path_flow = min(path_flow, graph[u][v]);
        }
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            graph[u][v] -= path_flow;
            graph[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    cout << "Enter the adjacency matrix (capacity) row-wise:" << endl;
    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    int source, sink;
    cout << "Enter the source node: ";
    cin >> source;
    cout << "Enter the sink node: ";
    cin >> sink;

    int max_flow = edmonds_karp(graph, source, sink);
    cout << "Max flow: " << max_flow << endl;

    return 0;
}