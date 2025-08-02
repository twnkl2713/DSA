#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int kthSmallest(vector<int>& arr, int k) {
    priority_queue<int> pq;

    // Step 1: Insert first k elements into the max-heap
    for (int i = 0; i < k; i++) {
        pq.push(arr[i]);
    }

    // Step 2: For remaining elements, maintain heap of k smallest
    for (int i = k; i < arr.size(); i++) {
        if (arr[i] < pq.top()) {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    // Step 3: Return the top element of max-heap
    return pq.top();
}

int main() {
    int n, k;
    cout << "Enter number of elements in array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of array:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the value of k: ";
    cin >> k;

    int result = kthSmallest(arr, k);
    cout << "The " << k << "th smallest element is: " << result << endl;

    return 0;
}
