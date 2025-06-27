#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>> dist(n, vector<int>(m, 0));
    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<int, int>> q;

    // Start BFS from all 0s
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] == 0) {
                q.push({i, j});
                vis[i][j] = 1;
            }
        }
    }

    int dRow[] = {-1, 0, 1, 0};
    int dCol[] = {0, 1, 0, -1};

    while(!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nrow = row + dRow[i];
            int ncol = col + dCol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol]) {
                dist[nrow][ncol] = dist[row][col] + 1;
                vis[nrow][ncol] = 1;
                q.push({nrow, ncol});
            }
        }
    }
    return dist;
}

int main() {
    vector<vector<int>> mat = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 1, 1}
    };
    vector<vector<int>> result = updateMatrix(mat);
    cout << "Updated Distance Matrix:\n";
    for(auto& row : result) {
        for(int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
