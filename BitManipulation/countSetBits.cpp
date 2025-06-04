#include<iostream>
#include<bitset>
using namespace std;

int countSetBits(int n) {
    int count = 0;
    while(n) {
        n = n & (n - 1); // clear the lowest set bit
        count++;
    }
    return count;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int result = countSetBits(n);
    cout << "Number of set bits in " << n << " is: " << result << endl;

    return 0;
}