class Solution {
  public:
    int minimumDifference(vector<int>& nums) {
        // Your code goes here
        int sum = 0;
        int n = nums.size();
        int diff = INT_MAX;
        for(int i=0; i<n; i++) {
            sum += nums[i];
        }
        vector<vector<bool>> K(n + 1, vector<bool>(sum + 1, false));
        for(int i=0; i<=n; i++) {
            K[i][0] = true;
        }
        for(int i=1; i<=n; i++) {
            for(int s=1; s<=sum; s++) {
                if(nums[i - 1] <= s) {
                    K[i][s] = K[i - 1][s - nums[i - 1]] || K[i - 1][s];
                }
                else {
                    K[i][s] = K[i - 1][s];
                }
            }
        }
        for(int i=sum/2; i>=0; i--) {
            if(K[n][i] == true) {
                diff = sum - 2 * i; // s1 = s, s2 = sum - s, diff = s2 - s1
                break;
            }
        }
        return diff;
    }
};
