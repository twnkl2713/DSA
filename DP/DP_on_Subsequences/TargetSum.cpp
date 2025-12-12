class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += nums[i];
        }
        if((target + sum) < 0 || (target + sum) % 2 != 0) return 0;
        int s1 = (target + sum) / 2;
        vector<vector<int>> K(n + 1, vector<int>(s1 + 1, 0));
        K[0][0] = 1;
        for(int i=1; i<=n; i++) {
            for(int j=0; j<=s1; j++) {
                if(nums[i-1] <= j) {
                    K[i][j] = (K[i-1][j] + K[i-1][j-nums[i-1]]) % 1000000007;
                }
                else {
                    K[i][j] = K[i-1][j];
                }
            }
        }
        return K[n][s1];
    }
};