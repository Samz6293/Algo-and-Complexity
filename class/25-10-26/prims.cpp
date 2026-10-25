#include <bits/stdc++.h>
using namespace std;

//prototypes
void prims(int V, vector<vector<pair<int,int>>> &adj);

int main() {
    int V, E;
    cout << "Enter numeber of vertices and edges: ";
    cin >> V >> E;

    vector<vector<pair<int, int>>> adj(V);

    cout << "Enter edges (u v weight):\n";
    for (int i=0; i<E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    prims(V, adj);
}

void prims(int V, vector<vector<pair<int,int>>> &adj) {
    vector<int> key(V, INT_MAX);

    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);


    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    key[0] = 0;
    pq.push({0, 0});


    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if(inMST[u]) continue;
        inMST[u] = true;


        for (auto edge : adj[u]) {
            int v = edge.first;
            int wt = edge.second;

            if(!inMST[v] && wt < key[v]) {
                key[v] = wt;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    cout << "Edge weight\n";
    for (int i=1; i<V; i++) {
        cout << parent[i]<< " - " << i << "   " << key[i] << endl;
    }
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
