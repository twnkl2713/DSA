#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int celebrity(vector<vector<int>>& mat) {
    stack<int> s;
    int n = mat.size();
    // Step 1: Push all people into the stack
    for (int i = 0; i < n; i++) {
        s.push(i);
    }
    // Step 2: Compare two at a time and eliminate non-celebs
    while (s.size() > 1) {
        int i = s.top(); s.pop();
        int j = s.top(); s.pop();
        if (mat[i][j] == 0) {
            // i doesn't know j, so j can't be a celeb
            s.push(i);
        } else {
            // i knows j, so i can't be a celeb
            s.push(j);
        }
    }
    // Step 3: Verify the final candidate
    if (s.empty()) return -1;
    int celeb = s.top();

    for (int i = 0; i < n; i++) {
        if (i != celeb) {
            // A celeb is known by everyone but knows no one
            if (mat[i][celeb] == 0 || mat[celeb][i] == 1) {
                return -1;
            }
        }
    }
    return celeb;
}

int main() {
    vector<vector<int>> mat = {
        {0, 1, 1},
        {0, 0, 1},
        {0, 0, 0}
    };
    int result = celebrity(mat);
    if (result == -1) {
        cout << "No celebrity found." << endl;
    } else {
        cout << "Celebrity is person at index: " << result << endl;
    }
    return 0;
}
