#include <iostream>
using namespace std;

int numberOfSteps(int num) {
    if (num == 0) return 0;
    if (num % 2 == 0)
        return 1 + numberOfSteps(num / 2);
    else
        return 1 + numberOfSteps(num - 1);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Steps to reduce " << n << " to zero: " << numberOfSteps(n) << endl;
    return 0;
}
