#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;

vector<int> findKClosestElements(vector<int>& arr, int k, int x) {
    priority_queue<pair<int, int>> maxHeap;
    int n = arr.size();
    for(int i=0; i<n; i++) {
        maxHeap.push({abs(arr[i] - x), arr[i]});
        if(maxHeap.size() > k) {
            maxHeap.pop();
        }
    }
    vector<int> result;
    while(!maxHeap.empty()) {
        result.push_back(maxHeap.top().second);
        maxHeap.pop();
    }
    sort(result.begin(), result.end());
    return result;
}

int main() {
    vector<int> arr = {5, 6, 7, 8, 9};
    int k = 3;
    int x = 7;
    vector<int> closest = findKClosestElements(arr, k, x);
    cout << "K closest elements: ";
    for (int num : closest) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}