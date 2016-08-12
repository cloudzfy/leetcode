class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int len = 0, flag = 1;
        if (strs.size() == 0) return ans;
        while (flag) {
            char ch = strs[0][len];
            if (ch == 0) {
                flag = 0;
            }
            for (int i = 1; i < strs.size(); i++) {
                if(strs[i][len] != ch) {
                    flag = 0;
                    break;
                }
            }
            if (flag) ans = ans + ch;
            len++;
        }
        return ans;
    }
};
