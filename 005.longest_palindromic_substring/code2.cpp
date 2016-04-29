class Solution {
public:
    string longestPalindrome(string s) {
        string exS = preProcess(s);
        int n = exS.length();
        vector<int> dp(n, 0);
        int C = 0, R = 0;
        for (int i = 1; i < n; i++) {
            int j = 2 * C - i;
            dp[i] = R > i ? min(R - i, dp[j]) : 0;
            while (i - 1 - dp[i] >= 0 && i + 1 + dp[i] < n && exS[i - 1 - dp[i]] == exS[i + 1 + dp[i]]) dp[i]++;
            if (R < i + dp[i]) {
                R = i + dp[i];
                C = i;
            }
        }
        int len = 0, index = -1;
        for (int i = 0; i < n; i++) {
            if (dp[i] > len) {
                len = dp[i];
                index = i;
            }
        }
        return s.substr((index - dp[index]) / 2, dp[index]);
    }
    
    string preProcess(string s) {
        string ans;
        ans.push_back('#');
        for (int i = 0; i < s.length(); i++) {
            ans.push_back(s[i]);
            ans.push_back('#');
        }
        return ans;
    }
};
