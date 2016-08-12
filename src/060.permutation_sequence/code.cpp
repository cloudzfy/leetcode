class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> mark(n);
        string ans(n, '0');
        int count = 1;
        for (int i = 1; i <= n; i++) {
            mark[i - 1] = i;
            count *= i;
        }
        k = k - 1;
        for (int i = 0; i < n; i++) {
            count /= (n - i);
            ans[i] = mark[k / count] + '0';
            for (int j = k / count; j < n - 1; j++) {
                mark[j] = mark[j + 1];
            }
            k %= count;
        }
        return ans;
    }
};
