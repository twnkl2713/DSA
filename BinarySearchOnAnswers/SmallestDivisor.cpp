#include<iostream>
#include<vector>
#include<climits>
#include<cmath>
using namespace std;

int sumByD(vector<int> &arr, int div){
    int sum = 0;
    int n = arr.size();
    for(int i=0; i<arr.size(); i++){
        sum += ceil((double)arr[i] / (double)div);
    }
    return sum;
}

int smallestDivisor(vector<int> &arr, int limit){
    int low = 1, high = *max(arr.begin(), arr.end());
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(sumByD(arr, mid) <= limit){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}

int main(){
    int n, limit;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements of the array: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << "Enter limit for sum of divisions: ";
    cin >> limit;

    int divisor = smallestDivisor(arr, limit);
    cout << "Smallest divisor to keep sum <= " << limit << " is: " << divisor << endl;

    return 0;
}