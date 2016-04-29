class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if ((n + m) % 2) return findKthSortedArrays(nums1, n, nums2, m, (n + m + 1) / 2);
        else return (findKthSortedArrays(nums1, n, nums2, m, (n + m) / 2) 
            + findKthSortedArrays(nums1, n, nums2, m, (n + m) / 2 + 1)) / 2;
    }
    
    double findKthSortedArrays(vector<int>& nums1, int n, vector<int>& nums2, int m, int k) {
        if (n > m) return findKthSortedArrays(nums2, m, nums1, n, k);
        if (n == 0) return nums2[nums2.size() - m + k - 1];
        if (k == 1) return min(nums1[nums1.size() - n], nums2[nums2.size() - m]);
        int i = min(k / 2, n);
        int j = k - i;
        if (nums1[nums1.size() - n + i - 1] < nums2[nums2.size() - m + j - 1]) {
            return findKthSortedArrays(nums1, n - i, nums2, m, k - i);
        } else {
            return findKthSortedArrays(nums1, n, nums2, m - j, k - j);
        }
    }
};
