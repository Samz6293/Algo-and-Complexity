#include<bits/stdc++.h>
using namespace std;


// prototypes
void insertionSort(int arr[], int n);
void traverse(int arr[], int n);

int main() {

    // faster input
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[] = {1,5,12,-9,6};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);
    traverse(arr, n);
    return 0;
}


void insertionSort(int arr[], int n) {

    for (int i=1; i<n; i++) {

        int temp = arr[i];
        int previousIndex = i-1;

        while (previousIndex >= 0 && temp < arr[previousIndex]) {
            arr[previousIndex + 1] = arr[previousIndex];
            previousIndex--;
        }
        arr[previousIndex + 1] = temp;
    }
}


void traverse(int arr[], int n) {
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
