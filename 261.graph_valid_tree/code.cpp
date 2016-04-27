class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> degree(n, 0);
        vector<vector<int>> graph(n, vector<int>(0));
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i].first].push_back(edges[i].second);
            graph[edges[i].second].push_back(edges[i].first);
            degree[edges[i].first]++;
            degree[edges[i].second]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) q.push(i);
        }
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            degree[cur]--;
            for (int i = 0; i < graph[cur].size(); i++) {
                degree[graph[cur][i]]--;
                if (degree[graph[cur][i]] == 1) q.push(graph[cur][i]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (degree[i] > 0) return false;
        }
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
        return count == 1;
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
