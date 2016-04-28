class Solution {
    unordered_map<char, string> p2s;
    unordered_map<string, char> s2p;
public:
    bool wordPatternMatch(string pattern, string str) {
        return backtracking(pattern, 0, str, 0);
    }
    
    bool backtracking(string pattern, int idxp, string str, int idxs) {
        if (idxp == pattern.length()) return idxs == str.length();
        if (p2s.find(pattern[idxp]) != p2s.end()) {
            string match = p2s[pattern[idxp]];
            if (str.substr(idxs, match.length()) == match) {
                return backtracking(pattern, idxp + 1, str, idxs + match.length());
            }
            return false;
        }
        for (int i = idxs; i < str.length(); i++) {
            if (pattern.length() - idxp > str.length() - i) break;
            string tmp = str.substr(idxs, i - idxs + 1);
            if (s2p.find(tmp) == s2p.end()) {
                s2p[tmp] = pattern[idxp];
                p2s[pattern[idxp]] = tmp;
                if (backtracking(pattern, idxp + 1, str, i + 1)) return true;
                s2p.erase(tmp);
                p2s.erase(pattern[idxp]);
            }
        }
        return false;
    }
};
