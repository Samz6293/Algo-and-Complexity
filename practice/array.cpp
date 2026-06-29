#include <iostream>
using namespace std;

void traverse(int A[], int n);

int main() {
    int A[7] = {1, 3, 5, 6, 7, 5, 3};
    int arraySize = sizeof(A) / sizeof(A[0]);
    traverse(A, 7);
}

void traverse(int A[], int n) {

    for (int i=0; i<n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}
