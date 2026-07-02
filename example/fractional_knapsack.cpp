#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    double profit[n], weight[n];
    cout << "Enter profits of items:\n";
    for (int i = 0; i < n; i++) cin >> profit[i];

    cout << "Enter weights of items:\n";
    for (int i = 0; i < n; i++) cin >> weight[i];

    double ratio[n]; // profit-to-weight ratio
    for (int i = 0; i < n; i++)
        ratio[i] = profit[i] / weight[i];

    // Sort items by ratio (descending)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                swap(ratio[i], ratio[j]);
                swap(profit[i], profit[j]);
                swap(weight[i], weight[j]);
            }
        }
    }
    double capacity;
    cout << "Enter capacity of knapsack: ";
    cin >> capacity;

    double totalprofit = 0;

    for (int i = 0; i < n; i++) {
        if (capacity >= weight[i]) {
            // Take the whole item
            capacity -= weight[i];
            totalprofit += profit[i];
        } else {
            // Take fractional part
            totalprofit += ratio[i] * capacity;
            break;
        }
    }

    cout << "Maximum profit in fractional Knapsack = " << totalprofit << endl;
    return 0;
}
