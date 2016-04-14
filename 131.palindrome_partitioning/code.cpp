class Solution {
private:
    vector<vector<string>> ans;
public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<bool>> isPalin(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            isPalin[i][i] = true;
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    if (j == i + 1 || isPalin[i + 1][j - 1]) isPalin[i][j] = true;
                }
            }
        }
        vector<string> myans;
        dfs(isPalin, s, 0, n, myans);
        return ans;
    }
    void dfs(vector<vector<bool>> &isPalin, string& s, int start, int end, vector<string>& myans) {
        if (start >= end) {
            ans.push_back(myans);
            return;
        }
        for (int i = start; i < end; i++) {
            if (isPalin[start][i]) {
                myans.push_back(s.substr(start, i - start + 1));
                dfs(isPalin, s, i + 1, end, myans);
                myans.pop_back();
            }
        }
    }
};
