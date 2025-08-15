#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

vector<int> frequencySort(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> map;
    for(int i=0; i<n; i++) {
        map[nums[i]]++;
    }
    priority_queue<pair<int, int>> maxHeap;
    for(auto& it: map) {
        maxHeap.push({it.second, it.first});
    }
    vector<int> result;
    while(!maxHeap.empty()) {
        int freq = maxHeap.top().first;
        int val = maxHeap.top().second;
        maxHeap.pop();
        for(int i=0; i<freq; i++) {
            result.push_back(val);
        }
    }
    return result;
}

int main() {
    vector<int> nums = {1, 1, 2, 2, 2, 3};
    vector<int> sortedArr = frequencySort(nums);
    cout << "Sorted array: ";
    for (int num : sortedArr) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}