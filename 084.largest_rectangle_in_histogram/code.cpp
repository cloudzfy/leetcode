class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int n = heights.size();
        stack<int> s;
        int ans = 0, h = 0;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && heights[s.top()] > heights[i]) {
                h = s.top();
                s.pop();
                ans = max(ans, s.empty()? i * heights[h] : (i - s.top() - 1) * heights[h]);
            }
            s.push(i);
        }
        return ans;
    }
};
