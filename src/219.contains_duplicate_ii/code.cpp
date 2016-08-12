class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
            count++;
            if (count > k + 1) {
                m[nums[i - count + 1]]--;
                count--;
            }
            if (m[nums[i]] > 1) return true;
        }
        return false;
    }
};
