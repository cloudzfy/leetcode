class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        if (m == 0) return ans;
        int n = matrix[0].size();
        int step = 0;
        int x1 = 0, x2 = n - 1, y1 = 1, y2 = m - 1;
        int x = 0, y = 0;
        for (int i = 0; i < m * n; i++) {
            ans.push_back(matrix[y][x]);
            if (step == 0) {
                if (x == x2) {
                    step = (step + 1) % 4;
                    x2--;
                    y++;
                } else x++;
            }
            else if (step == 1) {
                if (y == y2) {
                    step = (step + 1) % 4;
                    y2--;
                    x--;
                } else y++;
            }
            else if (step == 2) {
                if (x == x1) {
                    step = (step + 1) % 4;
                    x1++;
                    y--;
                } else x--;
            }
            else {
                if (y == y1) {
                    step = (step + 1) % 4;
                    y1++;
                    x++;
                } else y--;
            }
        }
        return ans;
    }
};
