class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<int> pre(n, 0);
        for (int i = 0; i < n; i++) {
            pre[i] = i;
        }
        for (int i = 0; i < edges.size(); i++) {
            setUnion(pre, edges[i].first, edges[i].second);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            find(pre, i);
            if (pre[i] == i) ans++;
        }
        return ans;
    }
    int find(vector<int>& pre, int x) {
        if (pre[x] != x) {
            pre[x] = find(pre, pre[x]);
        }
        return pre[x];
    }
    void setUnion(vector<int>& pre, int x, int y) {
        x = find(pre, x);
        y = find(pre, y);
        pre[x] = y;
    }
    
};
