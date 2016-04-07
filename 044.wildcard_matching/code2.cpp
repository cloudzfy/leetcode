class Solution {
public:
    bool isMatch(string s, string p) {
        int a = 0, b = 0;
        int star = -1, pos = -1;
        while (s[a]) {
            if (s[a] == p[b] || p[b] == '?') {
                a++;
                b++;
                continue;
            }
            if (p[b] == '*') {
                pos = a;
                star = b;
                b++;
                continue;
            }
            if (star != -1) {
                a = pos + 1;
                b = star + 1;
                pos++;
                continue;
            }
            return false;
        }
        while (p[b] == '*') b++;
        return p[b] == 0;
    }
};
