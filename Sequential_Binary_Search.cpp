#include <iostream>
#include <algorithm> // For std::sort
using namespace std;

// Function to compare two integers (used for sorting)
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Function for sequential search
int sequential_search(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}

// Function for binary search
int binary_search(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        
        if (arr[mid] == target) {
            return mid; // Return the index if found
        } else if (arr[mid] < target) {
            low = mid + 1; // Search the right half
        } else {
            high = mid - 1; // Search the left half
        }
    }
    return -1; // Return -1 if not found
}

int main() {
    int size;
    
    cout << "Enter the size of the array: ";
    cin >> size;
    
    int array[size];
    
    cout << "Enter values: " << endl;
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }
    
    int element;
    cout << "Enter the element to search: ";
    cin >> element;
    
    // Sequential search
    int sequential_result = sequential_search(array, size, element);
    if (sequential_result != -1) {
        cout << "Element " << element << " found at index " << sequential_result << " using sequential search\n";
    } else {
        cout << "Element not found using sequential search\n";
    }
    
    // Sort the array for binary search
    sort(array, array + size); // Using C++ standard library's sort function
    
    // Binary search
    int binary_result = binary_search(array, size, element);
    if (binary_result != -1) {
        cout << "Element " << element << " found at index " << binary_result << " using binary search\n";
    } else {
        cout << "Element not found using binary search\n";
    }
    
    return 0;
}
