class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
        int mid = *(nums.begin() + n / 2);
        int i = 0, j = n - 1, k = 0;
        while (k <= j) {
            if (nums[(2 * k + 1) % (n | 1)] > mid) {
                swap(nums[(2 * i + 1) % (n | 1)], nums[(2 * k + 1) % (n | 1)]);
                i++;
                k++;
            } else if (nums[(2 * k + 1) % (n | 1)] < mid) {
                swap(nums[(2 * j + 1) % (n | 1)], nums[(2 * k + 1) % (n | 1)]);
                j--;
            } else k++;
        }
    }
};
