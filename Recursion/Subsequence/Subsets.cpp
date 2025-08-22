#include <iostream>
#include <vector>
using namespace std;

void helper(int ind, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans) {
    if(ind == nums.size()) {
        ans.push_back(ds); // store the current subset
        return;
    }
    // take current element
    ds.push_back(nums[ind]);
    helper(ind+1, nums, ds, ans);
    
    // not take the current element
    ds.pop_back();
    helper(ind+1, nums, ds, ans);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> ds;
    helper(0, nums, ds, ans);
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3};  
    vector<vector<int>> result = subsets(nums);
    cout << "All subsets:\n";
    for(auto subset : result) {
        cout << "{ ";
        for(int x : subset) {
            cout << x << " ";
        }
        cout << "}\n";
    }
    return 0;
}
