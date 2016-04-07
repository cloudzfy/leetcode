class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int len = s.length();
        vector<bool> m(len, false);
        for (int i = 0; i < len; i++) {
            if (s[i] == '(') st.push(i);
            else if (s[i] == ')') {
                if (st.empty()) continue;
                int begin = st.top();
                st.pop();
                for (int j = begin; j <= i; j++) {
                    m[j] = true;
                }
            }
        }
        int ans = 0;
        int begin = -1;
        for (int i = 0; i < len; i++) {
            if (begin == -1 && m[i]) begin = i;
            if (!m[i] && begin != -1) {
                ans = max(ans, i - begin);
                begin = -1;
            }
        }
        if (begin != -1 && m[len - 1]) {
            ans = max(ans, len - begin);
        }
        return ans;
    }
};
