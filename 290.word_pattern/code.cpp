class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> strs;
        int begin = 0;
        for (int i = 0; i < str.length(); i++) {
            if (i == str.length() - 1 || str[i + 1] == ' ') {
                strs.push_back(str.substr(begin, i - begin + 1));
                begin = i + 2;
            }
        }
        if (pattern.length() != strs.size()) return false;
        map<char, string> m1;
        for (int i = 0; i < pattern.length(); i++) {
            if (m1.find(pattern[i]) != m1.end()) {
                if (m1[pattern[i]] != strs[i]) return false;
            } else {
                m1[pattern[i]] = strs[i];
            }
        }
        map<string, char> m2;
        for (int i = 0; i < strs.size(); i++) {
            if (m2.find(strs[i]) != m2.end()) {
                if (m2[strs[i]] != pattern[i]) return false;
            } else {
                m2[strs[i]] = pattern[i];
            }
        }
        return true;
    }
};
