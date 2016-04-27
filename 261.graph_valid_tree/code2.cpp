class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> pre(n, 0);
        for (int i = 0; i < n; i++) {
            pre[i] = i;
        }
        for (int i = 0; i < edges.size(); i++) {
            setUnion(pre, edges[i].first, edges[i].second);
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (setFind(pre, i) == i) count++;
        }
        return count == 1 && edges.size() == n - 1;
    }
    int setFind(vector<int>& pre, int x) {
        if (pre[x] != x) {
            pre[x] = setFind(pre, pre[x]);
        }
        return pre[x];
    }
    void setUnion(vector<int>& pre, int x, int y) {
        x = setFind(pre, x);
        y = setFind(pre, y);
        pre[x] = y;
    }
};
