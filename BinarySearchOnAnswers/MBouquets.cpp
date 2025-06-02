#include<iostream>
#include<vector>
#include<climits>
using namespace std;

bool possible(vector<int> &arr, int day, int m, int k){
    int cnt = 0;
    int noOfB = 0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] <= day){
            cnt ++;
        }
        else{
            noOfB += cnt/k;
            cnt = 0;
        }
    }
    noOfB += cnt/k;
    return noOfB >= m;
}

int roseGarden(vector<int> &arr, int r, int b){
    long long val = r * 1LL * b * 1LL;
    if(val > arr.size()) return -1;
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for(int i=0; i<arr.size(); i++){
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }
    int low = mini, high = maxi;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(possible(arr, mid, r, b)){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}

int main(){
    int n, m, k;
    cout << "Enter number of flowers: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter bloom days of flowers: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << "Enter number of bouquets (m): ";
    cin >> m;
    cout << "Enter number of adjacent flowers per bouquet (k): ";
    cin >> k;

    int minDay = roseGarden(arr, m, k);
    if(minDay == -1)
        cout << "It is not possible to make " << m << " bouquets with " << k << " flowers each." << endl;
    else
        cout << "The minimum day to make " << m << " bouquets is: " << minDay << endl;

    return 0;
}