#include<iostream>
#include<iterator>
using namespace std;

// Prototypes
void quicksort(int arr[], int start, int end);
int partition(int arr[], int start, int end);

int main () {
    int arr[] = {3, 1, 4, 2, 6, 5};
    int length = size(arr);
    
    quicksort(arr, 0, length-1);

    cout << "Quick Sorted Array: ";
    for(int i=0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void quicksort(int arr[], int start, int end) {

    if (start < end) {

        int pivotIndex = partition(arr, start, end);
        
        //left half sort
        quicksort(arr, start, pivotIndex-1);

        // Right half sort
        quicksort(arr, pivotIndex+1, end);
    }
}


int partition(int arr[], int start, int end) {

    int pivot = arr[end];
    int i = start-1;

    // Sorting smaller element left of pivot and vice versa
    for (int j=start; j < end; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[j], arr[i]);
        }
    }

    // Swapping pivot to correct place and returning the index
    i++;
    swap(arr[end], arr[i]);
    return i;
}