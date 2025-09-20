#include<bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> a) {
    long long n = a.size();
    long long Sn = n * (n + 1) / 2;
    long long S2n = n * (n + 1) * (2 * n + 1) / 6;
    long long S = 0, S2 = 0;
    for(int i=0; i<n; i++) {
        S += a[i];
        S2 += (long long)a[i] * (long long)a[i];
    }
    long long val1 = S - Sn; // X - Y
    long long val2 = S2 - S2n; // X^2 - Y^2
    val2 = val2 / val1; // X + Y
    long long x = (val1 + val2) / 2; // Repeating number
    long long y = x - val1; // Missing number
    return {(int)x, (int)y};
}

int main() {
    vector<int> arr = {4, 3, 6, 2, 1, 1}; // Example: n=6
    vector<int> result = findMissingRepeatingNumbers(arr);
    cout << "Repeating number: " << result[0] << endl;
    cout << "Missing number: " << result[1] << endl;
    return 0;
}