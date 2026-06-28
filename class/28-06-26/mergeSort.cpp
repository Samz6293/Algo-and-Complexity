#include<bits/stdc++.h>
using namespace std;

// prototypes
void mergeSort(int A[], int L, int H);
void merge(int A[], int L, int Mid, int H);
void traverse(int A[], int n);

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A[] = {8, 3, 7, -4, 90, 2, 6, 5};
    int n = sizeof(A) / sizeof(A[0]);

    mergeSort(A, 0, n - 1);
    traverse(A,n);
}

void mergeSort(int A[], int L, int H) {
    if (L<H) {
        int Mid = (L+H) / 2;

        mergeSort(A, L, Mid);
        mergeSort(A, Mid +1, H);
        merge(A, L, Mid, H);
    }
}

void merge(int A[], int L, int Mid, int H) {

    // size of first half
    int m = Mid - L + 1;

    // size of second half
    int n = H - Mid;

    // temporary arrays
    int Left[m + 1], Right[n + 1];

    // Copy data to temp arrays
    for (int i = 0; i < m; i++) {
        Left[i] = A[L + i];
    }
    for (int j = 0; j < n; j++) {
        Right[j] = A[Mid + 1 + j];
    }

    // Merging
    int i=0, j=0, k=L;

    while (i<m && j<n) {
        if (Left[i] < Right[j]) {
            A[k++] = Left[i++];
        }
        else {
            A[k++] = Right[j++];
        }
    }

    while (i < m) {
        A[k++] = Left[i++];
    }
    while (j < n) {
        A[k++] = Right[j++];
    }
}

void traverse(int A[], int n) {

    for (int i=0; i<n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}
