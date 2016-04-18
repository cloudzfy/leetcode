class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long reach = 0;
        int ans = 0;
        int index = 0;
        while (reach < n) {
            if (index < nums.size() && reach + 1 >= nums[index]) {
                reach += nums[index];
                index++;
            } else {
                reach += reach + 1;
                ans++;
            }
        }
        return ans;
    }
};
