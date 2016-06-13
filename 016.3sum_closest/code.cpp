class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1, right = n - 1;
            while (left < right) {
                while (left < right && left > i + 1 && nums[left] == nums[left - 1]) left++;
                while (left < right && right < n - 1 && nums[right] == nums[right + 1]) right--;
                if (left >= right) break;
                int sum = nums[i] + nums[left] + nums[right];
                if (abs(ans - target) > abs(sum - target)) ans = sum;
                if (sum < target) left++;
                else if (sum > target) right--;
                else break;
            }
            if (ans == target) break;
        }
        return ans;
    }
};
