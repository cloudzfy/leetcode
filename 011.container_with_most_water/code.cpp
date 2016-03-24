class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int l = 0, r = len - 1;
        int ans = 0;
        while (l < r) {
            ans = max(ans, min(height[l], height[r]) * (r - l));
            if (height[l] < height[r]) {
                int i = l + 1;
                while (height[i] < height[l] && i < len) {
                    i++;
                }
                l = i;
            } else {
                int i = r - 1;
                while(height[i] < height[r] && i >= 0) {
                    i--;
                }
                r = i;
            }
        }
        return ans;
    }
};
