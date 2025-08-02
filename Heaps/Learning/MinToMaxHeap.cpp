#include<iostream>
using namespace std;

// max heapify at index i
void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if(right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if(largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void convertMinToMaxHeap(int arr[], int n) {
    // start from the last non-leaf node and heapify in reverse
    for(int i=(n-2)/2; i>=0; i--) {
        maxHeapify(arr, n, i);
    }
}

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int minHeap[] = {1, 3, 5, 7, 9, 8};
    int n = sizeof(minHeap) / sizeof(minHeap[0]);

    cout << "Original Min Heap: ";
    printArray(minHeap, n);

    convertMinToMaxHeap(minHeap, n);

    cout << "Converted Max Heap: ";
    printArray(minHeap, n);

    return 0;
}