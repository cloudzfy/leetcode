class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> dp;
        for (int i = 0; i < nums.size(); i++) {
            int m = dp.size();
            if (m == 0) dp.push_back(nums[i]);
            else if (dp[m - 1] < nums[i]) dp.push_back(nums[i]);
            else {
                for (int j = m - 1; j >= 0; j--) {
                    if (j == 0 || dp[j - 1] < nums[i]) {
                        dp[j] = nums[i];
                        break;
                    }
                }
            }
            if (dp.size() >= 3) return true;
        }
        return false;
    }
};
