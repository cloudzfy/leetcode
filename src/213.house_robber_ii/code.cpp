class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        int ans = 0;
        vector<int> dp1(n, 0);
        vector<int> dp2(n, 0);
        dp1[0] = nums[0];
        for (int i = 1; i < n - 1; i++) {
            dp1[i] = nums[i];
            if (i - 1 >= 0) dp1[i] = max(dp1[i], dp1[i - 1]);
            if (i - 2 >= 0) dp1[i] = max(dp1[i], dp1[i - 2] + nums[i]);
        }
        ans = max(ans, dp1[n - 2]);
        dp2[n - 1] = nums[n - 1];
        for (int i = n - 2; i > 0; i--) {
            dp2[i] = nums[i];
            if (i + 1 < n) dp2[i] = max(dp2[i], dp2[i + 1]);
            if (i + 2 < n) dp2[i] = max(dp2[i], dp2[i + 2] + nums[i]);
        }
        ans = max(ans, dp2[1]);
        return ans;
    }
};
