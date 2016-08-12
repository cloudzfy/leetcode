class Solution {
public:
    bool isPalindrome(string s) {
        if (s.length() == 0) return true;
        int a = 0, b = s.length() - 1;
        while (a < b) {
            if (!isValid(s[a])) {
                a++;
                continue;
            }
            if (!isValid(s[b])) {
                b--;
                continue;
            }
            if (s[a] == s[b]) {
                a++;
                b--;
                continue;
            }
            return false;
        }
        return true;
    }
    bool isValid(char &c) {
        if (c <= 'Z' && c >= 'A') {
            c += 'a' - 'A';
            return true;
        }
        if (c <= 'z' && c >= 'a') return true;
        if (c <= '9' && c >= '0') return true;
        return false;
    }
};
