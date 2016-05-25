class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n1 = nums1.size(), n2 = nums2.size();
        int i = 0, j = 0;
        vector<int> ans;
        while (i < n1 && j < n2) {
            while (i < n1 && nums1[i] < nums2[j]) i++;
            if (i == n1) break; 
            while (j < n2 && nums2[j] < nums1[i]) j++;
            if (j == n2) break;
            if (nums1[i] == nums2[j]) {
                if (ans.size() == 0 || ans.back() != nums1[i]) ans.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        return ans;
    }
};
