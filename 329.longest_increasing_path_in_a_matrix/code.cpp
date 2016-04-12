class Solution {
private:
    int n, m;
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        n = matrix.size();
        m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dp[i][j] == 0) ans = max(ans, dfs(matrix, dp, i, j));
            }
        }
        return ans;
    }
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j) {
        if (dp[i][j] > 0) return dp[i][j];
        int ans = 0;
        if (i - 1 >= 0 && matrix[i - 1][j] < matrix[i][j]) ans = max(ans, dfs(matrix, dp, i - 1, j));
        if (i + 1 < n && matrix[i + 1][j] < matrix[i][j]) ans = max(ans, dfs(matrix, dp, i + 1, j));
        if (j - 1 >= 0 && matrix[i][j - 1] < matrix[i][j]) ans = max(ans, dfs(matrix, dp, i, j - 1));
        if (j + 1 < m && matrix[i][j + 1] < matrix[i][j]) ans = max(ans, dfs(matrix, dp, i, j + 1));
        dp[i][j] = ans + 1;
        return ans + 1;
    }
};
