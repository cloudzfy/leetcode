class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        if (A > C) swap(A, C);
        if (B > D) swap(B, D);
        if (E > G) swap(E, G);
        if (F > H) swap(F, H);
        vector<int> x;
        x.push_back(A);
        x.push_back(C);
        x.push_back(E);
        x.push_back(G);
        vector<int> y;
        y.push_back(B);
        y.push_back(D);
        y.push_back(F);
        y.push_back(H);
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        int ans = 0;
        for (int i = 1; i < x.size(); i++) {
            for (int j = 1; j < y.size(); j++) {
                if (x[i - 1] + x[i] < 2 * C && x[i - 1] + x[i] > 2 * A
                    && y[j - 1] + y[j] < 2 * D && y[j - 1] + y[j] > 2 * B) {
                    ans += (x[i] - x[i - 1]) * (y[j] - y[j - 1]);
                    continue;
                }
                if (x[i - 1] + x[i] < 2 * G && x[i - 1] + x[i] > 2 * E
                    && y[j - 1] + y[j] < 2 * H && y[j - 1] + y[j] > 2 * F) {
                    ans += (x[i] - x[i - 1]) * (y[j] - y[j - 1]);
                    continue;
                }
            }
        }
        return ans;
    }
};
