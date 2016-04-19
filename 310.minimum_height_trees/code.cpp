class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<set<int>> m(n, set<int>());
        vector<int> degree(n, 0);
        vector<int> ans;
        if (edges.size() == 0) {
            for (int i = 0; i < n; i++) {
                ans.push_back(i);
            }
            return ans;
        }
        for (int i = 0; i < edges.size(); i++) {
            m[edges[i].first].insert(edges[i].second);
            m[edges[i].second].insert(edges[i].first);
            degree[edges[i].first]++;
            degree[edges[i].second]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) q.push(i);
        }
        q.push(-1);
        while (!q.empty()) {
            int a = q.front();
            q.pop();
            if (a == -1) {
                if (q.empty()) return ans;
                ans.clear();
                q.push(-1);
                continue;
            } else ans.push_back(a);
            degree[a]--;
            int b = *(m[a].begin());
            m[b].erase(a);
            degree[b]--;
            if (degree[b] == 1) q.push(b);
        }
        return ans;
    }
};
