class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        for (int i = 0; i < x.size(); i++) {
            if (i + 3 < x.size()) {
                if (x[i] >= x[i + 2] && x[i + 1] <= x[i + 3]) return true;
            }
            if (i + 4 < x.size()) {
                if (x[i + 1] == x[i + 3] && x[i] + x[i + 4] >= x[i + 2]) return true;
            }
            if (i + 5 < x.size()) {
                if (x[i + 1] <= x[i + 3] && x[i + 1] + x[i + 5] >= x[i + 3] && x[i + 4] <= x[i + 2] && x[i + 4] >= x[i + 2] - x[i]) return true;
            }
        }
        return false;
    }
};
