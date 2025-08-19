#include<iostream>
using namespace std;

int productOfDigits(int n) {
    if(n%10 == n) return n;
    return (n % 10) * productOfDigits(n / 10);
}

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;
    int ans = productOfDigits(n);
    cout << "Product of Digits = " << ans << endl;
}