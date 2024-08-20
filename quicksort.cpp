#include <iostream>
#include <cstdlib> // For rand()
#include <ctime>   // For time()

using namespace std;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quickSort(int array[], int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    int size = 10000;
    int array[size];

    for (int i = 0; i < size; i++) {
        // array[i] = rand();    // Average Case
        // array[i] = i;         // Best Case
        // array[i] = 10000 - i; // Worst Case
    }

    cout << "The randomly generated array is: ";
    printArray(array, size);

    quickSort(array, 0, size - 1);

    cout << "Sorted array in ascending order: ";
    printArray(array, size);

    return 0;
}
