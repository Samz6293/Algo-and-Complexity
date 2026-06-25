#include<bits/stdc++.h>
using namespace std;


// prototypes
void selectionSort(int arr[], int n);
void traverse(int arr[], int n);

int main() {

    // faster input
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[] = {1,5,12,-9,6};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);
    traverse(arr, n);
    return 0;
}


void selectionSort(int arr[], int n) {

    for (int i=0; i < n; i++) {

        int minIndex = i;
        for (int j = i+1; j<n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i){
            swap(arr[i], arr[minIndex]);
        }
    }
}


void traverse(int arr[], int n) {
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
