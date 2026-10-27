#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 17;
    
    vector<int> dp(amount+1, 1e9);
    vector<int> parent(amount+1, -1);

    dp[0] = 0;

    for(int i=1; i<=amount; i++) {
        for(int c:coins){
            if(i-c >= 0 && dp[i-c]+1 < dp[i]) {
                dp[i] = dp[i-c] + 1;
                parent[i] = c;
            }
        }
    }

    if (dp[amount] == 1e9) {
        cout << "Not possible" << endl;
        return 0;
    }

    cout << "Minimum coins required: " << dp[amount] << endl;

    int x = amount;
    cout << "Coins used: ";
    while (x > 0) {
        cout << parent[x] << " ";
        x = x - parent[x];
    }
}