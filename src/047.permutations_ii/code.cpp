class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int len = nums.size();
        ans.push_back(nums);
        while (true) {
            int pos = -1;
            for (int i = len - 1; i > 0; i--) {
                if (nums[i - 1] < nums[i]) {
                    pos = i - 1;
                    break;
                }
            }
            if (pos == -1) break;
            for (int i = len - 1; i > pos; i--) {
                if (nums[pos] < nums[i]) {
                    int tmp = nums[pos];
                    nums[pos] = nums[i];
                    nums[i] = tmp;
                    break;
                }
            }
            int l = pos + 1, r = len - 1;
            while (l < r) {
                int tmp = nums[l];
                nums[l++] = nums[r];
                nums[r--] = tmp;
            }
            ans.push_back(nums);
        }
        return ans;
    }
};
