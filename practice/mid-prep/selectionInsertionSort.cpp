#include <bits/stdc++.h>
using namespace std;

// prototypes
void selectionSort (int Arr[], int n);
void insertionSort (int Arr[], int n);
void traverse (int Arr[], int n);
int main () {

    int Array[] = {2, 1, 6, 9, -9, -1, -8, 5, 3};
    int n = sizeof(Array) / sizeof(Array[0]);

    // selectionSort(Array, n);
    insertionSort(Array, n);
    traverse(Array, n);

}

void selectionSort (int Arr[], int n) {

    for (int i=0; i<n; i++) {
        int minIndex = i;

        for (int j=i+1; j<n; j++) {
            if (Arr[j] < Arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(Arr[i], Arr[minIndex]);
    }
}

void insertionSort (int Arr[], int n) {
    for (int i=1; i<n; i++) {
        int temp = Arr[i];
        int prevIndex = i-1;

        while (prevIndex >= 0 && temp < Arr[prevIndex]) {
            Arr[prevIndex + 1] = Arr[prevIndex];
            prevIndex--;
        }
        Arr[prevIndex+1] = temp;
    }
}

void traverse (int Arr[], int n) {

    for (int i=0; i<n; i++){
        cout << Arr[i] << " ";
    }
    cout << endl;
}
