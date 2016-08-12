class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        attemptSudoku(board);
    }
    bool attemptSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (int num = 0; num < 9; num++) {
                        board[i][j] = '1' + num;
                        if (isValidSudoku(board, i, j)) {
                            if (attemptSudoku(board)) return true;
                        }
                    }
                    board[i][j] = '.';
                    return false;
                }
            }
        }
        return true;
    }
    bool isValidSudoku (vector<vector<char>>& board, int i, int j) {
        for (int k = 0; k < 9; k++) {
            if (k != j && board[i][k] == board[i][j]) return false;
        }
        for (int k = 0; k < 9; k++) {
            if (k != i && board[k][j] == board[i][j]) return false;
        }
        for (int k = 0; k < 9; k++) {
            int x = i - i % 3 + k / 3;
            int y = j - j % 3 + k % 3;
            if ((x != i || y != j) && board[x][y] == board[i][j])
                return false;
        }
        return true;
    }
    
};
