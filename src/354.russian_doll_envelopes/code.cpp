class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> dp;
        for (int i = 0; i < envelopes.size(); i++) {
            int left = 0, right = dp.size();
            while (left < right) {
                int mid = (left + right) >> 1;
                if (dp[mid] < envelopes[i].second) left = mid + 1;
                else right = mid;
            }
            if (right == dp.size()) dp.push_back(envelopes[i].second);
            else dp[left] = envelopes[i].second;
        }
        return dp.size();
    }
    
    static bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
        if (a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    }
};
