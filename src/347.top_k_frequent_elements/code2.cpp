class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        vector<int> count(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            count[++m[nums[i]]]++;
        }
        int idx = nums.size();
        vector<int> ans;
        while (count[idx] < k) idx--;
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->second > idx) {
                ans.push_back(it->first);
                k--;
            }
        }
        for (auto it = m.begin(); it != m.end() && k > 0; it++) {
            if (it->second == idx) {
                ans.push_back(it->first);
                k--;
            }
        }
        return ans;
    }
};
