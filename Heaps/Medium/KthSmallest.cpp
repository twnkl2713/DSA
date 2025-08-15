#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int kthSmallest(vector<int> &arr, int k) {
    priority_queue<int> maxi; // max-heap
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        maxi.push(arr[i]);
        if (maxi.size() > k) {
            maxi.pop(); // remove largest so only k smallest remain
        }
    }
    return maxi.top();
}

int main() {
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;
    int result = kthSmallest(arr, k);
    cout << k << "-th smallest element is: " << result << endl;
    return 0;
}
