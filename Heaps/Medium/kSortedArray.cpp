#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void sortKSortedArray(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int n = nums.size();
    int idx = 0;

    // step 1: push first k+1 elements
    for(int i=0; i<=k && i<n; i++) {
        minHeap.push(nums[i]);
    }

    // step 2: process remaining elements
    for(int i=k+1; i<n; i++) {
        nums[idx++] = minHeap.top();
        minHeap.pop();
        minHeap.push(nums[i]);
    }

    // step 3: pop remaining elements
    while(!minHeap.empty()) {
        nums[idx++] = minHeap.top();
        minHeap.pop();
    }
}

int main() {
    vector<int> nums = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;
    sortKSortedArray(nums, k);
    cout << "Sorted array: ";
    for(int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}