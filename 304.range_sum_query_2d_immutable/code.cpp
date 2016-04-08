class NumMatrix {
private:
    vector<vector<int>> ans;
    int n;
    int m;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        n = matrix.size();
        if (n == 0) return;
        m = matrix[0].size();
        for (int i = 0; i < n; i++) {
            vector<int> myans(m, 0);
            myans[0] = matrix[i][0];
            for (int j = 1; j < m; j++) {
                myans[j] = myans[j - 1] + matrix[i][j];
            }
            ans.push_back(myans);
        }
        for (int j = 0; j < m; j++) {
            for (int i = 1; i < n; i++) {
                ans[i][j] += ans[i - 1][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (n == 0) return 0;
        int sum1 = 0, sum2 = 0;
        if (row1 != 0) {
            if (col1 != 0) {
                sum1 = ans[row1 - 1][col2] - ans[row1 - 1][col1 - 1];
            } else {
                sum1 = ans[row1 - 1][col2];
            }
        }
        if (col1 != 0) {
            sum2 = ans[row2][col2] - ans[row2][col1 - 1];
        } else {
            sum2 = ans[row2][col2];
        }
        return sum2 - sum1;
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
