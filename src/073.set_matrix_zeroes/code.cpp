class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return;
        int n = matrix[0].size();
        int row = -1, col = -1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    row = i;
                    col = j;
                    break;
                }
            }
        }
        if (row == -1) return;
        for (int i = 0; i < m; i++) {
            if (matrix[i][col] == 0) {
                matrix[i][col] = 1;
            }
            else matrix[i][col] = 0;
        }
        for (int j = 0; j < n; j++) {
            if (matrix[row][j] == 0) {
                matrix[row][j] = 1;
            }
            else matrix[row][j] = 0;
        }
        for (int i = 0; i < m; i++) {
            if (i == row) continue;
            for (int j = 0; j < n; j++) {
                if (j == col) continue;
                if (matrix[i][j] == 0) {
                    matrix[i][col] = 1;
                    matrix[row][j] = 1;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            if (matrix[i][col] == 1) {
                for (int j = 0; j < n; j++) {
                    matrix[i][j] = 0;
                }
            }
            else matrix[i][col] = 0;
        }
        for (int j = 0; j < n; j++) {
            if (matrix[row][j] == 1) {
                for (int i = 0; i < m; i++) {
                    matrix[i][j] = 0;
                }
            }
            else matrix[row][j] = 0;
        }
    }
};
