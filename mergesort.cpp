#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void merge(int array[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    // Copy data to temp arrays L[] and M[]
    for (int i = 0; i < n1; i++)
        L[i] = array[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = array[q + 1 + j];

    int i = 0, j = 0, k = p;

    // Merge the temp arrays back into the original array
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = M[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of M[], if any
    while (j < n2) {
        array[k] = M[j];
        j++;
        k++;
    }
}

void mergeSort(int array[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);

        // Merge the sorted halves
        merge(array, l, m, r);
    }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

int main() {
    const int size = 10000;
    int array[size] = {};

    for (int i = 0; i < size; i++) {
        // Uncomment one of the lines below to choose the case

        // array[i] = rand();  // Average Case
        // array[i] = i;  // Best Case
        // array[i] = size - i;  // Worst Case
    }

    cout << "The randomly generated array is: " << endl;
    printArray(array, size);

    mergeSort(array, 0, size - 1);

    cout << "Sorted array: " << endl;
    printArray(array, size);

    return 0;
}
