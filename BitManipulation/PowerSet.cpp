// print all subsets
#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> subsets(vector<int> &nums) {
    int n = nums.size();
    int subsets = 1 << n; // 2^n
    vector<vector<int>> ans;
    for(int num=0; num<subsets; num++) {
        vector<int> list;
        for(int i=0; i<nums.size(); i++) {
            if(num & (1 << i)) { // if it's set bit
                list.push_back(nums[i]);
            }
        }
        ans.push_back(list);
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<vector<int>> allSubsets = subsets(nums);

    cout << "All subsets:\n";
    for (const auto &subset : allSubsets) {
        cout << "{ ";
        for (int val : subset) {
            cout << val << " ";
        }
        cout << "}\n";
    }

    return 0;
}