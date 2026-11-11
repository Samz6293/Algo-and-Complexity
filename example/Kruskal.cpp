#include <bits/stdc++.h>
using namespace std;
int findParent(int v, vector<int> &parent)
{
    if (parent[v] == v)
        return v;
    return findParent(parent[v], parent);
}
void kruskal(int V, vector<vector<int>> &edges)
{
    
// Step 1: Sort all edges by increasing weight
// used lamda function here
    sort(edges.begin(), edges.end(),
         [](vector<int> &a, vector<int> &b) {
             return a[2] < b[2];
         });

    vector<int> parent(V);
    for (int i = 0; i < V; i++)
        parent[i] = i;

    int edgeCount = 0;
    int totalCost = 0;

    cout << "Edge   Weight\n";

    // Step 2: Pick smallest edge one by one
    for (int i = 0; i < edges.size(); i++) {

        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        int pu = findParent(u, parent);
        int pv = findParent(v, parent);

        // Step 3: Check for cycle
        if (pu != pv) {
            cout << u << " - " << v << "    " << w << endl;
            parent[pv] = pu;     
            totalCost += w;
            edgeCount++;
        }
        // Stop when MST is complete
        if (edgeCount == V - 1)
            break;
    }

    cout << "Total cost = " << totalCost << endl;
}

int main()
{
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> edges;

    cout << "Enter edges (u, v, weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    kruskal(V, edges);
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

6 7
1 2 11
1 9 12
2 5 5
9 5 4
2 3 2
3 4 11
5 4 15
*/
