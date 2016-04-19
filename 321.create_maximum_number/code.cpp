class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> dp1;
        vector<vector<int>> dp2;
        getDP(nums1, dp1);
        getDP(nums2, dp2);
        reverse(dp1.begin(), dp1.end());
        reverse(dp2.begin(), dp2.end());
        vector<int> ans;
        bool isFirst = true;
        for (int m = 0; m <= k && m < dp1.size(); m++) {
            int n = k - m;
            if (n < 0) continue;
            if (n >= dp2.size()) continue;
            vector<int> myans = merge(dp1[m], dp2[n]);
            if (isFirst) {
                isFirst = false;
                ans = myans;
            } else {
                if (isLarger(myans, 0, ans, 0)) {
                    ans = myans;
                }
            }
        }
        return ans;
    }
    void getDP(vector<int>& nums, vector<vector<int>>& dp) {
        dp.push_back(nums);
        if (nums.size() == 0) return;
        vector<int>::iterator it = nums.begin(), tmp;
        while (it + 1 != nums.end()) {
            if (*it < *(it + 1)) {
                if (it != nums.begin()) {
                    tmp = it - 1;
                    nums.erase(it);
                    it = tmp;
                } else {
                    nums.erase(it);
                }
                dp.push_back(nums);
                
            } else it++;
        }
        while (nums.size()) {
            tmp = it - 1;
            nums.erase(it);
            it = tmp;
            dp.push_back(nums);
        }
    }
    vector<int> merge(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<int> ans(m + n, 0);
        int i = 0, j = 0, k = 0;
        while (i < m || j < n) {
            if (i < m && j < n) {
                if (isLarger(nums1, i, nums2, j)) {
                    ans[k++] = nums1[i++];
                } else {
                    ans[k++] = nums2[j++];
                }
            } else if (i < m) {
                ans[k++] = nums1[i++];
            } else {
                ans[k++] = nums2[j++];
            }
        }
        return ans;
    }
    bool isLarger(vector<int>& nums1, int i, vector<int>& nums2, int j) {
        int m = nums1.size(), n = nums2.size();
        while (i < m && j < n) {
            if (nums1[i] > nums2[j]) return true;
            if (nums1[i] < nums2[j]) return false;
            i++;
            j++;
        }
        return i < m;
    }
};
