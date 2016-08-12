class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int len = 1;
        int count = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) count++;
            else count = 0;
            if (count <= 1) {
                nums[len] = nums[i];
                len++;
            }
        }
        return len;
    }
};
