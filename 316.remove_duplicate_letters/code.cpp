class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> m(26, 0);
        vector<bool> visited(26, false);
        for (int i = 0; i < s.length(); i++) {
            m[s[i] - 'a']++;
        }
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (!visited[s[i] - 'a']) {
                while (st.size() && s[i] < st.top() && m[st.top() - 'a']) {
                    visited[st.top() - 'a'] = false;
                    st.pop();
                }
                st.push(s[i]);
                visited[s[i] - 'a'] = true;
            }
            m[s[i] - 'a']--;
        }
        string ans;
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};
