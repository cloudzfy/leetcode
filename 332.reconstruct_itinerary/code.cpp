class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, map<string, int>> m;
        for (int i = 0; i < tickets.size(); i++) {
            m[tickets[i].first][tickets[i].second]++;
        }
        vector<string> ans;
        string begin = "JFK";
        ans.push_back(begin);
        dfs(m, tickets.size() + 1, begin, ans);
        return ans;
    }
    bool dfs(unordered_map<string, map<string, int>>& m, int n, string cur, vector<string>& ans) {
        if (ans.size() == n) return true;
        for (map<string, int>::iterator it = m[cur].begin(); it != m[cur].end(); it++) {
            if (it->second != 0) {
                it->second--;
                ans.push_back(it->first);
                if (dfs(m, n, it->first, ans)) return true;
                ans.pop_back();
                it->second++;
            }
        }
        return false;
    }
};
