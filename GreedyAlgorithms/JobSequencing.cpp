#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
    int n = deadline.size();

    // Create a vector of jobs: pair<profit, deadline>
    vector<pair<int, int>> jobs;
    for (int i = 0; i < n; i++) {
        jobs.push_back({profit[i], deadline[i]});
    }

    // Sort jobs by profit in descending order
    sort(jobs.begin(), jobs.end(), greater<pair<int, int>>());

    // Find the maximum deadline to determine size of slots
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        maxDeadline = max(maxDeadline, jobs[i].second);
    }

    // Initialize all time slots as free (-1)
    vector<int> slot(maxDeadline + 1, -1);

    int countJobs = 0;
    int totalProfit = 0;

    // Iterate through jobs and try to schedule them
    for (int i = 0; i < n; i++) {
        int d = jobs[i].second;

        // Find a free slot from d to 1
        for (int j = d; j > 0; j--) {
            if (slot[j] == -1) {
                slot[j] = i; // schedule job
                countJobs++;
                totalProfit += jobs[i].first;
                break;
            }
        }
    }

    return {countJobs, totalProfit};
}

int main() {
    vector<int> deadline = {2, 1, 2, 1, 3};
    vector<int> profit = {100, 50, 10, 20, 30};

    vector<int> result = jobSequencing(deadline, profit);

    cout << "Maximum Jobs Done: " << result[0] << endl;
    cout << "Total Profit Earned: " << result[1] << endl;

    return 0;
}
