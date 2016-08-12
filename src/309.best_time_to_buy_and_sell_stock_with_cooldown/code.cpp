class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0;
        vector<int> dp(n, 0);
        int tmp = 0;
        for (int i = 1; i < dp.size(); i++) {
            dp[i] = max(dp[i], dp[i - 1] + prices[i] - prices[i - 1]);
            if (i - 2 >= 0) dp[i] = max(dp[i], tmp);
            tmp = max(dp[i - 1], tmp);
        }
        return max(dp[n - 1], dp[n - 2]);
    }
};
