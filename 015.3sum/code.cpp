class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                if (j > i + 1 && nums[j] == nums[j - 1]) j++;
                else if (k < nums.size() - 1 && nums[k] == nums[k + 1]) k--;
                else if (nums[i] + nums[j] + nums[k] < 0) j++;
                else if (nums[i] + nums[j] + nums[k] > 0) k--;
                else {
                    ans.push_back(vector<int>{nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                
            }
        }
        return ans;
    }
};
