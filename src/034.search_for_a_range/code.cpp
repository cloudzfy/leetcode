class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left, right;
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int mid = (low + high) >> 1;
            if (nums[mid] == target) high = mid;
            else if (nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        if (low > high || nums[low] != target) return vector<int>{-1, -1};
        left = low;
        low = 0;
        high = nums.size() - 1;
        while (low < high) {
            int mid = (low + high + 1) >> 1;
            if (nums[mid] == target) low = mid;
            else if (nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        if (low > high || nums[high] != target) return vector<int>{-1, -1};
        right = high;
        return vector<int>{left, right};
    }
};
