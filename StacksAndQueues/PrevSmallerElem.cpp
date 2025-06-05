#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> prevSmallerElement(vector<int> &nums) {
    int n = nums.size();
    vector<int> ans(n, 0);
    stack<int> s;
    for(int i=0; i<n; i++) {
        while(!s.empty() && s.top() >= nums[i]) {
            s.pop(); // pop all elements greater than or equal to current
        }
        if(s.empty()) {
            ans[i] = -1;
        }
        else {
            ans[i] = s.top(); // top of stack is the previous smaller
        }
        s.push(nums[i]);
    }
    return ans;
}
int main() {
    vector<int> nums = {4, 5, 2, 10, 8};
    vector<int> result = prevSmallerElement(nums);
    cout << "Previous Smaller Elements: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
