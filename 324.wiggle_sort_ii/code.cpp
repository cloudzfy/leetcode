class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return;
        int left = 0, right = n - 1;
        int mid = 0;
        while (left <= right) {
            int pivot = nums[left];
            int i = left, j = right;
            while (i < j) {
                while (i < j && nums[j] >= pivot) j--;
                nums[i] = nums[j];
                while (i < j && nums[i] < pivot) i++;
                nums[j] = nums[i];
            }
            nums[i] = pivot;
            mid = nums[i];
            if (i == (n - 1) / 2) break;
            if (i < (n - 1) / 2) left = i + 1;
            else right = i - 1;
        }
        int m = (n | 1);
        for (int i = 1, j = 1; i < 2 * n; i += 2) {
            if (nums[i % m] > mid) {
                swap(nums[i % m], nums[j % m]);
                j += 2;
            }
        }
        for (int i = 2 * n - 1, j = 2 * n - 1; i >= 1; i -= 2) {
            if (nums[i % m] < mid) {
                swap(nums[i % m], nums[j % m]);
                j -= 2;
            }
        }
    }
};
