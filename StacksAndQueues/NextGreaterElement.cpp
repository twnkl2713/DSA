#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    unordered_map<int, int> map;
    stack<int> st;
    for(int i=nums2.size()-1; i>=0; i--) {
        while(!st.empty() && st.top() < nums2[i]) {
            st.pop(); // remove elements from the stack that are less than or equal to current no.
        }
        if(st.empty()) { // if stack is empty, no greater element to the right
            map[nums2[i]] = -1;
        }
        else {
            map[nums2[i]] = st.top(); // top of the stack is next greater element
        }
        st.push(nums2[i]); // push current no. to stack
    }
    vector<int> result;
    for(int i=0; i<nums1.size(); i++) {
        result.push_back(map[nums1[i]]);
    }
    return result;
}

int main() {
    vector<int> nums1 = {4, 1, 2}; // Subset of nums2
    vector<int> nums2 = {1, 3, 4, 2}; // Full array

    vector<int> result = nextGreaterElement(nums1, nums2);

    cout << "Next greater elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}