#include <iostream>
#include <string>
using namespace std;

bool checkValidString(string s) {
    int n = s.length();
    int min = 0, max = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            min++;
            max++;
        }
        else if (s[i] == ')') {
            min--;
            max--;
        }
        else { // s[i] == '*'
            min--;
            max++;
        }
        if (min < 0) min = 0;
        if (max < 0) return false;
    }
    return min == 0;
}

int main() {
    string s;
    cout << "Enter a string with '(', ')', and '*': ";
    cin >> s;
    if (checkValidString(s)) {
        cout << "Valid Parenthesis String" << endl;
    } else {
        cout << "Invalid Parenthesis String" << endl;
    }
    return 0;
}
