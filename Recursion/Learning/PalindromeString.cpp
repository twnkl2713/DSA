#include<iostream>
using namespace std;

bool isPalindromeHelper(const string &s, int left, int right) {
    if (left >= right) return true;
    if (s[left] != s[right]) return false;
    return isPalindromeHelper(s, left + 1, right - 1);
}

bool isPalindrome(string s) {
    return isPalindromeHelper(s, 0, s.size() - 1);
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;
    if (isPalindrome(str))
        cout << str << " is a palindrome" << endl;
    else
        cout << str << " is not a palindrome" << endl;
    return 0;
}
