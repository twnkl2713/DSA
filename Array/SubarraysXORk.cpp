#include<bits/stdc++.h>
using namespace std;

int subarraysWithXorK(vector<int> a, int k) {
    int n = a.size();
    int xr = 0;
    unordered_map<int, int> mp; // (frontXOR, cnt)
    mp[xr]++; // {0, 1}
    int cnt = 0;
    for(int i=0; i<n; i++) {
        // prefix XOR till i
        xr = xr ^ a[i];
        int x = xr ^ k;
        cnt += mp[x];
        mp[xr]++;
    }
    return cnt;
}

int main() {
    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;
    int ans = subarraysWithXorK(a, k);
    cout << "The number of subarrays with XOR k is: "
         << ans << "\n";
    return 0;
}