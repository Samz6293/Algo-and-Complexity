#include <bits/stdc++.h>
using namespace std;

int dp[10001]; // no of coins needed for each amount
int parentCoin[10001];   // store which coin was used last, we use it to reconstruct the solution

int minCoins(int amount, vector<int> &coins) {
    if (amount == 0) return 0;        // no coins needed
    if (amount < 0) return 1e9;       // invalid
    if (dp[amount] != -1) return dp[amount];

    int best = 1e9;
    int bestCoin = -1;

    // Try all coins
    for (int i = 0; i < coins.size(); i++) {
        int c = coins[i];
        int result = 1 + minCoins(amount - c, coins); // here we added 1 because we considered he have taken it
        

        if (result < best) {
            best = result;
            bestCoin = c;   // store which coin gives best result
        }
    }

    parentCoin[amount] = bestCoin;
    return dp[amount] = best;
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 17;

    memset(dp, -1, sizeof(dp));
    memset(parentCoin, -1, sizeof(parentCoin));

    int ans = minCoins(amount, coins);

    if (ans >= 1e9) {
        cout << "Not Possible" << endl;
        return 0;
    }

    cout << "Minimum Coins = " << ans << endl;

    cout << "Coins Used: ";
    int x = amount;
    while (x > 0) {
        cout << parentCoin[x] << " ";
        x -= parentCoin[x];
    }
    cout << endl;
}
