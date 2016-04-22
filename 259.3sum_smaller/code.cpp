class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int count = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1, right = n - 1;
            while (left < right) {
                while (left + 1 < right && nums[i] + nums[left] + nums[right] >= target) right--;
                if (nums[i] + nums[left] + nums[right] >= target) break;
                count += right - left;
                left++;
            }
        }
        return count;
    }
};
