#include <bits/stdc++.h>
using namespace std;

// prototypes
void fillData (int edges, vector<vector<int>>& adj);
void dfs (int node, vector<vector<int>>& adj, vector<bool>& visited);

int main () {

    cout << "Vertices Edges: ";
    int vertices, edges;
    cin >> vertices >> edges;


    vector<vector<int>> adj(vertices);
    fillData(edges, adj);

    cout << "Start vertex: ";
    int start;
    cin >> start;

    vector<bool> visited(vertices, false);

    cout << "DFS: ";
    dfs(start, adj, visited);
}

void fillData (int edges, vector<vector<int>>& adj) {

    cout << "Edges (u, v)" << endl;
    for (int i=0; i<edges; i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs (int node, vector<vector<int>>& adj, vector<bool>& visited) {

    visited[node] = true;
    cout << node << " ";

    for (int i=0; i<adj[node].size(); i++) {

        int neighbour = adj[node][i];
        if(!visited[neighbour]) {
            dfs(neighbour, adj, visited);
        }
    }
}