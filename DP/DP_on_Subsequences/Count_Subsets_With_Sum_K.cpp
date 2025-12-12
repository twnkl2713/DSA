class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<vector<int>> K(n + 1, vector<int>(target + 1, 0));
        for(int i=0; i<=n; i++) {
            K[i][0] = 1;
        }
        for(int i=1; i<=n; i++) {
            for(int s=0; s<=target; s++) {
                if(arr[i - 1] <= s) {
                    K[i][s] = K[i - 1][s] + K[i - 1][s - arr[i - 1]];
                }
                else {
                    K[i][s] = K[i - 1][s];
                }
            }
        }
        return K[n][target];
    }
};