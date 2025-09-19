// majority element (> n/3 times)

#include<bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    int cnt1 = 0, cnt2 = 0;
    int el1 = INT_MIN;
    int el2 = INT_MIN;
    for(int i=0; i<nums.size(); i++) {
        if(cnt1 == 0 && el2 != nums[i]) {
            cnt1 = 1;
            el1 = nums[i];
        }
        else if(cnt2 == 0 && el1 != nums[i]) {
            cnt2 = 1;
            el2 = nums[i];
        }
        else if(nums[i] == el1) cnt1++;
        else if(nums[i] == el2) cnt2++;
        else {
            cnt1--;
            cnt2--;
        }
    }
    vector<int> list;
    for(int i=0; i<nums.size(); i++) {
        if(el1 == nums[i]) cnt1++;
        if(el2 == nums[i]) cnt2++;
    }
    int mini = (int)(nums.size()/3) + 1;
    if(cnt1 >= mini) list.push_back(el1);
    if(cnt2 >= mini) list.push_back(el2);
    sort(list.begin(), list.begin());
    return list;
}

int main() {
    vector<int> nums = {1, 2, 2, 3, 2, 1, 1, 3};
    vector<int> ans = majorityElement(nums);
    cout << "Majority elements (> n/3 times): ";
    for (int x : ans) cout << x << " ";
    cout << endl;
    return 0;
}