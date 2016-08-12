class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp;
        for (int i = 0; i < n; i++) {
            int left = 0, right = dp.size() - 1;
            if (right < 0 || dp[right] < nums[i]) {
                dp.push_back(nums[i]);
                continue;
            }
            while (left <= right) {
                int mid = (left + right) >> 1;
                if (dp[mid] >= nums[i] && (mid == 0 || dp[mid - 1] < nums[i])) {
                    dp[mid] = nums[i];
                    break;
                }
                if (dp[mid] < nums[i]) left = mid + 1;
                else right = mid - 1;
            }
        }
        return (int)dp.size();
    }
};
