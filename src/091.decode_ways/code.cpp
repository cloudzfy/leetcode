class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        if (len == 0) return 0;
        if (s[0] == '0') return 0;
        vector<int> map(len, 0);
        for(int i = 0; i < len; i++) {
            if (s[i] != '0') {
                if (i >= 1) map[i] += map[i - 1];
                else map[i]++;
            }
            if (i >= 1 && s[i - 1] != '0') {
                int tmp = (s[i - 1] - '0') * 10 + s[i] - '0';
                if (tmp <= 26) {
                    if (i >= 2) map[i] += map[i - 2];
                    else map[i]++;
                }
            }
        }
        return map[len - 1];
    }
};
