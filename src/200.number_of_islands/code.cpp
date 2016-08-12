class Solution {
private:
    vector<int> ufset;
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        if (m == 0) return 0;
        ufset.resize(n * m);
        for (int i = 0; i < n * m; i++) {
            ufset[i] = i;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    int pos = i * m + j;
                    if (i > 0 && grid[i - 1][j] == '1') union2(pos - m, pos);
                    if (j > 0 && grid[i][j - 1] == '1') union2(pos - 1, pos);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n * m; i++) {
            if (grid[i / m][i % m] != '1') continue;
            if (i == find(i)) {
                ans++;
            }
        }
        return ans;
    }
    int find(int pos) {
        if (ufset[pos] != pos) {
            ufset[pos] = find(ufset[pos]);
        }
        return ufset[pos];
    }
    void union2(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) ufset[y] = x;
    }
};
