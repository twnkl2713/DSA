#include<iostream>
using namespace std;

int xorr(int n) {
    int mod = n % 4;
    if(mod == 0) return n;
    else if(mod == 1) return 1;
    else if(mod == 2) return n + 1;
    else return 0;
}

int findXOR(int l, int r) {
    return xorr(l-1) ^ xorr(r);
}

int main() {
    int l, r;
    cout << "Enter the range (l r): ";
    cin >> l >> r;

    int result = findXOR(l, r);
    cout << "XOR of all numbers from " << l << " to " << r << " is: " << result << endl;

    return 0;
}