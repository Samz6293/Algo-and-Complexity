#include <bits/stdc++.h>
using namespace std;

// prototypes
void traverse(int Array[], int n);
void selectionSort(int Array[], int n);
void insertionSort(int Array[], int n);
void mergeSort(int Array[], int startIndex, int endIndex);
void merge(int Array[], int startIndex, int midIndex, int endIndex);

int main() {

    cout << "Type no. of data: ";
    int n;
    cin >> n;
    int Array[n];

    cout << "Type array elements: ";
    for (int i=0; i<n; i++) {
        cin >> Array[i];
    }

    cout << "Array before sorting: ";
    traverse(Array, n);

    // selectionSort(Array, n);
    // insertionSort(Array, n);
    mergeSort(Array, 0, n-1);

    cout << "Array after sorting: ";
    traverse(Array, n);
}

void traverse(int Array[], int n) {

    for (int i=0; i<n; i++) {
        cout << Array[i] << " ";
    }
    cout << endl;
}

void selectionSort(int Array[], int n) {

    for (int i=0; i<n; i++) {

        int minIndex = i;
        for (int j=i+1; j<n; j++) {
            if (Array[minIndex] > Array[j]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(Array[minIndex], Array[i]);
        }

    }
}

void insertionSort(int Array[], int n) {

    for (int i=1; i<n; i++) {

        int temp = Array[i];
        int previousIndex = i-1;
        while(previousIndex >= 0 && Array[previousIndex] > temp) {
            Array[previousIndex+1] = Array[previousIndex];
            previousIndex--;
        }
        Array[previousIndex+1] = temp;
    }
}

void mergeSort(int Array[], int startIndex, int endIndex) {

    if (startIndex < endIndex) {

        int midIndex = (startIndex+endIndex) / 2;
        mergeSort(Array,  startIndex,  midIndex);
        mergeSort(Array,  midIndex+1,  endIndex);
        merge(Array, startIndex, midIndex, endIndex);
    }
}

void merge(int Array[], int startIndex, int midIndex, int endIndex) {

    // newArray init
    int m = (midIndex-startIndex) + 1;
    int leftArray[m];
    int n = endIndex - midIndex;
    int rightArray[n];

    // populating
    for (int i=0; i<m; i++) {
        leftArray[i] = Array[startIndex+i];
    }
    for (int j=0; j<n; j++) {
        rightArray[j] = Array[midIndex+1+j];
    }

    //merge
    int i=0, j=0, k= startIndex;
    while (i<m && j<n) {

        if (leftArray[i] <= rightArray[j]) {
            Array[k] = leftArray[i];
            i++;
        }
        else {
            Array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // merging rest
    while (i<m) {
        Array[k] = leftArray[i];
        i++;
        k++;
    }
    while (j<n) {
        Array[k] = rightArray[j];
        j++;
        k++;
    }
}
