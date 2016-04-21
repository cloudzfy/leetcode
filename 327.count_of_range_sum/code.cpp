class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> sums(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        return mergeSort(sums, 0, n, lower, upper);
    }
    int mergeSort(vector<long long>& nums, int begin, int end, int lower, int upper) {
        if (end - begin <= 0) return 0;
        int mid = (begin + end) >> 1;
        int count = 0;
        count += mergeSort(nums, begin, mid, lower, upper);
        count += mergeSort(nums, mid + 1, end, lower, upper);
        vector<long long> tmp(end - begin + 1, 0);
        int t = 0;
        for (int i = begin, j = mid + 1, k = mid + 1, l = mid + 1; i <= mid; i++) {
            while (j <= end && nums[j] - nums[i] <= upper) j++;
            while (k <= end && nums[k] - nums[i] < lower) k++;
            count += j - k;
            while (l <= end && nums[l] < nums[i]) tmp[t++] = nums[l++];
            tmp[t++] = nums[i];
        }
        for (int i = 0; i < t; i++) nums[i + begin] = tmp[i];
        return count;
    }
};
