class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        if (m == 0) return 0;
        int ans = INT_MIN;
        bool isReversed = false;
        if (n > m) {
            isReversed = true;
            swap(n, m);
        }
        for (int i = 0; i < n; i++) {
            vector<int> nums(m, 0);
            for (int j = i; j < n; j++) {
                for (int l = 0; l < m; l++) {
                    if (isReversed) nums[l] += matrix[l][j];
                    else nums[l] += matrix[j][l];
                }
                set<int> s;
                s.insert(0);
                int sum = 0;
                for (int l = 0; l < m; l++) {
                    sum += nums[l];
                    auto it = s.lower_bound(sum - k);
                    if (it != s.end()) ans = max(ans, sum - *it);
                    s.insert(sum);
                }
            }
        }
        return ans;
    }
};
