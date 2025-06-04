#include <iostream>
using namespace std;

int setKthBit(int n, int k) {
    return n | (1 << k);
}

int main() {
    int n, k;
    cout << "Enter a number (n): ";
    cin >> n;
    cout << "Enter bit position to set (k): ";
    cin >> k;

    int result = setKthBit(n, k);
    cout << "Number after setting the " << k << "-th bit: " << result << endl;

    return 0;
}
