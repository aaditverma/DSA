#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int INF = INT_MAX;

int tsp(vector<vector<int>>& graph, int src, vector<bool>& visited, int n, int count, int cost, int& minCost) {
    if (count == n && graph[src][0]) {
        minCost = min(minCost, cost + graph[src][0]);
        return minCost;
    }

    for (int i = 0; i < n; ++i) {
        if (!visited[i] && graph[src][i]) {
            visited[i] = true;
            tsp(graph, i, visited, n, count + 1, cost + graph[src][i], minCost);
            visited[i] = false;
        }
    }

    return minCost;
}

int main() {
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter the cost matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    vector<bool> visited(n, false);
    visited[0] = true;
    int minCost = INF;
    tsp(graph, 0, visited, n, 1, 0, minCost);

    cout << "Minimum cost for TSP: " << minCost << endl;

    return 0;
}
