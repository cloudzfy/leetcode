class Solution {
private:
    int m;
    int n;
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        if (m == 0) return false;
        n = board[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (word[0] != board[i][j]) continue;
                if(dfs(board, visit, word, j, i, 0)) return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visit, string& word, int x, int y, int pos) {
        if (word[pos] != board[y][x]) return false;
        if (pos == word.length() - 1) return true;
        visit[y][x] = true;
        if (x - 1 >= 0 && !visit[y][x - 1] && dfs(board, visit, word, x - 1, y, pos + 1)) return true;
        if (x + 1 < n && !visit[y][x + 1] && dfs(board, visit, word, x + 1, y, pos + 1)) return true;
        if (y - 1 >= 0 && !visit[y - 1][x] && dfs(board, visit, word, x, y - 1, pos + 1)) return true;
        if (y + 1 < m && !visit[y + 1][x] && dfs(board, visit, word, x, y + 1, pos + 1)) return true;
        visit[y][x] = false;
        return false;
    }
};
