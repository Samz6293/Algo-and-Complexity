#include <bits/stdc++.h>
using namespace std;

void populate(int items, vector<int>& profit, vector<int>& weight);
int knapsack (int items, int capacity, vector<int>& profit, vector<int>& weight);
int main() {

    cout << "No. of items: ";
    int items;
    cin >> items;

    cout << "Capacity: ";
    int capacity;
    cin >> capacity;

    // vectors
    vector<int> profit(items+1, 0);
    vector<int> weight(items+1, 0);
    populate(items, profit, weight);

    cout << "Maximum profit: " << knapsack(items, capacity, profit, weight) << endl;

}
void populate(int items, vector<int>& profit, vector<int>& weight) {
    for (int i=1; i<=items; i++) {
        cout << "profit of item " << i << ": ";
        cin >> profit[i];

        cout << "weight of item " << i << ": ";
        cin >> weight[i];
    }

    cout << "item profit weight" << endl;
    for (int i=1; i<=items; i++) {
        cout << i << "    " << profit[i] << "    " << weight[i] << endl;
    }
}

int knapsack (int items, int capacity, vector<int>& profit, vector<int>& weight) {
    vector<vector<int>> dp(items+1, vector<int> (capacity+1, 0));

    for (int i=1; i<=items; i++){
        for (int w=1; w<=capacity; w++){

            dp[i][w] = dp[i-1][w];
            if (weight[i] <= w) {
                dp[i][w] = max(dp[i-1][w], profit[i] + dp[i-1][w - weight[i]]);
            }
        }
    }
    return dp[items][capacity];
}