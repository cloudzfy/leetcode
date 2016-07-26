class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int ans = 1;
        int sign = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] > 0 && sign != 1) {
                ans++;
                sign = 1;
            } else if (nums[i] - nums[i - 1] < 0 && sign != -1) {
                ans++;
                sign = -1;
            }
        }
        return ans;
    }
};
