#include <bits/stdc++.h>
using namespace std;

class heap {
    public:
        int arr[100];
        int size = 0;
    
    heap() {
        arr[0] = -1; // 0th index is not used to simplify parent/child indexing
        size = 0;
    }
    
    void insert(int val) {
        size = size + 1; // increase the size as i am inserting
        int index = size; // creating space for insertion
        arr[index] = val; // insert (place value at the end)

        // move the inserted element up to maintain the max heap property
        while(index > 1) {
            int parent = index / 2;
            // if parent is smaller than child, swap them
            if(arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent; // move to parent index
            }
            else {
                return;
            }
        }
    }

    void print() {
        for(int i=1; i<=size; i++) {
            cout << arr[i] << " ";
        }cout << endl;
    }

    void deleteFromHeap() {
        if(size == 0) {
            cout << "nothing to delete" << endl;
            return;
        }
        arr[1] = arr[size]; // put the last element into first index
        size--; // remove last element
        
        // Heapify down: take root node to its correct position
        int i = 1;
        while(i <= size) {
            int leftIndex = 2*i;
            int rightIndex = 2*i + 1;

            // if left child is greater than current node, then swap
            if(leftIndex <= size && arr[i] < arr[leftIndex]) {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }

            // if right child is greater than current node, then swap
            else if(rightIndex <= size && arr[i] < arr[rightIndex]) {
                swap(arr[i], arr[leftIndex]);
                i = rightIndex;
            }
            else {
                return;
            }
        }
    }
};

// converts subtree rooted at index 'i' into a max heap
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    // compare with left child
    if(left <= n && arr[largest] < arr[left]) {
        largest = left;
    }

    // compare with right child
    if(right <= n && arr[largest] < arr[right]) {
        largest = right;
    }

    // if either child is larger, swap and continue heapifying
    if(largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    int size = n;
    while(size > 1) {
        // step 1: swap root(max) with last element
        swap(arr[size], arr[1]);
        size--;

        // step 2: heapify the reduced heap
        heapify(arr, size, 1);
    }
}

int main() {
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();

    h.deleteFromHeap();
    h.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5; // arr.size()
    for(int i=n/2; i>=1; i--) {
        heapify(arr, n, i);
    }

    cout << "printing the array now" << endl;
    for(int i=1; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // heap sort
    heapSort(arr, n);

    cout << "printing sorted array" << endl;
    for(int i=1; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}