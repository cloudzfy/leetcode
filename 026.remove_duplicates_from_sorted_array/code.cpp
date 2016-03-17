class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return len;
        int count = 1;
        for (int i = 1; i < len; i++) {
            if (nums[i] != nums[count - 1]) {
                nums[count++] = nums[i];
            }
        }
        return count;
    }
};
