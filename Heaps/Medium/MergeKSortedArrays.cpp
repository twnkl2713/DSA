#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
    typedef vector<int> type;
    priority_queue<type, vector<type>, greater<type>> minHeap;
    for (int i = 0; i < K; i++) {
        if (!arr[i].empty()) {
            minHeap.push({arr[i][0], i, 0});
        }
    }
    vector<int> result;
    while (!minHeap.empty()) {
        auto top = minHeap.top();
        minHeap.pop();
        result.push_back(top[0]);
        int i = top[1];
        int j = top[2];
        if (j + 1 < arr[i].size()) {
            minHeap.push({arr[i][j+1], i, j+1});
        }
    }
    return result;
}

int main() {
    int K;
    cout << "Enter number of arrays: ";
    cin >> K;
    vector<vector<int>> arr(K);
    for (int i = 0; i < K; i++) {
        int n;
        cout << "Enter size of array " << i+1 << ": ";
        cin >> n;
        arr[i].resize(n);
        cout << "Enter elements (sorted): ";
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    vector<int> merged = mergeKArrays(arr, K);
    cout << "Merged sorted array: ";
    for (int x : merged) {
        cout << x << " ";
    }
    return 0;
}