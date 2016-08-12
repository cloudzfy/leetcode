class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            dp[i][0] = matrix[i][0] - '0';
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == '0') dp[i][j] = 0;
                else dp[i][j] = dp[i][j - 1] + matrix[i][j] - '0';
            }
        }
        stack<int> s;
        int ans = 0;
        for (int j = 0; j < m; j++) {
            while (!s.empty()) s.pop();
            for (int i = 0; i < n + 1; i++) {
                while (!s.empty() && dp[s.top()][j] > dp[i][j]) {
                    int area = s.top();
                    s.pop();
                    ans = max(ans, s.empty()? i * dp[area][j] : (i - s.top() - 1) * dp[area][j]);
                }
                s.push(i);
            }
        }
        return ans;
    }
};
