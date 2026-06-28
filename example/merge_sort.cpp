#include <bits/stdc++.h>
using namespace std;

// this function merges two sorted sub-arrays
void Merge(int A[], int L, int Mid, int H) {

// size of first half
    int m = Mid - L + 1;  

// size of second half
    int n = H - Mid;      

    // Create temporary arrays
    int Left[m + 1], Right[n + 1];

    // Copy data to temp arrays
    for (int i = 0; i < m; i++)
        Left[i] = A[L + i];
    for (int j = 0; j < n; j++)
        Right[j] = A[Mid + 1 + j];

    // Merging the two halves
    int i = 0, j = 0, k = L;

    while (i < m && j < n) {
        if (Left[i] < Right[j])
            A[k++] = Left[i++];
        else
            A[k++] = Right[j++];
    }

// To Copy the remaining elements
    while (i < m)
        A[k++] = Left[i++];
    while (j < n)
        A[k++] = Right[j++];
}


void MergeSort(int A[], int L, int H) {
    if (L < H) {
        int Mid = (L + H) / 2;

        MergeSort(A, L, Mid);
        MergeSort(A, Mid + 1, H);
        Merge(A, L, Mid, H);
    }
}


int main() {

// to make it faster
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int A[] = {8, 3, 7, -4, 90, 2, 6, 5};
    int n = sizeof(A) / sizeof(A[0]);

    MergeSort(A, 0, n - 1);

    cout << "Sorted array:   ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}
