class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxNum = 1, minNum = 1, secminNum = 1;
        bool flag = false;
        int ans = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                maxNum *= nums[i];
                minNum *= nums[i];
                ans = max(ans, maxNum);
                ans = max(ans, minNum);
                if (flag) {
                    secminNum *= nums[i];
                    ans = max(ans, secminNum);
                }
            }
            if (nums[i] < 0) {
                minNum *= nums[i];
                ans = max(ans, minNum);
                maxNum = 1;
                if (flag) {
                    secminNum *= nums[i];
                    ans = max(ans, secminNum);
                }
                flag = true;
            }
            if (nums[i] == 0) {
                minNum = 1;
                maxNum = 1;
                secminNum = 1;
                flag = false;
                ans = max(ans, 0);
            }
        }
        return ans;
    }
};
