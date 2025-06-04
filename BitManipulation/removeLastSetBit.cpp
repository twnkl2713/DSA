#include <iostream>
#include <bitset>
using namespace std;

int removeLastSetBit(int n) {
    return n & (n - 1);  // Removes the rightmost set bit
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "\nBefore removing last set bit:\n";
    cout << "Decimal: " << n << endl;
    cout << "Binary : " << bitset<8>(n) << endl;

    int result = removeLastSetBit(n);

    cout << "\nAfter removing last set bit:\n";
    cout << "Decimal: " << result << endl;
    cout << "Binary : " << bitset<8>(result) << endl;

    return 0;
}
