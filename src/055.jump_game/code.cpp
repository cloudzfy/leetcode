class Solution {
public:
    bool canJump(vector<int>& nums) {
        int pos = 0, len = nums.size();
        for (int i = 0; i < len && i <= pos; i++) {
            pos = max(pos, i + nums[i]);
        }
        if (pos >= len - 1) return true;
        else return false;
    }
};
