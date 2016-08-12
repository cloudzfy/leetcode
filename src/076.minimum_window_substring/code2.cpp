class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> m(128, 0);
        for (int i = 0; i < t.length(); i++) {
            m[t[i]]++;
        }
        int minLen = INT_MAX;
        string ans;
        vector<int> cur(128, 0);
        int left = -1, count = 0, index = 0;
        while (s[index]) {
            if (m[s[index]] > 0) {
                if (left == -1) left = index;
                cur[s[index]]++;
                if (cur[s[index]] <= m[s[index]]) count++;
                while(true) {
                    if (m[s[left]] > 0) {
                        if (cur[s[left]] > m[s[left]]) {
                            cur[s[left]]--;
                        } else break;
                    }
                    left++;
                }
                if (count == t.length() && minLen > index - left + 1) {
                    minLen = index - left + 1;
                    ans = s.substr(left, minLen);
                }
            }
            index++;
        }
        return ans;
    }
};
