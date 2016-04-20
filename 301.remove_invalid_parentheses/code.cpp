class Solution {
private:
    unordered_set<string> ans;
public:
    vector<string> removeInvalidParentheses(string s) {
        int leftBracket = 0, rightBracket = 0;
        checkBracket(s, leftBracket, rightBracket);
        string myans;
        dfs(s, myans, 0, leftBracket, rightBracket, 0);
        return vector<string>(ans.begin(), ans.end());
    }
    void checkBracket(string& s, int& leftBracket, int& rightBracket) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') leftBracket++;
            else if (s[i] == ')') {
                if (leftBracket > 0) leftBracket--;
                else rightBracket++;
            }
        }
    }
    void dfs(string& s, string myans, int index, int leftBracket, int rightBracket, int needPair) {
        if (index == s.length()) {
            if (leftBracket == 0 && rightBracket == 0 && needPair == 0) {
                ans.insert(myans);
            }
            return;
        }
        if (s[index] == '(') {
            if (leftBracket > 0) dfs(s, myans, index + 1, leftBracket - 1, rightBracket, needPair);
            dfs(s, myans + s[index], index + 1, leftBracket, rightBracket, needPair + 1);
        } else if (s[index] == ')') {
            if (rightBracket > 0) dfs(s, myans, index + 1, leftBracket, rightBracket - 1, needPair);
            if (needPair > 0) dfs(s, myans + s[index], index + 1, leftBracket, rightBracket, needPair - 1);
        } else {
            dfs(s, myans + s[index], index + 1, leftBracket, rightBracket, needPair);
        }
    }
};
