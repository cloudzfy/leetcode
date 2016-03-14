class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = (int)nums1.size();
        int n = (int)nums2.size();
        if ((m + n) % 2 == 1)
        {
            return find(nums1, m, nums2, n, (m + n) / 2 + 1);
        }
        else
        {
            return (find(nums1, m, nums2, n, (m + n) / 2)
                    + find(nums1, m, nums2, n, (m + n) / 2 + 1)) / 2;
        }
    }
    double find(vector<int>& nums1, int m, vector<int>& nums2, int n, int k)
    {
        if (m > n)
        {
            return find(nums2, n, nums1, m, k);
        }
        if (m == 0)
        {
            return nums2[k - 1 + nums2.size() - n];
        }
        if (k <= 1)
        {
            return min(nums1[nums1.size() - m], nums2[nums2.size() - n]);
        }
        int pa = min(k / 2, m);
        int pb = k - pa;
        if (nums1[pa - 1 + nums1.size() - m] < nums2[pb - 1 + nums2.size() - n])
        {
            return find(nums1, m - pa, nums2, n, k - pa);
        }
        else if (nums1[pa - 1 + nums1.size() - m] > nums2[pb - 1 + nums2.size() - n])
        {
            return find(nums1, m, nums2, n - pb, k - pb);
        }
        else
        {
            return nums1[pa - 1];
        }
    }
};