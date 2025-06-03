#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool canWePlaceCows(vector<int> &arr, int dist, int cows) {
    int cntCows = 1, cord = arr[0];
    for(int i=1; i<arr.size(); i++) {
        if(arr[i] - cord >= dist){
            cntCows = cntCows + 1;
            cord = arr[i];
        }
    }
    if(cntCows >= cows) {
        return true;
    }
    else{
        return false;
    }
}

int aggressiveCows(vector<int> &arr, int k) {
    int ans = -1;
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int low = 0, high = arr[n-1] - arr[0];
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(canWePlaceCows(arr, mid, k) == true){
            ans = mid;
            low = mid + 1; // eliminate the left half and move to right->trying for a bigger min dist
        }
        else {
            high = mid - 1; // reducing the min dist
        }
    }
    return ans;
}

int main() {
    int n, cows;
    cout << "Enter number of stalls: ";
    cin >> n;

    vector<int> positions(n);
    cout << "Enter stall positions: ";
    for(int i = 0; i < n; i++) {
        cin >> positions[i];
    }

    cout << "Enter number of cows: ";
    cin >> cows;

    int maxDist = aggressiveCows(positions, cows);
    cout << "Maximum minimum distance to place cows: " << maxDist << endl;

    return 0;
}