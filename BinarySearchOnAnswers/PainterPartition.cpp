#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<numeric>
using namespace std;

int countPairs(vector<int> &arr, int maxTime) {
    int painters = 1;
    long long timeSpent = 0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] > maxTime) {
            return INT_MAX; // if a single one is larger, that's impossible 
        }
        if(timeSpent + arr[i] <= maxTime) {
            timeSpent += arr[i];
        }
        else {
            painters = painters + 1;
            timeSpent = arr[i];
        }
    }
    return painters;
}

int minTime(vector<int> &arr, int k) {
    if(k > arr.size()) {
        return -1; // impossible
    }
    int low = *max(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int ans = -1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        int painters = countPairs(arr, mid);
        if(painters > k) {
            low = mid + 1; // need more paniters -> increase time -> so eliminate the left part
        }
        else{
            ans = mid; // may or may not be the answer, so try for smaller ones
            high = mid - 1; // eliminate the right half
        }
    }
    return ans;
}

int main() {
    vector<int> boards = {10, 20, 30, 40}; // Time required for each board
    int painters = 2;

    int result = minTime(boards, painters);

    if(result != -1)
        cout << "Minimum time to paint all boards: " << result << endl;
    else
        cout << "Not enough boards to assign one per painter!" << endl;

    return 0;
}