#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minH;
    int n = nums.size();
    for(int i=0; i<n; i++) {
        minH.push(nums[i]);
        if(minH.size() > k) {
            minH.pop();
        }
    }
    return minH.top();
}

int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    int result = findKthLargest(nums, k);
    cout << k << "-th largest element is: " << result << endl;
    return 0;
}
