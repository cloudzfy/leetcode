class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int lenMin = INT_MAX;
        int lenMax = INT_MIN;
        for (unordered_set<string>::iterator it = wordDict.begin(); it != wordDict.end(); it++) {
            int len = it->length();
            lenMin = min(lenMin, len);
            lenMax = max(lenMax, len);
        }
        int n = s.length();
        vector<bool> dp(n, false);
        for (int i = 0; i < n; i++) {
            if (i == 0 || dp[i - 1]) {
                for (int j = lenMin; j <= lenMax && i + j <= n; j++) {
                    string tmp = s.substr(i, j);
                    if (wordDict.find(tmp) != wordDict.end()) {
                        dp[i + j - 1] = true;
                        if (i + j == n) return true;
                    }
                }
            }
        }
        return false;
    }
};
