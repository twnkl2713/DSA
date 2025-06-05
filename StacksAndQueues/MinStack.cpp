#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

class MinStack {
private:
    stack<int> s;
    long long minVal;

public:
    MinStack() {
        // constructor
    }

    void push(int val) {
        if(s.empty()) {
            s.push(val);
            minVal = val;
        }
        else{
            if(val < minVal) {
                s.push(2LL * val - minVal);
                minVal = val;
            }
            else{
                s.push(val);
            }
        }    
    }
    void pop() {
        if(s.empty()) return;
        if(s.top() < minVal) {
            minVal = 2LL * minVal - s.top();
        }
        s.pop();
    }
    int top() {
        if(s.empty()) return -1;
        if(s.top() < minVal) {
            return minVal;
        }
        return s.top();
    }
    int getMin() {
        if(s.empty()) return -1;
        return minVal;
    }
};

int main() {
    MinStack ms;

    ms.push(5);
    ms.push(3);
    ms.push(7);
    ms.push(2);

    cout << "Top: " << ms.top() << endl;        // Should print 2
    cout << "Min: " << ms.getMin() << endl;     // Should print 2

    ms.pop(); // removes 2
    cout << "After pop:\n";
    cout << "Top: " << ms.top() << endl;        // Should print 7
    cout << "Min: " << ms.getMin() << endl;     // Should print 3

    ms.pop(); // removes 7
    cout << "After another pop:\n";
    cout << "Top: " << ms.top() << endl;        // Should print 3
    cout << "Min: " << ms.getMin() << endl;     // Should print 3

    ms.pop(); // removes 3
    cout << "After another pop:\n";
    cout << "Top: " << ms.top() << endl;        // Should print 5
    cout << "Min: " << ms.getMin() << endl;     // Should print 5

    return 0;
}