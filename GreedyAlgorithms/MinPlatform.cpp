#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findPlatform(vector<int>& arr, vector<int>& dep) {
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    
    int i = 0, j = 0;
    int cnt = 0, maxCnt = 0;
    
    while(i < arr.size() && j < dep.size()) {
        if(arr[i] <= dep[j]) {
            cnt += 1;
            i++;
        }
        else {
            cnt -= 1;
            j++;
        }
        maxCnt = max(maxCnt, cnt);
    }
    
    return maxCnt;
}

int main() {
    vector<int> arrival = {900, 940, 950, 1100, 1500, 1800};
    vector<int> departure = {910, 1200, 1120, 1130, 1900, 2000};

    int result = findPlatform(arrival, departure);
    cout << "Minimum number of platforms required = " << result << endl;

    return 0;
}
