class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = getResult(nums[i], a, b, c);
        }
        vector<int> ans(nums.size(), 0);
        int left = 0, right = nums.size() - 1;
        if (a > 0) {
            int count = right;
            while (count >= 0) {
                if (nums[left] < nums[right]) ans[count--] = nums[right--];
                else ans[count--] = nums[left++];
            }
        } else {
            int count = 0;
            while (count < nums.size()) {
                if (nums[left] < nums[right]) ans[count++] = nums[left++];
                else ans[count++] = nums[right--];
            }
        }
        return ans;
    }
    
    int getResult(int num, int a, int b, int c) {
        return a * num * num + b * num + c;
    }
};
