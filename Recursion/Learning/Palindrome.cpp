#include<iostream>
using namespace std;

long long reverseNum(long long n, long long rev = 0) {
    if (n == 0) return rev;
    int rem = n % 10;
    return reverseNum(n / 10, rev * 10 + rem);
}

bool isPalindrome(int x) {
    if (x < 0) return false; 
    return x == reverseNum(x);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    if (isPalindrome(n))
        cout << n << " is a palindrome" << endl;
    else
        cout << n << " is not a palindrome" << endl;
    return 0;
}
