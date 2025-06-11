#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canJump(vector<int>& nums) {
    int n = nums.size();
    int farthest = 0;
    for(int i = 0; i < n; i++) {
        if(i > farthest) {
            return false;
        }
        farthest = max(farthest, i + nums[i]);
    }
    return true;
}

int main() {
    vector<int> nums = {2, 3, 1, 1, 4}; 
    if (canJump(nums)) {
        cout << "You can reach the last index" << endl;
    } else {
        cout << "You cannot reach the last index" << endl;
    }
    return 0;
}
