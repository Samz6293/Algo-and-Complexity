#include<bits/stdc++.h>
using namespace std;

// prototypes
void takeInput(int edges, vector<vector<int>>& graph);
void prims(int vertices, vector<vector<int>>& graph);

int main() {

    int vertices, edges;
    cout << "Vertices, Edges: ";
    cin >> vertices >> edges;

    // VxV table;
    vector<vector<int>> graph(vertices, vector<int> (vertices, 0));
    takeInput(edges, graph);

    prims(vertices, graph);

}

void takeInput(int edges, vector<vector<int>>& graph) {

    cout << "u v weight" << endl;
    for (int i=0; i<edges; i++) {
        int u,v,weight;
        cin >> u >> v >> weight;

        graph[u][v] = weight;
        graph[v][u] = weight;
    }
}

void prims(int vertices, vector<vector<int>>& graph) {

    vector<int> key(vertices, INT_MAX);
    vector<int> parent(vertices, -1);
    vector<bool> inMST(vertices, false);

    key[0] = 0;

    for (int count=0; count<vertices; count++) {

        int u = -1;
        int minKey = INT_MAX;
        
        // picking unconnected vertex with least weight
        for (int i=0; i<vertices; i++) {
            if(!inMST[i] && key[i] < minKey) {
                minKey = key[i];
                u = i;
            }
        }

        if (u == -1) break;
        inMST[u] = true;

        for (int v=0; v<vertices; v++) {
            if (graph[u][v] != 0 && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    int totalCost = 0;
    cout << "Edge   Weight" << endl;
    for (int i=1; i<vertices; i++) {
        cout << parent[i] << " - " << i << "    " << key[i] << endl;
        totalCost += key[i];
    }
    cout << totalCost << endl;
}