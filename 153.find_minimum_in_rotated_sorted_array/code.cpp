class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        int low = 0, high = len - 1;
        while (low <= high) {
            int mid = (low + high) >> 1;
            if (mid > 0 && nums[mid - 1] > nums[mid]) return nums[mid];
            if (nums[mid] <= nums[len - 1]) high = mid - 1;
            if (nums[mid] > nums[len - 1]) low = mid + 1;
        }
        return nums[low];
    }
};
