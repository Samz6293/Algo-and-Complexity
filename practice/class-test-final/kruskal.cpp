#include<bits/stdc++.h>
using namespace std;

void takeInput(int edges, vector<vector<int>>& edgelist);
void kruskal (int vertices, vector<vector<int>>& edgelist);
bool compareWeight (vector<int> a, vector<int> b);
int findParent (int v, vector<int>& parent);
int main() {
    int vertices, edges;
    cout << "Vertices Edges: ";
    cin >> vertices >> edges;

    vector<vector<int>> edgelist;
    takeInput(edges, edgelist);
    kruskal (vertices, edgelist);
}

void takeInput(int edges, vector<vector<int>>& edgelist) {
    cout << "u v w" << endl;
    for (int i=0; i<edges; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        edgelist.push_back({u, v, w});
    }
}

bool compareWeight (vector<int> a, vector<int> b) {
    return a[2] < b[2];
}
void kruskal (int vertices, vector<vector<int>>& edgelist) {
    
    // sort edges by weight
    sort(edgelist.begin(), edgelist.end(), compareWeight);

    // vertex group
    vector<int> parent(vertices);
    for (int i=0; i<vertices; i++) {
        parent[i] = i;
    }

    int edgeCount = 0;
    int totalCost = 0;

    cout << "Edge   Weight" << endl;
    for(int i=0; i<edgelist.size(); i++) {
        int u = edgelist[i][0];
        int v = edgelist[i][1];
        int w = edgelist[i][2];


        int pu = findParent(u, parent);
        int pv = findParent(v, parent);
        if (pu != pv) {
            cout << u << " - " << v << "    " << w << endl;
            parent[pv] = pu;
            totalCost += w;
            edgeCount++;
        }

        if (edgeCount == vertices-1) break;
    }
    cout << "Total cost: " << totalCost << endl;


}

int findParent (int v, vector<int>& parent) {
    if (parent[v] == v) {
        return v;
    }
    return findParent(parent[v], parent);
}