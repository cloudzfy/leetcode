class Solution {
public:
    bool isMatch(string s, string p) {
        char *ss = &s[0];
        char *pp = &p[0];
        return isMatch(ss, pp);
    }
    bool isMatch(char *s, char *p) {
        if (*p == 0) return *s == 0;
        if (*(p + 1) == '*') {
            if (*s == *p || (*p == '.' && *s != 0)) {
                return isMatch(s + 1, p) || isMatch(s, p + 2);
            }
            return isMatch(s, p + 2);
        } else {
            if (*s == *p || (*p == '.' && *s != 0)) {
                return isMatch(s + 1, p + 1);
            }
        }
        return false;
    }
};
