class Solution {
private:
    vector<string> ans;
public:
    vector<string> generateParenthesis(int n) {
        if (n > 0) {
            dfs(n, 0, 0, "");
        }
        return ans;
    }
    void dfs(int n, int left, int right, string myans) {
        if (left == n && right == n) {
            ans.push_back(myans);
        }
        else {
            if (left < n) {
                dfs(n, left + 1, right, myans + "(");
            }
            if (left > right) {
                dfs(n, left, right + 1, myans + ")");
            }
        }
    }
};
