class Solution {
    public:
       bool isSubsetSum(vector<int>& arr, int sum) {
            int n = arr.size();
            vector<vector<bool>> K(n+1, vector<bool>(sum+1, false));
            for(int i=0; i<=n; i++) {
                K[i][0] = true;
            }
            for(int i=1; i<=n; i++){
                for(int s=1; s<=sum; s++) {
                    if(arr[i-1] <= s) {
                        K[i][s] = K[i-1][s] || K[i-1][s-arr[i-1]];
                    } else {
                        K[i][s] = K[i-1][s];
                    }
                }
            }
            return K[n][sum];
       }
};