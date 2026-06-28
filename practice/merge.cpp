#include <bits/stdc++.h>
using namespace std;

//prototypes
void info(int A[], int n);
void merge(int A[], int m, int B[], int n, int C[]);
void traverse(int A[], int n);

int  main () {

    // fill arrays with user input
    int n,m;
    cout << "Size of arary A and B: ";

    cin >> m >> n; // A[m] and B[n]
    int A[m], B[n];

    //fill in info in ascending
    cout << "Numbers for array A: ";
    info(A, m);
    cout << "Numbers for array B: ";
    info(B, n);

    int C[m+n];
    merge(A, m, B, n, C);
    traverse(C, m+n);
}

void info(int A[], int n) {

    for (int i=0; i<n; i++){
        cin >> A[i];
    }
}

void traverse(int A[], int n) {

    cout << "Array of size " << n << ": ";
    for (int i=0; i<n; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

void merge(int A[], int m, int B[], int n, int C[]){

    int i=0, j=0, k=0;
    while (i<m && j<n) {

        if (A[i] < B[j]) {
            C[k] = A[i];
            i++;
        }
        else {
            C[k] = B[j];
            j++;
        }
        k++;
    }

    for (; i<m; i++) {
        C[k] = A[i];
        k++;
    }
    for (; j<n; j++) {
        C[k] = B[j];
        k++;
    }
}
