#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>>& image, int newColor, int iniColor, int delRow[], int delCol[]) {
    ans[row][col] = newColor;
    int n = image.size();
    int m = image[0].size();

    for(int i = 0; i < 4; i++) {
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];

        // Check bounds and if it matches initial color and not yet colored
        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
           && image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor) {
            dfs(nrow, ncol, ans, image, newColor, iniColor, delRow, delCol);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int iniColor = image[sr][sc];
    vector<vector<int>> ans = image;

    // Directions: up, right, down, left
    int delRow[] = {-1, 0, +1, 0};
    int delCol[] = {0, +1, 0, -1};

    dfs(sr, sc, ans, image, color, iniColor, delRow, delCol);

    return ans;
}

int main() {
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    int sr = 1, sc = 1; // starting row and column
    int newColor = 2;
    vector<vector<int>> result = floodFill(image, sr, sc, newColor);
    cout << "Flood Filled Image:\n";
    for (auto& row : result) {
        for (int pixel : row)
            cout << pixel << " ";
        cout << "\n";
    }
    return 0;
}
