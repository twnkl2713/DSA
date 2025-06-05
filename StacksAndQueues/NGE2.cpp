#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElements(vector<int> &nums) {
    int n = nums.size();
    vector<int> nge(n, -1); // initialize result with -1
    stack<int> s; // stack to hold indices

    for(int i=0; i<2*n; i++) { // for circular nature
        while(!s.empty() && nums[s.top()] < nums[i % n]) { // while current element is greater than the element at stack's top index
            nge[s.top()] = nums[i % n]; // assign next greater
            s.pop();
        }
        // push index only during the first pass
        if(i < n) {
            s.push(i);
        }
    }
    return nge;
}

int main() {
    vector<int> nums = {1, 2, 1};
    vector<int> result = nextGreaterElements(nums);
    cout << "Next Greater Elements in Circular Array: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}