class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<int> s;
        for (int i = 0; i < nums.size(); i++) {
            auto it = s.lower_bound(nums[i] - t);
            if (it != s.end() && abs(*it - nums[i]) <= t) {
                return true;
            }
            s.insert(nums[i]);
            if (i >= k) s.erase(s.find(nums[i - k]));
        }
        return false;
    }
};
