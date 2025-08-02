#include <iostream>
#include <queue>
using namespace std;

int main() {
    // min heap using comparator
    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(10);
    minHeap.push(30);
    minHeap.push(20);
    minHeap.push(5);

    // Top returns the minimum element
    cout << "Top element (Min): " << minHeap.top() << endl;

    // Remove top (min) element
    minHeap.pop();

    // Print remaining elements in order
    cout << "Remaining elements: ";
    while(!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;

    return 0;
}