class Solution {
public:
    int nthUglyNumber(int n) {
        int factor2 = 2, factor3 = 3, factor5 = 5;
        int index2 = 1, index3 = 1, index5 = 1;
        vector<int> ans(n, 0);
        ans[0] = 1;
        for(int i = 1; i < n; i++) {
            int minNum = min(factor2, min(factor3, factor5));
            ans[i] = minNum;
            if (minNum == factor2) {
                factor2 = ans[index2++] * 2;
            }
            if (minNum == factor3) {
                factor3 = ans[index3++] * 3;
            }
            if (minNum == factor5) {
                factor5 = ans[index5++] * 5;
            }
        }
        return ans[n - 1];
    }
};
