// transpose the matrix
// then reverse each row

#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            swap(matrix[i][j], matrix[i][j]);
        }
    }
    // reverse
    for(int i=0; i<n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    cout << "Original matrix:\n";
    for (auto &row : matrix) {
        for (auto &val : row) cout << val << " ";
        cout << "\n";
    }
    rotate(matrix);
    cout << "\nRotated matrix:\n";
    for (auto &row : matrix) {
        for (auto &val : row) cout << val << " ";
        cout << "\n";
    }
    return 0;
}
