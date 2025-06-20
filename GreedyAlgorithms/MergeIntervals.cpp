#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> mergedIntervals;
    if (intervals.size() == 0) {
        return mergedIntervals;
    }
    // Sort intervals based on the starting time
    sort(intervals.begin(), intervals.end());
    vector<int> tempInterval = intervals[0];
    for (auto it : intervals) {
        if (it[0] <= tempInterval[1]) {
            // Overlap found, merge
            tempInterval[1] = max(it[1], tempInterval[1]);
        } else {
            // No overlap, push current and move on
            mergedIntervals.push_back(tempInterval);
            tempInterval = it;
        }
    }
    // Push the last interval
    mergedIntervals.push_back(tempInterval);
    return mergedIntervals;
}

int main() {
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> result = merge(intervals);
    cout << "Merged Intervals:\n";
    for (const auto& interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;
    return 0;
}
