#include <bits/stdc++.h>
using namespace std;

int knapsack(int W, vector<int>& weight, vector<int>& value, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {

            // Do not take the item
            dp[i][w] = dp[i - 1][w];

            // Take the item if possible
            if (weight[i - 1] <= w) {
                dp[i][w] = max(dp[i][w],
                               value[i - 1] +
                               dp[i - 1][w - weight[i - 1]]);
            }
        }
    }

    return dp[n][W];
}

int main() {
    int n = 4;
    vector<int> weight = {2, 3, 4, 5};
    vector<int> value  = {1, 2, 5, 6};
    int W = 8;

    cout << "Maximum value = "
         << knapsack(W, weight, value, n) << endl;

    return 0;
}