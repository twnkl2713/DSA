#include <bits/stdc++.h>
using namespace std;

pair<int,int> twosum(vector<int>& nums, int n, int target) {
    unordered_map<int, int> mp; // value -> index
    for(int i = 0; i < n; i++) {
        int a = nums[i];
        int more = target - a;
        if(mp.find(more) != mp.end()) {
            return {mp[more], i};  // return pair of indices
        }
        mp[a] = i;
    }
    return {-1, -1}; // if no pair found
}

// OPTIMAL APPROACH :
// int left = 0, right = 0;
// sort(nums.begin(), nums.end());
// while(left < right) {
//     int sum = nums[left] + nums[right];
//     if(sum == target) {
//         return "yes";
//     }
//     else if(sum < target) {
//         left++;
//     }
//     else {
//         right--;
//     }
// }
// return -1;

int main() {
    vector<int> arr = {2, 7, 11, 15};
    int target = 9;
    int n = arr.size();
    pair<int,int> res = twosum(arr, n, target);
    if(res.first != -1) {
        cout << "Indices: " << res.first << " " << res.second << endl;
        cout << "Values: " << arr[res.first] << " + " << arr[res.second] 
             << " = " << target << endl;
    } else {
        cout << "No pair found" << endl;
    }
    return 0;
}
