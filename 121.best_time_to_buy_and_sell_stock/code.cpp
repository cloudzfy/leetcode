class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        vector<int> map(n, 0);
        map[0] = prices[0];
        for (int i = 1; i < n; i++) {
            map[i] = min(prices[i], map[i - 1]);
        }
        int ans = 0;
        for (int i = n - 1; i > 0; i--) {
            ans = max(ans, prices[i] - map[i - 1]);
        }
        return ans;
    }
};
