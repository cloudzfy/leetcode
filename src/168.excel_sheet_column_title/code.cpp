class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        while (n > 0) {
            int m = (n - 1) % 26;
            char ch = 'A' + m;
            ans = ch + ans;
            n = (n - m - 1) / 26;
        }
        return ans;
    }
};
