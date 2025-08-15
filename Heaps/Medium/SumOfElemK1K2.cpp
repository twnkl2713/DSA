#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int findKthSmallest(vector<int>& A, int k) {
    priority_queue<int> maxHeap;
    for (int i = 0; i < A.size(); i++) {
        maxHeap.push(A[i]);
        if ((int)maxHeap.size() > k) {
            maxHeap.pop();
        }
    }
    return maxHeap.top();
}

int sumBetweenTwoKth(vector<int>& A, int K1, int K2) {
    int first = findKthSmallest(A, K1);
    int second = findKthSmallest(A, K2);
    int sum = 0;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] > first && A[i] < second) {
            sum += A[i];
        }
    }
    return sum;
}

int main() {
    vector<int> A = {20, 8, 22, 4, 12, 10, 14};
    int K1 = 3, K2 = 6;
    cout << sumBetweenTwoKth(A, K1, K2) << endl; 
    return 0;
}