class Solution {
private:
    vector<string> ans;
public:
    vector<string> addOperators(string num, int target) {
        if (num.length() > 0) dfs(num, 0, 0, 1, -(long long)target, "");
        return ans;
    }
    void dfs(string& str, int cur, long long num, long long term, long long expr, string myans) {
        num = num * 10 + str[cur] - '0';
        if (cur == str.length() - 1) {
            if (expr + num * term == 0) ans.push_back(myans + str[cur]);
            return;
        }
        if (num != 0) dfs(str, cur + 1, num, term, expr, myans + str[cur]);
        dfs(str, cur + 1, 0, 1, expr + num * term, myans + str[cur] + '+');
        dfs(str, cur + 1, 0, -1, expr + num * term, myans + str[cur] + '-');
        dfs(str, cur + 1, 0, term * num, expr, myans + str[cur] + '*');
    }
};
