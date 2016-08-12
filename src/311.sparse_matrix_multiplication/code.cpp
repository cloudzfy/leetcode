class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size();
        int m = B.size();
        int l = B[0].size();
        vector<vector<int>> C(n, vector<int>(l, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (A[i][j]) {
                    for (int k = 0; k < l; k++) {
                        C[i][k] += A[i][j] * B[j][k];
                    }
                }
            }
        }
        return C;
    }
};
