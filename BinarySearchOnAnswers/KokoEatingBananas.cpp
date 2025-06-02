#include<iostream>
#include<vector>
#include<cmath>
#include<climits>
using namespace std;

int findMax(vector<int> piles){
    int maxi = INT_MIN;
    for(int i=0; i<piles.size(); i++){
        maxi = max(maxi, piles[i]);
    }
    return maxi;
}

int calculateTotalHours(vector<int> &piles, int hourly){
    int totalH = 0;
    for(int i=0; i<piles.size(); i++){
        totalH += ceil((double)piles[i] / (double)hourly);
    }
    return totalH;
}

int minRateToEatBananas(vector<int> &piles, int h){
    int low = 1, high = findMax(piles);
    int ans = high;
    while(low <= high){
        int mid = low + (high - low) / 2;
        int totalH = calculateTotalHours(piles, mid);
        if(totalH <= h){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}

int main(){
    int n, h;
    cout << "Enter number of piles: ";
    cin >> n;
    vector<int> piles(n);
    cout << "Enter piles of bananas: ";
    for(int i = 0; i < n; i++){
        cin >> piles[i];
    }
    cout << "Enter total allowed hours: ";
    cin >> h;

    int result = minRateToEatBananas(piles, h);
    cout << "Minimum eating speed (bananas/hour) to finish in " << h << " hours is: " << result << endl;

    return 0;
}