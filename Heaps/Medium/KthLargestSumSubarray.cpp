#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int kthLargest(vector<int> &arr, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) { 
            sum += arr[j];
            if (minHeap.size() < k) {
                minHeap.push(sum);
            } 
            else if (sum > minHeap.top()) {
                minHeap.pop();
                minHeap.push(sum);
            }
        }
    }
    return minHeap.top();
}

int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << "Enter k: ";
    cin >> k;
    int ans = kthLargest(arr, k);
    cout << k << "-th largest subarray sum = " << ans << endl;
    return 0;
}
