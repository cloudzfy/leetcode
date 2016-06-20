class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> dp(height.size(), 0);
        int maxHeight = 0;
        for (int i = 0; i < height.size(); i++) {
            dp[i] = maxHeight;
            maxHeight = max(maxHeight, height[i]);
        }
        maxHeight = 0;
        for (int i = height.size() - 1; i >= 0; i--) {
            dp[i] = min(dp[i], maxHeight);
            maxHeight = max(maxHeight, height[i]);
        }
        int ans = 0;
        for (int i = 0; i < height.size(); i++) {
            ans += dp[i] - height[i] > 0 ? dp[i] - height[i] : 0;
        }
        return ans;
    }
};
