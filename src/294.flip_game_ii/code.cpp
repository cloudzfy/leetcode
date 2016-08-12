class Solution {
private:
    unordered_map<string, bool> m;
public:
    bool canWin(string s) {
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == '+' && s[i - 1] == '+') {
                s[i] = '-';
                s[i - 1] = '-';
                bool win;
                if (m.find(s) == m.end()) {
                    win = canWin(s);
                    m[s] = win;
                } else win = m[s];
                s[i] = '+';
                s[i - 1] = '+';
                if (!win) return true;
            }
        }
        return false;
    }
};
