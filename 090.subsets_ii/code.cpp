class Solution {
private:
    vector<vector<int>> ans;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> myans;
        dfs(nums, myans, 0);
        return ans;
    }
    void dfs(vector<int>& nums, vector<int>& myans, int pos) {
        ans.push_back(myans);
        for (int i = pos; i < nums.size(); i++) {
            if (i > pos && nums[i] == nums[i - 1]) continue;
            myans.push_back(nums[i]);
            dfs(nums, myans, i + 1);
            myans.pop_back();
        }
    }
};
