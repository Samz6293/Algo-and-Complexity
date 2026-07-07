#include <bits/stdc++.h>
#include <utility>
using namespace std;

// prototypes
void traverse (int array[], int n);
void selectionSort (int array[], int n);

int main() {

    cout << "Type the size of array: ";
    int n;
    cin >> n;
    int array[n];

    cout << "Type the data of array: ";
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }

    cout << "Array before sorting: ";
    traverse(array, n);

    selectionSort(array, n);

    cout << "Array after sorting: ";
    traverse(array, n);
}

void traverse (int array[], int n) {

    for (int i=0; i<n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void selectionSort (int array[], int n) {

    for (int i=0; i<n; i++) {

        int smallestIndex = i;
        for (int j=i+1; j<n; j++) {
            if (array[smallestIndex] > array[j]) {
                smallestIndex = j;
            }
        }

        if (smallestIndex != i) {
            swap(array[smallestIndex], array[i]);
        }
    }
}
