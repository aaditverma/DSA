#include <iostream>
#include <climits>

using namespace std;

#define V 4
#define INF 99999

void printSolution(int dist[][V]);

void floydWarshall(int dist[][V]) {
    int i, j, k;

    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != INF && dist[i][k] != INF))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    printSolution(dist);
}

void printSolution(int dist[][V]) {
    cout << "The following matrix shows the shortest distances between every pair of vertices \n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF" << " ";
            else
                cout << dist[i][j] << "   ";
        }
        cout << endl;
    }
}

int main() {
    int graph[V][V];
    
    cout << "Enter the adjacency matrix for the graph (enter INF for infinity):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
            if(graph[i][j] == INF) {
                // Replace 'INF' with a large value
                graph[i][j] = INT_MAX;
            }
        }
    }

    floydWarshall(graph);

    return 0;
}
