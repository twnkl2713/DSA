#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool comp(const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1];
}

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty()) return 0;

    sort(intervals.begin(), intervals.end(), comp);

    int cnt = 1;
    int lastEnd = intervals[0][1];

    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i][0] >= lastEnd) {
            cnt++;
            lastEnd = intervals[i][1];
        }
    }
    return intervals.size() - cnt;
}

int main() {
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    int result = eraseOverlapIntervals(intervals);
    cout << "Minimum number of intervals to remove: " << result << endl;
    return 0;
}
