#include<bits/stdc++.h>
using namespace std;

vector<int> generateRow(int row) {
    int ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1);
    for(int col=1; col<row; col++) {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    for(int i=1; i<=numRows; i++) {
        ans.push_back(generateRow(i));
    }
    return ans;
}

int main() {
    int numRows;
    cout << "Enter number of rows for Pascal's Triangle: ";
    cin >> numRows;
    vector<vector<int>> pascal = generate(numRows);
    cout << "Pascal's Triangle:" << endl;
    for (auto &row : pascal) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}