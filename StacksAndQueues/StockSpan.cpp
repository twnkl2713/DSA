// max no. of consecutive days from today, i.e,
// price <= today's price(including current day price)

#include<iostream>
#include<stack>
using namespace std;

class StockSpanner {
    stack<pair<int,int>> st;
    long long ind;
public: 
    StockSpanner() {
        ind = 0LL;
    }
    int next(int price) {
        ind++;
        while(!st.empty() && st.top().first <= price){
            st.pop(); // stack contains only greater prev values(idx of the stock)
        }
        if(st.empty()){
            st.push({price, ind}); // initially
            return ind;
        }
        else {
            int span = ind - st.top().second; // prev high
            st.push({price, ind});
            return span;
        }
    }
};

int main() {
    StockSpanner ss;
    int prices[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(prices) / sizeof(prices[0]);
    cout << "Stock spans:\n";
    for (int i = 0; i < n; i++) {
        cout << ss.next(prices[i]) << " ";
    }
    cout << endl;
    return 0;
}