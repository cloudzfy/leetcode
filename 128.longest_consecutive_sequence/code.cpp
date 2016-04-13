class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]] = false;
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (!m[nums[i]]) {
                m[nums[i]] = true;
                int sum = 1;
                int num = nums[i] - 1;
                while (m.find(num) != m.end()) {
                    m[num--] = true;
                    sum++;
                }
                num = nums[i] + 1;
                while (m.find(num) != m.end()) {
                    m[num++] = true;
                    sum++;
                }
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};
