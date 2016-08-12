class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if (n == 0) return false;
        int m = matrix[0].size();
        if (m == 0) return false;
        int top = 0, buttom = n - 1;
        while (top < buttom) {
            int mid = (top + buttom) >> 1;
            if (matrix[mid][m - 1] == target) return true;
            if (matrix[mid][m - 1] > target) buttom = mid;
            else top = mid + 1;
        }
        int a = top;
        top = 0, buttom = n - 1;
        while (top < buttom) {
            int mid = (top + buttom + 1) >> 1;
            if (matrix[mid][0] == target) return true;
            if (matrix[mid][0] < target) top = mid;
            else buttom = mid - 1;
        }
        int b = top;
        for (int i = a; i <= b; i++) {
            int left = 0, right = m - 1;
            while (left <= right) {
                int mid = (left + right) >> 1;
                if (matrix[i][mid] == target) return true;
                if (matrix[i][mid] < target) left = mid + 1;
                else right = mid - 1;
            }
        }
        return false;
    }
};
