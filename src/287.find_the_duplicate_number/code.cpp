class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int left = 1, right = n;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (count(nums, mid) > mid) right = mid;
            else left = mid + 1;
        }
        return left;
    }
    int count(vector<int>& nums, int target) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= target) ans++;
        }
        return ans;
    }
};
