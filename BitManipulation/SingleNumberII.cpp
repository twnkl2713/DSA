#include<iostream>
#include<vector>
using namespace std;

int singleNumber(vector<int> &nums){
    int ones = 0, twos = 0;
    for(int i=0; i<nums.size(); i++){
        ones = (ones ^ nums[i]) & ~twos; // nums[i] will go to ones, if not in twos
        twos = (twos ^ nums[i]) & ~ones; // nums[i] will go to twos, if not in ones
    }
    return ones;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements (every number appears three times except one): ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = singleNumber(nums);
    cout << "The unique number is: " << result << endl;

    return 0;
}