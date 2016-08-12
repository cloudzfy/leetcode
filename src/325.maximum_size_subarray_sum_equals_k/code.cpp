class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        if (n == 0) return ans;
        vector<int> sums(n, 0);
        sums[0] = nums[0];
        if (sums[0] == k) ans = 1;
        for (int i = 1; i < n; i++) {
            sums[i] = sums[i - 1] + nums[i];
            if (sums[i] == k) ans = i + 1;
        }
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {
            m[sums[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            if (m.find(sums[i] + k) != m.end() && m[sums[i] + k] > i) {
                ans = max(ans, m[sums[i] + k] - i);
            }
        }
        return ans;
    }
};
