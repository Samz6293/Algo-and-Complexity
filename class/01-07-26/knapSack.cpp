#include<bits/stdc++.h>
using namespace std;

int main () {

    int n;
    cout << "Type no. of elements: ";
    cin >> n;

    double profit[n], weight[n];
    cout << "Type profit of products: ";
    for (int i=0; i<n; i++) {
        cin >> profit[i];
    }

    cout << "Type weight of products: ";
    for (int i=0; i<n; i++) {
        cin >> weight[i];
    }

    double ratio[n];
    for (int i=0; i<n; i++) {
         ratio[i] = profit[i] / weight[i];
    }

    // sorting
    for (int i=0; i< n-1; i++) {
        for (int j= i+1; j<n; j++) {
            if (ratio[i] < ratio[j]) {
                swap(ratio[i], ratio[j]);
                swap(profit[i], profit[j]);
                swap(weight[i], weight[j]);
            }
        }
    }

    double capacity;
    cout << "Type capacity of knapsack: ";
    cin >> capacity;

    double totalProfit = 0;
    for (int i=0; i<n; i++) {
        if (capacity >= weight[i]) {
            capacity -= weight[i];
            totalProfit += profit[i];
        }
        else {
            totalProfit += ratio[i] * capacity;
            break;
        }
    }

    cout << "Total profit in fractional knapsack: " << totalProfit << endl;

}
