#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> nextSmallerElement(vector<int> &heights, int n) {
    stack<int> s;
    vector<int> result(n, n);
    for(int i=n-1; i>=0; i--) {
        while(!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        if(!s.empty()) {
            result[i] = s.top();
        }
        s.push(i);
    }
    return result;
}
vector<int> prevSmallerElement(vector<int> &heights, int n) {
    stack<int> s;
    vector<int> result(n, -1);
    for(int i=0; i<n; i++) {
        while(!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        if(!s.empty()) {
            result[i] = s.top();
        }
        s.push(i);
    }
    return result;
}
int largestRectangleArea(vector<int> &heights) {
    int n = heights.size();
    vector<int> next = nextSmallerElement(heights, n);
    vector<int> prev = prevSmallerElement(heights, n);
    int area = INT_MIN;
    for(int i=0; i<n; i++) {
        int l = heights[i];
        if(next[i] == -1) {
            next[i] = n;
        }
        int b = next[i] - prev[i] -1;
        int newArea = l * b;
        area = max(area, newArea);
    }
    return area;
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    int maxArea = largestRectangleArea(heights);
    cout << "Largest Rectangle Area in Histogram: " << maxArea << endl;
    return 0;
}