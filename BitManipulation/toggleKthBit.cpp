#include <iostream>
#include <bitset>
using namespace std;

int toggleKthBit(int n, int k) {
    return n ^ (1 << k);  // Toggle the k-th bit
}

int main() {
    int n, k;
    cout << "Enter a number (n): ";
    cin >> n;
    cout << "Enter bit position to toggle (k): ";
    cin >> k;

    cout << "\nBefore toggling:\n";
    cout << "Decimal: " << n << endl;
    cout << "Binary : " << bitset<8>(n) << endl;

    int result = toggleKthBit(n, k);

    cout << "\nAfter toggling " << k << "-th bit:\n";
    cout << "Decimal: " << result << endl;
    cout << "Binary : " << bitset<8>(result) << endl;

    return 0;
}
