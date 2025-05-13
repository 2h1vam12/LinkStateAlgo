#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <climits>
#include <chrono>

using namespace std;

const int INF = 1073741824;

void dijkstra(const vector<vector<int>>& graph, int src, int verbose) {
    int n = graph.size();
    vector<int> dist(n, INF);
    vector<bool> visited(n, false);
    vector<int> prev(n, -1);
    dist[src] = 0;

    if (verbose) {
        cout << "Step-by-step Dijkstra table:" << endl;
    }

    for (int i = 0; i < n; ++i) {
        int u = -1;
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }

        if (u == -1 || dist[u] == INF) break;

        visited[u] = true;
        for (int v = 0; v < n; ++v) {
            if (!visited[v] && graph[u][v] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                prev[v] = u;
            }
        }

        if (verbose) {
            cout << "After step " << i + 1 << ":" << endl;
            for (int k = 0; k < n; ++k) {
                cout << "Node " << k << ": Distance = " << (dist[k] == INF ? -1 : dist[k])
                     << ", Prev = " << prev[k] << endl;
            }
            cout << "-----------------------------" << endl;
        }
    }

    cout << "Forwarding Table from Node " << src << ":" << endl;
    for (int i = 0; i < n; ++i) {
        if (i == src || dist[i] == INF) continue;
        int path = i;
        while (prev[path] != src && prev[path] != -1) {
            path = prev[path];
        }
        int next_hop = (prev[i] == -1 ? -1 : path);
        cout << "To Node " << i << ": Next Hop = " << next_hop
             << ", Cost = " << dist[i] << endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cerr << "Usage: " << argv[0] << " <input_file> <source_node> <verbose_flag>" << endl;
        return 1;
    }

    string filename = argv[1];
    int source = stoi(argv[2]);
    int verbose = stoi(argv[3]);

    ifstream infile(filename);
    if (!infile) {
        cerr << "Error: Could not open file " << filename << endl;
        return 1;
    }

    int n;
    infile >> n;
    vector<vector<int>> graph(n, vector<int>(n, INF));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int cost;
            infile >> cost;
            if (i == j) {
                graph[i][j] = 0;
            } else if (cost == 0) {
                graph[i][j] = INF;  // Treat as no direct link unless explicitly nonzero
            } else {
                graph[i][j] = cost;
            }
                }
            }

    auto start = chrono::high_resolution_clock::now();
    dijkstra(graph, source, verbose);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> elapsed = end - start;
    cout << "Execution Time: " << elapsed.count() << " ms" << endl;

    return 0;
}