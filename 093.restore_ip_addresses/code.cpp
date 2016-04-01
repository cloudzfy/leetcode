class Solution {
private:
    vector<string> ans;
public:
    vector<string> restoreIpAddresses(string s) {
        string myans;
        dfs(s, 0, 0, myans);
        return ans;
    }
    
    void dfs(string &s, int pos, int count, string myans) {
        int num = 0;
        if (pos == s.length() && count == 4) {
            ans.push_back(myans.substr(1, myans.length() - 1));
            return;
        }
        if (count == 4) return;
        for (int i = 0; i < 3; i++) {
            if (pos + i == s.length()) return;
            num += s[pos + i] - '0';
            if (num > 255) break;
            dfs(s, pos + i + 1, count + 1, myans + '.' + s.substr(pos, i + 1));
            if (num == 0) break;
            num *= 10;
        }
    }
};
