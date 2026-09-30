#include <bits/stdc++.h>
using namespace std;

// int MAX = 1000;

vector<int> adj[1000];   
bool visited[1000];      


void BFS(int start) {
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS: ";

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int nbr : adj[node]) {
            if (!visited[nbr]) {
                visited[nbr] = true;
                q.push(nbr);
            }
        }
    }
    cout << endl;
}


void DFS(int node) {
    visited[node] = true;
    cout << node << " ";

    for (int nbr : adj[node]) {
        if (!visited[nbr]) {
            DFS(nbr);
        }
    }
}

int main() {
    
    /*
        Directed graph with multiple edges:

        0 → 1, 2, 3
        1 → 2, 4
        2 → 4
        3 → 4
    */

    adj[0] = {1, 2, 3};
    //adj[0].push_back(3);
    adj[1] = {2, 4};   // duplicate edge to 2
    adj[2] = {4};
    adj[3] = {4};

    // BFS
    memset(visited, false, sizeof(visited));
    BFS(0);

    // DFS
    memset(visited, false, sizeof(visited));
    cout << "DFS: ";
    DFS(0);
    cout << endl;

    return 0;
}