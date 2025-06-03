#include<iostream>
#include<vector>
using namespace std;

int maxElement(vector<vector<int>>& mat, int n, int col) {
    int maxValue = -1;
    int ind = -1;
    for(int i=0; i<n; i++) {
        if(mat[i][col] > maxValue) {
            maxValue = mat[i][col];
            ind = i;
        }
    }
    return ind;
}

vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    int low = 0, high = m - 1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        int maxRowIndex = maxElement(mat, n, mid);
        int left = (mid - 1 >= 0) ? mat[maxRowIndex][mid - 1] : -1;
        int right = (mid + 1 < m) ? mat[maxRowIndex][mid + 1] : -1;
        if(mat[maxRowIndex][mid] > left && mat[maxRowIndex][mid] > right) {
            return {maxRowIndex, mid};
        }
        else if(mat[maxRowIndex][mid] < left) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return {-1, -1};
}

int main() {
    vector<vector<int>> mat = {
        {10, 8, 10, 10},
        {14, 13, 12, 11},
        {15, 9, 11, 21},
        {16, 17, 19, 20}
    };

    vector<int> peak = findPeakGrid(mat);
    if (peak[0] != -1) {
        cout << "Peak element found at position: (" << peak[0] << ", " << peak[1] << ") = " << mat[peak[0]][peak[1]] << endl;
    } else {
        cout << "No peak element found\n";
    }
    return 0;
}