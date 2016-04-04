class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> map(n, 0);
        for (int i = 0; i < n; i++) {
            if (i == 0) map[i] = nums[i];
            else if (i == 1) map[i] = max(nums[i], map[i - 1]);
            else map[i] = max(map[i - 1], map[i - 2] + nums[i]);
        }
        return map[n - 1];
    }
};
