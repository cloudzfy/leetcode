class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 0);
        int maxCount = 0;
        for (int i = n - 1; i >= 0; i--) {
            int count = 0;
            for (int j = i + 1; j < n; j++) {
                if (nums[j] % nums[i] == 0) count = max(count, dp[j]);
            }
            dp[i] = count + 1;
            maxCount = max(maxCount, dp[i]);
        }
        vector<int> ans;
        int num = 1;
        for (int i = 0; i < n; i++) {
            if (dp[i] == maxCount && nums[i] % num == 0) {
                ans.push_back(nums[i]);
                maxCount--;
                num = nums[i];
            }
        }
        return ans;
    }
};
