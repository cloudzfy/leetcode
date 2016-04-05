class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.size() == 0) return 1;
        int pos = 0;
        while (pos < nums.size()) {
            if (nums[pos] > 0 && nums[pos] - 1 < nums.size() && nums[pos] != pos + 1 && nums[pos] != nums[nums[pos] - 1]) {
                swap(nums[pos], nums[nums[pos] - 1]);
            } else pos++;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) return i + 1;
        }
        return nums.size() + 1;
    }
};
