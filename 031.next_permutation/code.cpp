class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size(), mark = -1;
        for (int i = len - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                mark = i;
                break;
            }
        }
        if (mark == -1) {
            reverse(nums, 0, len - 1);
        } else {
            for (int i = len - 1; i > mark; i--) {
                if (nums[i] > nums[mark]) {
                    int tmp = nums[i];
                    nums[i] = nums[mark];
                    nums[mark] = tmp;
                    break;
                }
            }
            reverse(nums, mark + 1, len - 1);
        }
    }
    
    void reverse(vector<int>& nums, int l, int r) {
        while (l < r) {
            int tmp = nums[l];
            nums[l++] = nums[r];
            nums[r--] = tmp;
        }
    }
};
