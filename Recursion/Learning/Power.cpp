#include<iostream>
#include<limits>
using namespace std;

double myPow(double x, int n) {
    if(n == 0) return 1;
    if(n == 1) return x;
    if(n < 0) {
        if(n == INT_MIN) {
            long long nn = -(long long)n;
            return 1.0 / (x * myPow(x, nn - 1)); 
        }
        return 1.0 / myPow(x, -n);
    }
    double half = myPow(x, n/2);
    if(n % 2 == 0) {
        return half * half;
    }
    else {
        return x * half * half;
    }
}

int main() {
    double x;
    int n;
    cout << "Enter base (x): ";
    cin >> x;
    cout << "Enter exponent (n): ";
    cin >> n;
    double result = myPow(x, n);
    cout << x << "^" << n << " = " << result << endl;
    return 0;
}