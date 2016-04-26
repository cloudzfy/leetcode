class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> ans;
        vector<int> pre(n * m, 0);
        vector<vector<bool>> map(m, vector<bool>(n, false));
        for (int i = 0; i < n * m; i++) {
            pre[i] = i;
        }
        int count = 0;
        for (int i = 0; i < positions.size(); i++) {
            int x = positions[i].first;
            int y = positions[i].second;
            int pos = x * n + y;
            count++;
            map[x][y] = true;
            if (x - 1 >= 0 && map[x - 1][y]) count -= setUnion(pre, pos, pos - n);
            if (y - 1 >= 0 && map[x][y - 1]) count -= setUnion(pre, pos, pos - 1);
            if (x + 1 < m && map[x + 1][y]) count -= setUnion(pre, pos, pos + n);
            if (y + 1 < n && map[x][y + 1]) count -= setUnion(pre, pos, pos + 1);
            ans.push_back(count);
        }
        return ans;
        
    }
    int find(vector<int>& pre, int x) {
        if (pre[x] != x) {
            pre[x] = find(pre, pre[x]);
        }
        return pre[x];
    }
    int setUnion(vector<int>& pre, int x, int y) {
        x = find(pre, x);
        y = find(pre, y);
        pre[x] = y;
        if (x != y) return 1;
        return 0;
    }
};
