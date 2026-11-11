#include<bits/stdc++.h>
using namespace std;

// prototypes
int findParent(int v, vector<int> &parent);
void kruskal(int V, vector<vector<int>> &edges)

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> edges;

    cout << "Enter edges (u, v, weight): " << endl;
    for (int i=0; i<E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    kruskal(V, edges);
    return 0;
}

int findParent(int v, vector<int> &parent) {
    if (parent[v] == v) return v;
    return findParent(parent[v], parent);
}

void kruskal(int V, vector<vector<int>> &edges) {
    sort(edges.begin(), edges.end(),
         [](vector<int> &a, vector<int> &b) {
             return a[2] < b[2];
         });

    vector<int> parent(V);
    for (int i=0; i<V; i++)
        parent[i] = i;
    int edgeCount = 0;
    int totalCost = 0;

    cout << "Edge Weigt"
}
