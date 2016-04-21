class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;
        vector<int> m(26, 0);
        for (int i = 0; i < s1.length(); i++) {
            m[s1[i] - 'a']++;
        }
        for (int i = 0; i < s2.length(); i++) {
            m[s2[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (m[i] != 0) return false;
        }
        int n = s1.length();
        for (int i = 1; i < s1.length(); i++) {
            if ((isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
                || (isScramble(s1.substr(0, i), s2.substr(n - i)) && isScramble(s1.substr(i), s2.substr(0, n - i)))) {
                return true;
            }
        }
        return false;
    }
};
