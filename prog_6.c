#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Max heap lai heapify garne
void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

// Min heap lai heapify garne
void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] < arr[smallest])
        smallest = l;
    if (r < n && arr[r] < arr[smallest])
        smallest = r;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

// Max heap build garne
void buildMaxHeap(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}

// Min heap build garne
void buildMinHeap(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);
}

// Print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {10, 3, 5, 1, 8, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Original Array: ");
    printArray(arr, n);

    int maxHeap[n];
    int minHeap[n];

    // Copy original array
    for (int i = 0; i < n; i++) {
        maxHeap[i] = arr[i];
        minHeap[i] = arr[i];
    }

    // Build heaps
    buildMaxHeap(maxHeap, n);
    buildMinHeap(minHeap, n);

    printf("Max Heap: ");
    printArray(maxHeap, n);

    printf("Min Heap: ");
    printArray(minHeap, n);

    return 0;
}