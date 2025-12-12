class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int W = capacity;
        int n = val.size();
        vector<vector<int>> K(n + 1, vector<int>(W + 1, 0));
        for(int i=0; i<=n; i++) {
            for(int w=0; w<=W; w++) {
                if(i == 0 || w == 0) {
                    K[i][w] = 0;
                }
                else if(wt[i - 1] <= w) {
                    K[i][w] = max(val[i - 1] + K[i][w - wt[i - 1]], K[i - 1][w]);
                }
                else {
                    K[i][w] = K[i - 1][w];
                }
            }
        }
        return K[n][W];
    }
};