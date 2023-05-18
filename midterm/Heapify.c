#include <stdio.h>

void heapify(int arr[], int n, int i, int isMaxHeap) {
    int largestOrSmallest = i; // Initialize largest/smallest as root
    int left = 2 * i + 1; // Left child index
    int right = 2 * i + 2; // Right child index

    if (isMaxHeap) {
        // For max heap, find the largest element among root, left child, and right child
        if (left < n && arr[left] > arr[largestOrSmallest])
            largestOrSmallest = left;

        if (right < n && arr[right] > arr[largestOrSmallest])
            largestOrSmallest = right;
    } else {
        // For min heap, find the smallest element among root, left child, and right child
        if (left < n && arr[left] < arr[largestOrSmallest])
            largestOrSmallest = left;

        if (right < n && arr[right] < arr[largestOrSmallest])
            largestOrSmallest = right;
    }

    if (largestOrSmallest != i) {
        // Swap the root with the largest/smallest element
        int temp = arr[i];
        arr[i] = arr[largestOrSmallest];
        arr[largestOrSmallest] = temp;

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largestOrSmallest, isMaxHeap);
    }
}

void buildHeap(int arr[], int n, int isMaxHeap) {
    // Start from the last non-leaf node and heapify each node in reverse order
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, isMaxHeap);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = { 4, 10, 3, 5, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    printf("Max heap: ");
    buildHeap(arr, n, 1); // Build max heap
    printArray(arr, n);

    printf("Min heap: ");
    buildHeap(arr, n, 0); // Build min heap
    printArray(arr, n);

    return 0;
}
