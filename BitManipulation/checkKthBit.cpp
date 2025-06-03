#include <iostream>
using namespace std;

bool checkKthBit(int n, int k) {
    return (n & (1 << k)) != 0;
}

int main() {
    int n, k;
    cout << "Enter a number (n): ";
    cin >> n;
    cout << "Enter bit position to check (k): ";
    cin >> k;

    if (checkKthBit(n, k)) {
        cout << "The " << k << "-th bit is set (1)" << endl;
    } else {
        cout << "The " << k << "-th bit is not set (0)" << endl;
    }

    return 0;
}
