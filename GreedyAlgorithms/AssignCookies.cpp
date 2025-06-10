#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    
    int r = 0, l = 0;
    while (r < g.size() && l < s.size()) {
        if (g[r] <= s[l]) {
            r++;  // Child is content
        }
        l++;  // Move to next cookie
    }
    return r;
}

int main() {
    vector<int> g = {1, 2, 3};      
    vector<int> s = {1, 1};    
    int result = findContentChildren(g, s);
    cout << "Maximum number of content children: " << result << endl;
    return 0;
}
