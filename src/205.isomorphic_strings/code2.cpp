class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;
        vector<int> m1(128, 0);
        for (int i = 0; i < s.length(); i++) {
            if (m1[s[i]] == 0) m1[s[i]] = t[i];
            else if (m1[s[i]] != t[i]) return false;
        }
        vector<int> m2(128, 0);
        for (int i = 0; i < t.length(); i++) {
            if (m2[t[i]] == 0) m2[t[i]] = s[i];
            else if (m2[t[i]] != s[i]) return false;
        }
        return true;
    }
};
