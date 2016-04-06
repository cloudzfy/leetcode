class Solution {
public:
    int jump(vector<int>& nums) {
        int maxJump = 0;
        int curJump = 0, curIndex = 0;
        int ans = 0;
        if (nums.size() == 0) return ans;
        maxJump = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (curJump < i) {
                ans++;
                curJump = maxJump;
            }
            maxJump = max(maxJump, i + nums[i]);
        }
        return ans;
    }
};
