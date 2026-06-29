#include<bits/stdc++.h>
using namespace std;

// prototypes
void traverse(int A[], int n);
void mergeSort(int A[], int startIndex, int endIndex);
void merge(int A[], int startIndex, int midIndex, int endIndex);

int main() {

    // making a user generated array
    int n;
    cout << "Length of array: ";
    cin >> n;
    int A[n];
    cout << "Array elements: ";
    for (int i=0; i<n; i++) {
        cin >> A[i];
    }

    cout << "Given array: ";
    traverse(A, n);

    mergeSort(A, 0, n-1);

    cout << "Sorted Array: ";
    traverse(A, n);

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
        mergeSort(A, startIndex, midIndex);
        mergeSort(A, midIndex+1, endIndex);
        merge(A, startIndex, midIndex, endIndex);

    }

}

void merge(int A[], int startIndex, int midIndex, int endIndex) {

    // making left subarray
    int m = (midIndex - startIndex) + 1;
    int leftArray[m];

    // making right subarray
    int n = endIndex - midIndex;
    int rightArray[n];
    
    // copying elements of A to respective sub arrays
    for (int i=0; i<m; i++) {
        leftArray[i] = A[startIndex+i];
    }
    for (int j=0; j<n; j++) {
        rightArray[j] = A[midIndex+1+j];
    }


    // merging the subarrays to A
    int i=0, j=0, k=startIndex;
    while(i<m && j<n) {

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

    while (i<m) {
        A[k] = leftArray[i];
        i++;
        k++;
    }

    while (j<n) {
        A[k] = rightArray[j];
        j++;
        k++;
    }

}
