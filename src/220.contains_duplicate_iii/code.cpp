class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        unordered_map<long long, long long> m;
        if (k < 0 || t < 0) return false;
        for (int i = 0; i < nums.size(); i++) {
            long long index = floor((long double)nums[i] / ((long long)t + 1));
            if (m.find(index) != m.end()) return true;
            if (m.find(index - 1) != m.end() && nums[i] - m[index - 1] <= (long long)t) return true;
            if (m.find(index + 1) != m.end() && m[index + 1] - nums[i] <= (long long)t) return true;
            m[index] = (long long)nums[i];
            if (i >= k) m.erase(nums[i - k] / ((long long)t + 1));
        }
        return false;
    }
};
