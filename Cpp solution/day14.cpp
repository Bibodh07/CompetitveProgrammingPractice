#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int findMaxForm(vector<string>& strs, int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (const string& s : strs) {
        int zeros = 0, ones = 0;

        for (char c : s) {
            if (c == '0') zeros++;
            else ones++;
        }

        // Backward iteration: use each string at most once.
        for (int i = m; i >= zeros; i--) {
            for (int j = n; j >= ones; j--) {
                dp[i][j] = max(
                    dp[i][j],
                    1 + dp[i - zeros][j - ones]
                );
            }
        }
    }

    return dp[m][n];
}

int main() {
    vector<string> strs = {"10", "0001", "111001", "1", "0"};

    cout << findMaxForm(strs, 5, 3) << '\n';  // 4

}