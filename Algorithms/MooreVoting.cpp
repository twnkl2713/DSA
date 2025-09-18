// MOORE'S VOTING ALGORITHM 
// PATTERN: MAJORITY ELEMENT ( appears > n/2 times)
// WHEN: Only 1 majority guaranteed
// Problem guarantees at most one majority element.

#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
    int candidate = 0, cnt = 0;
    for(int i=0; i<nums.size(); i++) {
        if(cnt == 0) {
            cnt = 1;
            candidate = nums[i];
        }
        else if(nums[i] == candidate) {
            cnt++;
        }
        else {
            cnt--;
        }
    }
    cnt = 0;
    for(int i=0; i<nums.size(); i++) {
        if(nums[i] == candidate) {
            cnt++;
        }
    }
    if(cnt > (nums.size() / 2)) {
        return candidate;
    }
    return -1;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int ans = majorityElement(nums);
    if (ans != -1) {
        cout << "Majority Element is: " << ans << endl;
    } else {
        cout << "No majority element found" << endl;
    }
    return 0;
}