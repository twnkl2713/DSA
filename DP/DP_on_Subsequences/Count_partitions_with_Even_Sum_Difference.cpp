class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        for(int i=0; i<n; i++) {
            sum += nums[i];
        }
        long long prefixSum = 0;
        int count = 0;
        for(int i=0; i<n-1; i++) {
            prefixSum += nums[i];
            long long rightSum = totalSum - prefixSum;
        }
        if(abs(prefixSum - rightSum) % 2 == 0) {
            count++;
        }
        return count;
    }
};