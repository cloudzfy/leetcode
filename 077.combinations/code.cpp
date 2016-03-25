class Solution {
private:
    vector<vector<int>> ans;
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> myans;
        dfs(myans, n, k, 0);
        return ans;
    }
    void dfs(vector<int>& myans, int n, int k, int cur) {
        if (k == 0) {
            ans.push_back(myans);
            return;
        }
        for (int i = cur + 1; i <= n - k + 1; i++) {
            myans.push_back(i);
            dfs(myans, n, k - 1, i);
            myans.pop_back();
        }
    }
};
