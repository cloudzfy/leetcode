class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0, blue = nums.size() - 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                if (red < i) swap(nums[red], nums[i]);
                red++;
            }
        }
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] == 2) {
                if (blue > i) swap(nums[blue], nums[i]);
                blue--;
            }
        }
    }
};
