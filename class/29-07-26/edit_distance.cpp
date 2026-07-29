#include <bits/stdc++.h>
using namespace std;

// prototypes
int editDistance(string a, string b);

int main() {

    string a = "kitchen";
    string b = "sitting";
    cout << "Edit Distance: " << editDistance(a, b) << endl;

}


int editDistance(string a, string b) {

    int n = a.size();
    int m = b.size();

    // fixed table
    int dp[101][101];

    //base cases
    for (int i=0; i<=n; i++) {
        dp[i][0] = i;
    }
    for (int j=0; j<=m; j++) {
        dp[0][j] = j;
    }

    // filling the table
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {

            if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }

            else {
                int Op1 = dp[i][j-1];
                int Op2 = dp[i-1][j];
                int Op3 = dp[i-1][j-1];
                dp[i][j] = 1 + min({Op1, Op2, Op3});
            }

        }
    }
    return dp[n][m];
}
