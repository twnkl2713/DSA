#include <iostream>
#include <vector>

using namespace std;

int lowerBound(vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1;
    int ans = arr.size();

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
    int maxCount = 0;
    int rowIndex = -1;
    int cols = mat[0].size();

    for (int i = 0; i < mat.size(); i++) {
        int firstOneIndex = lowerBound(mat[i], 1);
        int onesCount = cols - firstOneIndex;

        if (onesCount > maxCount) {
            maxCount = onesCount;
            rowIndex = i;
        }
    }

    return {rowIndex, maxCount};
}

int main() {
    // Sample input (rows must be sorted)
    vector<vector<int>> mat = {
        {0, 0, 1, 1},
        {0, 1, 1, 1},
        {0, 0, 0, 1}
    };

    vector<int> result = rowAndMaximumOnes(mat);
    cout << "Row with max 1s: " << result[0] << ", Count: " << result[1] << endl;

    return 0;
}
