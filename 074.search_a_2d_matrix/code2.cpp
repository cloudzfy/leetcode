class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        int low = 0, high = m * n - 1;
        while (low <= high) {
            int mid = (low + high) >> 1;
            int tmp = matrix[mid / n][mid % n];
            if (tmp == target) return true;
            else if (tmp < target) low = mid + 1;
            else if (tmp > target) high = mid - 1;
        }
        return false;
    }
};
