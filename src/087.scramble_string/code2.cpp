class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;
        if (s1.length() != s2.length()) return false;
        vector<int> count(26, 0);
        int len = s1.length();
        for (int i = 0; i < len; i++) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) return false;
        }
        int nCount = 0;
        for (int i = 0; i < len; i++) {
            count[s1[i] - 'a']++;
            if (count[s1[i] - 'a'] == 1) nCount++;
            count[s2[i] - 'a']--;
            if (count[s2[i] - 'a'] == 0) nCount--;
            if (nCount == 0 && i < len - 1) {
                if (isScramble(s1.substr(0, i + 1), s2.substr(0, i + 1)) && isScramble(s1.substr(i + 1), s2.substr(i + 1)))
                    return true;
            }
        }
        for (int i = 0; i < len; i++) {
            count[s1[i] - 'a']++;
            if (count[s1[i] - 'a'] == 1) nCount++;
            count[s2[len - i - 1] - 'a']--;
            if (count[s2[len - i - 1] - 'a'] == 0) nCount--;
            if (nCount == 0 && i < len - 1) {
                if (isScramble(s1.substr(0, i + 1), s2.substr(len - i - 1)) && isScramble(s1.substr(i + 1), s2.substr(0, len - i - 1)))
                    return true;
            }
        }
        return false;
    }
};
