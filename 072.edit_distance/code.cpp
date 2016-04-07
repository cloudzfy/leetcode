class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.length() + 1;
        int n2 = word2.length() + 1;
        vector<vector<int>> m(n1, vector<int>(n2, n1 + n2));
        for (int i = 0; i < n1; i++) {
            m[i][0] = i;
        }
        for (int i = 0; i < n2; i++) {
            m[0][i] = i;
        }
        for (int i = 1; i < n1; i++) {
            for (int j = 1; j < n2; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    m[i][j] = m[i - 1][j - 1];
                } else {
                    m[i][j] = m[i - 1][j - 1] + 1;
                }
                m[i][j] = min(m[i][j], min(m[i - 1][j] + 1, m[i][j - 1] + 1));
            }
        }
        return m[n1 - 1][n2 - 1];
    }
};
