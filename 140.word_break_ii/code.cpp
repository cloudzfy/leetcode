class Solution {
private:
    vector<string> ans;
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n, false);
        vector<vector<string>> wordList(n, vector<string>());
        int lenMin = INT_MAX;
        int lenMax = INT_MIN;
        for (unordered_set<string>::iterator it = wordDict.begin(); it != wordDict.end(); it++) {
            int len = it->length();
            lenMin = min(lenMin, len);
            lenMax = max(lenMax, len);
        }
        for (int i = 0; i < n; i++) {
            if (i == 0 || dp[i - 1]) {
                for (int j = lenMin; j <= lenMax && i + j <= n; j++) {
                    string word = s.substr(i, j);
                    if (wordDict.find(word) != wordDict.end()) {
                        dp[i + j - 1] = true;
                        wordList[i].push_back(word);
                    }
                }
            }
        }
        if (!dp[n - 1]) return ans;
        string myans;
        dfs(wordList, n, 0, myans);
        return ans;
    }
    
    void dfs(vector<vector<string>>& wordList, int n, int index, string myans) {
        if (index == n) {
            ans.push_back(myans.substr(1, myans.length() - 1));
            return;
        }
        for (int i = 0; i < wordList[index].size(); i++) {
            string word = wordList[index][i];
            dfs(wordList, n, index + word.length(), myans + " " + word);
        }
    }
};
