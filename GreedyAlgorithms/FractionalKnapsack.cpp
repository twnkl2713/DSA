#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int value;
    int weight;
};

bool comp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
    int n = val.size();
    vector<Item> arr(n);

    // Fill array of Items
    for (int i = 0; i < n; i++) {
        arr[i].value = val[i];
        arr[i].weight = wt[i];
    }

    // Sort items by value/weight ratio
    sort(arr.begin(), arr.end(), comp);

    double totalVal = 0.0;

    for (int i = 0; i < n; i++) {
        if (arr[i].weight <= capacity) {
            totalVal += arr[i].value;
            capacity -= arr[i].weight;
        } else {
            totalVal += arr[i].value * ((double)capacity / arr[i].weight);
            break;
        }
    }

    return totalVal;
}

int main() {
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int capacity = 50;

    double maxVal = fractionalKnapsack(values, weights, capacity);
    cout << "Maximum value in knapsack = " << maxVal << endl;

    return 0;
}
