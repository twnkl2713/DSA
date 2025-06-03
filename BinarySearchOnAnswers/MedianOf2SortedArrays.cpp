#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<numeric>
using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();
    int n = n1 + n2;
    int ind2 = n / 2;
    int ind1 = ind2 - 1;
    int cnt = 0, i = 0, j = 0;
    int ind1el = 0, ind2el = 0;
    while(i < n1 && j < n2) {
        int val;
        if(nums1[i] < nums2[j]) {
            val = nums1[i++];
        }
        else {
            val = nums2[j++];
        }
        if(cnt == ind1) ind1el = val;
        if(cnt == ind2) ind2el = val;
        cnt++;
    }
    while (i < n1) {
        int val = nums1[i++];
        if (cnt == ind1) ind1el = val;
        if (cnt == ind2) ind2el = val;
        cnt++;
    }
    while (j < n2) {
        int val = nums2[j++];
        if (cnt == ind1) ind1el = val;
        if (cnt == ind2) ind2el = val;
        cnt++;
    }
    if (n % 2 == 1) {
        return ind2el;
    }
    return (ind1el + ind2el) / 2.0;
}

int main() {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    double median = findMedianSortedArrays(nums1, nums2);
    cout << "Median is: " << median << endl;

    return 0;
}
