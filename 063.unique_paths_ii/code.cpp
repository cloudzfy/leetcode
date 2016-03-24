class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0) return 0;
        int n = obstacleGrid[0].size();
        vector<vector<int>> map(m, vector<int>(n, 0));
        map[0][0] = 1 - obstacleGrid[0][0];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!obstacleGrid[i][j]) {
                    if (i - 1 >= 0) map[i][j] += map[i - 1][j];
                    if (j - 1 >= 0) map[i][j] += map[i][j - 1];
                }
            }
        }
        return map[m - 1][n - 1];
    }
};
