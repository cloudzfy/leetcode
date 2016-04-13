class Solution {
private:
    int n, m;
public:
    void solve(vector<vector<char>>& board) {
        n = board.size();
        if (n == 0) return;
        m = board[0].size();
        if (m == 0) return;
        vector<vector<bool>> noflip(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O' && !noflip[i][0]) bfs(board, noflip, i * m);
            if (board[i][m - 1] == 'O' && !noflip[i][m - 1]) bfs(board, noflip, i * m + m - 1);
        }
        for (int j = 1; j < m - 1; j++) {
            if (board[0][j] == 'O' && !noflip[0][j]) bfs(board, noflip, j);
            if (board[n - 1][j] == 'O' && !noflip[n - 1][j]) bfs(board, noflip, (n - 1) * m + j);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && !noflip[i][j]) board[i][j] = 'X';
            }
        }
    }
    void bfs(vector<vector<char>>& board, vector<vector<bool>>& noflip, int pos) {
        queue<int> q;
        q.push(pos);
        while (!q.empty()) {
            pos = q.front();
            q.pop();
            int i = pos / m, j = pos % m;
            if (noflip[i][j]) continue;
            noflip[i][j] = true;
            if (i - 1 >= 0 && board[i - 1][j] == 'O' && !noflip[i - 1][j]) q.push(pos - m);
            if (i + 1 < n && board[i + 1][j] == 'O' && !noflip[i + 1][j]) q.push(pos + m);
            if (j - 1 >= 0 && board[i][j - 1] == 'O' && !noflip[i][j - 1]) q.push(pos - 1);
            if (j + 1 < m && board[i][j + 1] == 'O' && !noflip[i][j + 1]) q.push(pos + 1);
        }
    }
};
