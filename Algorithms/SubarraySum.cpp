#include<bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    int prefix_sum = 0, maxLen = 0;
    for(int i=0; i<nums.size(); i++) {
        prefix_sum += nums[i];
        if(prefix_sum == k) { // subarray from 0..i
            maxLen = max(maxLen, i+1);
        }
        int rem = prefix_sum - k;
        if(mp.find(rem) != mp.end()) {
            int len = i - mp[rem];
            maxLen = max(maxLen, len);
        }
        // store only first occurrence(for longest length)
        if(mp.find(prefix_sum) == mp.end()) {
            mp[prefix_sum] = i;
        }
    }
    return maxLen;
}

int main() {
    vector<int> arr = {10, 5, 2, 7, 1, 9};
    int k = 15;
    cout << longestSubarrayWithSumK(arr, k); 
}