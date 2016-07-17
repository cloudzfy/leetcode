class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int> > dp(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i++) {
            dp[i][i] = 0;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; i + j < n; j++) {
                for (int k = j + 1; k < i + j; k++) {
                    dp[j][j + i] = min(dp[j][j + i], k + 1 + max(dp[j][k - 1], dp[k + 1][i + j]));
                }
                dp[j][j + i] = min(dp[j][j + i], j + 1 + dp[j + 1][j + i]);
                dp[j][j + i] = min(dp[j][j + i], j + i + 1 + dp[j][j + i - 1]);
            }
        }
        return dp[0][n - 1];
    }
};
