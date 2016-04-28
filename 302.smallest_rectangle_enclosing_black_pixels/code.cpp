class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int n = image.size();
        if (n == 0) return 0;
        int m = image[0].size();
        if (m == 0) return 0;
        int left = horizontalSearch(image, 0, y, 0, n - 1, 0);
        int right = horizontalSearch(image, y, m - 1, 0, n - 1, 1);
        int top = verticalSearch(image, 0, m - 1, 0, x, 0);
        int bottom = verticalSearch(image, 0, m - 1, x, n - 1, 1);
        return (right - left + 1) * (bottom - top + 1);
    }
    
    int horizontalSearch(vector<vector<char>>& image, int left, int right, int top, int bottom, int offset) {
        while (left < right) {
            int mid = ((left + right) >> 1) + offset;
            bool getOne = false;
            for (int i = top; i <= bottom; i++) {
                if (image[i][mid] == '1') {
                    getOne = true;
                    break;
                }
            }
            if (getOne) {
                if (!offset) right = mid;
                else left = mid;
            } else {
                if (!offset) left = mid + 1;
                else right = mid  - 1;
            }
        }
        return left;
    }
    
    int verticalSearch(vector<vector<char>>& image, int left, int right, int top, int bottom, int offset) {
        while (top < bottom) {
            int mid = ((top + bottom) >> 1) + offset;
            bool getOne = false;
            for (int i = left; i <= right; i++) {
                if (image[mid][i] == '1') {
                    getOne = true;
                    break;
                }
            }
            if (getOne) {
                if (!offset) bottom = mid;
                else top = mid;
            } else {
                if (!offset) top = mid + 1;
                else bottom = mid - 1;
            }
        }
        return top;
    }
};
