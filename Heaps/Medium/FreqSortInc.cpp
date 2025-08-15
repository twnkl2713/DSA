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
    auto cmp = [](pair<int, int>& a, pair<int, int>& b) {
        if(a.first == b.first) {
            return a.second < b.second; // higher value first is freq same
        }
        else {
            return a.first > b.first; // lower freq first
        }
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> minHeap(cmp);
    for(auto& it: map) {
        minHeap.push({it.second, it.first});
    }
    vector<int> result;
    while(!minHeap.empty()) {
        int freq = minHeap.top().first;
        int val = minHeap.top().second;
        minHeap.pop();
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