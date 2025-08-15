#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int minCost(vector<int>& nums) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int n = nums.size();
    for(int i=0; i<n; i++) {
        minHeap.push(nums[i]);
    }
    int Tcost = 0;
    while(minHeap.size() > 1) {
        int first = minHeap.top();
        minHeap.pop();
        int second = minHeap.top();
        minHeap.pop();
        int sum = first + second;
        Tcost += sum;
        minHeap.push(sum);
    }
    return Tcost;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << "Minimum cost to connect ropes: " << minCost(nums) << endl;
    return 0;
}