#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

vector<int> mergeHeaps(vector<int>& a, vector<int>& b) {
    vector<int> ans = a;
    ans.insert(ans.end(), b.begin(), b.end());
    int size = ans.size();
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(ans, size, i);
    }
    return ans;
}

int main() {
    vector<int> a = {10, 5, 6};
    vector<int> b = {7, 9, 4};

    vector<int> mergedHeap = mergeHeaps(a, b);

    cout << "Merged Max Heap: ";
    for (int val : mergedHeap) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
