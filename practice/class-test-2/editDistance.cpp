#include<bits/stdc++.h>
using namespace std;

int editDistance(string m, string n);

int main() {
    string a = "kitchen";
    string b = "sitting";
    cout << "Edit Distance: " << editDistance(a, b) << endl;
}

int editDistance(string m, string n) {
    int a = m.size();
    int b = n.size();

    int dp[100][100];

    for(int i=0; i<=a; i++) {
        dp[i][0] = i;
    }

    for(int j=0; j<=b; j++) {
        dp[0][j] = j;
    }

    for (int i=1; i<=a; i++) {
        for (int j=1; j<=b; j++) {
            if (m[i-1] == n[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                int Op1 = dp[i-1][j-1];
                int Op2 = dp[i][j-1];
                int Op3 = dp[i-1][j];
                dp[i][j] = 1 + min({Op1, Op2, Op3});
            }
        }
    }
    return dp[a][b];
}