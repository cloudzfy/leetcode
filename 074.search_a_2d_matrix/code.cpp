class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        int low = 0, high = m - 1;
        if (low != high) {
            while (low <= high) {
                int mid = (low + high) >> 1;
                if (matrix[mid][0] == target) return true;
                else if (matrix[mid][0] < target) low = mid + 1;
                else high = mid - 1;
            }
        }
        int pos = high;
        if (pos == -1) return false;
        low = 0; high = n - 1;
        while (low <= high) {
            int mid = (low + high) >> 1;
            if (matrix[pos][mid] == target) return true;
            else if (matrix[pos][mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
};
