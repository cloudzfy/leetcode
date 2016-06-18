class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        if (m == 0) return 0;
        vector<vector<int> > dp1(n, vector<int>(m, 0));
        vector<vector<int> > dp2(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'X') count++;
                if (grid[i][j] == 'Y' && j > 0) {
                    dp1[i][j - 1] = count;
                    count = 0;
                }
            }
            for (int j = m - 1; j >= 0; j--) {
                if (grid[i][j] == 'Y') {
                    count = 0;
                    continue;
                }
                if (dp1[i][j] == 0) dp1[i][j] = count;
                else count = dp1[i][j];
            }
        }
        for (int j = 0; j < m; j++) {
            int count = 0;
            for (int i = 0; i < n; i++) {
                if (grid[i][j] == 'X') count++;
                if (grid[i][j] == 'Y' && i > 0) {
                    dp2[i - 1][j] = count;
                    count = 0;
                }
            }
            for (int i = n - 1; i >= 0; i--) {
                if (grid[i][j] == 'Y') {
                    count = 0;
                    continue;
                }
                if (dp2[i][j] == 0) dp2[i][j] = count;
                else count = dp2[i][j];
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '0') ans = max(ans, dp1[i][j] + dp2[i][j]);
            }
        }
        return ans;
    }
};
