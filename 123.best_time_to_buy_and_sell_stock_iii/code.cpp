class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int numPrices = prices.size();
        if (numPrices < 2) return 0;
        vector<int> dp1(numPrices, 0);
        vector<int> dp2(numPrices, 0);
        int lowest = prices[0];
        dp1[0] = 0;
        for (int i = 1; i < numPrices; i++) {
            dp1[i] = max(dp1[i - 1], prices[i] - lowest);
            lowest = min(prices[i], lowest);
        }
        int highest = prices[numPrices - 1];
        dp2[numPrices - 1] = 0;
        for (int i = numPrices - 1; i > 0; i--) {
            dp2[i - 1] = max(dp2[i], highest - prices[i - 1]);
            highest = max(prices[i - 1], highest);
        }
        int ans = 0;
        for (int i = 0; i < numPrices; i++) {
            ans = max(ans, dp1[i] + dp2[i]);
        }
        return ans;
    }
};
