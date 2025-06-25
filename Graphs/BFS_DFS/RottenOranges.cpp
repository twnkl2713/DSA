#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<pair<int, int>, int>> q;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int cntfresh = 0;

    // Initialize queue and count fresh oranges
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 2) {
                q.push({{i, j}, 0});
                vis[i][j] = 2;
            } else {
                vis[i][j] = 0;
            }
            if(grid[i][j] == 1) {
                cntfresh++;
            }
        }
    }

    int time = 0;
    int cnt = 0;
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    // BFS traversal
    while(!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        q.pop();
        time = max(time, t);

        for(int i = 0; i < 4; i++) {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1) {

                q.push({{nrow, ncol}, t + 1});
                vis[nrow][ncol] = 2;
                cnt++;
            }
        }
    }
    if(cnt != cntfresh) return -1;
    return time;
}

int main() {
    vector<vector<int>> grid = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };
    int result = orangesRotting(grid);
    cout << "Minimum time to rot all oranges: " << result << endl;
    return 0;
}
