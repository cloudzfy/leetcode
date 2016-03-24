class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        vector<vector<int>> map(m, vector<int>(n, INT_MAX));
        map[0][0] = grid[0][0];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i - 1 >= 0) map[i][j] = min(map[i][j], map[i - 1][j] + grid[i][j]);
                if (j - 1 >= 0) map[i][j] = min(map[i][j], map[i][j - 1] + grid[i][j]);
            }
        }
        return map[m - 1][n - 1];
    }
};
