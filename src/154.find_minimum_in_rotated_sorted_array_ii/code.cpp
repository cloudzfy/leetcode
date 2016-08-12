class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) return nums[0];
        int left = 0, right = len - 1;
        while (left < right && nums[left] >= nums[right]) {
            int mid = (left + right) >> 1;
            if (nums[mid] > nums[right]) left = mid + 1;
            else if (nums[mid] < nums[right]) right = mid;
            else right--;
        }
        return nums[left];
    }
};
