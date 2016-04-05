class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;
        map<char, char> m;
        for (int i = 0; i < s.length(); i++) {
            map<char, char>::iterator it = m.find(s[i]);
            if (it == m.end()) {
                m[s[i]] = t[i];
            } else if (it->second != t[i]) {
                return false;
            }
        }
        m.clear();
        for (int i = 0; i < t.length(); i++) {
            map<char, char>::iterator it = m.find(t[i]);
            if (it == m.end()) {
                m[t[i]] = s[i];
            } else if (it->second != s[i]) {
                return false;
            }
        }
        return true;
    }
};
