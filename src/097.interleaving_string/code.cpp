class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) return false;
        int len1 = s1.length() + 1;
        int len2 = s2.length() + 1;
        vector<vector<bool>> dp(len1, vector<bool>(len2, false));
        dp[0][0] = true;
        for (int i = 1; i < len1; i++) {
            if (s1[i - 1] == s3[i - 1]) dp[i][0] = true;
            else break;
        }
        for (int j = 1; j < len2; j++) {
            if (s2[j - 1] == s3[j - 1]) dp[0][j] = true;
            else break;
        }
        for (int i = 1; i < len1; i++) {
            for (int j = 1; j < len2; j++) {
                if (s1[i - 1] == s3[i + j - 1]) dp[i][j] = dp[i][j] || dp[i - 1][j];
                if (s2[j - 1] == s3[i + j - 1]) dp[i][j] = dp[i][j] || dp[i][j - 1];
            }
        }
        return dp[len1 - 1][len2 - 1];
    }
};
