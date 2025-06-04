#include<iostream>
#include<vector>
using namespace std;

vector<int> singleNumber(vector<int> &nums) {
    long long numXORR = 0;
    for(auto it: nums) {
        numXORR = numXORR ^ it;
    }
    long long rightmostBit = numXORR & -numXORR;
    int b1 = 0, b2 = 0;
    for(auto it: nums) {
        // if right bit is set
        if(it & rightmostBit) {
            b1 = b1 ^ it;
        }
        else {
            b2 = b2 ^ it;
        }
    }
    return {b1, b2};
}

int main() {
    vector<int> nums;
    int n, x;
    
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> x;
        nums.push_back(x);
    }

    vector<int> result = singleNumber(nums);
    cout << "The two unique numbers are: " << result[0] << " and " << result[1] << endl;

    return 0;
}