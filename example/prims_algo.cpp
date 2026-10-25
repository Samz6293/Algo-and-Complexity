#include <bits/stdc++.h>
using namespace std;

void prims(int V, vector<vector<pair<int,int>>> &adj) {

    vector<int> key(V, INT_MAX);        // Minimum weight edge

// We here just initialized v positions with INT_MAX value. we still can insert more than v positions here

    vector<int> parent(V, -1);          // Store MST
    vector<bool> inMST(V, false);       // Track included vertices

    // Min-heap {weight, vertex}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

// pair<int,int> to store weight, vertex.
// vector<pair<int,int>> for internal use ( to store elements in heap order)
// priority_queue is by default max_heap, to make it min_heap we used "greater<pair<int,int>>"
 
    key[0] = 0;               // Start from node 0
    pq.push({0, 0});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;

        

        // for(int i = 0; i<adj[u].size(); i++){
        //  int v = adj[u][i].first;
        //  int wt = adj[u][i].second;
        
        for (auto edge : adj[u]) {
            int v = edge.first;
            int wt = edge.second;

            if (!inMST[v] && wt < key[v]) {
                key[v] = wt;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    cout << "Edge   Weight\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << "    " << key[i] << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<pair<int,int>>> adj(V);

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // undirected graph
    }

    prims(V, adj);

    return 0;
}
/*
5 6
0 1 2
0 3 6
1 2 3
1 3 8
1 4 5
2 4 7
*/