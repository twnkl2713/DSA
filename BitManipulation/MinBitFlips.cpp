#include <iostream>
using namespace std;

int minBitFlips(int a, int b) {
    int ans = a ^ b;
    int count = 0;
    for(int i=0; i<32; i++){
        if(ans & (1 << i)) {
            count++;
        }
    }
    return count;
}

int main() {
    int a, b;
    cout << "Enter number a: ";
    cin >> a;
    cout << "Enter number b: ";
    cin >> b;

    int result = minBitFlips(a, b);
    cout << "Minimum bit flips to convert " << a << " to " << b << " is: " << result << endl;

    return 0;
}