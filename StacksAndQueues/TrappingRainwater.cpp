#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    int l = 0, r = n - 1;
    int lmax = 0, rmax = 0;
    int ans = 0;

    while (l < r) {
        lmax = max(lmax, height[l]);  // Track max height from the left
        rmax = max(rmax, height[r]);  // Track max height from the right

        if (lmax < rmax) {
            // Water trapped at index l depends on lmax
            ans += lmax - height[l];
            l++;
        } else {
            // Water trapped at index r depends on rmax
            ans += rmax - height[r];
            r--;
        }
    }
    return ans;
}

int main() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int trappedWater = trap(height);
    cout << "Total Trapped Rain Water: " << trappedWater << endl;
    return 0;
}
