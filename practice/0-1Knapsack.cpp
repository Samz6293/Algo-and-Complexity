#include <bits/stdc++.h>
using namespace std;

// prototypes
int knapSack (vector<int>& itemWeight, vector<int>& itemValue, int items, int maxWeight);

int main() {

    // number of items
    int items = 4;

    // all items weight and value in ascending order
    vector<int> itemWeight = {2, 3, 4, 5};
    vector<int> itemValue = {1, 2, 5, 6};

    // capacity of knapSack
    int maxWeight = 8;

    cout << "Maximum value: " << knapSack(itemWeight, itemValue, items, maxWeight) << endl;
}


int knapSack (vector<int>& itemWeight, vector<int>& itemValue, int items, int maxWeight) {

    // making vector table and setting value to 0
    vector<vector<int>> dp (items+1, vector<int> (maxWeight+1, 0));

    for (int i=1; i<=items; i++) {
        for (int w=0; w<= maxWeight; w++) {

            // always carry forward the value from the row above by default
            dp[i][w] = dp[i-1][w];

            // only try to improve it if the new item actually fits
            if (itemWeight[i-1] <= w) {
                dp[i][w] = max(dp[i][w], itemValue[i-1] + dp[i-1][w - itemWeight[i-1]]);
            }
        }
    }
    return dp[items][maxWeight];
}
