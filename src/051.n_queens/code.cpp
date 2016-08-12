class Solution {
private:
    vector<vector<string>> ans;
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> myans(n, string(n, '.'));
        fillNQueens(myans, n, 0, 0, 0);
        return ans;
    }
    void fillNQueens(vector<string>& myans, int n, int row, int ld, int rd) {
        int full = (1 << n) - 1;
        if (row == full) {
            ans.push_back(myans);
            return;
        }
        int allowed = full & (~(row | ld | rd));
        while (allowed) {
            int pos = allowed & (~allowed + 1);
            allowed -= pos;
            setMap(myans, 'Q', pos, row);
            fillNQueens(myans, n, row | pos, (ld | pos) << 1, (rd | pos) >> 1);
            setMap(myans, '.', pos, row);
        }
    }
    void setMap(vector<string>& myans, char c, int pos, int row) {
        int i = 0;
        while (row != 0) {
            if ((row & 1) == 1) i++;
            row >>= 1;
        }
        int j = 0;
        while (pos != 0) {
            if ((pos & 1) == 1) break;
            pos >>= 1;
            j++;
        }
        myans[i][j] = c;
    }
};
