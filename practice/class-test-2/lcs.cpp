#include<bits/stdc++.h>
using namespace std;

int LCS(string& m, string& n, int i, int j);
string build(string& m, string& n, int i, int j);

int dp[100][100];

int main() {
    string m = "trump";
    string n = "putin";
    memset(dp, -1, sizeof(dp));
    cout << "LCS: " << LCS(m, n, 0, 0) << endl;
    cout << "Words used: " << build(m, n, 0, 0) << endl;
}

int LCS(string& m, string& n, int i, int j) {
    if (i == m.size() || j == n.size()) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    if(m[i] == n[j]) return 1 + LCS(m, n, i+1, j+1);
    return max (LCS(m, n, i+1, j), LCS(m, n, i, j+1));
}

string build(string& m, string& n, int i, int j) {
    if (i == m.size() || j == n.size()) return "";
    if (m[i] == n[j]) return m[i] + build(m, n, i+1, j+1);

    if (dp[i+1][j] > dp[i][j+1]) {
        return build(m, n, i+1, j);
    }
    return build(m,n, i, j+1);
}