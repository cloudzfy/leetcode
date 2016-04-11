class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int ans = INT_MAX;
        int count = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            count++;
            while (sum >= s) {
                if (sum >= s) ans = min(ans, count);
                sum -= nums[i - count + 1];
                count--;
            }
        }
        if (ans == INT_MAX) return 0;
        return ans;
    }
};
