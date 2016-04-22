class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        if (n == 0) return 0;
        int k = costs[0].size();
        if (k == 0) return 0;
        vector<vector<int>> dp(n, vector<int>(k, 0));
        int firstMin = INT_MAX, secondMin = INT_MAX;
        int firstIdx = -1;
        for (int j = 0; j < k; j++) {
            if (firstMin > costs[0][j]) {
                secondMin = firstMin;
                firstMin = costs[0][j];
                firstIdx = j;
            } else if (secondMin > costs[0][j]) {
                secondMin = costs[0][j];
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < k; j++) {
                if (j != firstIdx) dp[i][j] = firstMin + costs[i][j];
                else dp[i][j] = secondMin + costs[i][j];
            }
            firstMin = INT_MAX;
            secondMin = INT_MAX;
            firstIdx = -1;
            for (int j = 0; j < k; j++) {
                if (firstMin > dp[i][j]) {
                    secondMin = firstMin;
                    firstMin = dp[i][j];
                    firstIdx = j;
                } else if (secondMin > dp[i][j]) {
                    secondMin = dp[i][j];
                }
            }
        }
        return firstMin;
    }
};
