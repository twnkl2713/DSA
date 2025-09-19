#include<bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    int row = matrix.size();
    int col = matrix[0].size();
    int count = 0;
    int total = row * col;
    int startingRow  = 0;
    int startingCol = 0;
    int endingRow = row-1;
    int endingCol = col-1;
    while(count < total){
        // Print Starting Row
        for(int i=startingCol; count<total && i<=endingCol; i++){
            ans.push_back(matrix[startingRow][i]);
            count++;
        }
        startingRow++;
        // Print Ending Column
        for(int i=startingRow; count<total && i<=endingRow; i++){
            ans.push_back(matrix[i][endingCol]);
            count++;
        }
        endingCol--;
        // Print Ending Row
        for(int i=endingCol; count<total && i>=startingCol;i--){
            ans.push_back(matrix[endingRow][i]);
            count++;
        }
        endingRow--;
        // Print Starting Column
        for(int i=endingRow; count<total && i>=startingRow; i--){
            ans.push_back(matrix[i][startingCol]);
            count++;
        }
        startingCol++;
    }
    return ans;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    vector<int> result = spiralOrder(matrix);
    cout << "Spiral order: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}