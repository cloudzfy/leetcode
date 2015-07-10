class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]=i;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(m.find(target - nums[i]) != m.end() && m[target - nums[i]] != i)
            {
                ans.push_back(i + 1);
                ans.push_back(m[target - nums[i]] + 1);
                break;
            }
        }
        return ans;
    }
};