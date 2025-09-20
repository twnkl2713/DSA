// KADANE'S ALGORITHM
// here it is product
// intuition - 
// 1. start fresh: just nums[i] - ignore previous subarray
// 2. extend the previous maximum: prod1 * nums[i]
// 3. extend the previous minimum: prod2 * nums[i] (in case nums[i] is negative)

#include<bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int prod1 = nums[0], prod2 = nums[0], prod3 = nums[0], result = nums[0];
    for(int i=1; i<n; i++) {
        int temp = max({nums[i], prod1*nums[i], prod2*nums[i]});
        prod2 = min({nums[i], prod1*nums[i], prod2*nums[i]});
        prod1 = temp;
        result = max(prod1, result);
    }
    return result;
}

int main() {
    vector<int> nums = {2, 3, -2, 4};
    cout << "Maximum product subarray = " << maxProduct(nums) << endl;
    vector<int> nums2 = {-2, 0, -1};
    cout << "Maximum product subarray = " << maxProduct(nums2) << endl;
    return 0;
}