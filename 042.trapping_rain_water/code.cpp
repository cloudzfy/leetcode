class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 1) return 0;
        int maxHeight = -1, maxIndex = -1;
        int n = height.size();
        for (int i = 0; i < n; i++) {
            if (height[i] > maxHeight) {
                maxHeight = height[i];
                maxIndex = i;
            }
        }
        int ans = 0, curHeight = height[0];
        for (int i = 1; i < maxIndex; i++) {
            if (curHeight < height[i]) curHeight = height[i];
            else ans += curHeight - height[i];
        }
        curHeight = height[n - 1];
        for (int i = n - 2; i > maxIndex; i--) {
            if (curHeight < height[i]) curHeight = height[i];
            else ans += curHeight - height[i];
        }
        return ans;
    }
};
