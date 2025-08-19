#include<iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int target) {
    if(low > high) {
        return -1;
    }
    int mid = low + (high - low) / 2;
    if(arr[mid] == target) {
        return mid;
    }
    else if(arr[mid] > target) {
        return binarySearch(arr, low, mid - 1, target);
    }
    else {
        return binarySearch(arr, mid + 1, high, target);
    }
}

int main() {
    int n, target;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements in sorted order: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter element to search: ";
    cin >> target;
    int index = binarySearch(arr, 0, n - 1, target);
    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found" << endl;
    return 0;
}