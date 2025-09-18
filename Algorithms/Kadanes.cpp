// Kadane's Algorithm - Maximum Subarray Sum

// Pattern: Maximum Subarray Sum(contiguos)
// When: Array has positives + negatives

#include<bits/stdc++.h>
using namespace std;

int kadane(vector<int>& nums) {
    int maxSum = INT_MIN;
    int currSum = 0, ansStart = -1, ansEnd = -1, start = -1;
    for(int i=0; i<nums.size(); i++) {
        if(currSum == 0) {
            start = i;
        }
        currSum += nums[i];
        if(currSum > maxSum) {
            maxSum = currSum;
            ansStart = start, ansEnd = i;
        }
        if(currSum < 0) {
            currSum = 0;
        }
    }
    return maxSum;
}

int main() {
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    cout << kadane(arr); 
}