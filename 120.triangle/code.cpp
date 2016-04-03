class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> map(n, 0);
        for (int i = 0; i < n; i++) {
            if (i != 0) map[i] = map[i - 1] + triangle[i][i];
            for (int j = i - 1; j > 0; j--) {
                map[j] = triangle[i][j] + min(map[j - 1], map[j]);
            }
            map[0] += triangle[i][0];
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            ans = min(ans, map[i]);
        }
        return ans;
    }
};
