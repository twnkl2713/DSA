#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<numeric>
using namespace std;

bool check(vector<int> &stations, int k, double mid) {
    int count = 0;
    for(int i=0; i<stations.size(); i++) {
        int diff = stations[i] - stations[i-1];
        if(diff > mid) {
            count += diff / mid;
        }
    }
    if(count > k) return false;
    else return true;
}

double findSmallestMaxDistance(vector<int> &stations, int k) {
    double low = 0;
    int n = stations.size();
    double high = stations[n-1] - stations[0];
    double ans = 0;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(check(stations, k, mid) == true) {
            ans = mid;
            high = mid - 0.000001;
        }
        else {
            low = mid + 0.000001;
        }
    }
    return ans;
}

int main() {
    vector<int> stations = {0, 10, 20, 30, 40, 50};
    int k = 5; // no.of additional stations to add

    double result = findSmallestMaxDistance(stations, k);
    cout << "Smallest maximum distance after adding " << k << " stations: ";
    cout.precision(6);
    cout << fixed;
    cout << result << endl;

    return 0;
}
