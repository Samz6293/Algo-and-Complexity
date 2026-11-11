#include <bits/stdc++.h>
using namespace std;

// prototypes
void fillData (int edges, vector<vector<int>>& adj);
void bfs (int start, int vertices, vector<vector<int>>& adj);

int main () {
    cout << "Vertices Edges: ";
    int vertices, edges;
    cin >> vertices >> edges;

    vector<vector<int>> adj(vertices);
    fillData(edges, adj);

    int start;
    cout << "Start Vertex: ";
    cin >> start;

    bfs(start, vertices, adj);
}

void fillData (int edges, vector<vector<int>>& adj) {

    cout << "Edges (u, v)" << endl;
    for (int i=0; i<edges; i++) {

        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void bfs (int start, int vertices, vector<vector<int>>& adj) {
    vector<bool> visited(vertices, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS: ";
    while (!q.empty())
    {
        int node = q.front();
        cout << node << " ";
        q.pop();

        for(int i=0; i<adj[node].size(); i++) {

            int neighbour = adj[node][i];
            if(!visited[neighbour]) {

                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
    
}