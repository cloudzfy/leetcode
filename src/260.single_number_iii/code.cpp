class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans(2, 0);
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum ^= nums[i];
        }
        int lowbit = sum & (-sum);
        int ans1 = 0, ans2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] & lowbit) {
                ans[0] ^= nums[i];
            } else {
                ans[1] ^= nums[i];
            }
        }
        return ans;
    }
};
