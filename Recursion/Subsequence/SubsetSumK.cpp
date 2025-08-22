#include <iostream>
#include <vector>
using namespace std;

void printS(int ind, vector<int>& nums, int sum, int k, vector<int>& ds, vector<vector<int>>& ans) {
    int n = nums.size();
    if(ind == n) {
        if(sum == k) {
            ans.push_back(ds);   // store this subset
        }
        return;
    }

    // take current element
    ds.push_back(nums[ind]);
    sum += nums[ind];
    printS(ind+1, nums, sum, k, ds, ans);

    // backtrack (remove element)
    sum -= nums[ind];
    ds.pop_back();

    // do not take current element
    printS(ind+1, nums, sum, k, ds, ans);
}

int subsetSumEqualsK(vector<int>& nums, int k) {
    vector<vector<int>> ans;
    vector<int> ds;
    int sum = 0;
    printS(0, nums, sum, k, ds, ans);
    return ans.size(); // count of subsets with sum k
}

int main() {
    vector<int> nums = {1, 2, 1};
    int k = 2;
    int count = subsetSumEqualsK(nums, k);
    cout << "Total subsets with sum = " << k << " is: " << count << endl;
    return 0;
}
