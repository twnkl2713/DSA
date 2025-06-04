#include <iostream>
using namespace std;

int divideByTwo(int n) {
    return n >> 1;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int result = divideByTwo(n);
    cout << n << " divided by 2 is: " << result << endl;

    return 0;
}
