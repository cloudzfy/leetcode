class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> ans;
        vector<int> pre;
        unordered_map<int, int> map;
        int count = 0;
        for (int i = 0; i < positions.size(); i++) {
            int x = positions[i].first;
            int y = positions[i].second;
            int pos = x * n + y;
            map[pos] = pre.size();
            pre.push_back(pre.size());
            count++;
            if (x - 1 >= 0 && map.find(pos - n) != map.end()) count -= setUnion(pre, map[pos], map[pos - n]);
            if (y - 1 >= 0 && map.find(pos - 1) != map.end()) count -= setUnion(pre, map[pos], map[pos - 1]);
            if (x + 1 < m && map.find(pos + n) != map.end()) count -= setUnion(pre, map[pos], map[pos + n]);
            if (y + 1 < n && map.find(pos + 1) != map.end()) count -= setUnion(pre, map[pos], map[pos + 1]);
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
