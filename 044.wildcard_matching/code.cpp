class Solution {
public:
    bool isMatch(string s, string p) {
        int lenS = s.length();
        int lenP = p.length();
        if (lenP == 0) return lenS == 0;
        vector<int> m(lenS + 1, -2);
        m[0] = -1;
        for (int i = 0; i < lenP; i++) {
            for (int j = lenS; j > 0; j--) {
                if (m[j - 1] == i - 1) {
                    if (s[j - 1] == p[i] || p[i] == '?') m[j] = i;
                }
            }
            for (int j = lenS; j >= 0; j--) {
                if (m[j] == i - 1 && p[i] == '*') {
                    for (int k = j; k <= lenS && m[k] != i; k++) {
                        m[k] = i;
                    }
                }
            }
        }
        if (m[lenS] == lenP - 1) return true;
        return false;
        
    }
};
