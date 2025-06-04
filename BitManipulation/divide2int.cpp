#include<iostream>
#include<climits>
using namespace std;

int divide(int dividend, int divisor) {
    if(dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }
    long long n = abs((long long)dividend);
    long long d = abs((long long)divisor);
    long long ans = 0;
    while(n >= d) {
        int count = 0;
        // find the highest power of 2 such that (d << (count + 1)) <= n
        while(n >= (d << (count + 1))) {
            count++;
        }
        ans += (1LL << count); // add 2^count to the ans
        n -= (d << count); // subtract the multiplied divisor from the dividend
    }
    // adjusting sign of results based on original signs
    bool sameSign = (dividend >= 0) == (divisor >= 0);
    ans = sameSign ? ans : -ans;
    if (ans > INT_MAX) return INT_MAX;
    if (ans < INT_MIN) return INT_MIN;
    return (int)ans;
}

int main() {
    int dividend, divisor;
    cout << "Enter dividend: ";
    cin >> dividend;
    cout << "Enter divisor: ";
    cin >> divisor;
    int result = divide(dividend, divisor);
    cout << "Quotient: " << result << endl;
    return 0;
}