class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if (n == 0) return false;
        int m = matrix[0].size();
        if (m == 0) return false;
        return search(matrix, target, 0, n - 1, 0, m - 1);
    }
    bool search(vector<vector<int>>& matrix, int target, int top, int buttom, int left, int right) {
        if (top > buttom || left > right) return false;
        if (matrix[top][left] > target || matrix[buttom][right] < target) return false;
        int rowMid = (top + buttom) >> 1;
        int colMid = (left + right) >> 1;
        if (matrix[rowMid][colMid] == target) return true;
        else if (matrix[rowMid][colMid] < target) {
            return search(matrix, target, top, rowMid, colMid + 1, right)
                || search(matrix, target, rowMid + 1, buttom, left, colMid)
                || search(matrix, target, rowMid + 1, buttom, colMid + 1, right);
        } else {
            return search(matrix, target, top, rowMid - 1, left, colMid - 1)
                || search(matrix, target, top, rowMid - 1, colMid, right)
                || search(matrix, target, rowMid, buttom, left, colMid - 1);
        }
    }
};
