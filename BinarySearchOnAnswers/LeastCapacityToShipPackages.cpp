#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

int findDays(vector<int> &weights, int cap){
    int day = 1, load = 0;
    for(int i=0; i<weights.size(); i++){
        if(weights[i] + load > cap){
            day = day + 1; // will be shifted to the next day
            load = weights[i];
        }
        else{
            load += weights[i];
        }
    }
    return day;
}

int leastWeightCapacity(vector<int> &weights, int d){
    int low = *max(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);
    int result = high;
    while(low <= high){
        int mid = low + (high - low) / 2;
        int noOfDays = findDays(weights, mid);
        if(noOfDays <= d){
            result = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}
int main(){
    int n, d;
    cout << "Enter number of weights: ";
    cin >> n;
    vector<int> weights(n);
    cout << "Enter the weights: ";
    for(int i = 0; i < n; i++){
        cin >> weights[i];
    }
    cout << "Enter the number of days: ";
    cin >> d;

    int capacity = leastWeightCapacity(weights, d);
    cout << "Least weight capacity to ship in " << d << " days is: " << capacity << endl;

    return 0;
}
