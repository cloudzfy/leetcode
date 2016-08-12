class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> m;
        for (int i = 0; i < buildings.size(); i++) {
            m.push_back(make_pair(buildings[i][0], buildings[i][2]));
            m.push_back(make_pair(buildings[i][1], -buildings[i][2]));
        }
        sort(m.begin(), m.end(), cmp);
        vector<pair<int, int>> ans;
        multiset<int> q;
        int pre = 0;
        for (int i = 0; i < m.size(); i++) {
            int cur = m[i].second;
            if (cur > 0) {
                q.insert(cur);
                cur = *(q.rbegin());
            } else {
                q.erase(q.find(-cur));
                if (q.size() == 0) cur = 0;
                else cur = *(q.rbegin());
            }
            if (pre != cur) {
                ans.push_back(make_pair(m[i].first, cur));
                pre = cur;
            }
        }
        return ans;
    }
    static bool cmp(pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    }
};
