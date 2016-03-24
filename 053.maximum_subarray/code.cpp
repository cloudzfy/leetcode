class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        int opt = nums[0], accu = 0;
        for (int i = 0; i < len; i++) {
            accu += nums[i];
            opt = max(opt, accu);
            if (accu < 0) accu = 0;
        }
        return opt;
    }
};
