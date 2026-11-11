#include <bits/stdc++.h>
using namespace std;

void takeInput(int roads, vector<vector<int>>& roadCost);
void prims(int villages, vector<vector<int>>& roadCost);

int main() {

    cout << "No. of villages: ";
    int villages;
    cin >> villages;

    cout << "No. of roads: ";
    int roads;
    cin >> roads;

    // roadCost[a][b] = cost of road between village a and b (0 = no road)
    vector<vector<int>> roadCost(villages, vector<int> (villages, 0));
    takeInput(roads, roadCost);

    prims(villages, roadCost);
}

void takeInput(int roads, vector<vector<int>>& roadCost) {
    cout << "Enter roads (a b cost):" << endl;
    for (int i=0; i<roads; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        roadCost[a][b] = cost;
        roadCost[b][a] = cost;   // two-way road
    }
}

void prims(int villages, vector<vector<int>>& roadCost) {

    // cheapest road I know of that would connect each village (INT_MAX = no road known yet)
    vector<int> cheapestRoad(villages, INT_MAX);
    // which connected village that cheapest road comes from (-1 = none yet)
    vector<int> roadFrom(villages, -1);
    // is this village already connected?
    vector<bool> connected(villages, false);

    cheapestRoad[0] = 0;   // we start at village 0, connecting it costs nothing

    for (int round=0; round<villages; round++) {

        // step 1: pick the unconnected village with the cheapest road
        int picked = -1;   // -1 = no village picked yet
        int cheapestSoFar = INT_MAX;
        for (int village=0; village<villages; village++) {
            if (!connected[village] && cheapestRoad[village] < cheapestSoFar) {
                cheapestSoFar = cheapestRoad[village];
                picked = village;
            }
        }
        if (picked == -1) break;   // no village can be reached

        // step 2: connect it
        connected[picked] = true;

        // step 3: check every road going out of the picked village
        for (int other=0; other<villages; other++) {
            // is there a road, is "other" not connected yet, and is this road cheaper?
            if (roadCost[picked][other] != 0 && !connected[other] && roadCost[picked][other] < cheapestRoad[other]) {
                cheapestRoad[other] = roadCost[picked][other];
                roadFrom[other] = picked;
            }
        }
    }

    int totalCost = 0;
    cout << "Road   Cost" << endl;
    for (int village=1; village<villages; village++) {
        cout << roadFrom[village] << " - " << village << "    " << cheapestRoad[village] << endl;
        totalCost += cheapestRoad[village];
    }
    cout << "Total cost = " << totalCost << endl;
}
