class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0) return -1;
        int low = 0, high = len - 1;
        while (low <= high) {
            int mid = (low + high) >> 1;
            if (nums[mid] == target) return mid;
            if (nums[mid] > target) {
                if ((nums[mid] >= nums[0] && target >= nums[0]) 
                    || (nums[mid] <= nums[len - 1] && target <= nums[len - 1])) {
                    high = mid - 1;
                } else low = mid + 1;
            } else {
                if ((nums[mid] >= nums[0] && target >= nums[0]) 
                    || (nums[mid] <= nums[len - 1] && target <= nums[len - 1])) {
                    low = mid + 1;
                } else high = mid - 1;
            }
        }
        return -1;
    }
};
