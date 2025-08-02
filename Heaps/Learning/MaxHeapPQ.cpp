#include<iostream>
#include<queue>
using namespace std;

int main() {
    priority_queue<int> maxHeap; // by default, this is a max heap

    maxHeap.push(10);
    maxHeap.push(30);
    maxHeap.push(20);
    maxHeap.push(5);

    // top returns the max element
    cout << "Top element (Max): " << maxHeap.top() << endl;

    // remove top (max) element
    maxHeap.pop();

    // print remaining elements in order
    cout << "Remaining elements: ";
    while(!maxHeap.empty()) {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    cout << endl;

    return 0;
}