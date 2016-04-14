class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int pivot = nums[left];
            int i = left, j = right;
            while (i < j) {
                while (i < j && nums[j] < pivot) j--;
                nums[i] = nums[j];
                while (i < j && nums[i] >= pivot) i++;
                nums[j] = nums[i];
            }
            nums[i] = pivot;
            if (i == k - 1) return nums[i];
            else if (i < k - 1) left = i + 1;
            else right = i - 1;
        }
        return nums[k - 1];
    }
};
