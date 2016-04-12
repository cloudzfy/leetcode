class Solution {
public:
    int numDistinct(string s, string t) {
        int lenS = s.length() + 1;
        int lenT = t.length() + 1;
        vector<vector<int>> dp(lenT, vector<int>(lenS, 0));
        dp[0][0] = true;
        for (int i = 1; i < lenT; i++) {
            int tmp = 0;
            for (int j = 1; j < lenS; j++) {
                tmp += dp[i - 1][j - 1];
                if (t[i - 1] == s[j - 1]) dp[i][j] = tmp;
            }
        }
        int ans = 0;
        for (int j = 1; j < lenS; j++) {
            ans += dp[lenT - 1][j];
        }
        return ans;
    }
};
