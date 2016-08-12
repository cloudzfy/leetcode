class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int ans = (C - A) * (D - B) + (G - E) * (H - F);
        int Ax = max(A, E);
        int Bx = max(B, F);
        int Cx = min(C, G);
        int Dx = min(D, H);
        if (Ax >= Cx || Bx >= Dx) return ans;
        return ans - (Cx - Ax) * (Dx - Bx);
    }
};
