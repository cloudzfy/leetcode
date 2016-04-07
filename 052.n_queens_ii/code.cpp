class Solution {
private:
    int ans;
public:
    int totalNQueens(int n) {
        ans = 0;
        fillNQueens(n, 0, 0, 0);
        return ans;
    }
    void fillNQueens(int n, int row, int ld, int rd) {
        int full = (1 << n) - 1;
        if (row == full) {
            ans++;
            return;
        }
        int allowed = full & (~(row | ld | rd));
        while (allowed) {
            int pos = allowed & (~allowed + 1);
            allowed -= pos;
            fillNQueens(n, row | pos, (ld | pos) << 1, (rd | pos) >> 1);
        }
    }
};
