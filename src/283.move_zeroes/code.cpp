class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroIndex = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                if (zeroIndex != i) swap(nums[i], nums[zeroIndex]);
                zeroIndex++;
            }
        }
    }
};
