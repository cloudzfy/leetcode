class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        k = min(k, n1 * n2);
        vector<int> idx(n1, 0);
        vector<pair<int, int> > ans;
        for (int i = 0; i < k; i++) {
            int sum = INT_MAX, p = -1;
            for (int j = 0; j < n1; j++) {
                if (idx[j] < n2 && nums1[j] + nums2[idx[j]] < sum) {
                    p = j;
                    sum = nums1[j] + nums2[idx[j]];
                }
            }
            ans.push_back(make_pair(nums1[p], nums2[idx[p]]));
            idx[p]++;
        }
        return ans;
    }
};
