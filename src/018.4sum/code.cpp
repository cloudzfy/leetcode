class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int tmp1 = nums[i] + nums[j] - target;
                int k = j + 1;
                int l = nums.size() - 1;
                while (k < l) {
                    if (k > j + 1 && nums[k] == nums[k - 1]) k++;
                    else if (l < nums.size() - 1 && nums[l] == nums[l + 1]) l--;
                    else {
                        int tmp = tmp1 + nums[k] + nums[l];
                        if (tmp < 0) k++;
                        else if (tmp > 0) l--;
                        else {
                            ans.push_back(vector<int>{nums[i], nums[j], nums[k], nums[l]});
                            k++;
                            l--;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
