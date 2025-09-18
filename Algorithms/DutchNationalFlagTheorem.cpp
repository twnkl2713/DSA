// DUTCH NATIONAL FLAG THEOREM

// Pattern: Array has 3 groups of elements
// When: Sort in-place without extra space

#include<bits/stdc++.h>
using namespace std;

void dutchFlag(vector<int>& nums) {
    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;
    while(mid <= high) {
        if(nums[mid] == 0) {
            swap(nums[low++], nums[mid++]);
        }
        else if(nums[mid] == 1) {
            mid++;
        }
        else {
            swap(nums[mid], nums[high--]);
        }
    }
}

int main() {
    vector<int> arr = {2,0,2,1,1,0};
    dutchFlag(arr);
    for (int x : arr) cout << x << " "; 
}