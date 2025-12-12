class Solution {
public:
    bool subsetSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<bool>> K(n + 1, vector<bool>(target + 1, false));
        for(int i=0; i<=n; i++) {
            K[i][0] = true;
        }
        for(int i=1; i<=n; i++) {
            for(int s=1; s<=target; s++) {
                if(nums[i - 1] <= s) {
                    K[i][s] = K[i-1][s] || K[i-1][s-nums[i-1]];
                }
                else {
                    K[i][s] = K[i-1][s];
                }
            }
        }
        return K[n][target];
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0; 
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
        }
        if(sum % 2 != 0) return false;
        return subsetSum(nums, sum/2);
    }
};