class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans(n, 1);
        int pre = 1, count = 1;
        for (int i = 1; i < n; i++) {
            if (pre * 10 <= n) {
                ans[count++] = pre * 10;
                pre *= 10;
            } else {
                while (pre % 10 == 9 || pre + 1 > n) pre /= 10;
                ans[count++] = pre + 1;
                pre += 1;
            }
        }
        return ans;
    }
};
