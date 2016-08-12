class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if (s.length() == t.length()) {
            int count = 0;
            for (int i = 0; i < s.length(); i++) {
                if (s[i] != t[i]) count++;
            }
            return count == 1;
        } else if (s.length() == t.length() + 1) {
            int i = 0, j = 0;
            while (i <= s.length() && j <= t.length()) {
                if (s[i] == t[j]) j++;
                i++;
            }
            return i == s.length() + 1 && j == t.length() + 1;
        } else if (s.length() + 1 == t.length()) {
            int i = 0, j = 0;
            while (i <= s.length() && j <= t.length()) {
                if (s[i] == t[j]) i++;
                j++;
            }
            return i == s.length() + 1 && j == t.length() + 1;
        } else return false;
    }
};
