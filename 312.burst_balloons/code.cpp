class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> newNums(n + 2, 1);
        for (int i = 0; i < n; i++) {
            newNums[i + 1] = nums[i];
        }
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int i = 2; i < n + 2; i++) {
            for (int j = 0; i + j < n + 2; j++) {
                for (int k = j + 1; k < j + i; k++) {
                    int coins = newNums[j] * newNums[k] * newNums[j + i];
                    dp[j][j + i] = max(dp[j][j + i], dp[j][k] + dp[k][j + i] + coins);
                }
            }
        }
        return dp[0][n + 1];
    }
};
