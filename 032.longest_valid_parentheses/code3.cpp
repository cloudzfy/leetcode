class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        int len = 0, count = 0;
        for (int i = 0; i < s.length(); i++) {
            len++;
            if (s[i] == '(') count++;
            else if (s[i] == ')') count--;
            if (count < 0) {
                count = 0;
                len = 0;
            } else if (count == 0) {
                ans = max(ans, len);
            }
        }
        len = 0;
        count = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            len++;
            if (s[i] == ')') count++;
            else if (s[i] == '(') count--;
            if (count < 0) {
                count = 0;
                len = 0;
            } else if (count == 0) {
                ans = max(ans, len);
            }
        }
        return ans;
    }
};
