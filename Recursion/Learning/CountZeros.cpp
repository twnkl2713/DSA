#include<iostream>
using namespace std;

int countZeros(int n, int c) {
    if(n == 0) return c;
    int rem = n % 10;
    if(rem == 0) {
        return countZeros(n/10, c+1);
    }
    return countZeros(n/10, c);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int ans = countZeros(n, 0);
    cout << "Number of zeros: " << ans << endl;
    return 0;
}