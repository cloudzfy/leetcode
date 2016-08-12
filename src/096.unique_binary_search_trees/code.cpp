class Solution {
public:
    int numTrees(int n) {
        vector<int> map(n + 1, 0);
        map[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j + 1 <= i; j++) {
                map[i] += map[j] * map[i - 1 - j];
            }
        }
        return map[n];
    }
};
