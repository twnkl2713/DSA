#include<iostream>
using namespace std;

// function to check if array represents a Min Heap
bool isMinHeap(int arr[], int n) {
    // check from 0 to last internal node(parent of last node)
    for(int i=0; i<=(n-2)/2; i++) {
        int left = 2*i + 1;
        int right = 2*i + 2;

        // if left child exists and is smaller than parent
        if(left < n && arr[left] < arr[i]) {
            return false;
        }
        // if right child exists and is smaller than parent
        if(right < n && arr[right] < arr[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int arr1[] = {1, 3, 5, 7, 9, 8};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {10, 15, 9, 30, 40};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    cout << "arr1 is " << (isMinHeap(arr1, n1) ? "a Min Heap" : "not a Min Heap") << endl;
    cout << "arr2 is " << (isMinHeap(arr2, n2) ? "a Min Heap" : "not a Min Heap") << endl;

    return 0;
}