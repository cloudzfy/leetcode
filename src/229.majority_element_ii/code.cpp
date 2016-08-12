class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int len = nums.size();
        if (len == 0) return ans;
        int candidate1, candidate2;
        int count1 = 0, count2 = 0;
        for (int i = 0; i < len; i++) {
            if (count1 > 0 && candidate1 == nums[i]) count1++;
            else if (count2 > 0 && candidate2 == nums[i]) count2++;
            else if (count1 == 0) {
                candidate1 = nums[i];
                count1++;
            } else if (count2 == 0) {
                candidate2 = nums[i];
                count2++;
                continue;
            } else {
                count1--;
                count2--;
            }
        }
        if (count1 > 0) {
            int count = 0;
            for (int i = 0; i < len; i++) {
                if (candidate1 == nums[i]) count++;
            }
            if (count > len / 3) ans.push_back(candidate1);
        }
        if (count2 > 0) {
            int count = 0;
            for (int i = 0; i < len; i++) {
                if (candidate2 == nums[i]) count++;
            }
            if (count > len / 3) ans.push_back(candidate2);
        }
        return ans;
    }
};
