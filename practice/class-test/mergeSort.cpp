#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//prototypes
void traverse(int array[], int n);
void mergeSort (int array[], int startIndex, int endIndex);
void merge(int array[], int startIndex, int midIndex, int endIndex);

int main() {

    // Initialize array
    cout << "Type size of array: ";
    int size;
    cin >> size;
    int array[size];

    // populate array
    cout << "Type the data of array: ";
    for (int i=0; i<size; i++) {
        cin >> array[i];
    }
    cout << endl;

    cout << "Array before sorting: ";
    traverse(array, size);

    mergeSort(array, 0, size-1);

    cout << "Array after sorting: ";
    traverse(array, size);
}

void traverse(int array[], int n) {

    for (int i=0; i<n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void mergeSort (int array[], int startIndex, int endIndex) {

    if (startIndex < endIndex) {

        int midIndex = (startIndex+endIndex) / 2;
        mergeSort(array, startIndex, midIndex);
        mergeSort(array, midIndex+1, endIndex);
        merge(array, startIndex, midIndex, endIndex);
    }
}

void merge (int array[], int startIndex, int midIndex, int endIndex) {

    // left subarray
    int m = (midIndex - startIndex) + 1;
    int A[m];

    // right subarray
    int n = endIndex - midIndex;
    int B[n];

    // filling data of both arrays
    for(int i=0; i<m; i++) {
        A[i] = array[startIndex+i];
    }
    for(int j=0; j<n; j++) {
        B[j] = array[midIndex+1+j];
    }

    // merging both subarrays
    int i=0, j=0, k=startIndex;
    while (i<m && j<n) {

        if (A[i] < B[j]) {
            array[k] = A[i];
            i++;
        }
        else {
            array[k] = B[j];
            j++;
        }
        k++;
    }

    // filling the remaining
    while (i<m) {
        array[k] = A[i];
        i++;
        k++;
    }
    while (j<n) {
        array[k] = B[j];
        j++;
        k++;
    }

}
