#include <bits/stdc++.h>
using namespace std;

// prototypes
void traverse(int A[], int n);
void mergeSort(int A[], int startIndex, int endIndex);
void merge(int A[], int startIndex, int midIndex, int endIndex);

int main() {

    int A[] = {8, 3, 7, -4, 90, 2, 6, 5};
    int arraySize = sizeof(A) / sizeof(A[0]);

    cout << "Array before sorting: ";
    traverse(A, arraySize);

    mergeSort(A, 0, arraySize - 1);
    // arraySize - 1; because we are sending the last index here.

    cout << "Array after sorting: ";
    traverse(A, arraySize);

}

void traverse(int A[], int n) {

    for (int i=0; i<n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

}

void mergeSort(int A[], int startIndex, int endIndex) {

    if (startIndex < endIndex) {

        int midIndex = (startIndex + endIndex) / 2;

        // calling mergeSort for left subarray followed by right
        mergeSort(A, startIndex, midIndex);
        mergeSort(A, midIndex + 1, endIndex);
        merge(A, startIndex, midIndex, endIndex);

    }

}

void merge(int A[], int startIndex, int midIndex, int endIndex) {

    // left subarray creation
    int m = (midIndex - startIndex) + 1;
    int leftArray[m+1];

    // right subarray creation
    int n = endIndex - midIndex; // since right halves start at midIndex+1
    int rightArray[n];

    // populating the subarrays
    for (int i=0; i<m; i++) {
        leftArray[i] = A[startIndex+i];  // since right halves start at midIndex+1
    }
    for (int j=0; j<n; j++) {
        rightArray[j] = A[midIndex + 1 + j]; // since right halves start at midIndex+1
    }

    // merging both subarrays
    int i = 0, j = 0, k = startIndex;
    while (i<m && j<n) {

        if (leftArray[i] < rightArray[j]) {
            A[k] = leftArray[i];
            i++;
        }
        else {
            A[k] = rightArray[j];
            j++;
        }

        k++;
    }

    // Copy the rest elements to main array
    while (i<m) {
        A[k] = leftArray[i];
        i++;
    }
    while (j<n) {
        A[k] = rightArray[j];
        j++;
    }

}
