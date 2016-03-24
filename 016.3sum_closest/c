class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                if (j > i + 1 && nums[j] == nums[j - 1]) j++;
                else if (k < nums.size() - 1 && nums[k] == nums[k + 1]) k--;
                else {
                    int tmp = nums[i] + nums[j] + nums[k];
                    if (abs(tmp - target) < abs(ans - target)) {
                        ans = tmp;
                    }
                    if (tmp > target) k--;
                    else if (tmp < target) j++;
                    else break;
                }
            }
            if(ans == target) break;
        }
        return ans;
    }
};
