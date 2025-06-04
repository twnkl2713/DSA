#include<iostream>
using namespace std;

pair<int, int> get(int a, int b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    return {a, b};
}

int main() {
    int a = 5, b = 10;
    cout << "Before swapping: a = " << a << ", b = " << b << endl;

    pair<int, int> result = get(a, b);

    cout << "After swapping: a = " << result.first << ", b = " << result.second << endl;

    return 0;
}