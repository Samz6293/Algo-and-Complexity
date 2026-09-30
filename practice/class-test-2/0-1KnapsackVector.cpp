#include <bits/stdc++.h>
using namespace std;

//prototypes
void populate(int n, vector<int>& profit, vector<int>& weight);
int knapsack(int n, int W, vector<int>& profit, vector<int>& weight);

int main() {

    cout << "No. of items: ";
    int items;
    cin >> items;

    cout << "Bag capacity: ";
    int capacity;
    cin >> capacity;

    // making and filling profit & weight
    vector<int> profit(items+1, 0);
    vector<int> weight(items+1, 0);
    populate(items, profit, weight);

    cout << "Max profit: " << knapsack(items, capacity, profit, weight) << endl;
}

void populate(int n, vector<int>& profit, vector<int>& weight) {

    for (int i=1; i<=n; i++) {
        cout << "profit of item " << i << ": ";
        cin >> profit[i];
        cout << "weight of item " << i << ": ";
        cin >> weight[i];
        cout << endl;
    }

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    for (int i=1; i<=n; i++) {
        cout << "profit of item " << i << ": " << profit[i] << ", weight of item " << i << ": " << weight[i] << endl;
    }
}

int knapsack(int n, int W, vector<int>& profit, vector<int>& weight){

    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for(int i=1; i<=n; i++) {
        for(int w=1; w<=W; w++) {
            dp[i][w] = dp[i-1][w];
            if(w >= weight[i]) {
                dp[i][w] = max(dp[i][w], profit[i]+ dp[i-1][w- weight[i]]);
            }
        }
    }
    return dp[n][W];
}
