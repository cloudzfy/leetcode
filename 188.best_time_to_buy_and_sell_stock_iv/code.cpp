class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (k >= n) return maxProfit(prices);
        vector<int> global(n, 0);
        vector<int> local(n, 0);
        for (int j = 0; j < k; j++) {
            for (int i = 1; i < n; i++) {
                int profit = prices[i] - prices[i - 1];
                local[i] = max(local[i - 1] + profit, global[i - 1] + profit);
            }
            for (int i = 1; i < n; i++) {
                global[i] = max(global[i - 1], local[i]);
            }
        }
        return global[n - 1];
    }
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] - prices[i - 1] > 0) ans += prices[i] - prices[i - 1];
        }
        return ans;
    }
};
