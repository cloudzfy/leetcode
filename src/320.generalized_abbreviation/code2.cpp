class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> ans;
        string myans;
        dfs(ans, word, 0, myans);
        return ans;
    }
    void dfs(vector<string>& ans, string word, int cur, string myans) {
        if (cur >= word.length()) {
            ans.push_back(myans);
            return;
        }
        for (int j = cur; j < word.length(); j++) {
            for (int i = j; i < word.length(); i++) {
                if (i + 1 < word.length()) dfs(ans, word, i + 2, myans + to_string(i - j + 1) + word[i + 1]);
                else dfs(ans, word, i + 1, myans + to_string(i - j + 1));
            }
            myans += word[j];
        }
        ans.push_back(myans);
    }
};
