class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int len = nums.size(), n = 1;
        for (int i = 2; i <= len; i++) {
            n *= i;
        }
        ans.push_back(nums);
        for (int i = 1; i < n; i++) {
            int pos = -1;
            for (int j = len - 1; j > 0; j--) {
                if (nums[j - 1] < nums[j]) {
                    pos = j - 1;
                    break;
                }
            }
            if (pos == -1) {
                reverse(nums, 0, len - 1);
                ans.push_back(nums);
                continue;
            }
            for (int j = len - 1; j > pos; j--) {
                if (nums[pos] < nums[j]) {
                    int tmp = nums[pos];
                    nums[pos] = nums[j];
                    nums[j] = tmp;
                    break;
                }
            }
            reverse(nums, pos + 1, len - 1);
            ans.push_back(nums);
        }
        return ans;
    }
    
    void reverse(vector<int>& nums, int l, int r) {
        while (l < r) {
            int tmp = nums[l];
            nums[l++] = nums[r];
            nums[r--] = tmp;
        }
    }
};
