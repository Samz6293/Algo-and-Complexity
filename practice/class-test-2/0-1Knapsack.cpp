#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n = 4;
    int m = 8; // m is bag capacity (W)

    // A dummy 0 at index 0 makes the arrays 1-indexed, matching Abdul Bari's logic
    int p[] = {0, 1, 2, 5, 6};
    int wt[] = {0, 2, 3, 4, 5};

    // Table of size [n+1][m+1] -> [5][9]
    int k[n + 1][m + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= m; w++) {

            if (i == 0 || w == 0) {
                k[i][w] = 0;
                cout << k[i][w] << " ";
            }
            // Check if current item's weight fits inside current capacity w
            else if (wt[i] <= w) {
                k[i][w] = max(p[i] + k[i - 1][w - wt[i]], k[i - 1][w]);
                cout << k[i][w] << " ";
            }
            // If the item doesn't fit, just copy the value from the previous row
            else {
                k[i][w] = k[i - 1][w];
                cout << k[i][w] << " ";
            }
        }
        cout << " <-- item: " << i << " weight: "<< wt[i] << " profit: "<< p[i] << endl;
    }

    // Result is stored at row n, column m
    cout << "Profit: " << k[n][m] << endl;

    return 0;
}