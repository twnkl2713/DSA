#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1; // last element of nums1's original part
    int j = n - 1; // last element of nums2
    int k = m + n - 1; // last position of nums1

    while(i >= 0 && j >= 0) {
        if(nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        }
        else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }
    // copy rem elements of num2 to num1
    while(j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}

int main() {
    vector<int> nums1 = {1, 3, 5, 0, 0, 0}; // size = m+n
    vector<int> nums2 = {2, 4, 6};
    int m = 3, n = 3;
    merge(nums1, m, nums2, n);
    cout << "Merged array: ";
    for(int x : nums1) cout << x << " ";
    cout << endl;
    return 0;
}