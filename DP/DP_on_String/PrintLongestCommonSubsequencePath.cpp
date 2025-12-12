#include <bits/stdc++.h>
using namespace std;

string printLCS(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    // DP table building
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i-1] == s2[j-1]) 
                dp[i][j] = 1 + dp[i-1][j-1];
            else 
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    // Traceback to get LCS path
    int i = n, j = m;
    string lcs = "";

    while (i > 0 && j > 0) {
        if (s1[i-1] == s2[j-1]) {
            lcs.push_back(s1[i-1]);  // character is part of LCS
            i--, j--;
        }
        else if (dp[i-1][j] > dp[i][j-1]) {
            i--; // move up
        }
        else {
            j--; // move left
        }
    }

    reverse(lcs.begin(), lcs.end());
    return lcs;
}

int main() {
    string s1 = "abcde";
    string s2 = "bdgek";
    cout << "LCS: " << printLCS(s1, s2) << endl;
}
