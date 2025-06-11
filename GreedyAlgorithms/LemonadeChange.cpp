#include <iostream>
#include <vector>
using namespace std;

bool lemonadeChange(vector<int>& bills) {
    int five = 0, ten = 0;
    for (int bill : bills) {
        if (bill == 5) {
            five++;
        } else if (bill == 10) {
            if (five > 0) {
                five--;
                ten++;
            } else {
                return false;
            }
        } else { // bill == 20
            if (ten > 0 && five > 0) {
                ten--;
                five--;
            } else if (five >= 3) {
                five -= 3;
            } else {
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<int> bills = {5, 5, 5, 10, 20};
    if (lemonadeChange(bills)) {
        cout << "True\n";
    } else {
        cout << "False\n";
    }
    return 0;
}
