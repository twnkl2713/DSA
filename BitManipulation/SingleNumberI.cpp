#include<iostream>
#include<vector>
using namespace std;

int singleNumber(vector<int> &nums) {
    int xor1 = 0;
    for(int i=0; i<nums.size(); i++){
        xor1 = xor1 ^ nums[i];
    }
    return xor1;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements (every element appears twice except one): ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = singleNumber(nums);
    cout << "The single (non-repeating) number is: " << result << endl;

    return 0;
}