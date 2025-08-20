#include<iostream>
using namespace std;

int reverse(int n) {
    if(n == 0) return 0;
    int rem = n % 10;
    int sum = sum * 10 + rem;
    return reverse(n / 10);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int reversed = reverse(n);
    cout << "Reversed number: " << reversed << endl;
    return 0;
}