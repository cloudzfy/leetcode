class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 3) return 0;
        int ans = 0;
        int leftHeight = height[0], rightHeight = height[n - 1];
        int left = 0, right = n - 1;
        while (left < right) {
            if (leftHeight < rightHeight) {
                left++;
                ans += leftHeight - height[left] > 0 ? leftHeight - height[left] : 0;
                leftHeight = max(leftHeight, height[left]);
            } else {
                right--;
                ans += rightHeight - height[right] > 0 ? rightHeight - height[right] : 0;
                rightHeight = max(rightHeight, height[right]);
            }
        }
        return ans;
    }
};
