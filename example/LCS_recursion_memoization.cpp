#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int LCS(string &a, string &b, int i, int j) {
    if (i == a.size() || j == b.size()) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    if (a[i] == b[j])
        return dp[i][j] = 1 + LCS(a, b, i+1, j+1);

    return dp[i][j] = max(LCS(a, b, i+1, j),
                          LCS(a, b, i, j+1));
}

// Build LCS string using the dp table
string buildLCS(string &a, string &b, int i, int j) {

    if(i == a.size() || j == b.size())
        return "";

    if(a[i] == b[j]) {
        return a[i] + buildLCS(a,b,i+1,j+1);
    }

    if(dp[i+1][j] > dp[i][j+1])
        return buildLCS(a,b,i+1,j);

    else
        return buildLCS(a,b,i,j+1);
}

int main() {
    string a = "trump";
    string b = "putin";

    memset(dp, -1, sizeof(dp));
    cout<<dp[0][0]<<endl;
    cout << "LCS Length = " << LCS(a, b, 0, 0) << endl;

    cout << "LCS = " << buildLCS(a, b, 0, 0) << endl;
}
