#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct meeting {
    int start;
    int end;
    int pos;
};

// Comparator to sort meetings by end time
bool comp(meeting m1, meeting m2) {
    return m1.end < m2.end;
}

// Function to find the maximum number of non-overlapping meetings
int maxMeetings(vector<int>& start, vector<int>& end) {
    int n = start.size();
    vector<meeting> m(n);

    for (int i = 0; i < n; i++) {
        m[i].start = start[i];
        m[i].end = end[i];
        m[i].pos = i + 1;
    }

    sort(m.begin(), m.end(), comp);

    int count = 1;
    int freeTime = m[0].end;

    for (int i = 1; i < n; i++) {
        if (m[i].start > freeTime) {
            count++;
            freeTime = m[i].end;
        }
    }

    return count;
}

int main() {
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end   = {2, 4, 6, 7, 9, 9};

    int maxMeet = maxMeetings(start, end);
    cout << "Maximum number of meetings: " << maxMeet << endl;

    return 0;
}
