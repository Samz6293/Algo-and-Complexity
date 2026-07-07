#include <bits/stdc++.h>
using namespace std;

//prototypes
void traverse(int Array[], int size);
void insertionSort(int Array[], int size);

int main() {

    int Array[] = {4, 5, 1, 2, -9, -54, 3, 0};
    int size = sizeof(Array)/ sizeof(Array[0]);

    cout << "Array before sorting: ";
    traverse(Array, size);

    insertionSort(Array, size);

    cout << "Array after sorting: ";
    traverse(Array, size);
}

void traverse(int Array[], int size) {

    for (int i=0; i<size; i++) {
        cout << Array[i] << " ";
    }
    cout << endl;
}

void insertionSort(int Array[], int size) {

    for (int i=0; i<size; i++) {

        int temp = Array[i];
        int previousIndex = i - 1;

        while (previousIndex >= 0 && temp < Array[previousIndex]) {

            Array[previousIndex + 1] = Array[previousIndex];
            previousIndex--;
        }
        Array[previousIndex+1] = temp;
    }
}
