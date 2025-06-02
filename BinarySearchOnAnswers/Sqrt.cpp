#include<iostream>
using namespace std;

int floorSqrt(int num){
    int low = 1, high = num;
    while(low <= high){
        long long mid = low + (high - low) / 2;
        long long val = mid * mid;
        if(val <= num){
            low = mid + 1; // eliminate left half
        }
        else{
            high = mid - 1; // eliminate right half
        }
    }
    return high;
}

int main(){
    int num;
    cout << "Enter a number: ";
    cin >> num;

    int result = floorSqrt(num);
    cout << "The floor square root of " << num << " is: " << result << endl;

    return 0;
}