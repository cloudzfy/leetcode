class Solution {
private:
    vector<vector<int>> ans;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = 1;
        for (int i = 0; i < nums.size(); i++) {
            len *= 2;
        }
        for (int i = 0; i < len; i++) {
            vector<int> myans;
            int tmp = i;
            for (int j = 0; j < nums.size(); j++) {
                if (tmp % 2 == 1) myans.push_back(nums[j]);
                tmp = tmp >> 1;
            }
            ans.push_back(myans);
        }
        return ans;
    }
};
