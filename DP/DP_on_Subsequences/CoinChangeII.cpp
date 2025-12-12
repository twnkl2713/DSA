class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(amount + 1, 0));
        dp[0][0] = 1;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= amount; j++) {
                dp[i][j] = dp[i - 1][j]; // exclude current coin
                if (coins[i - 1] <= j) {
                    dp[i][j] += dp[i][j - coins[i - 1]]; // include current coin
                }
            }
        }
        return dp[n][amount];
    }
};