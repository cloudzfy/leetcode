class NumMatrix {
private:
    int n, m;
    vector<vector<int>> matrix;
    vector<vector<int>> bitree;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        n = matrix.size();
        if (n == 0) return;
        m = matrix[0].size();
        if (m == 0) return;
        this->matrix.resize(n + 1, vector<int>(m + 1, 0));
        this->bitree.resize(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                this->matrix[i + 1][j + 1] = matrix[i][j];
                addValue(i + 1, j + 1, matrix[i][j]);
            }
        }
    }

    void update(int row, int col, int val) {
        int num = val - matrix[row + 1][col + 1];
        matrix[row + 1][col + 1] = val;
        addValue(row + 1, col + 1, num);
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return getValue(row2 + 1, col2 + 1) + getValue(row1, col1) - getValue(row1, col2 + 1) - getValue(row2 + 1, col1);
    }
    
    int lowbit(int i) {
        return i & (-i);
    }
    
    void addValue(int x, int y, int value) {
        for (int i = x; i <= n; i += lowbit(i)) {
            for (int j = y; j <= m; j += lowbit(j)) {
                bitree[i][j] += value;
            }
        }
    }
    
    int getValue(int x, int y) {
        int val = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            for (int j = y; j > 0; j -= lowbit(j)) {
                val += bitree[i][j];
            }
        }
        return val;
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);
