#include <iostream>
#include <vector>
using namespace std;

/**
 * Merges two sorted subarrays of arr[]
 * First subarray is arr[left..mid]
 * Second subarray is arr[mid+1..right]
 */
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    vector<int> L(n1), R(n2);

    // Copy data to temp arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temp arrays back into arr[left..right]
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = left; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of L[] if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining elements of R[] if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/**
 * Main mergeSort function that recursively sorts arr[left..right]
 */
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        // Same as (left+right)/2, but avoids overflow for large left and right
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

/**
 * Utility function to print an array
 */
void printArray(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

/**
 * Driver code to test the implementation
 */
int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    
    cout << "Given array is: \n";
    printArray(arr);

    mergeSort(arr, 0, arr.size() - 1);

    cout << "\nSorted array is: \n";
    printArray(arr);

    return 0;
}
