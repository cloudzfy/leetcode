class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        if (n == 0) return;
        int m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int count = 0;
                for (int a = max(0, i - 1); a < min(i + 2, n); a++) {
                    for (int b = max(0, j - 1); b < min(j + 2, m); b++) {
                        if (a == i && b == j) continue;
                        count += board[a][b] & 1;
                    }
                }
                if ((board[i][j] & 1) && count <= 3 && count >= 2) board[i][j] |= 2;
                if (!(board[i][j] & 1) && count == 3) board[i][j] |= 2;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                board[i][j] >>= 1;
            }
        }
    }
};
