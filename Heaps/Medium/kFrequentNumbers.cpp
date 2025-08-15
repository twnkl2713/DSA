// Decreasing Order

#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++) {
        mp[nums[i]]++;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    for(auto& it: mp) {
        minHeap.push({it.second, it.first});
        if(minHeap.size() > k) {
            minHeap.pop();
        }
    }
    vector<int> result;
    while(!minHeap.empty()) {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }
    return result;
}

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> result = topKFrequent(nums, k);
    cout << "Top " << k << " frequent elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
