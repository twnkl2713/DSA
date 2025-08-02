#include <iostream>
#include <vector>
#include <queue>
using namespace std;

long long minCost(vector<int>& arr) {
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int val : arr) pq.push(val);

    long long cost = 0;
    while (pq.size() > 1) {
        long long a = pq.top(); pq.pop();
        long long b = pq.top(); pq.pop();
        long long sum = a + b;
        cost += sum;
        pq.push(sum);
    }

    return cost;
}

int main() {
    vector<int> arr = {4, 3, 2, 6};
    cout << "Minimum cost: " << minCost(arr) << endl;
    return 0;
}
