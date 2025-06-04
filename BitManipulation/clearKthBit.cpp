#include <iostream>
#include <bitset>
using namespace std;

int clearKthBit(int n, int k) {
    return n & ~(1 << k);  // Clear the k-th bit
}

int main() {
    int n, k;
    cout << "Enter a number (n): ";
    cin >> n;
    cout << "Enter bit position to clear (k): ";
    cin >> k;

    cout << "\nBefore clearing:\n";
    cout << "Decimal: " << n << endl;
    cout << "Binary : " << bitset<8>(n) << endl;

    int result = clearKthBit(n, k);

    cout << "\nAfter clearing " << k << "-th bit:\n";
    cout << "Decimal: " << result << endl;
    cout << "Binary : " << bitset<8>(result) << endl;

    return 0;
}
