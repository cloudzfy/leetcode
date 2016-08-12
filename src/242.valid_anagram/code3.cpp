class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        map<char, int> m;
        for (int i = 0; i < s.length(); i++) {
            m[s[i]]++;
            m[t[i]]--;
        }
        for (map<char, int>::iterator it = m.begin(); it != m.end(); it++) {
            if (it->second != 0) return false;
        }
        return true;
    }
};
