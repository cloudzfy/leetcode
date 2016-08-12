// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        int ans = 0, pre = 0;
        for (int i = 1; i < n; i++) {
            if (knows(ans, i)) {
                pre = ans;
                ans = i;
            }
        }
        for (int i = ans - 1; i >= 0; i--) {
            if (knows(ans, i)) return -1;
        }
        for (int i = 0; i < n; i++) {
            if (ans == i || pre == i) continue;
            if (!knows(i, ans)) return -1;
        }
        return ans;
    }
};
