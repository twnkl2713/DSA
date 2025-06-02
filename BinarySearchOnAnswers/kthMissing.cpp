#include<iostream>
#include<vector>
using namespace std;

int findKthPositive(vector<int>& arr, int k) {
    int low = 0, high = arr.size() - 1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        int missing = arr[mid] - (mid + 1); // (mid + 1) is how many numbers should have been there if none were missing (1-based indexing)
        if(missing < k){ // how many numbers are missing before or at arr[mid]
            low = mid + 1; // eliminate left
        }
        else{
            high = mid - 1;
        }
    }
    return k + high + 1;
}

int main() {
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;

    int kthMissing = findKthPositive(arr, k);
    cout << "The " << k << "th missing positive integer is: " << kthMissing << endl;

    return 0;
}