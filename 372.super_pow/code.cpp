class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int ans = 1;
        a %= 1337;
        for (int i = 0; i < b.size(); i++) {
            if (i != 0) {
                ans = getPow(ans, 10);
            }
            ans = (ans * getPow(a, b[i])) % 1337;
        }
        return ans;
    }
    
    int getPow(int num, int exp) {
        int ans = 1;
        for (int i = 0; i < exp; i++) {
            ans = (ans * num) % 1337;
        }
        return ans;
    }
};
