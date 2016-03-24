class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int x1 = 0, x2 = n - 1, y1 = 1, y2 = n - 1;
        int step = 0;
        int x = 0, y = 0;
        for (int i = 1; i <= n * n; i++) {
            ans[y][x] = i;
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
