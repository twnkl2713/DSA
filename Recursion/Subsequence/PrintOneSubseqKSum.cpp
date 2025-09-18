#include <bits/stdc++.h>
using namespace std;

bool printS(int ind, int sum, vector<int>& nums, int k, vector<int>& ds) {
    int n = nums.size();
    if (ind == n) {
        if (sum == k) {
            // Print the first valid subset
            cout << "First subset with sum = " << k << " is: { ";
            for (int x : ds) cout << x << " ";
            cout << "}" << endl;
            return true;  // stop recursion once found
        }
        return false;
    }
    // take current element
    ds.push_back(nums[ind]);
    if (printS(ind + 1, sum + nums[ind], nums, k, ds)) return true;
    // not take current element
    ds.pop_back();
    if (printS(ind + 1, sum, nums, k, ds)) return true;
    return false;
}

int main() {
    vector<int> nums = {1, 2, 1, 3};
    int k = 4;
    vector<int> ds;
    if (!printS(0, 0, nums, k, ds))
        cout << "No subset found with sum = " << k << endl;
    return 0;
}
