class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if (n == 0) return false;
        int m = matrix[0].size();
        if (m == 0) return false;
        for (int i = 0, j = m - 1; i < n; i++) {
            while (j > 0 && matrix[i][j] > target) j--;
            if (matrix[i][j] == target) return true;
        }
        return false;
    }
};
