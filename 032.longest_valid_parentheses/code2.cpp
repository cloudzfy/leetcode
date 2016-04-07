class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        vector<int> m(n, 0);
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                int left = i - 1 - m[i - 1];
                if (left >= 0 && s[left] == '(') {
                    m[i] = m[i - 1] + 2;
                    if (left - 1 >= 0) m[i] += m[left - 1];
                }
                ans = max(ans, m[i]);
            }
        }
        return ans;
    }
};
